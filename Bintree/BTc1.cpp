#include "stdio.h"
#include "stdlib.h"
struct tree
{
 int data;
 struct tree *left;
 struct tree *right;
};
typedef struct tree treenode;
typedef treenode *btree;

btree createtree(int *data,int pos)
{
  btree newnode;
  if(data[pos]==0||pos>15)
	return NULL;
  else
	  newnode=(btree)malloc(sizeof(treenode));
    newnode->data=data[pos];
	newnode->left=createtree(data,2*pos);
	newnode->right=createtree(data,2*pos+1);
	return newnode;
   }


void preOrder( btree p)
{
  if(p!= NULL)
    {
		printf("%4d",p->data);
        preOrder(p->left);
        preOrder(p->right);
    }
}

void inOrder(btree p)
{
  if(p != NULL)
    {
        inOrder(p->left);
        printf("%4d",p->data);
        inOrder(p->right);
    }
}

void postOrder(btree p)
{
  if(p != NULL)
    {
        postOrder(p->left);
        postOrder(p->right);
        printf("%4d",p->data);
    }
}

int main()
{
 btree root=NULL;
 int i;
 int data[16]={0,5,4,6,2,0,0,8,1,3,0,0,0,0,7,9};
 root=createtree(data,1);
 printf("PreOrder is:\n");
 preOrder(root);
 printf("\n");
 printf("midOrder is:\n");
 inOrder(root);
 printf("\n");
 printf("postorder is:\n");
 postOrder(root);
 printf("\n");
}

