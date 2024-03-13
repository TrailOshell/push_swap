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

void	find_median(t_stack *stack, t_node **stack_name)
{
	t_node	*tmp;
	int		node_count;
	int		median_count;
	int		node_current;
	int		median;

	node_count = count_nodes(*stack_name);
	current_stack_order(stack, stack_name);
	median_count = (node_count / 2) + (node_count % 2);
	node_current = 1;
	tmp = stack->order;
	while (node_current < median_count)
	{
		tmp = tmp->next;
		node_current++;
	}
	stack->median = tmp->val;
}

int	check_median_push(t_stack *stack, t_node *stack_name, int median) {
	t_node	*tmp;

	tmp = stack_name;
	//while (tmp->next != stack_name)
	while (tmp)
	{
		if (tmp->val <= median)
		{
			stack->target = tmp;
			return (1);
		}
		tmp = tmp->next;
		if (tmp == stack_name)
			break ;
	}
	return (0);
}

int	isnear_head(t_stack *stack, t_node *stack_name, t_node *node)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		count;

	count = 0;
	tmp = stack_name;
	tmp2 = stack_name->prev;
	while (tmp != tmp2)
	{
		if (tmp->val == node->val)
			return (1);
		else if (tmp2->val == node->val)
			return (0);
		tmp = tmp->next;
		tmp2 = tmp2->prev;
	}
	return (1);

	//while (tmp)
	//{
	//	if (tmp->val == node->val)
	//		break ;
	//	count++;
	//	tmp = tmp->next;
	//	if (tmp == stack_name)
	//		break ;
	//}
	//if (count <= (count_nodes(stack_name) / 2))
	//	return (1);
	//return (0);
}

void	set_operations(t_stack *stack, t_node *stack_name)
{
	if (stack_name == stack->a)
	{
		stack->swap = &(do_sa);
		stack->rotate = &(do_ra);
		stack->reverse = &(do_rra);
		stack->push = &(do_pb);
	}
	else if (stack_name == stack->b)
	{
		stack->swap = &(do_sb);
		stack->rotate = &(do_rb);
		stack->reverse = &(do_rrb);
		stack->push = &(do_pa);
	}
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
				do_double_op(stack);
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
				do_double_op(stack);
			}
			stack->push(stack);
		}
		do_double_op(stack);
		//printf("%d\n", check_median_push(stack, *stack_name, stack->median));
		print_stack(stack);
	}
}


void	sort_3_ascend(t_stack *stack, t_node **stack_name)
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
	if (max_node == *stack_name)
		stack->rotate(stack);
	else if (max_node == (*stack_name)->next)
		stack->reverse(stack);
	*stack_name = max_node->next;
	if ((*stack_name)->val > (*stack_name)->next->val)
		stack->swap(stack);
}

void	sort_3_descend(t_stack *stack, t_node **stack_name)
{
	t_node	*head;
	t_node	*min_node;

	set_operations(stack, *stack_name);
	min_node = *stack_name;
	head = *stack_name;
	while (head->next != *stack_name)
	{
		head = head->next;
		if (min_node->val > head->val)
			min_node = head;
	}
	if (min_node == *stack_name)
		stack->rotate(stack);
	else if (min_node == (*stack_name)->next)
		stack->reverse(stack);
	*stack_name = min_node->next;
	if ((*stack_name)->val < (*stack_name)->next->val)
		stack->swap(stack);
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
		{
			printf("%srun do_double_op()\n%s", GREEN, RESET_C);
			do_ss(stack);
		}
		else if (stack->a->val > stack->a->prev->val
			&& stack->b->val < stack->b->prev->val)
		{
			printf("%srun do_double_op()\n%s", GREEN, RESET_C);
			do_rrr(stack);
		}
		else if (stack->a->val > stack->a->prev->val
			&& stack->b->val < stack->b->prev->val)
		{
			printf("%srun do_double_op()\n%s", GREEN, RESET_C);
			do_rr(stack);
		}
		else
		{
			printf("%snot do_double_op()\n%s", CYAN, RESET_C);
			print_stack(stack);
			break ;
		}
		// print_stack(stack);
	}
	// print_stack(stack);
}

/*
	5 -> 3
	(5 / 2) + 1 = 3
	6 -> 3
*/