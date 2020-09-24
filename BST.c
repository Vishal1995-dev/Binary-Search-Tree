#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * left;
	struct node * right;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE head,int value)
{
	PNODE newn =(PNODE)malloc(sizeof(NODE));
	newn->data=value;
	newn->left=NULL;
	newn->right=NULL;
	
	PNODE temp=*head;
	
	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		while(1)
		{
			if(temp->data==value)
			{
				printf("Data already present in tree\n");
				free(newn);
				break;
			}
			if(temp->data<value)
			{
				if(temp->right==NULL)
				{
					temp->right=newn;
					break;
				}
				temp=temp->right;
			}
			else
			{
				if(temp->left==NULL)
				{
					temp->left=newn;
					break;
				}
				temp=temp->left;
			}
		}
	}
}

int Search(PNODE head,int value)
{
	int ret=0;
	while(head!=NULL)
	{
		if(head->data==value)
		{
			ret=1;
			break;
		}
		else if(head->data>value)
		{
			head=head->left;
		}
		else
		{
			head=head->right;
		}
	}
	return ret;
}

void Inorder(PNODE head)
{
	if(head!=NULL)
	{
		Inorder(head->left);
		printf("%d  ",head->data);
		Inorder(head->right);
	}
}


void Preorder(PNODE head)
{
	if(head!=NULL)
	{
		printf("%d  ",head->data);
		Inorder(head->left);
		Inorder(head->right);
	}
}

void Postorder(PNODE head)
{
	if(head!=NULL)
	{
		Inorder(head->left);
		Inorder(head->right);
		printf("%d  ",head->data);
	}
}

int main()
{
	PNODE first = NULL;
	int choice = 1;
	int val=0,ret=0;
	while(choice)
	{
		printf("--------------------------\n");
		printf("BST\n");
		printf("--------------------------\n");
		printf("1.Insert\n2.Search\n3.Display\n0.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter value to insert\n");
				scanf("%d",&val);
				Insert(&first,val);
				break;
			case 2:
				printf("Enter value to search\n");
				scanf("%d",&val);
				ret=Search(first,val);
				if(ret==1)
				{
					printf("Element is present\n");
				}
				else
				{
					printf("Element is not present\n");
				}
				break;
			case 3:
				printf("In-Order traversal : \n");
				Inorder(first);
				printf("\n");
				
				printf("Pre-Order traversal : \n");
				Preorder(first);
				printf("\n");
				
				printf("Post-Order traversal : \n");
				Postorder(first);
				printf("\n");
				break;
		}
	}
	return 0;
}
