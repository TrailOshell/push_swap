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

t_node	*current_stack_order(t_stack *stack, t_node **stack_name)
{
	t_node	*head;
	t_node	*min_node;
	t_node	*min_prev;
	t_node	*tmp;

	dupe_stack(stack, *stack_name, &(stack->order));
	min_prev = NULL;
	head = stack->order;
	while (head->next != stack->order)
	{
		min_node = head;
		tmp = head;
		while (tmp->next != head)
		{
			tmp = tmp->next;
			if (tmp->val < min_node->val
				&& (!min_prev || tmp->val > min_prev->val))
				min_node = tmp;
		}
		swap_nodes_value(&(min_node), &(head));
		min_prev = head;
		head = head->next;
	}
	return (stack->order);
}

void	push_till_median(t_stack *stack, t_node **stack_name, char stack_char)
{
	t_node	*head;

	set_operations(stack, *stack_name);
	find_median(stack, stack_name);
	do_double_op(stack);
	while (check_median_push(stack, *stack_name, stack->median))
	{
		// printf("target = %d\n", stack->target->val);
		head = *stack_name;
		if (stack->target == (*stack_name))
			stack->push(stack);
		else if (stack->target == (*stack_name)->next)
		{
			if (stack->b && stack->b->val < stack->b->next->val)
				do_ss(stack);
			else
				stack->swap(stack);
			stack->push(stack);
		}
		else if (isnear_head(stack, *stack_name, stack->target) == 1)
		{
			while (stack->target != head)
			{
				head = head->next;
				if (stack->b && stack->b->val < stack->b->prev->val)
					do_rr(stack);
				else
					stack->rotate(stack);
			}
			stack->push(stack);
		}
		else if (isnear_head(stack, *stack_name, stack->target) == 0)
		{
			while (stack->target != head)
			{
				head = head->prev;
				if (stack->b && stack->b->val > stack->b->prev->val)
					do_rrr(stack);
				else
					stack->reverse(stack);
			}
			stack->push(stack);
		}
		//do_double_op(stack);
		//printf("%d\n", check_median_push(stack, *stack_name, stack->median));
		//print_stack(stack);
	}
}

void	push_max(t_stack *stack, t_node **stack_name)
{
	t_node	*head;
	t_node	*max_node;

	set_operations(stack, *stack_name);
	max_node = *stack_name;
	head = *stack_name;
	while (head->next != *stack_name)
	{
		head = head->next;
		if (max_node->val < head->val)
			max_node = head;
	}
	head = *stack_name;
	//printf("%smax_node = %d\n%s", PURPLE, max_node->val, RESET_C);
	//printf("%sstack head = %d\n%s", PURPLE, (*stack_name)->val, RESET_C);
	//printf("%shead = %d\n%s", PURPLE, head->val, RESET_C);
	if (max_node == head)
		stack->push(stack);
	else if (max_node == (head)->next)
	{
		stack->swap(stack);
		stack->push(stack);
	}
	else if (isnear_head(stack, head, max_node) == 1)
	{
		while (max_node != head)
		{
			head = head->next;
			stack->rotate(stack);
		}
		stack->push(stack);
	}
	else if (isnear_head(stack, head, max_node) == 0)
	{
		while (max_node != head)
		{
			head = head->prev;
			stack->reverse(stack);
		}
		stack->push(stack);
	}
}

void	do_double_op(t_stack *stack)
{
	// printf("a = %d\n", count_nodes(stack->a));
	// printf("b = %d\n", count_nodes(stack->b));
	if ((!stack->a || !stack->b)
		|| (count_nodes(stack->a) <= 3 || count_nodes(stack->b) <= 3))
		return ;
	while (stack->a && stack->b)
	{
		if (stack->a->val > stack->a->next->val
			&& stack->b->val < stack->b->next->val)
			do_ss(stack);
		else if (stack->a->val > stack->a->prev->val
			&& stack->b->val < stack->b->prev->val)
			do_rrr(stack);
		else if (stack->a->val > stack->a->prev->val
			&& stack->b->val < stack->b->prev->val)
			do_rr(stack);
		else
			break ;
		//printf("%srun do_double_op()\n%s", GREEN, RESET_C);
		// print_stack(stack);
	}
	// print_stack(stack);
}