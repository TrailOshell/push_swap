/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:35:11 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/28 19:35:40 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_swap_push(t_stack *stack)
{
	stack->swap(stack);
	stack->push(stack);
}

void	do_r_till_target_push(t_stack *stack, t_node *head)
{
	while (stack->target != head)
	{
		head = head->next;
		stack->rotate(stack);
	}
	stack->push(stack);
}

void	do_rr_till_target_push(t_stack *stack, t_node *head)
{
	while (stack->target != head)
	{
		head = head->prev;
		stack->reverse(stack);
	}
	stack->push(stack);
}

void	do_condition_then_push(t_stack *stack, t_node **stack_name, int chunk_order)
{
	t_node	*head;

	add_log(stack, newlog(stack, NULL, "pushing"), 0);
	head = *stack_name;
	if (stack->target == (*stack_name))
		stack->push(stack);
	else if (stack->target == (*stack_name)->next)
		do_swap_push(stack);
	else if (isnear_head(stack, *stack_name, stack->target) == 1)
		do_r_till_target_push(stack, head);
	else if (isnear_head(stack, *stack_name, stack->target) == 0)
		do_rr_till_target_push(stack, head);
	stack->b->chunk_order = chunk_order;
}
