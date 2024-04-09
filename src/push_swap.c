/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:09:38 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/09 13:31:25 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_data	*start_data(t_data *data)
{
	if (!data)
		data = malloc(sizeof(t_data));
	data->a = NULL;
	data->b = NULL;
	data->order = NULL;
	data->target = NULL;
	data->iserror = 0;
	data->median = 0;
	data->quarter = 0;
	data->half_quarter = 0;
	data->swap = NULL;
	data->rotate = NULL;
	data->reverse = NULL;
	data->push = NULL;
	return (data);
}

void	end_data(t_data *data)
{
	if (!data)
		return ;
	while (data->a)
		nodedel(&data->a);
	while (data->b)
		nodedel(&data->b);
	while (data->order)
		nodedel(&data->order);
	free(data);
}

void	run_sorting(t_data *data)
{
	int		chunk_order;

	chunk_order = 0;
	while (!(check_ordered(data->a)) && count_nodes(data->a) > 5)
	{
		if (count_nodes(data->a) <= 100)
			push_till_median(data, ++chunk_order);
		else
			push_till_quarter(data, ++chunk_order);
	}
	if (!(check_ordered(data->a)))
		sort_in_5(data);
	while (count_nodes(data->b))
		push_min_max_chunk(data, chunk_order--);
	final_ordering(data);
}

void	push_swap(char **argv)
{
	t_data	*data;

	data = NULL;
	data = start_data(data);
	input_stack(data, &(data->a), ++argv);
	if (data->iserror)
		write(1, "Error\n", 6);
	else
		run_sorting(data);
	end_data(data);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	push_swap(argv);
}
