/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:19:21 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/06 14:11:23 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	find_target_min_max(t_data *data, t_node *head, int min, int max)
{
	t_node		*tmp;
	t_node		*tmp2;

	tmp = head;
	tmp2 = head->prev;
	data->target = NULL;
	while (tmp)
	{
		if (tmp->val == min || tmp->val == max)
			data->target = tmp;
		else if (tmp2->val == min || tmp2->val == max)
			data->target = tmp2;
		if (data->target != NULL)
			break ;
		tmp = tmp->next;
		tmp2 = tmp2->prev;
	}
}

void	set_target_min_max(t_data *data, int *min, int *max, int *near_head)
{
	*min = find_min(&(data->b));
	*max = find_max(&(data->b));
	find_target_min_max(data, data->b, *min, *max);
	*near_head = isnear_head(data->b, data->target);
}
