/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:35:11 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/06 15:22:39by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_operations(t_data *data, t_node *stack)
{
	if (stack == data->a)
	{
		data->swap = &(do_sa);
		data->rotate = &(do_ra);
		data->reverse = &(do_rra);
		data->push = &(do_pb);
	}
	else if (stack == data->b)
	{
		data->swap = &(do_sb);
		data->rotate = &(do_rb);
		data->reverse = &(do_rrb);
		data->push = &(do_pa);
	}
}

void	do_swap_push(t_data *data)
{
	data->swap(data);
	data->push(data);
}

void	do_r_till_target_push(t_data *data, t_node *head)
{
	while (data->target != head)
	{
		head = head->next;
		data->rotate(data);
	}
	data->push(data);
}

void	do_rr_till_target_push(t_data *data, t_node *head)
{
	while (data->target != head)
	{
		head = head->prev;
		data->reverse(data);
	}
	data->push(data);
}

void	do_condition_then_push(t_data *data, t_node *stack, int chunk_order)
{
	t_node	*head;

	head = stack;
	if (data->target == (stack))
		data->push(data);
	else if (data->target == (stack)->next)
		do_swap_push(data);
	else if (isnear_head(stack, data->target) == 1)
		do_r_till_target_push(data, head);
	else if (isnear_head(stack, data->target) == 0)
		do_rr_till_target_push(data, head);
	data->b->chunk_order = chunk_order;
}
