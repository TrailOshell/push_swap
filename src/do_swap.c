/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:36:47 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/04 17:56:03 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_swap(t_node *node)
{
	int		tmp;

	if (node->next == node)
		return ;
	tmp = node->next->val;
	node->next->val = node->val;
	node->val = tmp;
}

void	do_sa(t_stack *stack)
{
	do_swap(stack->a);
	write(1, "sa\n", 3);
}

void	do_sb(t_stack *stack)
{
	do_swap(stack->b);
	write(1, "sb\n", 3);
}

void	do_ss(t_stack *stack)
{
	do_swap(stack->a);
	do_swap(stack->b);
	write(1, "ss\n", 3);
}

	//if (node->val && node->next->val)
	//{
	//	tmp = node->next->val;
	//	node->next->val = node->val;
	//	node->val = tmp;
	//}