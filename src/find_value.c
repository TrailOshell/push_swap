/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:45:15 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/06 16:43:34 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_max(t_node **stack)
{
	t_node	*max_node;
	t_node	*head;

	max_node = *stack;
	head = *stack;
	while (head->next != *stack)
	{
		head = head->next;
		if (max_node->val < head->val)
			max_node = head;
	}
	return (max_node->val);
}

int	find_min(t_node **stack)
{
	t_node	*min_node;
	t_node	*head;

	min_node = *stack;
	head = *stack;
	while (head->next != *stack)
	{
		head = head->next;
		if (min_node->val > head->val)
			min_node = head;
	}
	return (min_node->val);
}

void	find_median(t_data *data, t_node **stack)
{
	t_node	*tmp;
	int		node_count;
	int		median_count;
	int		node_current;

	node_count = count_nodes(*stack);
	current_stack_order(data, stack);
	median_count = (node_count / 2) + (node_count % 2);
	node_current = 1;
	tmp = data->order;
	while (node_current < median_count)
	{
		tmp = tmp->next;
		node_current++;
	}
	data->median = tmp->val;
}

void	find_quarter(t_data *data, t_node **stack)
{
	t_node	*tmp;
	int		node_count;
	int		quarter_count;
	int		node_current;

	node_count = count_nodes(*stack);
	current_stack_order(data, stack);
	quarter_count = (node_count / 4) + (node_count % 2);
	node_current = 1;
	tmp = data->order;
	while (node_current < quarter_count)
	{
		tmp = tmp->next;
		node_current++;
	}
	data->quarter = tmp->val;
}

void	find_half_quarter(t_data *data, t_node **stack)
{
	t_node	*tmp;
	int		node_count;
	int		half_quarter_count;
	int		node_current;

	node_count = count_nodes(*stack);
	current_stack_order(data, stack);
	half_quarter_count = (node_count / 8) + (node_count % 2);
	node_current = 1;
	tmp = data->order;
	while (node_current < half_quarter_count)
	{
		tmp = tmp->next;
		node_current++;
	}
	data->half_quarter = tmp->val;
}
