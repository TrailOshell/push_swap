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

void	push_till_median(t_stack *stack, t_node **stack_name, int chunk_order)
{
	t_node	*head;

	add_log(stack, newlog(stack, NULL, "push_till_median"), 0);
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

void	push_chunk_median(t_stack *stack, t_node **stack_name, int chunk_n)
{
	t_node	*chunk;
	t_node	*head;

	chunk = NULL;
	dupe_chunk(stack, &(stack->b), &chunk, chunk_n);
	find_median(stack, &chunk);
	printf("chunk = %d ", chunk_n);
	print_node(chunk, "");
	printf("median = %d\n", stack->median);
	set_operations(stack, *stack_name);
	add_log(stack, newlog(stack, NULL, "pushing_chunk"), 0);
	head = *stack_name;
	print_node(stack->b, "stack b");
	while ((*stack_name)->chunk_order == chunk_n)
	{
		if ((*stack_name)->val > stack->median && (*stack_name)->chunk_order == chunk_n)
		{
			add_log(stack, newlog(stack, NULL, "push"), 0);
			stack->push(stack);
		}
		//else if ((*stack_name)->chunk != chunk || count_nodes(*stack_name) <= 5)
		else
			stack->rotate(stack);
		if (*stack_name == head)
			break ;
		//print_stack(stack);
	}
	print_node(stack->a, "stack a");
	print_node(stack->b, "stack b");
}

void	find_target_chunk_sort(t_stack *stack, t_node *node, int chunk)
{
	t_node	*head;

	head = node;
	stack->target = NULL;
	while (node)
	{
		if (node->val > node->next->val)
			stack->target = node;
		if (node == head)
			break ;
	}
}

void	check_chunk_sort(t_stack *stack, t_node *node, int chunk)
{

}

void	sort_chunk(t_stack *stack, int chunk_n)
{
	find_target_chunk_sort(stack, stack->a, chunk_n);
	printf("%starget = %d\n%s", CYAN, stack->target->val, RESET_C);
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

	add_log(stack, newlog(stack, NULL, "final_order"), 0);
	min = find_min(stack, &(stack->a));
	while (stack->a->val != min)
		do_rra(stack);
}
