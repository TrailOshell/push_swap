/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:13:04 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/09 14:35:36 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_till_median(t_data *data, int chunk_order)
{
	set_operations(data, data->a);
	find_median(data, data->a);
	find_quarter(data, data->a);
	check_median_push(data, data->a, data->median);
	while (data->target)
	{
		do_condition_then_push(data, data->a, chunk_order);
		check_median_push(data, data->a, data->median);
		if (check_rotate_median_push(data) && data->a != data->target)
			do_rr(data);
		else if (check_rotate_median_push(data))
			do_rb(data);
	}
}

void	push_till_quarter(t_data *data, int chunk_order)
{
	set_operations(data, data->a);
	find_quarter(data, data->a);
	find_half_quarter(data, data->a);
	check_median_push(data, data->a, data->quarter);
	while (data->target)
	{
		do_condition_then_push(data, data->a, chunk_order);
		check_median_push(data, data->a, data->quarter);
		if (check_rotate_quarter_push(data) && data->a != data->target)
			do_rr(data);
		else if (check_rotate_quarter_push(data) == 1)
			do_rb(data);
	}
}

void	push_min_max(t_data *data, int *ismin, int *near_head, int chunk_order)
{
	set_target_chunk(data, ismin, near_head, chunk_order);
	if (*near_head == 1)
		do_r_till_target_push(data, data->b);
	else if (*near_head == 0)
		do_rr_till_target_push(data, data->b);
	if (*ismin == 1)
	{
		if (data->b)
			set_target_chunk(data, ismin, near_head, chunk_order);
		if (*near_head == 1 && data->b != data->target)
			do_rr(data);
		else
			do_ra(data);
	}
}

void	push_min_max_chunk(t_data *data, int chunk_order)
{
	int	ismin;
	int	near_head;

	ismin = 0;
	near_head = 0;
	set_operations(data, data->b);
	while (check_has_chunk(data->b, chunk_order) == 1)
		push_min_max(data, &ismin, &near_head, chunk_order);
	if (chunk_order > 1)
		set_target_chunk(data, &ismin, &near_head, (chunk_order - 1));
	while (check_ordered(data->a) == 0)
	{
		if (data->b && near_head == 0 && data->target != data->b)
			do_rrr(data);
		else
			do_rra(data);
	}
}

void	final_ordering(t_data *data)
{
	int	min;

	min = find_min(data->a);
	while (data->a->val != min)
		do_rra(data);
}
