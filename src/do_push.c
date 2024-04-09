/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:29:37 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/09 12:59:15 by tsomchan         ###   ########.fr       */
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

void	new_head_push_pull(t_node **head_push,
			t_node **head_pull, t_node **push_node)
{
	if ((*head_pull)->next == *head_pull)
		*head_pull = NULL;
	else
	{
		*head_pull = (*head_pull)->next;
		(*head_pull)->prev = (*push_node)->prev;
		(*push_node)->prev->next = *head_pull;
		(*push_node)->next->prev = (*push_node)->prev;
		(*push_node)->prev->next = (*push_node)->next;
	}
	if (!*head_push)
	{
		(*push_node)->next = *push_node;
		(*push_node)->prev = *push_node;
	}
	else
	{
		(*head_push)->prev->next = *push_node;
		(*push_node)->next = *head_push;
		(*push_node)->prev = (*head_push)->prev;
		(*head_push)->prev = *push_node;
	}
	*head_push = *push_node;
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
	new_head_push_pull(head_push, head_pull, &push_node);
}

void	do_pa(t_data *data)
{
	do_push(data, 'a');
	write(1, "pa\n", 3);
}

void	do_pb(t_data *data)
{
	do_push(data, 'b');
	write(1, "pb\n", 3);
}
