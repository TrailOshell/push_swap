/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:05:50 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/06 14:17:04 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//currently not using t_stack *stack
void	add_node_last(t_node **stack, t_node *add)
{
	t_node	**head;
	t_node	*tmp;

	head = stack;
	if (!*head)
	{
		*head = add;
		tmp = add;
	}
	else
	{
		head = stack;
		tmp = (*head)->prev;
		tmp->next = add;
		(*head)->prev = add;
	}
	add->next = *head;
	add->prev = tmp;
}

t_node	*nodenew(int num, int chunk_order)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->val = num;
	new->next = NULL;
	new->prev = NULL;
	new->chunk_order = chunk_order;
	return (new);
}

void	nodedel(t_node **node)
{
	t_node	*tmp;
	t_node	*last;

	tmp = *node;
	last = (*node)->prev;
	if ((*node)->next == *node)
	{
		free(*node);
		*node = NULL;
	}
	else
	{
		*node = (*node)->next;
		last->next = *node;
		(*node)->prev = last;
		free(tmp);
		tmp = NULL;
	}
}

void	swap_nodes_value(t_node **node_1, t_node **node_2)
{
	int		tmp_val;

	tmp_val = (*node_1)->val;
	(*node_1)->val = (*node_2)->val;
	(*node_2)->val = tmp_val;
}

int	count_nodes(t_node *node)
{
	t_node	*tmp;
	int		count;	

	tmp = node;
	if (!tmp)
		return (0);
	count = 1;
	while (tmp->next != node)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
