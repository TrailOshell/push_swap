/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:44:25 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/09 14:45:28 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_has_chunk(t_node *stack, int chunk_order)
{
	t_node	*tmp;
	t_node	*head;

	head = stack;
	tmp = stack;
	while (tmp)
	{
		if (tmp->chunk_order == chunk_order)
			return (1);
		tmp = tmp->next;
		if (tmp == head)
			break ;
	}
	return (0);
}

int	find_min_in_chunk(t_node *stack, int chunk_order)
{
	t_node	*min_node;
	t_node	*head;

	if ((stack)->chunk_order == chunk_order)
		min_node = stack;
	else
		min_node = (stack)->prev;
	head = stack;
	while (head->next != stack)
	{
		head = head->next;
		if (min_node->val > head->val && head->chunk_order == chunk_order)
			min_node = head;
	}
	return (min_node->val);
}

int	find_max_in_chunk(t_node *stack, int chunk_order)
{
	t_node	*max_node;
	t_node	*head;

	if ((stack)->chunk_order == chunk_order)
		max_node = stack;
	else
		max_node = (stack)->prev;
	head = stack;
	while (head->next != stack)
	{
		head = head->next;
		if (max_node->val < head->val && head->chunk_order == chunk_order)
			max_node = head;
	}
	return (max_node->val);
}

void	find_target_min_max(t_data *data, t_node *head, int min, int max)
{
	t_node		*tmp;
	t_node		*tmp2;

	tmp = head;
	tmp2 = head->prev;
	data->target = NULL;
	while (tmp)
	{
		if (tmp->val == max || tmp->val == min)
			data->target = tmp;
		else if (tmp2->val == max || tmp2->val == min)
			data->target = tmp2;
		if (data->target != NULL)
			break ;
		tmp = tmp->next;
		tmp2 = tmp2->prev;
	}
}

void	set_target_chunk(t_data *data, int *ismin
		, int *near_head, int chunk)
{
	int	min;
	int	max;

	min = find_min_in_chunk(data->b, chunk);
	max = find_max_in_chunk(data->b, chunk);
	find_target_min_max(data, data->b, min, max);
	*ismin = 0;
	if (data->target->val == min)
		*ismin = 1;
	*near_head = isnear_head(data->b, data->target);
}
