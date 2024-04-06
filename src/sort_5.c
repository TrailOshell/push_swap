/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:23:03 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/06 14:11:56 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_2(t_data *data)
{
	if (data->a->val > (data->a->next->val))
		do_sa(data);
}

void	sort_3(t_data *data)
{
	int	max;

	max = find_max(&(data->a));
	if (data->a->val == max)
		data->rotate(data);
	else if (data->a->next->val == max)
		data->reverse(data);
	sort_2(data);
}

void	sort_4(t_data *data)
{
	int	min;

	min = find_min(&(data->a));
	while (data->a->val != min)
	{
		do_ra(data);
		data->a = data->a->next;
	}
	do_pb(data);
	sort_3(data);
	do_pa(data);
}

void	sort_5(t_data *data)
{
	int	count;

	count = 5;
	find_median(data, &(data->a));
	while (count > 3)
	{
		if (data->a->val < data->median)
		{
			do_pb(data);
			count--;
		}
		else
			do_ra(data);
	}
	sort_3(data);
	if (data->b->val < (data->b->next->val))
		do_sb(data);
	do_pa(data);
	do_pa(data);
}

void	sort_in_5(t_data *data)
{
	int	count;

	add_log(data, newlog(data, NULL, "sort_in_5"), 0);
	count = count_nodes(data->a);
	if (count == 2)
		sort_2(data);
	else if (count == 3)
		sort_3(data);
	else if (count == 4)
		sort_4(data);
	else if (count == 5)
		sort_5(data);
}
