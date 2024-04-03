/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:06:17 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/03 18:18:10 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_reverse(t_node **node)
{
	*node = (*node)->prev;
}

void	do_rra(t_data *data)
{
	do_reverse(&data->a);
	write(1, "rra\n", 4);
	add_log(data, newlog(data, "rra", NULL), 1);
}

void	do_rrb(t_data *data)
{
	do_reverse(&data->b);
	write(1, "rrb\n", 4);
	add_log(data, newlog(data, "rrb", NULL), 1);
}

void	do_rrr(t_data *data)
{
	do_reverse(&data->a);
	do_reverse(&data->b);
	write(1, "rrr\n", 4);
	add_log(data, newlog(data, "rrr", NULL), 1);
}
