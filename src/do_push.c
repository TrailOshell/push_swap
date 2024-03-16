/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:29:37 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/16 19:09:29 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_push(t_stack *stack, char push_stack)
{
	t_node	**head_push;
	t_node	**head_pull;
	t_node	*tmp;

	if (push_stack == 'a')
	{
		head_push = &(stack->a);
		head_pull = &(stack->b);
	}
	else if (push_stack == 'b')
	{
		head_push = &(stack->b);
		head_pull = &(stack->a);
	}
	if (!*head_pull)
		return ;
	tmp = *head_pull;
	//	linking new stack pull
	if ((*head_pull)->next == *head_pull)
		*head_pull = NULL;
	else
	{
		*head_pull = (*head_pull)->next;
		(*head_pull)->prev = tmp->prev;
		tmp->prev->next = *head_pull;
		//printf("%s%d\n%s", PURPLE, (*head_pull)->val, RESET_C);
	}
	// linking new stack a
	//printf("%srun\n%s", YELLOW, RESET_C);
	//printf("%s%d\n%s", PURPLE, tmp->val, RESET_C);
	//printf("%s%d\n%s", PURPLE, (*head_push)->prev->next->val, RESET_C);
	tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	if (!*head_push)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		(*head_push)->prev->next = tmp;
		tmp->next = *head_push;
		tmp->prev = (*head_push)->prev;
		(*head_push)->prev = tmp;
	}
	*head_push = tmp;
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