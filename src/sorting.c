/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:13:04 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/06 14:55:19by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_till_median(t_data *data, t_node **stack, int chunk_order)
{
	print_stack(data);
	add_log(data, newlog(data, NULL, "push_till_median_first"), 0);
	set_operations(data, *stack);
	find_median(data, stack);
	find_quarter(data, stack);
	printf("\n%smedian = %d%s\n", GREEN, data->median, RESET_C);
	check_median_push(data, *stack, data->median);
	while (data->target)
	{
		do_condition_then_push(data, stack, chunk_order);
		check_median_push(data, *stack, data->median);
		if (check_rotate_median_push(data) && data->a != data->target)
			do_rr(data);
		else if (check_rotate_median_push(data))
			do_rb(data);
	}
	//print_stack(data);
}

void	push_till_quarter(t_data *data, t_node **stack, int chunk_order)
{
	print_stack(data);
	add_log(data, newlog(data, NULL, "push_till_quarter"), 0);
	set_operations(data, *stack);
	find_quarter(data, stack);
	find_half_quarter(data, stack);
	printf("\n%squarter = %d%s\n", GREEN, data->quarter, RESET_C);
	check_median_push(data, *stack, data->quarter);
	while (data->target)
	{
		do_condition_then_push(data, stack, chunk_order);
		check_median_push(data, *stack, data->quarter);
		if (check_rotate_quarter_push(data) && data->a != data->target)
			do_rr(data);
		else if (check_rotate_quarter_push(data))
			do_rb(data);
	}
}

void	push_min_max(t_data *data, t_node **stack)
{
	int	min;
	int	max;
	int	near_head;

	//add_log(data, newlog(data, NULL, "push_min_max"), 0);
	set_operations(data, *stack);
	min = 0;
	max = 0;
	near_head = 0;
	set_target_min_max(data, &min, &max, &near_head);
	if (near_head == 1)
	{
		add_log(data, newlog(data, NULL, "push_min_max do_r"), 0);
		do_r_till_target_push(data, *stack);
	}
	else if (near_head == 0)
	{
		add_log(data, newlog(data, NULL, "push_min_max do_rr"), 0);
		do_rr_till_target_push(data, *stack);
	}
	if (data->target->val == min)
	{
		if (*stack)
			set_target_min_max(data, &min, &max, &near_head);
		if (near_head == 1 && data->b != data->target)
			do_rr(data);
		else
			do_ra(data);
	}
}
