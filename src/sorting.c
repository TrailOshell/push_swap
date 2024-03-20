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
		// printf("target = %d\n", stack->target->val);
		head = *stack_name;
		if (stack->target == (*stack_name))
			stack->push(stack);
		else if (stack->target == (*stack_name)->next)
		{
			stack->swap(stack);
			stack->push(stack);
		}
		else if (isnear_head(stack, *stack_name, stack->target) == 1)
		{
			while (stack->target != head)
			{
				head = head->next;
				stack->rotate(stack);
			}
			stack->push(stack);
		}
		else if (isnear_head(stack, *stack_name, stack->target) == 0)
		{
			while (stack->target != head)
			{
				head = head->prev;
				stack->reverse(stack);
			}
			stack->push(stack);
		}
		stack->b->chunk_order = chunk_order;
		// add_log(stack, newlog(stack, NULL, "slight sorted stack b"), 0);
		check_median_push(stack, *stack_name, stack->median);
		// printf("%d\n", check_median_push(stack, *stack_name, stack->median));
		//print_stack(stack);
	}
}

void	push_min_max(t_stack *stack, t_node **stack_name)
{
	int			min;
	int			max;
	t_node		*tmp;
	t_node		*tmp2;
	void		(*do_op)(t_stack *);
	int			target;

	min = find_min(stack, stack_name);
	max = find_max(stack, stack_name);
	tmp = *stack_name;
	tmp2 = (*stack_name)->prev;
	while (tmp)
	{
		if (tmp->val == min || tmp->val == max)
		{
			target = tmp->val;
			do_op = do_rb;
			break ;
		}
		else if (tmp2->val == min || tmp2->val == max)
		{
			target = tmp2->val;
			do_op = do_rrb;
			break ;
		}
		tmp = tmp->next;
		tmp2 = tmp2->prev;
	}
	while (stack->b->val != target)
		do_op(stack);
	do_pa(stack);
	if (target == min)
		do_ra(stack);
}

void	final_order(t_stack *stack)
{
	int	min;

	min = find_min(stack, &(stack->a));
	while (stack->a->val != min)
		do_rra(stack);
}

/*
void	do_double_op(t_stack *stack)
{
	// printf("a = %d\n", count_nodes(stack->a));
	// printf("b = %d\n", count_nodes(stack->b));
	if ((!stack->a || !stack->b)
		|| (count_nodes(stack->a) <= 5 || count_nodes(stack->b) <= 5))
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
*/

/*
void	push_till_median(t_stack *stack, t_node **stack_name, char stack_char)
{
	t_node *last;

	set_operations(stack, *stack_name);
	find_median(stack, stack_name);
	check_median_push(stack, *stack_name, stack->median);
	last = (*stack_name)->prev;
	while (stack->target)
	{
		add_log(stack, newlog(stack, NULL, "pushing"), 0);
		// printf("target = %d\n", stack->target->val);
		if ((*stack_name)->val <= stack->target->val)
			stack->push(stack);
		else if (count_nodes(*stack_name) <= 5 || *stack_name == last)
			break ;
		else
		{
			printf("run\n");
			stack->rotate(stack);
		}
		// add_log(stack, newlog(stack, NULL, "slight sorted stack b"), 0);
		check_median_push(stack, *stack_name, stack->median);
		last = (*stack_name)->prev;
		// printf("%d\n", check_median_push(stack, *stack_name, stack->median));
		// print_stack(stack);
	}
}
*/