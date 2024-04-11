/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:06:37 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/11 14:26:59y tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//char	*ps_itoa(int num)
void	ps_itoa(int num)
{
	char	c;

	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * -1;
	}
	if (num > 9)
	{
		ps_itoa(num / 10);
	}
	c = '0' + (num % 10);
	write(1, &c, 1);
}

void	write_stack(t_node *node, char *text)
{
	t_node			*head;
	t_node			*tmp;

	head = node;
	tmp = node;
	write(1, text, ps_strlen(text));
	write(1, ": [", 3);
	while (tmp)
	{
		if (tmp->chunk_order % 2 == 0)
			set_color(BLUE);
		else
			set_color(YELLOW);
		ps_itoa(tmp->val);
		if (tmp->next != head)
			write(1, ", ", 2);
		tmp = tmp->next;
		if (tmp == head)
			break ;
	}
	write(1, "]\n", 2);
	set_color(RESET_C);
}

void	set_color(char *color)
{
	int	len;

	len = 7;
	if (ps_strcmp(color, RESET_C) == 1)
		len = 4;
	write(1, color, len);
}

void	write_color(char *s, char *color)
{
	set_color(color);
	write(1, s, ps_strlen(s));
	set_color(RESET_C);
}

void	final_check(t_data *data)
{
	if (check_ordered(data->a) == 1)
	{
		write_color("O- ordered -O ", GREEN);
	}
	else
	{
		write_color("X- NOT ordered -X ", RED);
	}
	write_stack(data->a, "");
}
