/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:34:19 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/11 18:27:09 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	write_error(void)
{
	write(1, YELLOW, 7);
	write(1, "Error\n", 6);
	write(1, RESET_C, 4);
}

int	empty_error(t_data *data, char *input)
{
	while (*input == ' ')
		input++;
	if (*input == '\0')
		data->iserror = 1;
	return (data->iserror);
}

int	input_error(t_data *data, char *input)
{
	int	isnbr;

	isnbr = 0;
	while (*input == ' ')
		input++;
	if (*input == '-' || *input == '+')
		input++;
	if (*input >= '0' && *input <= '9')
		isnbr = 1;
	while (*input >= '0' && *input <= '9')
		input++;
	if (isnbr != 1 || (*input != ' ' && *input != '\0'))
		data->iserror = 1;
	return (data->iserror);
}

int	dupnbr_error(t_data *data, int num)
{
	t_node	*last;
	t_node	*tmp;

	if (count_nodes(data->a) == 1)
		return (0);
	last = data->a->prev;
	tmp = data->a;
	while (tmp != last)
	{
		if (tmp->val == num)
		{
			data->iserror = 1;
			break ;
		}
		tmp = tmp->next;
	}
	return (data->iserror);
}

int	overflow_error(t_data *data, long num)
{
	if (num < -2147483648 || num > 2147483647)
		data->iserror = 1;
	return (data->iserror);
}
