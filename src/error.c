/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:34:19 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/01 18:03:35 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	notnbr_error(t_stack *stack, char *argv)
{
	if (*argv == '-')
		argv++;
	while (*argv)
	{
		if (*argv < '0' || *argv > '9')
		{
			stack->iserror = 1;
			return (1);
		}
		argv++;
	}
	return (0);
}

int	dupnbr_error(t_stack *stack, int num)
{
	t_node	*tmp;

	tmp = stack->a;
	while (tmp)
	{
		if (tmp->val == num)
		{
			stack->iserror = 1;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

/*
	printf("argv = %s$\n", argv);
		printf("*argv = %c$\n", *argv);
	printf("run 0\n");
*/