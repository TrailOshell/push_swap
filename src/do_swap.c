/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:36:47 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/18 14:42:36 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_swap(t_node *node)
{
	int	tmp;

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
	add_log(stack, newlog(stack, "sa", NULL), 1);
}

void	do_sb(t_stack *stack)
{
	do_swap(stack->b);
	write(1, "sb\n", 3);
	add_log(stack, newlog(stack, "sb", NULL), 1);
}

void	do_ss(t_stack *stack)
{
	do_swap(stack->a);
	do_swap(stack->b);
	write(1, "ss\n", 3);
	add_log(stack, newlog(stack, "ss", NULL), 1);
}

	//if (node->val && node->next->val)
	//{
	//	tmp = node->next->val;
	//	node->next->val = node->val;
	//	node->val = tmp;
	//}

/*
void	do_swap(t_node *node)
{
	t_node	*swap1;
	t_node	*swap2;
	
	swap1 = node;
	swap2 = node->next;
	swap1->prev->next = swap2;
	swap2->next->prev = swap1;
	swap2->prev = swap1->prev;
	swap1->next = swap2->next;
	swap1->prev = swap2;
	swap2->next = swap1;
}
*/