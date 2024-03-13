/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:55:00 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/13 19:29:59 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_log	*newlog(t_stack *stack, char *op, char *text)
{
	t_log	*new;

	new = malloc(sizeof(t_log));
	if (!new)
		return (0);
	new->id = 0;
	new->next = NULL;
	new->prev = NULL;
	new->op = NULL;
	new->text = NULL;
	if (*op)
		new->op = ps_strdup(op);
	if (*text)
		new->text = ps_strdup(text);
	new->a = NULL;
	new->b = NULL;
	dupe_stack(stack, stack->a, &(new->a));
	dupe_stack(stack, stack->b, &(new->b));
	return (new);
}

void	add_log(t_stack *stack, t_log *log)
{
	if (!stack->log)
	{
		log->id = 1;
		stack->log = log;
		log->next = log;
		log->prev = log;
	}
	else
	{
		log->id = stack->log->prev->id + 1;
		log->next = stack->log;
		log->prev = stack->log->prev;
		stack->log->prev->next = log;
		stack->log->prev = log;
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
		if (log->next == log)
		{
			free(log);
			log = NULL;
			break ;
		}
		else
		{
			log = log->next;
			tmp->prev->next = log;
			free(tmp);
			tmp = NULL;
		}
		printf("run\n");
		if (log == head)
			break ;
	}
}

void	set_log_target(t_log *log, t_node **a, t_node **b)
{
	if (ps_strcmp(log->op, "rr") == 1)
	{
		*a = log->a->prev;
		*b = log->b->prev;
	}
	else if (ps_strcmp(log->op, "ra") == 1)
		*a = log->a->prev;
	else if (ps_strcmp(log->op, "rb") == 1)
		*b = log->b->prev;
	else if (ps_strcmp(log->op, "rra") == 1 || ps_strcmp(log->op, "pa") == 1)
		*a = log->a;
	else if (ps_strcmp(log->op, "rrb") == 1 || ps_strcmp(log->op, "pb") == 1)
		*b = log->b;
	else if (ps_strcmp(log->op, "rrr") == 1)
	{
		*a = log->a;
		*b = log->b;
	}
	else if (ps_strcmp(log->op, "sa") == 1)
		*a = log->a->next;
	else if (ps_strcmp(log->op, "sb") == 1)
		*b = log->b->next;
	else if (ps_strcmp(log->op, "ss") == 1)
	{
		*a = log->a->next;
		*b = log->b->next;
	}
	else
	{
		*a = NULL;
		*b = NULL;
	}
}

void	print_log_stack(t_log *log, t_node *target_a, t_node *target_b)
{
	t_node	*head;

	printf("%sa: [", RED);
	head = log->a;
	while (log->a)
	{
		if (target_a && log->a == target_a)
			printf("%s %d%s", YELLOW, log->a->val, RED);
		else
			printf("%d", log->a->val);
		log->a = log->a->next;
		if (log->a == head)
			break ;
		printf(", ");
	}
	printf("]");
	printf("\n");
	printf("\t\t\t%sb: [", BLUE);
	head = log->b;
	while (log->b)
	{
		if (target_b && log->b == target_b)
			printf("%s %d%s", YELLOW, log->b->val, BLUE);
		else
			printf("%d", log->a->val);
		log->b = log->b->next;
		if (log->b == head)
			break ;
		printf(", ");
	}
	printf("]");
	printf("\n%s", RESET_C);
}

void	print_log(t_log *log)
{
	t_node	*target_a;
	t_node	*target_b;

	while (log)
	{
		set_log_target(log, &target_a, &target_b);
		printf("%s\t%d:\t%s", GREEN, log->id, RESET_C);
		printf("%s %s%s", PURPLE, log->op, RESET_C);
		if (log->text)
			printf("%s %s%s", YELLOW, log->text, RESET_C);
		printf("\t");
		print_log_stack(log, target_a, target_b);
		log = log->next;
		if (log->id == 1)
			break ;
	}
	printf("end log\n");
	//t_log	*head;
	//t_log	*tmp;
	//t_node	*node1;
	//t_node	*node2;

	//head = log;
	//tmp = log;
	//printf("%s", text);
	//printf(": [");
	//while (tmp)
	//{
	//	printf("%d", tmp->val);
	//	tmp = tmp->next;
	//	if (tmp == head)
	//		break ;
	//	printf(", ");
	//}
	//printf("]");
	//printf("\n");
}
