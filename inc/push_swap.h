/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:51:52 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/04 21:52:06 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

//	ONLY for testing
# include <stdio.h>

# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define RESET_C "\033[0m"

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*a;
	struct s_node	*b;
	struct s_node	*last_a;
	struct s_node	*last_b;
	struct s_node	*order;
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
t_node	*get_order_stack(t_stack *stack, char **argv);
void	end_stack(t_stack *stack);

//	node files
// node.c
// void	add_node_last(t_stack *stack, char stack_name, t_node *add);
void	add_node_last(t_stack *stack, t_node **stack_name, t_node *add);
void	add_node_head(t_stack *stack, char stack_name, t_node *add);
void	del_node_head(t_stack *stack, char stack_name, t_node *add);
t_node	*nodenew(int num);
void	nodedel(t_node **node);

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
void	print_node(t_node *node, char *text);
//void	set_color(char *color);
//char	*strtocolor(char *str);
//void	printcolor(char *s, char *color);

#endif