/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:09:38 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/28 22:04:21 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_node(t_node *node, char *text)
{
	printf("%s", text);
	printf(": [");
	while (node)
	{
		printf("%d", node->val);
		if (node->next)
			printf(",");
		node = node->next;
	}
	printf("]");
	printf("\n");
}

void	input_stack_b(t_stack *stack, char **input)
{
	int		num;

	//input++;
	while (*input)
	{
		num = atoi(*input);
		add_node_last(stack, 'b', nodenew(num));
		input++;
	}
}

void	push_swap(char **argv)
{
	t_stack	*stack;
	t_node	*node;

	stack = NULL;
	stack = start_stack(stack);
	input_stack(stack, argv);
	input_stack_b(stack, (char *[4]){(char [99]){"6"},
		(char [99]){"13"}, (char [99]){"14"}, NULL});
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	do_sa(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	do_sb(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	do_ss(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	//printf("last_a = %d\n", stack->last_a->val);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	push_swap(argv);
}

/*
	//printf("%p\n", stack);
	//node = malloc(sizeof(t_node));
	//write(1, "test\n", 6);
	//stack->a = node;
	//write(1, "test\n", 6);
	write(1, "test\n", 6);
	stack->a = malloc(sizeof(t_node));
	stack->a->val = 42;
	printf("%d", stack->a->val);
*/