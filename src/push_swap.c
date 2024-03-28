/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:09:38 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/01 16:18:48by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_rotate_median_push(t_stack *stack)
{
	if ((stack->b->chunk_order == 1 && stack->b->val <= stack->quarter)
		|| (stack->b->chunk_order > 1 && stack->b->val > stack->quarter))
		return (1);
	return (0);
}

void	push_till_median_first(t_stack *stack, t_node **stack_name, int chunk_order)
{
	t_node	*head;

	add_log(stack, newlog(stack, NULL, "push_till_median_first"), 0);
	set_operations(stack, *stack_name);
	find_median(stack, stack_name);
	find_quarter(stack, stack_name);
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
		if (check_rotate_median_push(stack) && stack->a != stack->target)
			do_rr(stack);
		else if (check_rotate_median_push(stack))
			do_rb(stack);
		//if (stack->b->val < stack->b->next->val)
		//	do_sb(stack);
	}
	while (chunk_order > 1 && stack->b->prev->chunk_order == chunk_order)
		do_rrb(stack);
}

void	push_swap(char **argv)
{
	t_stack	*stack;
	t_node	*node;
	int		total_count;
	int		chunk_order;

	stack = NULL;
	stack = start_stack(stack);
	input_stack(stack, &(stack->a), ++argv);
	if (stack->iserror)
	{
		write(1, "Error\n", 6);
		end_stack(stack);
		return ;
	}
	total_count = count_nodes(stack->a);
	//dupe_stack(stack, &(stack->a), &(stack->order));
	//current_stack_order(stack, &(stack->a));
	chunk_order = 0;
	while (count_nodes(stack->a) > 5)
	{
		push_till_median_first(stack, &(stack->a), ++chunk_order);
	}
	//while (count_nodes(stack->a) > 5)
	//{
	//	chunk_order++;
	//	// find_median(stack, &(stack->a));
	//	// printf("median val = %d\n", stack->median);
	//	//printf("count nodes = %d\n", count_nodes(stack->a));
	//	printf("order = %d\n", chunk_order);
	//	if (total_count <= 100)
	//	{
	//		push_till_median(stack, &(stack->a), chunk_order);
	//	}
	//	else
	//		push_till_median(stack, &(stack->a), chunk_order);
	//	//printf("b order = %d\n", stack->b->chunk_order);
	//}
	// printf("count nodes = %d\n", count_nodes(stack->a));
	sort_in_5(stack);
	//push_chunk_median(stack, &(stack->b), chunk_order);
	//sort_chunk(stack, chunk_order);
	//push_chunk_median(stack, &(stack->b), chunk_order);
	//sort_chunk(stack, chunk_order);
	//push_chunk_median(stack, &(stack->b), chunk_order);
	//sort_chunk(stack, chunk_order);
	//push_chunk_median(stack, &(stack->b), chunk_order);
	//sort_chunk(stack, chunk_order);
	//push_chunk_median(stack, &(stack->b), chunk_order);
	//sort_chunk(stack, chunk_order);
	//while (chunk_order > 0)
	//{
	//	push_chunk_median(stack, &(stack->b), chunk_order);
	//	chunk_order--;
	//}
	while (count_nodes(stack->b))
	{
		add_log(stack, newlog(stack, NULL, "push_min_max"), 0);
		push_min_max(stack, &(stack->b));
	}
	final_order(stack);
	print_log(stack->log);
	//logging(stack, stack->log);
	debug_ordered(stack);
	end_stack(stack);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	push_swap(argv);
}
