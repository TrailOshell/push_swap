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

	stack = NULL;
	stack = start_stack(stack);
	input_stack(stack, &(stack->a), ++argv);
	if (stack->iserror)
	{
		write(1, "Error\n", 6);
		end_stack(stack);
		return ;
	}
	current_stack_order(stack, &(stack->a));
	while (count_nodes(stack->a) > 5)
	{
		find_median(stack, &(stack->a));
		add_log(stack, newlog(stack, NULL, "push_till_median"), 0);
		//printf("median val = %d\n", stack->median);
		push_till_median(stack, &(stack->a), 'a');
		//printf("count nodes = %d\n", count_nodes(stack->a));
	}
	add_log(stack, newlog(stack, NULL, "sort_in_5"), 0);
	sort_in_5(stack);
	//sort_3_ascend(stack, &(stack->a));
	//sort_3_descend(stack, &(stack->b));
	while (count_nodes(stack->b))
	{
		add_log(stack, newlog(stack, NULL, "push_max"), 0);
		push_max(stack, &(stack->b));
		// print_stack(stack);
	}
	//print_node_connect(stack->median, "median_node");
	print_log(stack->log);
	debug_ordered(stack);
	end_stack(stack);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	push_swap(argv);
}

/*
void	push_swap(char **argv)
{
	t_stack	*stack;
	t_node	*node;

	stack = NULL;
	stack = start_stack(stack);
	input_stack(stack, &(stack->a), ++argv);
	//add_log(stack, newlog(stack, "new", " "));
	//print_node(stack->a, "print a");
	//printf("stack->a->next = %d", stack->a->next->val);
	if (!stack->iserror)
	{
		//debug_operations(stack);
		//debug_operations_1_node(stack);
		//debug_push_empty_a(stack);
		//debug_push_empty_b(stack);
		//debug_push_1_a(stack);
	}
	else
		write(1, "Error\n", 7);
	current_stack_order(stack, &(stack->a));
	//set_color(YELLOW);
	//print_node(stack->order, "print order");
	//set_color(RESET_C);
	//printf("count nodes = %d\n", count_nodes(stack->a));
	while (count_nodes(stack->a) > 3)
	{
		find_median(stack, &(stack->a));
		//printf("%srun push_till_median\n%s", YELLOW, RESET_C);
		//printf("median val = %d\n", stack->median);
		push_till_median(stack, &(stack->a), 'a');
		//printf("count nodes = %d\n", count_nodes(stack->a));
	}
	//printf("stack a val = %d\n", stack->a->val);
	//print_stack(stack);
	//printf("%srun sort_3_ascend\n%s", YELLOW, RESET_C);
	sort_3_ascend(stack, &(stack->a));
	//print_stack(stack);
	//sort_3_descend(stack, &(stack->b));
	//print_stack(stack);
	//while (stack->b)
	//while (count_nodes(stack->b) > 90)
	while (count_nodes(stack->b))
	{
		// printf("%srun push_max\n%s", YELLOW, RESET_C);
		push_max(stack, &(stack->b));
		// print_stack(stack);
	}
	//print_node_connect(stack->median, "median_node");
	print_log(stack->log);
	//free_log(stack->log);
	end_stack(stack);
}
*/