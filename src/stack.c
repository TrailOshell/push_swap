/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ /*   stack.c                                            :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:59:05 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/08 17:18:57by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*start_stack(t_stack *stack)
{
	if (!stack)
		stack = malloc(sizeof(t_stack));
	stack->a = NULL;
	stack->b = NULL;
	stack->last_a = NULL;
	stack->last_b = NULL;
	stack->order = NULL;
	stack->target = NULL;
	stack->iserror = 0;
	stack->median = 0;
	stack->quarter = 0;
	stack->swap = NULL;
	stack->rotate = NULL;
	stack->reverse = NULL;
	stack->push = NULL;
	stack->log = NULL;
	return (stack);
}

void	input_stack(t_stack *stack, t_node **stack_name, char **input)
{
	int		num;

	while (*input)
	{
		if (notnbr_error(stack, *input))
			return ;
		num = atoi_push_swap(*input);
		if (stack->a && dupnbr_error(stack, num))
			return ;
		add_node_last(stack, stack_name, nodenew(num, 0));
		input++;
	}
}

void	dupe_stack(t_stack *stack, t_node **stack_origin, t_node **stack_dupe)
{
	t_node	*head;
	t_node	*tmp;
	t_node	*new;

	head = *stack_origin;
	while (*stack_dupe)
		nodedel(&(*stack_dupe));
	while (*stack_origin)
	{
		new = nodenew((*stack_origin)->val, (*stack_origin)->chunk_order);
		add_node_last(stack, stack_dupe, new);
		*stack_origin = (*stack_origin)->next;
		if (*stack_origin == head)
			break ;
	}
}

void	dupe_chunk(t_stack *stack, t_node **stack_origin, t_node **stack_dupe,
			int chunk_order)
{
	t_node	*head;
	t_node	*tmp;
	t_node	*new;

	head = *stack_origin;
	tmp = *stack_origin;
	while (*stack_dupe)
		nodedel(&(*stack_dupe));
	while (tmp)
	{
		new = nodenew(tmp->val, tmp->chunk_order);
		add_node_last(stack, stack_dupe, new);
		tmp = tmp->next;
		if (tmp == head || tmp->chunk_order != chunk_order)
			break ;
	}
}

void	end_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack->a)
		nodedel(&stack->a);
	while (stack->b)
		nodedel(&stack->b);
	while (stack->order)
		nodedel(&stack->order);
	free_log(stack->log);
	free(stack);
}

//	print_node(stack->a, "deleting the stack...");

/* input_stack()
	printf("*argv = %s$\n", *argv);
	printf("notnbr_error(*argv) = %d$\n", notnbr_error(*argv));
*/