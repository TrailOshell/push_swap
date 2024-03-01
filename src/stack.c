/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:59:05 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/01 16:59:34 by tsomchan         ###   ########.fr       */
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

void	input_stack(t_stack *stack, char **argv)
{
	int		num;

	argv++;
	while (*argv)
	{
		if (notnbr_error(*argv))
		{
			printf("*argv = %s$\n", *argv);
			printf("notnbr_error(*argv) = %d$\n", notnbr_error(*argv));
			stack->iserror = 1;
			return ;
		}
		num = atoi_push_swap(*argv);
		add_node_last(stack, 'a', nodenew(num));
		argv++;
	}
}

void end_stack(t_stack *stack)
{
	t_node *tmp;

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