#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct	Node
{
    struct Node* left;
    struct Node* right;
    int data;
}	Node;

typedef struct	Queue
{
	int	front;
	int	rear;
	Node*	items[MAX_SIZE];
}	Queue;

Node* newNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->left=node->right=NULL;
    node->data=data;
    return node;
}

void	initQueue(Queue *q)
{
	q->front = -1;
	q->rear = -1;
}

int	isEmpty(Queue *q)
{
	return (q->front == -1);
}

void	enqueue(Queue *q, Node *root)
{
	if (isEmpty(q))
		q->front = 0;
	q->rear++;
	q->items[q->rear] = root;
}

Node	*dequeue(Queue *q)
{
	Node	*node;

	node = q->items[q->front];
	q->front++;
	if (q->front > q->rear)
	{
		q->front = -1;
		q->rear = -1;
	}
	return (node);	
}

void	levelOrder(Node* root)
{
	Queue	q;
	Node	*curr;

	initQueue(&q);
	enqueue(&q, root);
	while (!isEmpty(&q))
	{
		curr = dequeue(&q);
		printf("%d ", curr->data);
		if (curr->left)
			enqueue(&q, curr->left);
		if (curr->right)
			enqueue(&q, curr->right);
	}
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
