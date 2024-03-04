/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:59:05 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/04 21:57:07 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*start_stack(t_stack *stack)
{
	if (!stack)
		stack = malloc(sizeof(t_stack));
	stack->a = NULL;
	stack->b = NULL;
	stack->last_a = NULL;
	stack->last_b = NULL;
	stack->iserror = 0;
	stack->order = NULL;
	return (stack);
}

void	input_stack(t_stack *stack, t_node **stack_name, char **input)
{
	int		num;

	while (*input)
	{
		if (notnbr_error(stack, *input))
			return ;
		num = atoi_push_swap(*input);
		if (dupnbr_error(stack, num))
			return ;
		add_node_last(stack, stack_name, nodenew(num));
		input++;
	}
}

void	dupe_stack(t_stack *stack, t_node *stack_origin, t_node **stack_dupe)
{
	t_node *head;
	t_node *tmp;

	head = stack_origin;
	while (stack_origin)
	{
		add_node_last(stack, stack_dupe, nodenew(stack_origin->val));
		stack_origin = stack_origin->next;
		if (stack_origin == head)
			break ;
	}
}

t_node	*get_order_stack(t_stack *stack, char **argv)
{
	t_node	*head;
	t_node	*min_node;
	t_node	*tmp;

	//printf("stack->order->next = %d", stack->order->next->val);
	//printf("stack->order->val = %d", (*stack)->order->val);
	//printf("%s\n", *argv);
	//input_stack(*stack, &((*stack)->order), argv);
	dupe_stack(stack, stack->a, &(stack->order));
	head = stack->order;
	while (stack->order)
	{
		min_node = head;
		tmp = head;
		while (tmp)
		{
			if (min_node->val > tmp->val)
				min_node = tmp;
			tmp = tmp->next;
			//if (tmp = tmp)
				break ;
		}
		if (head = stack->order)
			break ;
	}
	printf("run get order\n");
	return (stack->order);
}

void	end_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*head;

	if (!stack)
		return ;
	tmp = NULL;
	head = stack->a;
	while (stack->a)
		nodedel(&stack->a);
	while (stack->b)
		nodedel(&stack->b);
	free(stack);
}

//	print_node(stack->a, "deleting the stack...");

/* input_stack()

	printf("*argv = %s$\n", *argv);
	printf("notnbr_error(*argv) = %d$\n", notnbr_error(*argv));
*/

//void delstack(t_stack *stack)
//{
//	t_node *tmp;

//	if (!stack)
//		return ;
//	tmp = NULL; //	while (stack->a)
//	{
//		tmp = stack->a->next;
//		free(stack->a);
//		stack->a = tmp;
//	}
//	while (stack->b)
//	{
//		tmp = stack->b->next;
//		free(stack->b);
//		stack->b = tmp;
//	}
//}

/*
if(*argv != ' ')
{
	len = ft_strlen(ft_strchr(argv, ' '));
	//if (!stack->a)
	stack.a = nodenew(ft_atoi(ft_substr(argv, 0, len)));
	//else
	//	stack->a->next = nodenew(ft_atoi(ft_substr(argv, 0, len)));
	stack.a = stack.a->next;
	argv = argv + len;
}
argv++;
*/

/* input_stack()
	print_node(stack->a, "stack a");
	
	//t_node	*head;
	//t_node	*node;

	//head = node;
	//stack->a = head;
*/

/*
t_node	*get_order_stack(t_stack **stack, char **argv)
{
	t_node	*order;
	t_node	*tmp;
	t_node	*head;
	t_node	*min_node;
	int		min;

	//printf("stack->order->next = %d", stack->order->next->val);
	//printf("stack->order->val = %d", (*stack)->order->val);
	order = (*stack)->order;
	//printf("%s\n", *argv);
	tmp = NULL;
	input_stack(*stack, &tmp, argv);
	printf("run\n");
	while (tmp)
	{
		//	loop to find min in the tmp stack
		head = tmp;
		min_node = tmp;
		while (tmp)
		{
			if (min_node->val > tmp->val)
				min_node = tmp;
			tmp = tmp->next;
			if (tmp == head)
				break ;
		}
		if (tmp == min_node)
			tmp = tmp->next;
		//	put min_node to stack->order and remove  min_node from tmp stack
		if (min_node->next == min_node)
		{
			add_node_last(*stack, order, min_node);
			break ;
		}
		else
		{
			min_node->prev->next = min_node->next;
			min_node->next->prev = min_node->prev;
			add_node_last(*stack, order, min_node);
		}
	}
	
	return order;
}
*/