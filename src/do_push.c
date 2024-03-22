/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:29:37 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/22 16:17:53y tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_head_push_pull(t_stack *s, char c, t_node ***push, t_node ***pull)
{
	if (c == 'a')
	{
		*push = &(s->a);
		*pull = &(s->b);
	}
	else if (c == 'b')
	{
		*push = &(s->b);
		*pull = &(s->a);
	}
}

void	do_push(t_stack *stack, char push_stack)
{
	t_node	**head_push;
	t_node	**head_pull;
	t_node	*push_node;

	set_head_push_pull(stack, push_stack, &head_push, &head_pull);
	if (!*head_pull)
		return ;
	push_node = *head_pull;
	node_new_head_pull(head_pull, &push_node);
	node_new_head_push(head_push, &push_node);
}

void	do_pa(t_stack *stack)
{
	do_push(stack, 'a');
	write(1, "pa\n", 3);
	add_log(stack, newlog(stack, "pa", NULL), 1);
}

void	do_pb(t_stack *stack)
{
	do_push(stack, 'b');
	write(1, "pb\n", 3);
	add_log(stack, newlog(stack, "pb", NULL), 1);
}

	/*
    t_node *head_a;
    t_node *head_b;
    
    //stack_a make new head
    head_a->val = stack->b->val;
	//stack_a connect new head to old head
    head_a->next = stack->a->next;

	//stack_b track new head
	head_b = stack->b->next;
	//stack_b remove old head
	dellst(stack->b);
	*/