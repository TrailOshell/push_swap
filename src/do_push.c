/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:29:37 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/29 17:30:19 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_push(t_stack *stack, char push_stack)
{
	t_node	**head_push;
	t_node	**head_pull;
	t_node 	*tmp;

	if (push_stack == 'a')
	{
		head_push = &(stack->a);
		head_pull = &(stack->b);
	}
	else
	{
		head_push = &(stack->b);
		head_pull = &(stack->a);
	}
	tmp = *head_pull;
	*head_pull = (*head_pull)->next;
	tmp->next = *head_push;
	*head_push = tmp;
}

void	do_pa (t_stack *stack)
{
	do_push(stack, 'a');
	write(1, "pa\n", 3);
}

void	do_pb (t_stack *stack)
{
	do_push(stack, 'b');
	write(1, "pb\n", 3);
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