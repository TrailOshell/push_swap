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

void	do_condition_then_push(t_data *data, t_node **stack, int chunk_order)
{
	t_node	*head;

	add_log(data, newlog(data, NULL, "pushing"), 0);
	head = *stack;
	if (data->target == (*stack))
		data->push(data);
	else if (data->target == (*stack)->next)
		do_swap_push(data);
	else if (isnear_head(*stack, data->target) == 1)
		do_r_till_target_push(data, head);
	else if (isnear_head(*stack, data->target) == 0)
		do_rr_till_target_push(data, head);
	data->b->chunk_order = chunk_order;
}

void	do_rra_till_ordered(t_data *data)
{
	int	min;

	add_log(data, newlog(data, NULL, "do_rra_till_ordered"), 0);
	min = find_min(&(data->a));
	while (data->a->val != min)
		do_rra(data);
}
