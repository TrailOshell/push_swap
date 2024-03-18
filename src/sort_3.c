/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */ /*                                                +#+#+#+#+#+   +#+           */ /*   Created: 2024/03/13 16:48:05 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/13 16:49:26 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//void	sort_3_ascend(t_stack *stack, t_node **stack_name)
//{
//	t_node	*head;
//	t_node	*max_node;

//	set_operations(stack, *stack_name);
//	max_node = *stack_name;
//	head = *stack_name;
//	while (head->next != *stack_name)
//	{
//		head = head->next;
//		if (max_node->val < head->val)
//			max_node = head;
//	}
//	if (max_node == *stack_name)
//		stack->rotate(stack);
//	else if (max_node == (*stack_name)->next)
//		stack->reverse(stack);
//	*stack_name = max_node->next;
//	if ((*stack_name)->val > (*stack_name)->next->val)
//		sort_2(stack);
//}

//void	sort_3_descend(t_stack *stack, t_node **stack_name)
//{
//	t_node	*head;
//	t_node	*min_node;

//	set_operations(stack, *stack_name);
//	min_node = *stack_name;
//	head = *stack_name;
//	while (head->next != *stack_name)
//	{
//		head = head->next;
//		if (min_node->val > head->val)
//			min_node = head;
//	}
//	if (min_node == *stack_name)
//		stack->rotate(stack);
//	else if (min_node == (*stack_name)->next)
//		stack->reverse(stack);
//	*stack_name = min_node->next;
//	if ((*stack_name)->val < (*stack_name)->next->val)
//		stack->swap(stack);
//}
