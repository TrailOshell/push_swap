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
		chunk_order++;
		// find_median(stack, &(stack->a));
		// printf("median val = %d\n", stack->median);
		//printf("count nodes = %d\n", count_nodes(stack->a));
		printf("order = %d\n", chunk_order);
		if (total_count <= 100)
		{
			add_log(stack, newlog(stack, NULL, "push_till_median"), 0);
			push_till_median(stack, &(stack->a), 'a', chunk_order);
		}
		else
			push_till_median(stack, &(stack->a), 'a', chunk_order);
		//printf("b order = %d\n", stack->b->chunk_order);
	}
	// printf("count nodes = %d\n", count_nodes(stack->a));
	add_log(stack, newlog(stack, NULL, "sort_in_5"), 0);
	sort_in_5(stack);
	//while (chunk_order > 0)
	//{
	//	push_chunk_median(stack, &(stack->b), 'b', chunk_order);
	//	chunk_order--;
	//}
	//print_log(stack->log);
	while (count_nodes(stack->b))
	{
		add_log(stack, newlog(stack, NULL, "push_min_max"), 0);
		push_min_max(stack, &(stack->b));
	}
	add_log(stack, newlog(stack, NULL, "final_order"), 0);
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
