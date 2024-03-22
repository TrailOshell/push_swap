/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_linking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:45 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/22 16:28:47 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	node_link_self(t_node *node)
{
	node->next = node;
	node->prev = node;
}

void	node_new_head_pull(t_node **head_pull, t_node **push_node)
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
}

void	node_new_head_push(t_node **head_push, t_node **push_node)
{
	if (!*head_push)
		node_link_self(*push_node);
	else
	{
		(*head_push)->prev->next = *push_node;
		(*push_node)->next = *head_push;
		(*push_node)->prev = (*head_push)->prev;
		(*head_push)->prev = *push_node;
	}
	*head_push = *push_node;
}
