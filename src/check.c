/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:34:04 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/28 19:45:53 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_rotate_median_push(t_stack *stack)
{
	if (stack->b->chunk_order == 1 && stack->b->val <= stack->quarter)
		return (1);
	//else if (stack->b->chunk_order > 1 && stack->b->val <= stack->quarter)
	else if (stack->b->chunk_order > 1 && stack->b->val > stack->quarter)
		return (1);
	return (0);
}

int	check_rotate_quarter_push(t_stack *stack)
{
	if (stack->b->chunk_order == 1 && stack->b->val <= stack->half_quarter)
		return (1);
	//else if (stack->b->chunk_order > 1 && stack->b->val > stack->half_quarter)
	else if (stack->b->chunk_order > 1 && stack->b->val <= stack->half_quarter)
		return (1);
	return (0);
}

int	check_median_push(t_stack *stack, t_node *stack_name, int median)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*head;
	int		index;

	tmp = stack_name;
	tmp2 = stack_name->prev;
	head = stack_name;
	index = 0;
	while (tmp != tmp2)
	{
		if (tmp->val <= median)
		{
			stack->target = tmp;
			return (1);
		}
		tmp = tmp->next;
		tmp2 = tmp2->prev;
		index++;
		if (tmp == head)
			break ;
	}
	stack->target = NULL;
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

int	isnear_head(t_stack *stack, t_node *stack_name, t_node *node)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		count;

	count = 0;
	tmp = stack_name;
	tmp2 = stack_name->prev;
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
