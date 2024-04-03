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

void	set_head_push_pull(t_data *d, char s, t_node ***push, t_node ***pull)
{
	if (s == 'a')
	{
		*push = &(d->a);
		*pull = &(d->b);
	}
	else if (s == 'b')
	{
		*push = &(d->b);
		*pull = &(d->a);
	}
}

void	do_push(t_data *data, char stack)
{
	t_node	**head_push;
	t_node	**head_pull;
	t_node	*push_node;

	set_head_push_pull(data, stack, &head_push, &head_pull);
	if (!*head_pull)
		return ;
	push_node = *head_pull;
	node_new_head_pull(head_pull, &push_node);
	node_new_head_push(head_push, &push_node);
}

void	do_pa(t_data *data)
{
	do_push(data, 'a');
	write(1, "pa\n", 3);
	add_log(data, newlog(data, "pa", NULL), 1);
}

void	do_pb(t_data *data)
{
	do_push(data, 'b');
	write(1, "pb\n", 3);
	add_log(data, newlog(data, "pb", NULL), 1);
}

/*
    t_node *head_a;
    t_node *head_b
	/*
    t_node *head_a;
    t_node *head_b;
    
    //stack_a make new head
    head_a->val = data->b->val;
	//stack_a connect new head to old head
    head_a->next = data->a->next;

	//stack_b track new head
	head_b = data->b->next;
	//stack_b remove old head
	dellst(data->b);
    
    //stack_a make new head
    head_a->val = data->b->val;
	//stack_a connect new head to old head
    head_a->next = data->a->next;

	//stack_b track new head
	head_b = data->b->next;
	//stack_b remove old head
	dellst(data->b);
*/