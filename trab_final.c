#include <stdio.h>
#include <stdlib.h>
//create struct
struct Node
{
	long int value;
	struct Node *left;
	struct Node *right;
};
//create function
typedef struct Node Node;
//create tree
void create_tree(Node **head)
{
	*head = NULL;
}
//height of tree
int height(Node **head)
{
	if ((*head) == NULL)
	{
		return -1;
	}
	else
	{
		int he = height(&((*head)->left));
		int hd = height(&((*head)->right));
		if(he<hd) return hd+1;
		else return he+1;
	}
}
Node *Mleft(Node **head)
{
	if((*head) -> left != NULL)
	{
		return Mleft(&(*head)->left);
	}
	else
	{
		Node *aux = *head;
		if((*head)->right != NULL)
		{
			*head = ((*head) ->right);
		}
		else
		{
			*head = NULL;
		}
		return aux;
	}
}
//count the numbers of nodes
int count_no(Node *head)
{
	if( head == NULL)
	{
		return 0;
	}
	return 1+ count_no(head->left) + count_no(head->left);
}
//remove element
void removes(Node **head,long int value)
{
	if(*head == NULL)
	{
		return;
	}
	if(value < (*head)->value)
	{
		removes(&(*head)->left,value);
	}
	else
	{
		if(value > (*head)->value)
		{
			removes(&(*head)-> right,value);
		}
		else
		{
			Node *aux = *head;
			if (((*head) -> left == NULL) && ((*head)->right==NULL))
			{
				free(aux);
				(*head) = NULL;
			}
			else
			{
				if ((*head)->right == NULL)
				{
					(*head) = (*head)->left;
					aux = (*head)->left;
					aux->left = NULL;
					free(aux);
					aux = NULL;
				}
				else
				{
					if ((*head)->left == NULL)
					{
						(*head) = (*head) -> right;
						aux->left = NULL;
						free(aux);
						aux = NULL;
					}
					else
					{
					aux = Mleft(&(*head)->left);
					aux -> left =(*head)-> left;
					aux -> right = (*head)->right;
					(*head)->left = (*head)->right = NULL;
					free((*head));
					(*head) = aux;
					aux = NULL;
					}
				}
		
			}

		}
	}
}
// insert values in tree
void insert_value(Node **head,long int value)
{
	
	if (*head == NULL)
	{
		*head = (Node *) malloc(sizeof(Node));
		(*head) -> left = NULL;
		(*head) -> right = NULL;
		(*head) -> value = value;
	}
	else
	{
		if( value < ((*head) ->value))
		{
			insert_value(&((*head)-> left), value);
		}
		else
		{
			insert_value(&((*head)-> right), value);
		}
	}
}
// clear all tree
void clear_tree( Node *tree)
{
	if(tree == NULL)
	{
		return;
	}
	clear_tree(tree -> left);
	clear_tree(tree -> right);
	free(tree);
}
void print_tree_in_order( Node **tree)
{
	if(*tree == NULL)
	{
		
		return;
	}
	print_tree_in_order(&((*tree) ->left));
	printf("Value: %li\n", ((*tree)->value));
	print_tree_in_order(&((*tree) ->right));
	
}
void print_tree_pre_order( Node **tree)
{
	if(*tree == NULL)
	{
		
		return;
	}
	
	printf("Value: %li\n", ((*tree)->value));
	print_tree_pre_order(&((*tree) ->left));
	print_tree_pre_order(&((*tree) ->right));
	
}
void print_tree_pos_order( Node **tree)
{
	if(*tree == NULL)
	{
		
		return;
	}
	print_tree_pos_order(&((*tree) ->left));
	print_tree_pos_order(&((*tree) ->right));
	printf("Value: %li\n", ((*tree)->value));
	
}
int main(void)
{
	Node *tree = NULL;
	int value_insert, choice = -1, nos ;
	while( choice != 0)
	{
		printf("\nChoose one of the options below!\n(0) Exit\n(1) Insert Elements\n(2) Print in Order\n(3) Print in PosOrder\n(4) Print in PreOrder\n(5) Remove Element\n(6) Count os nós\n(7) Tree Height\n ");
		scanf("%d",&choice);
		if(choice == 1)
		{
		clear_tree(tree);
		create_tree(&(tree));			
			printf("How many key elements do you want to enter: ");
			scanf("%d",&value_insert);
			for(int i = 0; i<value_insert; i++)
			{
				insert_value(&(tree),rand()%100);
			}
			
			
		}
		else if(choice == 2)
		{
			if(tree == NULL)
			{
				printf("Empty Tree");
			}		
			else
			{
			printf("Tree in Order\n");
			print_tree_in_order(&(tree));
			}
		}
		else if(choice == 3)
		{
			if(tree == NULL)
			{
				printf("Empty Tree");
			}
			else
			{
			printf("Tree in PosOrder\n");
			print_tree_pos_order(&(tree));
			}
		
		}
		else if(choice == 4)
		{
			if(tree == NULL)	
			{
				printf("Empty Tree");
			}
			else
			{
			printf("Tree in PreOrder");
			print_tree_pre_order(&(tree));
			
			
			}

			
		}
		else if(choice == 5)
		{
			scanf("%d",&value_insert);
			removes(&(tree),value_insert);
			print_tree_pre_order(&(tree));

		}
		else if(choice == 6)
		{
			nos = count_no(tree);
			printf("Amount of Node(s) in Tree: %d\n",nos);

		}
		else if(choice == 7)
		{
			printf("Tree Height: %d",height(&(tree)));		
		}
	
	}
	clear_tree(tree);
		
	return 0;
}
