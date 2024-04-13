/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:59:05 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/11 20:01:59y tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	nbrlen(char *input)
{
	int	len;

	if (ps_strcmp(input, "-2147483648"))
		return (11);
	len = 0;
	while (input[len] == ' ')
		len++;
	if (input[len] == '-' || input[len] == '+')
		len++;
	while (input[len] >= '0' && input[len] <= '9')
		len++;
	while (input[len] == ' ')
		len++;
	return (len);
}

void	input_stack(t_data *data, char **input)
{
	long	num;
	int		len;

	while (*input)
	{
		if (empty_error(data, *input) == 1)
			return ;
		while (**input)
		{
			if (input_error(data, *input) == 1)
				return ;
			num = atoi_push_swap(*input);
			add_node_last(&(data->a), nodenew(num, 0));
			if (overflow_error(data, num) == 1 || dupnbr_error(data, num) == 1)
				return ;
			len = nbrlen(*input);
			*input += len;
		}
		input++;
	}
}

/* input_stack() debug
	printf("len = %d\t", len);
	printf("%s*input = \"%s\"\n%s", PURPLE, *input, RESET_C);
	printf("%snum = \"%ld\"\n%s", PURPLE, num, RESET_C);
*/

void	dupe_stack(t_node *origin, t_node **dupe)
{
	t_node	*head;
	t_node	*new;

	head = origin;
	while (*dupe)
		nodedel(dupe);
	while (origin)
	{
		new = nodenew(origin->val, origin->chunk_order);
		add_node_last(dupe, new);
		origin = origin->next;
		if (origin == head)
			break ;
	}
}

t_node	*get_min_node(t_node *head, t_node *min_prev)
{
	t_node	*tmp;
	t_node	*min_next;

	min_next = head;
	tmp = head;
	while (tmp)
	{
		if (tmp->val < min_next->val && (!min_prev || tmp->val > min_prev->val))
			min_next = tmp;
		tmp = tmp->next;
		if (tmp == head)
			break ;
	}
	return (min_next);
}

t_node	*current_stack_order(t_data *data, t_node *stack)
{
	t_node	*head;
	t_node	*min_next;
	t_node	*min_prev;

	dupe_stack(stack, &(data->order));
	min_prev = NULL;
	head = data->order;
	while (head)
	{
		min_next = get_min_node(head, min_prev);
		swap_nodes_value(&min_next, &head);
		min_prev = head;
		head = head->next;
		if (head == data->order)
			break ;
	}
	return (data->order);
}

/* current_stack_order() 
	write_stack(data->order, "order");
		write_stack(head, "head");
		printf("min_next = %d\n", min_next->val);
		write_stack(data->order, "swapped order");
		printf("min_prev = %d\n", min_prev->val);
*/