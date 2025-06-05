#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct	Node
{
    struct Node* left;
    struct Node* right;
    int data;
}	Node;

Node* newNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->left=node->right=NULL;
    node->data=data;
    return node;
}

int     getHeight(Node* root)
{
        int     height_l;
        int     height_r;

        height_l = 0;
        height_r = 0;
        if (root->left)
                height_l += getHeight(root->left);
        if (root->right)
                height_r += getHeight(root->right);
        if (height_l >= height_r)
                return (height_l + 1);
        else
                return (height_r + 1);
}

void	print_level(Node *node, int i)
{
	if (!node)
		return ;
	if (i == 0)
		printf("%d ", node->data);
	else
	{
		print_level(node->left, i - 1);
		print_level(node->right, i - 1);
	}
}

void	levelOrder(Node* root)
{
	int	height;
	int	i;
	
	height = getHeight(root);
	i = 0;
	while (i < height)
		print_level(root, i++);
}

Node* insert(Node* root,int data){
    if(root==NULL)
        return newNode(data);
    else{
        Node* cur;
        if(data<=root->data){
            cur=insert(root->left,data);
            root->left=cur;                
        }
        else{
            cur=insert(root->right,data);
            root->right=cur;
        }
        
    }
    return root;
}
int main(){
    Node* root=NULL;
    int T,data;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&data);
        root=insert(root,data);
    }
    levelOrder(root);
    return 0;
    
}
