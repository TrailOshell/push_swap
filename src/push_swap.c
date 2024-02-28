/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:09:38 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/28 19:16:21 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(char **argv)
{
	t_stack	*stack;
	t_node	*node;

	stack = NULL;
	stack = start_stack(stack);
	stack->a = malloc(sizeof(t_node));
	stack->a->val = 42;
	write(1, "test\n", 6);
	printf("%d", stack->a->val);
	//input_stack(stack, argv);
}

int	main(int argc, char **argv)
{
	//if (argc < 2)
	//	return (0);
	write(1, "test\n", 6);
	push_swap(argv);
}

/*
	//printf("%p\n", stack);
	//node = malloc(sizeof(t_node));
	//write(1, "test\n", 6);
	//stack->a = node;
	//write(1, "test\n", 6);
*/