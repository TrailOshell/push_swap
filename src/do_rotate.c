/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:17:05 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/28 22:18:56y tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_rotate(t_node **node)
{
	*node = (*node)->next;
}

void	do_ra(t_data *data)
{
	do_rotate(&data->a);
	write(1, "ra\n", 3);
	add_log(data, newlog(data, "ra", NULL), 1);
}

void	do_rb(t_data *data)
{
	do_rotate(&data->b);
	write(1, "rb\n", 3);
	add_log(data, newlog(data, "rb", NULL), 1);
}

void	do_rr(t_data *data)
{
	do_rotate(&data->a);
	do_rotate(&data->b);
	write(1, "rr\n", 3);
	add_log(data, newlog(data, "rr", NULL), 1);
}
