/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:06:17 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/18 14:41:49 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_reverse(t_node **node)
{
	*node = (*node)->prev;
}

void	do_rra(t_stack *stack)
{
	do_reverse(&stack->a);
	write(1, "rra\n", 4);
	add_log(stack, newlog(stack, "rra", NULL), 1);
}

void	do_rrb(t_stack *stack)
{
	do_reverse(&stack->b);
	write(1, "rrb\n", 4);
	add_log(stack, newlog(stack, "rrb", NULL), 1);
}

void	do_rrr(t_stack *stack)
{
	do_reverse(&stack->a);
	do_reverse(&stack->b);
	write(1, "rrr\n", 4);
	add_log(stack, newlog(stack, "rrr", NULL), 1);
}

/*
void	do_reverse(t_node **node)
{
	*node = (*node)->prev;
	t_node	*tmp;
	t_node	*first;
	t_node	*last;

	tmp = *node;
	last = *node;
	while (last->next->next)
		last = last->next;
	first = last->next;
	*node = first;
	first->next = tmp;
	last->next = NULL;
}
*/
/*
// void	do_reverse(t_node *node)
// {
// 	t_node	*head;
// 	int		tmp1;
// 	int		tmp2;
// 
// 	if (!node->next)
// 		return ;
// 	head = node;
// 	tmp2 = node->val;
// 	node = node->next;
// 	while (node)
// 	{
// 		tmp1 = tmp2;
// 		tmp2 = node->val;
// 		node->val = tmp1;
// 		node = node->next;
// 	}
// 	head->val = tmp2;
// }
*/