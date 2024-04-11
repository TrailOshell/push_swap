/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:34:19 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/11 16:38:31 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	write_error(void)
{
	write(1, YELLOW, 7);
	write(1, "Error\n", 6);
	write(1, RESET_C, 4);
}

int	nbr_error(t_data *data, char *argv)
{
	int	isnbr;

	isnbr = 0;
	if (*argv == '\0')
	{
		data->iserror = 1;
		return (1);
	}
	while (*argv == ' ')
		argv++;
	if (*argv == '-' || *argv == '+')
		argv++;
	if (*argv >= '0' && *argv <= '9')
		isnbr = 1;
	while (*argv >= '0' && *argv <= '9')
		argv++;
	if (isnbr == 1 && (*argv == ' ' || *argv == '\0'))
		return (0);
	else
	{
		data->iserror = 1;
		return (1);
	}
	return (0);
	//while (*argv)
	//{
	//	if (*argv < '0' || *argv > '9')
	//	{
	//		data->iserror = 1;
	//		return (1);
	//	}
	//	argv++;
	//}
	//return (0);
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
