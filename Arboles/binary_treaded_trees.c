#include <stdio.h>
#include <conio.h>
struct tree
{
	int val;
	struct tree *right;
	struct tree *left;
	int thread;
};
struct tree *root = NULL;
struct tree* inssert_node(struct tree *root, struct tree *ptr, struct tree *rt)
{
	if(root == NULL)
	{
		root = ptr;
		if(rt!=NULL)
		{
			root->right = rt;
			root->thread = 1;
		}
	}
	else if(ptr->val < root->val)
		root->left=insert_node(root->left, ptr, root);
	else
		if(root->thread==1)
			root->left=insert_node(root->left, ptr, root);
		else
			if(root->thread==1)
			{
				root->right=insert_node(NULL, ptr, rt);
				root->thread=0;
			}
			else
				root->right=insert_node(root->right, ptr, rt);
	return root;
}
struct tree* create_threaded_tree()
{
	struct tree *ptr;
	int num;
	printf("\n Enter the elements, press -1 to terminate ");
	scanf("%d", &num);
	while(num!=-1)
	{
		ptr=(struct tree*)malloc(sizeof(struct tree));
		ptr->val=num;
		ptr->left=ptr->right=NULL;
		ptr->thread=0;
		toot=insert_node(root, ptr, NULL);
		printf(" \n Enter the next element ");
		fflush(stdin);
		scanf("%d", &num);
	}
	return root;
}
void inorder(struct tree *root)
{
	struct tree *ptr=root, *prev;
	do
	{
		while(ptr!=NULL)
		{
			prev=ptr;
			ptr=ptr->left;
		}
		if(prev!=NULL)
		{
			printf("%d", prev->val);
			ptr=prev->right;
			while(prev!=null && prev->thread)
			{
				printf("%d", ptr->val);
				prev=ptr;
				ptr=ptr->right;
			}
		}
	}while(ptr!=NULL);
}

