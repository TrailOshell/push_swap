/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:51:52 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/02 20:30:10 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

//	ONLY for testing
# include <stdio.h>

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	//struct	s_node *prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*a;
	struct s_node	*b;
	struct s_node	*last_a;
	struct s_node	*last_b;
	struct s_node	*c;
	struct s_node	*target;
	int				iserror;
	int				min;
	int				min_prev;
}	t_stack;

//	push_swap.c
void	push_swap(char **argv);

//	stack files
// stack.c
t_stack	*start_stack(t_stack *stack);
// void	input_stack(t_stack *stack, char **input);
void	input_stack(t_stack *stack, t_node **stack_name, char **input);
void	end_stack(t_stack *stack);

//	node files
// node.c
// void	add_node_last(t_stack *stack, char stack_name, t_node *add);
void	add_node_last(t_stack *stack, t_node **stack_name, t_node *add);
void	add_node_head(t_stack *stack, char stack_name, t_node *add);
void	del_node_head(t_stack *stack, char stack_name, t_node *add);
t_node	*nodenew(int num);

//	operations files
// do_swap.c
void	do_sa(t_stack *stack);
void	do_sb(t_stack *stack);
void	do_ss(t_stack *stack);
// do_push.c
void	do_pa(t_stack *stack);
void	do_pb(t_stack *stack);
// do_rotate.c
void	do_ra(t_stack *stack);
void	do_rb(t_stack *stack);
void	do_rr(t_stack *stack);
// do_reverse.c
void	do_rra(t_stack *stack);
void	do_rrb(t_stack *stack);
void	do_rrr(t_stack *stack);

//	sorting/algorithm files

//	util files
// util.c
int		atoi_push_swap(char *str);

//	error functions
// error.c
int		notnbr_error(t_stack *stack, char *argv);
int		dupnbr_error(t_stack *stack, int num);

//	test functions
//void	printNode(t_node *node, char *text)

#endif