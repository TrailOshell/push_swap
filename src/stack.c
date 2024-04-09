/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:59:05 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/09 13:18:51 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	input_stack(t_data *data, t_node **stack, char **input)
{
	int		num;

	while (*input)
	{
		if (notnbr_error(data, *input))
			return ;
		num = atoi_push_swap(*input);
		if (data->a && dupnbr_error(data, num))
			return ;
		add_node_last(stack, nodenew(num, 0));
		input++;
	}
}

void	dupe_stack(t_node **origin, t_node **dupe)
{
	t_node	*head;
	t_node	*new;

	head = *origin;
	while (*dupe)
		nodedel(&(*dupe));
	while (*origin)
	{
		new = nodenew((*origin)->val, (*origin)->chunk_order);
		add_node_last(dupe, new);
		*origin = (*origin)->next;
		if (*origin == head)
			break ;
	}
}

t_node	*current_stack_order(t_data *data, t_node *stack)
{
	t_node	*head;
	t_node	*min_node;
	t_node	*min_prev;
	t_node	*tmp;

	dupe_stack(&stack, &(data->order));
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
