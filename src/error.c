/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:34:19 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/11 17:27:32 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	write_error(void)
{
	write(1, YELLOW, 7);
	write(1, "Error\n", 6);
	write(1, RESET_C, 4);
}

int	input_error(t_data *data, char *argv)
{
	int	isnbr;

	isnbr = 0;
	if (*argv == '\0')
		data->iserror = 1;
	while (*argv == ' ')
		argv++;
	if (*argv == '-' || *argv == '+')
		argv++;
	if (*argv >= '0' && *argv <= '9')
		isnbr = 1;
	while (*argv >= '0' && *argv <= '9')
		argv++;
	if (isnbr != 1 || (*argv != ' ' && *argv != '\0'))
		data->iserror = 1;
	return (data->iserror);
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
			break ;
		}
	}
	return (data->iserror);
}

int	overflow_error(t_data *data, long num)
{
	if (num < -2147483648 || num > 2147483647)
		data->iserror = 1;
	return (data->iserror);
}
