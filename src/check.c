/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:34:04 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/03 18:12:59 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_rotate_median_push(t_data *data)
{
	if (data->b->chunk_order == 1 && data->b->val <= data->quarter)
		return (1);
	else if (data->b->chunk_order > 1 && data->b->val > data->quarter)
		return (1);
	return (0);
}

int	check_rotate_quarter_push(t_data *data)
{
	//if (data->b->chunk_order == 1 && data->b->val <= data->half_quarter)
	//	return (1);
	//else if (data->b->chunk_order > 1 && data->b->val <= data->half_quarter)
	//	return (1);
	if (data->b->val <= data->half_quarter)
		return (1);
	return (0);
}

int	check_rotate_chunk(t_data *data, int value)
{
	if (data->b->chunk_order == 1 && data->b->val <= value)
		return (1);
	else if (data->b->chunk_order > 1 && data->b->val <= value)
		return (1);
	return (0);
}

int	check_median_push(t_data *data, t_node *stack, int median)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*head;
	int		index;

	tmp = stack;
	tmp2 = stack->prev;
	head = stack;
	index = 0;
	while (tmp)
	{
		if (tmp->val <= median)
		{
			data->target = tmp;
			return (1);
		}
		tmp = tmp->next;
		tmp2 = tmp2->prev;
		index++;
		if (tmp == head)
			break ;
	}
	data->target = NULL;
	return (0);
}

int	check_ordered(t_node *a)
{
	t_node	*head;

	head = a;
	while (a)
	{
		if (a->next == head)
			break ;
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}

int	isnear_head(t_data *data, t_node *stack, t_node *node)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		count;

	count = 0;
	tmp = stack;
	tmp2 = stack->prev;
	while (tmp != tmp2)
	{
		if (tmp->val == node->val)
			return (1);
		else if (tmp2->val == node->val)
			return (0);
		else if (tmp == tmp2)
			break ;
		tmp = tmp->next;
		tmp2 = tmp2->prev;
	}
	return (0);
}
