/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:34:04 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/18 18:09:57 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_median_push(t_stack *stack, t_node *stack_name, int median)
{
	t_node	*tmp;

	tmp = stack_name;
	while (tmp->next != stack_name)
	{
		tmp = tmp->next;
		if (tmp->val <= median)
		{
			stack->target = tmp;
			return (1);
		}
	}
	return (0);
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
