#include <stdlib.h>

typedef struct s_node
{
	int				number;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

void	add_node(t_node **tree, t_node *node)
{
	if (!tree)
		return ;
	if (!*tree)
		*tree = node;
	else
	{
		if (node && node->number > (*tree)->number)
			add_node(&((*tree)->right), node);
		else
			add_node(&((*tree)->left), node);
	}
}

t_node	*init_node(int number)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node)
	{
		node->number = number;
	}
	else
		return (NULL);
	return (node);
}

void	print_list(t_node *node)
{
	if (node)
	{
		printf("%i\n", node->number);
		if (node->left)
			print_list(node->left);
		if (node->right)
			print_list(node->right);
		free(node);
	}
}

int	main(void)
{
	t_node	*tree;

	tree = NULL;
	add_node(&tree, init_node(3));
	add_node(&tree, init_node(5));
	add_node(&tree, init_node(4));
	add_node(&tree, init_node(1));
	print_list(tree);
	return (0);
}
