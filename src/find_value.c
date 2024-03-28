/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:45:15 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/28 17:36:02y tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_max(t_stack *stack, t_node **stack_name)
{
	t_node	*max_node;
	t_node	*head;

	max_node = *stack_name;
	head = *stack_name;
	while (head->next != *stack_name)
	{
		head = head->next;
		if (max_node->val < head->val)
			max_node = head;
	}
	return (max_node->val);
}

int	find_min(t_stack *stack, t_node **stack_name)
{
	t_node	*min_node;
	t_node	*head;

	min_node = *stack_name;
	head = *stack_name;
	while (head->next != *stack_name)
	{
		head = head->next;
		if (min_node->val > head->val)
			min_node = head;
	}
	return (min_node->val);
}

void	find_median(t_stack *stack, t_node **stack_name)
{
	t_node	*tmp;
	int		node_count;
	int		median_count;
	int		node_current;
	int		median;

	node_count = count_nodes(*stack_name);
	current_stack_order(stack, stack_name);
	median_count = (node_count / 2) + (node_count % 2);
	node_current = 1;
	tmp = stack->order;
	while (node_current < median_count)
	{
		tmp = tmp->next;
		node_current++;
	}
	stack->median = tmp->val;
}

void	find_quarter(t_stack *stack, t_node **stack_name)
{
	t_node	*tmp;
	int		node_count;
	int		quarter_count;
	int		node_current;
	int		median;

	node_count = count_nodes(*stack_name);
	current_stack_order(stack, stack_name);
	quarter_count = (node_count / 4) + (node_count % 2);
	node_current = 1;
	tmp = stack->order;
	while (node_current < quarter_count)
	{
		tmp = tmp->next;
		node_current++;
	}
	stack->quarter = tmp->val;
}

void	find_half_quarter(t_stack *stack, t_node **stack_name)
{
	t_node	*tmp;
	int		node_count;
	int		half_quarter_count;
	int		node_current;
	int		median;

	node_count = count_nodes(*stack_name);
	current_stack_order(stack, stack_name);
	half_quarter_count = (node_count / 8) + (node_count % 2);
	node_current = 1;
	tmp = stack->order;
	while (node_current < half_quarter_count)
	{
		tmp = tmp->next;
		node_current++;
	}
	stack->half_quarter = tmp->val;
}

//void	find_chunk_median(t_stack *stack, t_node **stack_name, int chunk_order)
//{
//	t_node	*tmp;
//	int		node_count;
//	int		median_count;
//	int		node_current;
//	int		median;

//	node_count = 0;
//	tmp = *stack_name;
//	while (tmp->next->chunk_order == chunk_order)
//	{
//		tmp = tmp->next;
//		node_count++;
//	}
//	current_stack_order(stack, stack_name);
//	median_count = (node_count / 2) + (node_count % 2);
//	node_current = 1;
//	tmp = stack->order;
//	while (node_current < median_count)
//	{
//		tmp = tmp->next;
//		node_current++;
//	}
//	stack->median = tmp->val;
//}
