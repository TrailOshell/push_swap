/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:34:19 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/03 17:57:59 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	notnbr_error(t_data *data, char *argv)
{
	if (*argv == '-')
		argv++;
	while (*argv)
	{
		if (*argv < '0' || *argv > '9')
		{
			data->iserror = 1;
			return (1);
		}
		argv++;
	}
	return (0);
}

int	dupnbr_error(t_data *data, int num)
{
	t_node	*head;
	t_node	*tmp;

	head = data->a;
	tmp = data->a->prev;
	while (tmp->next != head->prev)
	{
		tmp = tmp->next;
		if (tmp->val == num)
		{
			data->iserror = 1;
			return (1);
		}
	}
	return (0);
}

/*
	printf("argv = %s$\n", argv);
		printf("*argv = %c$\n", *argv);
	printf("run 0\n");
*/