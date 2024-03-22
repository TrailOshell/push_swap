/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:34:04 by tsomchan          #+#    #+#             */ /*   Updated: 2024/03/19 06:38:00 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_median_push(t_stack *stack, t_node *stack_name, int median)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*head;

	tmp = stack_name;
	tmp2 = stack_name->prev;
	head = stack_name;
	while (tmp != tmp2)
	{
		// printf("tmp %d, tmp2 %d\n", tmp->val, tmp2->val);
		// if (stack->b)
		// 	print_stack(stack);
		if (tmp->val <= median)
		{
			stack->target = tmp;
			return (1);
		}
		// else if (tmp2->val <= median)
		// {
		// 	stack->target = tmp2;
		// 	return (1);
		// }
		tmp = tmp->next;
		tmp2 = tmp2->prev;
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
