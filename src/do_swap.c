/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:36:47 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/28 21:48:53 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_sa(t_stack *stack)
{
	t_node	*node;
	int		tmp;

	node = stack->a;
	if (node->val && node->next->val)
	{
		tmp = node->next->val;
		node->next->val = node->val;
		node->val = tmp;
	}
	write(1, "sa\n", 3);
}

void	do_sb(t_stack *stack)
{
	t_node	*node;
	int		tmp;

	node = stack->b;
	if (node->val && node->next->val)
	{
		tmp = node->next->val;
		node->next->val = node->val;
		node->val = tmp;
	}
	write(1, "sb\n", 3);
}

void	do_ss(t_stack *stack)
{
	t_node	*node;
	int		tmp;

	node = stack->a;
	if (node->val && node->next->val)
	{
		tmp = node->next->val;
		node->next->val = node->val;
		node->val = tmp;
	}
	node = stack->b;
	if (node->val && node->next->val)
	{
		tmp = node->next->val;
		node->next->val = node->val;
		node->val = tmp;
	}
	write(1, "ss\n", 3);
}
