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
	//int		total_count;
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
	//total_count = count_nodes(stack->a);
	chunk_order = 0;
	while (count_nodes(stack->a) > 5)
	{
		if (count_nodes(stack->a) <= 100)
			push_till_median(stack, &(stack->a), ++chunk_order);
		else
			push_till_quarter(stack, &(stack->a), ++chunk_order);
	}
	sort_in_5(stack);
	while (count_nodes(stack->b))
		push_min_max(stack, &(stack->b));
	final_order(stack);
	print_log(stack->log); debug_ordered(stack);
	//print_stack(stack);
	end_stack(stack);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	push_swap(argv);
}
