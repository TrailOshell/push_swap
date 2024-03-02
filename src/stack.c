/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:59:05 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/02 20:32:09 by tsomchan         ###   ########.fr       */
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

t_stack	*get_order_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*order;

	return(order);
}

void	end_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	tmp = NULL;
	while (stack->a)
	{
		tmp = stack->a->next;
		free(stack->a);
		stack->a = tmp;
	}
	while (stack->b)
	{
		tmp = stack->b->next;
		free(stack->b);
		stack->b = tmp;
	}
	free(stack);
}

/* input_stack()

	printf("*argv = %s$\n", *argv);
	printf("notnbr_error(*argv) = %d$\n", notnbr_error(*argv));
*/

//void delstack(t_stack *stack)
//{
//	t_node *tmp;

//	if (!stack)
//		return ;
//	tmp = NULL;
//	while (stack->a)
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