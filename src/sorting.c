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

int	check_median_push(t_stack *stack, t_node *stack_name, int median)
{
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
	int		count;

	count = 0;
	tmp = stack_name;
	while (tmp)
	{
		if (tmp->val == node->val)
			break ;
		count++;
		tmp = tmp->next;
		if (tmp == stack_name)
			break ;
	}
	if (count <= (count_nodes(stack_name) / 2))
		return (1);
	return (0);
}

void	set_operations(char stack_char, void (*swap)(t_stack),
						void (*rotate)(t_stack), void (*reverse)(t_stack),
						void (*push)(t_stack *))
{
	if (stack_char == 'a')
	{
		swap = &(do_sa);
		rotate = &(do_ra);
		reverse = &(do_rra);
		push = &(do_pb);
	}
	else if (stack_char == 'b')
	{
		swap = &(do_sb);
		rotate = &(do_rb);
		reverse = &(do_rrb);
		push = &(do_pa);
	}
}

void	push_till_median(t_stack *stack, t_node **stack_name, char stack_char)
{
	t_node	*head;
	void	(*swap)(t_stack *);
	void	(*rotate)(t_stack *);
	void	(*reverse)(t_stack *);
	void	(*push)(t_stack *);
	//t_node	*median_node;

	if (stack_char == 'a')
	{
		swap = &(do_sa);
		rotate = &(do_ra);
		reverse = &(do_rra);
		push = &(do_pb);
	}
	else if (stack_char == 'b')
	{
		swap = &(do_sb);
		rotate = &(do_rb);
		reverse = &(do_rrb);
		push = &(do_pa);
	}
	find_median(stack, stack_name);
	while (check_median_push(stack, *stack_name, stack->median))
	{
		printf("target = %d\n", stack->target->val);
		head = *stack_name;
		if (stack->target == (*stack_name))
		{
			push(stack);
			//print_stack(stack);
		}
		else if (stack->target == (*stack_name)->next)
		{
			swap(stack);
			push(stack);
			//print_stack(stack);
		}
		else if (isnear_head(stack, *stack_name, stack->target) == 1)
		{
			while (stack->target != head)
			{
				head = head->next;
				rotate(stack);
			}
			push(stack);
			//print_stack(stack);
		}
		else if (isnear_head(stack, *stack_name, stack->target) == 0)
		{
			while (stack->target != head)
			{
				head = head->prev;
				rotate(stack);
			}
			push(stack);
		}
		printf("%d\n", check_median_push(stack, *stack_name, stack->median));
		print_stack(stack);
	}
}


void	sort_3(t_stack *stack, t_node **stack_name)
{
	t_node	*head;
	t_node	*max_node;
	void	(*swap)(t_stack *);
	void	(*rotate)(t_stack *);
	void	(*reverse)(t_stack *);

	if ((*stack_name) == stack->a)
	{
		swap = &(do_sa);
		rotate = &(do_ra);
		reverse = &(do_rra);
	}
	else if ((*stack_name) == stack->b)
	{
		swap = &(do_sb);
		rotate = &(do_rb);
		reverse = &(do_rrb);
	}
	max_node = *stack_name;
	head = *stack_name;
	while (head->next != *stack_name)
	{
		head = head->next;
		if (max_node->val < head->val)
			max_node = head;
	}
	if (max_node == *stack_name)
		rotate(stack);
	else if (max_node == (*stack_name)->next)
		reverse(stack);
	*stack_name = max_node->next;
	if ((*stack_name)->val > (*stack_name)->next->val)
		swap(stack);
}

void	sort_3_descend(t_stack *stack, t_node **stack_name)
{
	t_node	*head;
	t_node	*min_node;
	void	(*swap)(t_stack *);
	void	(*rotate)(t_stack *);
	void	(*reverse)(t_stack *);

	if ((*stack_name) == stack->a)
	{
		swap = &(do_sa);
		rotate = &(do_ra);
		reverse = &(do_rra);
	}
	else if ((*stack_name) == stack->b)
	{
		swap = &(do_sb);
		rotate = &(do_rb);
		reverse = &(do_rrb);
	}
	min_node = *stack_name;
	head = *stack_name;
	while (head->next != *stack_name)
	{
		head = head->next;
		if (min_node->val > head->val)
			min_node = head;
	}
	if (min_node == *stack_name)
		rotate(stack);
	else if (min_node == (*stack_name)->next)
		reverse(stack);
	*stack_name = min_node->next;
	if ((*stack_name)->val < (*stack_name)->next->val)
		swap(stack);
}

void	push_max(t_stack *stack, t_node **stack_name)
{
	t_node	*head;
	t_node	*max_node;
	void	(*swap)(t_stack *);
	void	(*rotate)(t_stack *);
	void	(*reverse)(t_stack *);
	void	(*push)(t_stack *);

	if ((*stack_name) == stack->a)
	{
		swap = &(do_sa);
		rotate = &(do_ra);
		reverse = &(do_rra);
		push = &(do_pb);
	}
	else if ((*stack_name) == stack->b)
	{
		swap = &(do_sb);
		rotate = &(do_rb);
		reverse = &(do_rrb);
		push = &(do_pa);
	}
	max_node = *stack_name;
	head = *stack_name;
	while (head->next != *stack_name)
	{
		head = head->next;
		if (max_node->val < head->val)
			max_node = head;
	}
	if (max_node == *stack_name)
		push(stack);
	else if (max_node == (*stack_name)->next)
	{
		swap(stack);
		push(stack);
	}
	//*stack_name = max_node->next;
	printf("%srun\n%s", YELLOW, RESET_C);
	//if ((*stack_name)->val < (*stack_name)->next->val)
	//	swap(stack);
}

/*
	5 -> 3
	(5 / 2) + 1 = 3
	6 -> 3
*/