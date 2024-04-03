/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:59:05 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/08 17:18:57by tsomchan         ###   ########.fr       */
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
	data->log = NULL;
	return (data);
}

void	input_stack(t_data *data, t_node **stack, char **input)
{
	int		num;

	while (*input)
	{
		if (notnbr_error(data, *input))
			return ;
		num = atoi_push_swap(*input);
		if (data->a && dupnbr_error(data, num))
			return ;
		add_node_last(data, stack, nodenew(num, 0));
		input++;
	}
}

void	dupe_stack(t_data *data, t_node **origin, t_node **dupe)
{
	t_node	*head;
	t_node	*tmp;
	t_node	*new;

	head = *origin;
	while (*dupe)
		nodedel(&(*dupe));
	while (*origin)
	{
		new = nodenew((*origin)->val, (*origin)->chunk_order);
		add_node_last(data, dupe, new);
		*origin = (*origin)->next;
		if (*origin == head)
			break ;
	}
}

void	end_stack(t_data *data)
{
	if (!data)
		return ;
	while (data->a)
		nodedel(&data->a);
	while (data->b)
		nodedel(&data->b);
	while (data->order)
		nodedel(&data->order);
	free_log(data->log);
	free(data);
}

//void	dupe_chunk(t_stack *stack, t_node **stack_origin, t_node **stack_dupe,
//			int chunk_order)
//{
//	t_node	*head;
//	t_node	*tmp;
//	t_node	*new;

//	head = *stack_origin;
//	tmp = *stack_origin;
//	while (*stack_dupe)
//		nodedel(&(*stack_dupe));
//	while (tmp)
//	{
//		new = nodenew(tmp->val, tmp->chunk_order);
//		add_node_last(data, stack_dupe, new);
//		tmp = tmp->next;
//		if (tmp == head || tmp->chunk_order != chunk_order)
//			break ;
//	}
//}

//	print_node(data->a, "deleting the stack...");

/* input_stack()
	printf("*argv = %s$\n", *argv);
	printf("notnbr_error(*argv) = %d$\n", notnbr_error(*argv));
*/