/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:28:25 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/03 18:01:12 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*current_stack_order(t_data *data, t_node **stack)
{
	t_node	*head;
	t_node	*min_node;
	t_node	*min_prev;
	t_node	*tmp;

	dupe_stack(data, stack, &(data->order));
	min_prev = NULL;
	head = data->order;
	while (head->next != data->order)
	{
		min_node = head;
		tmp = head;
		while (tmp->next != head)
		{
			tmp = tmp->next;
			if (tmp->val < min_node->val
				&& (!min_prev || tmp->val > min_prev->val))
				min_node = tmp;
		}
		swap_nodes_value(&(min_node), &(head));
		min_prev = head;
		head = head->next;
	}
	return (data->order);
}

