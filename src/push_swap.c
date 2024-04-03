/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:09:38 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/01 16:18:48by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(char **argv)
{
	t_data	*data;
	t_node	*node;
	int		chunk_order;

	data = NULL;
	data = start_data(data);
	input_stack(data, &(data->a), ++argv);
	if (data->iserror)
	{
		write(1, "Error\n", 6);
		end_stack(data);
		return ;
	}
	chunk_order = 0;
	while (count_nodes(data->a) > 5)
	{
		if (count_nodes(data->a) <= 100)
			push_till_median(data, &(data->a), ++chunk_order);
		else
			push_till_quarter(data, &(data->a), ++chunk_order);
	}
	sort_in_5(data);
	while (count_nodes(data->b))
		push_min_max(data, &(data->b));
	final_order(data);
	print_log(data->log); debug_ordered(data);
	//print_stack(data);
	end_stack(data);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	push_swap(argv);
}
