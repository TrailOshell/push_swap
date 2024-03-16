/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */ /*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
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
	new->op = ps_strdup(op);
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
		log = log->next;
		free(tmp);
		if (log == head)
			break ;
	}
}

void	set_log_target(t_log *log, t_node **a, t_node **b)
{
	char	*s;

	s = ps_strdup(log->op);
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

	printf("%sa: [", color);
	head = log_node;
	while (log_node)
	{
		if (target && log_node == target)
			printf("%s%d%s", YELLOW, log_node->val, color);
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
		printf("%s\t%d:\t%s", GREEN, log->id, RESET_C);
		printf("%s %s%s", PURPLE, log->op, RESET_C);
		if (log->text)
			printf("%s %s%s", YELLOW, log->text, RESET_C);
		printf("\t");
		print_log_stack(log->a, target_a, RED);
		printf("\t\t\t");
		print_log_stack(log->b, target_b, BLUE);
		printf("%s", RESET_C);
		log = log->next;
		if (log->id == 1)
			break ;
	}
}

/* newlog()
	//new->a = malloc(sizeof(t_node));
	//new->b = malloc(sizeof(t_node));
	//if (stack->a)
	//{
	//	printf("stack->a = %d\t", stack->a->val);
	//	printf("new->a = %d\n", new->a->val);
	//	print_stack(stack);
	//}
	//if (stack->b)
	//{
	//	printf("stack->b = %d\t", stack->b->val);
	//	printf("new->b = %d\n", new->b->val);
	//	print_stack(stack);
	//}
*/

/* void	set_log_target(t_log *log, t_node **a, t_node **b)
	//if (ps_strcmp(log->op, "rr") == 1)
	//{
	//	*a = log->a->prev;
	//	*b = log->b->prev;
	//}
	//else if (ps_strcmp(log->op, "ra") == 1)
	//	*a = log->a->prev;
	//else if (ps_strcmp(log->op, "rb") == 1)
	//	*b = log->b->prev;
	//else if (ps_strcmp(log->op, "rra") == 1 || ps_strcmp(log->op, "pa") == 1)
	//	*a = log->a;
	//else if (ps_strcmp(log->op, "rrb") == 1 || ps_strcmp(log->op, "pb") == 1)
	//	*b = log->b;
	//else if (ps_strcmp(log->op, "rrr") == 1)
	//{
	//	*a = log->a;
	//	*b = log->b;
	//}
	//else if (ps_strcmp(log->op, "sa") == 1)
	//	*a = log->a->next;
	//else if (ps_strcmp(log->op, "sb") == 1)
	//	*b = log->b->next;
	//else if (ps_strcmp(log->op, "ss") == 1)
	//{
	//	*a = log->a->next;
	//	*b = log->b->next;
	//}
	//else
	//{
	//	*a = NULL;
	//	*b = NULL;
	//}
*/