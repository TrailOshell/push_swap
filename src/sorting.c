/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:13:04 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/09 16:53:47y tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_till_median(t_stack *stack, t_node **stack_name, char stack_char
			, int chunk_order)
{
	t_node	*head;

	set_operations(stack, *stack_name);
	find_median(stack, stack_name);
	check_median_push(stack, *stack_name, stack->median);
	while (stack->target)
	{
		add_log(stack, newlog(stack, NULL, "pushing"), 0);
		head = *stack_name;
		if (stack->target == (*stack_name))
			stack->push(stack);
		else if (stack->target == (*stack_name)->next)
			do_swap_push(stack);
		else if (isnear_head(stack, *stack_name, stack->target) == 1)
			do_r_till_target_push(stack, head);
		else if (isnear_head(stack, *stack_name, stack->target) == 0)
			do_rr_till_target_push(stack, head);
		stack->b->chunk_order = chunk_order;
		check_median_push(stack, *stack_name, stack->median);
	}
}

void	push_chunk_median(t_stack *stack, t_node **stack_name, int chunk_order)
{
	t_node	*chunk;
	t_node	*head;

	chunk = NULL;
	//print_log(stack->log);
	//print_stack(stack);
	//dupe_chunk(stack, &(stack->b), &chunk, stack->b->chunk_order);
	dupe_chunk(stack, &(stack->b), &chunk, chunk_order);
	//dupe_stack(stack, &(stack->b), &chunk);
	find_median(stack, &chunk);
	print_node(chunk, "chunk_order");
	printf("= %d\n", chunk_order);
	printf("median = %d\n", stack->median);
	set_operations(stack, *stack_name);
	add_log(stack, newlog(stack, NULL, "pushing_chunk"), 0);
	head = *stack_name;
	while (*stack_name)
	{
		if ((*stack_name)->val < stack->median)
			stack->push(stack);
		else if ((*stack_name)->chunk_order != chunk_order
			|| (*stack_name) == head || count_nodes(*stack_name) <= 5)
			break ;
		else
			stack->rotate(stack);
		print_stack(stack);
	}
}

void	push_min_max(t_stack *stack, t_node **stack_name)
{
	int	min;
	int	max;
	int	near_head;

	set_operations(stack, *stack_name);
	min = find_min(stack, stack_name);
	max = find_max(stack, stack_name);
	find_target_min_max(stack, *stack_name, min, max);
	near_head = isnear_head(stack, *stack_name, stack->target);
	if (near_head == 1)
		do_r_till_target_push(stack, *stack_name);
	else if (near_head == 0)
		do_rr_till_target_push(stack, *stack_name);
	if (stack->target->val == min)
		do_ra(stack);
}

void	final_order(t_stack *stack)
{
	int	min;

	min = find_min(stack, &(stack->a));
	while (stack->a->val != min)
		do_rra(stack);
}
