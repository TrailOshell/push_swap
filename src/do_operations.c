/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:35:11 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/22 14:51:11 by tsomchan         ###   ########.fr       */
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

