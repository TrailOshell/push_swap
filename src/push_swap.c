/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:09:38 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/28 18:47:46 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*start_stack(t_stack *stack)
{
	if (!stack)
		stack = malloc(sizeof(t_stack));
	stack->a = NULL;
	stack->b = NULL;
	return (stack);
}

void	input_argv(t_stack *stack, char *argv)
{
	t_node	*head;
	t_node	*node;
	int		len;

	head = node;
	while(*argv)
	{
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
	}
	stack->a = head;
}

void	push_swap(char *argv)
{
	t_stack	*stack;
	t_node	*node;

	stack = NULL;
	stack = start_stack(stack);
	stack->a = malloc(sizeof(t_node));
	stack->a->val = 42;
	write(1, "test\n", 6);
	printf("%d", stack->a->val);
	//input_argv(stack, argv);
}

int	main(int argc, char **argv)
{
	if (argc < 1)
		return (0);
	write(1, "test\n", 6);
	push_swap(argv[1]);
}

/*
	//printf("%p\n", stack);
	//node = malloc(sizeof(t_node));
	//write(1, "test\n", 6);
	//stack->a = node;
	//write(1, "test\n", 6);
*/