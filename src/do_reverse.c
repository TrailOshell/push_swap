/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:06:17 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/29 18:16:47 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void do_reverse(t_node *node)
{
	t_node *head;
	int tmp1;
	int tmp2;

	if (!node->next)
		return ;
	head = node;
	tmp2 = node->val;
	node = node->next;
	while (node)
	{
		tmp1 = tmp2;
		tmp2 = node->val;
		node->val = tmp1;
		node = node->next;
	}
	head->val = tmp2;
}

void do_rra(t_stack *stack)
{
	do_reverse(stack->a);
	write(1, "rra\n", 4);
}

void do_rrb(t_stack *stack)
{
	do_reverse(stack->b);
	write(1, "rrb\n", 4);
}

void do_rrr(t_stack *stack)
{
	do_reverse(stack->a);
	do_reverse(stack->b);
	write(1, "rrr\n", 4);
}