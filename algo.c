/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 04:32:03 by flevesqu          #+#    #+#             */
/*   Updated: 2016/03/08 05:33:29 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	enter_game(t_stack *a, t_gen *gen)
{
	t_stack *b;

	gen->nb = 0;
	gen->total = count(a);
	b = NULL;
	gen->aff = NULL;
	if (gen->flags & 0x1)
		display_stacks(a, b, gen);
	while (check(a))
		algo(&a, &b, gen);
	while (b)
		algo_3_bis(&a, &b, gen);
	if (!(gen->flags & 0x8))
	{
		gen->aff ? ft_putendl(gen->aff) : putchar('\n');
		free(gen->aff);
	}
	if (gen->flags & 0x2 && !(gen->flags & 0x1))
		display_fstack(a, b);
	if (gen->flags & 0x4)
		ft_printf("Require [%d] moves.\n", gen->nb);
	free(gen);
}

void	algo(t_stack **a, t_stack **b, t_gen *g)
{
	int	c;
	int	s;
	int	t;
	int	v;
	int	m;

	c = def_check(*a, &s, &t, &v);
	m = max(*a);
	if (!t && c == 1 && !s && !check_4(*a))
		algo_1(a, b, g);
	else if (((!v && !t && s) || m < 5)
		&& c <= m / 2 && (c == s + 1 || c == s) && (first(*a) == last(*a) - 1
		|| (first(*a) == m && last(*a) == min(*a))))
	{
		rra(a, b, g);
		sa(a, b, g);
	}
	else if (((!v && !t && s) || m < 5)
			&& (((c == s + 1 || c == s) && s < m / 2) || (c <= s / 2 && m < 5)))
		algo_2(a, b, g);
	else if (m < 10 || s > c / 2)
		algo_3(a, b, g);
	else
		algo_4(a, b, g);
}

void	algo_3(t_stack **a, t_stack **b, t_gen *g)
{
	int	w;
	int	c;
	int	mi;

	mi = min(*a);
	w = where_3(*a, max(*a));
	c = count(*a);
	if (w <= c / 2)
		while (w > 0)
		{
			w -= 1;
			rra(a, b, g);
		}
	else
		while (w < c)
		{
			w += 1;
			ra(a, b, g);
		}
	pb(a, b, g);
}

int		algo_2(t_stack **a, t_stack **b, t_gen *g)
{
	int	w;
	int	rw;
	int	fw;
	int	c;

	c = count(*a);
	w = where_2(*a);
	rw = rev_where_2(*a);
	fw = w < c - rw ? w : rw;
	if (fw < c / 2)
		while (fw > -1)
		{
			fw -= 1;
			rra(a, b, g);
		}
	else
		while (fw < c - 1)
		{
			fw += 1;
			ra(a, b, g);
		}
	*b && last(*b) > prelast(*b) ? ss(a, b, g) : sa(a, b, g);
	return (1);
}

int		algo_1(t_stack **a, t_stack **b, t_gen *g)
{
	int	w;
	int	c;

	c = count(*a);
	if ((w = where_1(*a)) <= c / 2)
		while (w)
		{
			w -= 1;
			rra(a, b, g);
		}
	else
		while (w != c)
		{
			w += 1;
			ra(a, b, g);
		}
	return (w == c ? 0 : w);
}
