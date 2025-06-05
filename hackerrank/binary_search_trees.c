#include <stdio.h>
#include <stdlib.h>

typedef struct	Node
{
    struct Node*	left;
    struct Node*	right;
    int			data;
}	Node;

Node*	newNode(int data)
{
	Node*	node;

	node = (Node*)malloc(sizeof(Node));
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return (node);
}

int	getHeight(Node* root)
{
	int	height_l;
	int	height_r;

	height_l = 0;
	height_r = 0;
	if (root->left)
	{
		height_l = 1;
		height_l += getHeight(root->left);
	}
	if (root->right)
	{
		height_r = 1;
		height_r += getHeight(root->right);
	}
	if (height_l >= height_r)
		return (height_l);
	else
		return (height_r);
}

Node*	insert(Node* root,int data)
{
	if (root == NULL)
		return (newNode(data));
	else
	{
		Node*	cur;
		if (data <= root->data)
		{
			cur = insert(root->left, data);
			root->left = cur;
		}
		else
		{
			cur = insert(root->right, data);
			root->right = cur;
		}
	}
	return (root);
}

int	main(void)
{
	Node*	root;
	int	T;
	int	data;
	int	height;

	root = NULL;
	scanf("%d", &T);
	while (T-- > 0)
	{
		scanf("%d", &data);
		root = insert(root, data);
	}
	height = getHeight(root);
	printf("%d", height);
	return (0);
}
