/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 00:34:59 by flevesqu          #+#    #+#             */
/*   Updated: 2016/03/08 04:55:07 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_stack
{
	int				content;
	int				pos;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_gen
{
	int		nb;
	char	flags;
	int		total;
	char	*aff;
	t_stack	**a;
	t_stack	**b;
}				t_gen;

void			pa(t_stack **a, t_stack **b, t_gen *g);
void			pb(t_stack **a, t_stack **b, t_gen *g);
void			sa(t_stack **a, t_stack **b, t_gen *g);
void			sb(t_stack **a, t_stack **b, t_gen *g);
void			ss(t_stack **a, t_stack **b, t_gen *g);
void			ra(t_stack **a, t_stack **b, t_gen *g);
void			rb(t_stack **a, t_stack **b, t_gen *g);
void			rr(t_stack **a, t_stack **b, t_gen *g);
void			rra(t_stack **a, t_stack **b, t_gen *g);
void			rrb(t_stack **a, t_stack **b, t_gen *g);
void			rrr(t_stack **a, t_stack **b, t_gen *g);
void			push(t_stack **a, t_stack **b);
void			swap(t_stack *s);
void			rotate(t_stack **s);
void			rev_rotate(t_stack **s);

void			error(int r);
void			control_stack(int nb, t_stack *first);
t_stack			*new_stack(int value);
void			enter_game(t_stack *a, t_gen *gen);
int				ps_atoi(char*str);
void			def_pos(t_stack *a);
void			free_stack(t_stack *a);
int				def_opt(char *av, t_gen *gen);

void			algo(t_stack **a, t_stack **b, t_gen *gen);
int				algo_1(t_stack **a, t_stack **b, t_gen *gen);
int				algo_2(t_stack **a, t_stack **b, t_gen *gen);
void			algo_3(t_stack **a, t_stack **b, t_gen *gen);
void			algo_3_bis(t_stack **a, t_stack **b, t_gen *gen);
void			algo_4(t_stack **a, t_stack **b, t_gen *gen);
void			algo_4_bis(t_gen *gen, int piv);
void			algo_4_b(t_gen *gen, int piv);
void			algo_4_c(t_gen *gen, int piv);
int				algo_4_a(t_stack **a, t_stack **b, t_gen *gen);
void			algo_4_fus(t_stack **a, t_stack **b, t_gen *gen);
void			algo_4_fus_rev(t_stack **a, t_stack **b, t_gen *gen);
int				def_check(t_stack *a, int *s, int *t, int *v);

int				first(t_stack *s);
int				last(t_stack *s);
int				prelast(t_stack *s);

int				count(t_stack *a);
int				check(t_stack *a);
int				check_2(t_stack *a);
int				check_3(t_stack *a);
int				check_4(t_stack *a);
int				check_5(t_stack *a);
int				where_1(t_stack *a);
int				where_2(t_stack *a);
int				where_3(t_stack *a, int search);
int				rev_where_2(t_stack *a);
int				max(t_stack *a);
int				min(t_stack *a);

void			display_stacks(t_stack *a, t_stack *b, t_gen *g);
void			display_pos(t_stack *a, t_stack *b, t_gen *g);
void			display_fstack(t_stack *a, t_stack *b);

#endif
