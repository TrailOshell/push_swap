/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:18:20 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/27 23:52:42 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

typedef struct s_node 
{
	int	val;
	struct	s_node *next;
	//struct	s_node *prev;
}	t_node;

typedef struct s_stack 
{
	struct s_node *a;
	struct s_node *b;
} t_stack;

void start_stack(t_stack *stack)
{

}

t_node	*nodenew(int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node)); if (!new)
		return (0);
	new->val = num;
	new->next = NULL;
	return (new);
}

void input_argument(t_stack *stack, char *input)
{
	t_node *head;
	t_node *node;
	int len;
	//int count;

	head = node;
	while(*input)
	{
		if(*input != ' ')
		{
			len = ft_strlen(ft_strchr(input, ' '));
			//if (!stack->a)
			stack->a = nodenew(ft_atoi(ft_substr(input, 0, len)));
			//else
			//	stack->a->next = nodenew(ft_atoi(ft_substr(input, 0, len)));
			stack->a = stack->a->next;
			input = input + len;
		}
		input++;
	}
	stack->a = head;
}

do_pa (t_stack *stack)
{
    t_node *head_a;
    t_node *head_b;
    
    //stack_a make new head
    head_a->val = stack->b->val;
	//stack_a connect new head to old head
    head_a->next = stack->a->next;

	//stack_b track new head
	head_b = stack->b->next;
	//stack_b remove old head
	dellst(stack->b);
}

void	printNode(t_node *node, char *text)
{

	printf("%s", text);
	printf(": [");
	while (node)
	{
		printf("%d", node->val);
		if (node->next)
			printf(",");
		node = node->next;
	}
	printf("]");
	printf("\n");
}

//push_swap operations (only one stack)
void do_s(t_node *node)
{
	int tmp;

	// printf("run\n");
	if (node->val && node->next->val)
	{
		tmp = node->next->val;
		node->next->val = node->val;
		node->val = tmp;
	}
}

void do_r(t_node *node)
{
	int tmp;

	tmp = node->val;
	while (node->next)
	{
		node->val = node->next->val;
		node = node->next;
	}
	node->val = tmp;
}

void do_rr(t_node *node)
{
	int tmp1;
	int tmp2;
	t_node *head;

	head = node;
	tmp2 = node->val;
	node = node->next;
	while (node)
	{
		tmp1 = tmp2;
		tmp2 = node->val;
		node->val = tmp1;
		node = node->next;
	}
	head->val = tmp2;
}


//struct t_node* sortList(struct t_node* head) {
t_node *sortList(t_node* head)
{
	//struct t_node *head;
	// do_s(head);
	//do_r(head);
	do_rr(head);
	return (head);
}

int main(void)
{
	t_node lstNode =
	{42,
	&(t_node){2,
	&(t_node){0,
	&(t_node){-24,
	&(t_node){4,	NULL}}}}};
	printNode(&lstNode, "Input ");
	printNode(sortList(&lstNode), "Output");
}