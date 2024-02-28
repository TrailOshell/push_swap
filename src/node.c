/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:05:50 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/28 20:24:24 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	add_node_last(t_node **stack_node, t_node *add)
{
	t_node	*tmp;

	tmp = *stack_node;
	if (!*stack_node)
	{
		*stack_node = add;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add;
}

t_node	*nodenew(int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->val = num;
	new->next = NULL;
	return (new);
}

/* nodenew()
	//printf("nodenew %d\n", new->val);
*/
