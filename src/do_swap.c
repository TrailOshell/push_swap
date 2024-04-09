/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:36:47 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/09 11:44:22 by tsomchan         ###   ########.fr       */
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
}

void	do_sb(t_data *data)
{
	do_swap(data->b);
	write(1, "sb\n", 3);
}

void	do_ss(t_data *data)
{
	do_swap(data->a);
	do_swap(data->b);
	write(1, "ss\n", 3);
}
