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

int	find_max_in_chunk(t_node **stack, int chunk_order)
{
	t_node	*max_node;
	t_node	*head;

	if ((*stack)->chunk_order == chunk_order)
		max_node = *stack;
	else
		max_node = (*stack)->prev;
	head = *stack;
	while (head->next != *stack)
	{
		head = head->next;
		if (max_node->val < head->val && head->chunk_order == chunk_order)
			max_node = head;
	}
	return (max_node->val);
}

int	find_min_in_chunk(t_node **stack, int chunk_order)
{
	t_node	*min_node;
	t_node	*head;

	if ((*stack)->chunk_order == chunk_order)
		min_node = *stack;
	else
		min_node = (*stack)->prev;
	head = *stack;
	while (head->next != *stack)
	{
		head = head->next;
		if (min_node->val > head->val && head->chunk_order == chunk_order)
			min_node = head;
	}
	return (min_node->val);
}

void	set_target_min_max_chunk(t_data *data, int *ismin, int *near_head, int chunk_order)
{
	int	min;
	int	max;

	min = find_min_in_chunk(&(data->b), chunk_order);
	max = find_max_in_chunk(&(data->b), chunk_order);
	find_target_min_max(data, data->b, min, max);
	*ismin = 0;
	if (data->target->val == min)
		*ismin = 1;
	*near_head = isnear_head(data->b, data->target);
}

int	check_has_chunk(t_node *stack, int chunk_order)
{
	t_node	*tmp;
	t_node	*head;

	head = stack;
	tmp = stack;
	while (tmp)
	{
		if (tmp->chunk_order == chunk_order)
			return (1);
		tmp = tmp->next;
		if (tmp == head)
			break ;
	}
	return (0);
}

void	push_min_max_chunk(t_data *data, int chunk_order)
{
	int	ismin;
	int	near_head;

	//add_log(data, newlog(data, NULL, "push_min_max"), 0);
	set_operations(data, data->b);
	while (check_has_chunk(data->b, chunk_order) == 1)
	{
		ismin = 0;
		near_head = 0;
		set_target_min_max_chunk(data, &ismin, &near_head, chunk_order);
		if (near_head == 1)
			do_r_till_target_push(data, data->b);
		else if (near_head == 0)
			do_rr_till_target_push(data, data->b);
		if (ismin == 1)
		{
			if (data->b)
				set_target_min_max_chunk(data, &ismin, &near_head, chunk_order);
			if (near_head == 1 && data->b != data->target)
				do_rr(data);
			else
				do_ra(data);
		}
		print_stack(data);
	}
	if (chunk_order - 1 > 0)
		set_target_min_max_chunk(data, &ismin, &near_head, (chunk_order - 1));
	while (check_ordered(data->a) == 0)
	{
		if (data->b && near_head == 0 && data->target != data->b)
			do_rrr(data);
		else
			do_rra(data);
	}
	print_stack(data);
}

void	push_ten_percent(t_data *data, t_node **stack, int chunk_order)
{
	print_stack(data);
	add_log(data, newlog(data, NULL, "push_ten_percent"), 0);
	set_operations(data, *stack);
	//find_ten_percent(data, stack);
	//check_median_push(data, *stack, data->median);
	while (data->target)
	{
		do_condition_then_push(data, stack, chunk_order);
		//check_median_push(data, *stack, data->median);
		//if (check_rotate_median_push(data) && data->a != data->target)
			//do_rr(data);
		//else if (check_rotate_median_push(data))
			//do_rb(data);
	}
	//print_stack(data);
}