/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:55:00 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/16 19:01:57by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_log	*newlog(t_data *data, char *op, char *text)
{
	t_log	*new;

	new = malloc(sizeof(t_log));
	if (!new)
		return (0);
	new->id = 0;
	new->op_count = 0;
	new->next = NULL;
	new->prev = NULL;
	new->op = NULL;
	new->text = NULL;
	if (op)
		new->op = ps_strdup(op);
	if (text)
		new->text = ps_strdup(text);
	new->a = NULL;
	new->b = NULL;
	dupe_stack(data, &(data->a), &(new->a));
	dupe_stack(data, &(data->b), &(new->b));
	return (new);
}

void	add_log(t_data *data, t_log *log, int add_count)
{
	if (!data->log)
	{
		log->id = 1;
		log->op_count = add_count;
		data->log = log;
		log->next = log;
		log->prev = log;
	}
	else
	{
		log->id = data->log->prev->id + 1;
		log->op_count = data->log->prev->op_count + add_count;
		log->next = data->log;
		log->prev = data->log->prev;
		data->log->prev->next = log;
		data->log->prev = log;
	}
}

void	free_log(t_log *log)
{
	t_log	*tmp;
	t_log	*head;

	if (!log)
		return ;
	head = log;
	while (log != NULL)
	{
		if (log->op)
			free(log->op);
		if (log->text)
			free(log->text);
		while (log->a)
			nodedel(&(log->a));
		while (log->b)
			nodedel(&(log->b));
		tmp = log;
		log = log->next;
		free(tmp);
		if (log == head)
			break ;
	}
}

void	set_log_target(t_log *log, t_node **a, t_node **b)
{
	char	*s;

	*a = NULL;
	*b = NULL;
	if (log->op)
		s = ps_strdup(log->op);
	else
		return ;
	if (ps_strcmp(s, "sa") || ps_strcmp(s, "ss"))
		*a = log->a->next;
	else if (ps_strcmp(s, "ra") || ps_strcmp(s, "rr"))
		*a = log->a->prev;
	else if (ps_strcmp(s, "rra") || ps_strcmp(s, "pa") || ps_strcmp(s, "rrr"))
		*a = log->a;
	if (ps_strcmp(s, "sb") || ps_strcmp(s, "ss"))
		*b = log->b->next;
	else if (ps_strcmp(s, "rb") || ps_strcmp(s, "rr"))
		*b = log->b->prev;
	else if (ps_strcmp(s, "rrb") || ps_strcmp(s, "pb") || ps_strcmp(s, "rrr"))
		*b = log->b;
	free(s);
}

void	print_log_stack(t_node *log_node, t_node *target, char *color)
{
	t_node	*head;

	head = log_node;
	while (log_node)
	{
		if (target && log_node == target)
		{
			printf("%s%d%s", YELLOW, log_node->val, color);
			//printf("%s(%d)%s", PURPLE, log_node->chunk_order, color);
		}
		else if (log_node->chunk_order != 0 && log_node->chunk_order == head->chunk_order)
		{
			printf("%s%d%s", PURPLE, log_node->val, color);
			//printf("%d", log_node->val);
			//printf("%s(%d)%s", PURPLE, log_node->chunk_order, color);
		}
		else
			printf("%d", log_node->val);
		log_node = log_node->next;
		if (log_node == head)
			break ;
		printf(", ");
	}
	printf("]");
	printf("\n");
}

void	print_log(t_log *log)
{
	t_node	*target_a;
	t_node	*target_b;

	while (log)
	{
		set_log_target(log, &target_a, &target_b);
		if (log->text)
		{
			printf("%s\t%d:\t%s", GREEN, log->next->op_count, RESET_C);
			printf("%s %s%s\n", YELLOW, log->text, RESET_C);
			printf("%s\t\t\ta: [", RED);
			print_log_stack(log->a, target_a, RED);
			printf("%s\t\t\tb: [", BLUE);
			print_log_stack(log->b, target_b, BLUE);
			set_color(RESET_C);
		}
		if (log->op)
		{
			printf("%s\t%d:\t%s", GREEN, log->op_count, RESET_C);
			printf("%s %s%s", PURPLE, log->op, RESET_C);
			printf("%s\ta: [", RED);
			print_log_stack(log->a, target_a, RED);
			printf("%s\t\t\tb: [", BLUE);
			print_log_stack(log->b, target_b, BLUE);
			set_color(RESET_C);
		}
		log = log->next;
		if (log->id == 1)
			break ;
	}
}

void	logging(t_data *data, t_log *log)
{
	t_node	*target_a;
	t_node	*target_b;

	while (log)
	{
		//printf("\f");
		usleep(5000);	
		system("clear");
		set_log_target(log, &target_a, &target_b);
		if (log->text)
		{
			printf("%s\t%d:\t%s", GREEN, log->next->op_count, RESET_C);
			printf("%s %s%s\n", YELLOW, log->text, RESET_C);
		}
		else if (log->op)
		{
			printf("%s\t%d:\t%s", GREEN, log->op_count, RESET_C);
			printf("%s %s%s\n", PURPLE, log->op, RESET_C);
		}
		printf("%s\t\t\ta: [", RED);
		print_log_stack(log->a, target_a, RED);
		printf("%s\t\t\tb: [", BLUE);
		print_log_stack(log->b, target_b, BLUE);
		set_color(RESET_C);
		log = log->next;
		if (log->id == 1)
			break ;
	}
}
