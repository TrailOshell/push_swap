/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:36:47 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/03 18:17:38 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_swap(t_node *node)
{
	int	tmp;

	if (node->next == node)
		return ;
	tmp = node->next->val;
	node->next->val = node->val;
	node->val = tmp;
}

void	do_sa(t_data *data)
{
	do_swap(data->a);
	write(1, "sa\n", 3);
	add_log(data, newlog(data, "sa", NULL), 1);
}

void	do_sb(t_data *data)
{
	do_swap(data->b);
	write(1, "sb\n", 3);
	add_log(data, newlog(data, "sb", NULL), 1);
}

void	do_ss(t_data *data)
{
	do_swap(data->a);
	do_swap(data->b);
	write(1, "ss\n", 3);
	add_log(data, newlog(data, "ss", NULL), 1);
}
