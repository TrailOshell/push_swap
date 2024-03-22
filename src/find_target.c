/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:19:21 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/22 15:29:04 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	find_target_min_max(t_stack *stack, t_node *head, int min, int max)
{
	t_node		*tmp;
	t_node		*tmp2;

	tmp = head;
	tmp2 = head->prev;
	stack->target = NULL;
	while (tmp)
	{
		if (tmp->val == min || tmp->val == max)
			stack->target = tmp;
		else if (tmp2->val == min || tmp2->val == max)
			stack->target = tmp2;
		if (stack->target != NULL)
			break ;
		tmp = tmp->next;
		tmp2 = tmp2->prev;
	}
}
