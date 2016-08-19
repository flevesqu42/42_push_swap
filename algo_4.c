/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 07:02:30 by flevesqu          #+#    #+#             */
/*   Updated: 2016/03/08 05:41:30 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_4(t_stack **a, t_stack **b, t_gen *g)
{
	g->a = a;
	g->b = b;
	if (g->total > 350)
	{
		algo_4_b(g, g->total / 2);
		algo_4_c(g, g->total / 2);
		while (check(*a))
			algo_3(a, b, g);
	}
	else
		algo_4_bis(g, g->total / 2);
	while (*b)
		algo_3_bis(a, b, g);
}

void	algo_4_bis(t_gen *g, int piv)
{
	int	index;
	int	c;

	index = count(*g->a);
	while ((c = check(*g->a)) && index)
	{
		if (last(*g->a) > piv)
		{
			pb(g->a, g->b, g);
			if (last(*g->a) > piv && (*g->b && (*g->b)->next)
					&& last(*g->b) > (piv * 2) - (piv / 2))
				rb(g->a, g->b, g);
		}
		else if ((*g->b && (*g->b)->next)
				&& last(*g->b) > (piv * 2) - (piv / 2))
			rr(g->a, g->b, g);
		else
			ra(g->a, g->b, g);
		while (c && algo_4_a(g->a, g->b, g))
			c = check(*g->a);
		index--;
	}
	if (c)
		algo_4_bis(g, piv / 2);
}

void	algo_4_b(t_gen *g, int piv)
{
	int	index;

	index = count(*g->a);
	while (index)
	{
		if (last(*g->a) > piv)
		{
			pb(g->a, g->b, g);
			if (last(*g->a) > piv && (*g->b && (*g->b)->next)
					&& last(*g->b) > (piv * 2) - (piv / 2))
				rb(g->a, g->b, g);
		}
		else
		{
			if ((*g->b && (*g->b)->next) && last(*g->b) > (piv * 2) - (piv / 2))
				rr(g->a, g->b, g);
			else
				ra(g->a, g->b, g);
		}
		index--;
	}
	if (count(*g->a) > 1)
		algo_4_b(g, piv / 2);
}

void	algo_4_c(t_gen *g, int piv)
{
	int	index;

	index = count(*g->b);
	while (index)
	{
		if (last(*g->b) < g->total - piv)
		{
			pa(g->a, g->b, g);
			if (((*g->a && (*g->a)->next)
						&& last(*g->a) > g->total - ((piv * 2) - (piv / 2))))
				ra(g->a, g->b, g);
		}
		else
		{
			if ((*g->a && (*g->a)->next)
					&& last(*g->a) > g->total - ((piv * 2) - (piv / 2)))
				rr(g->a, g->b, g);
			else
				rb(g->a, g->b, g);
		}
		index--;
	}
	if (count(*g->b) > 1)
		algo_4_c(g, piv / 2);
}

int		algo_4_a(t_stack **a, t_stack **b, t_gen *g)
{
	int c;
	int s;
	int t;
	int v;
	int m;

	c = def_check(*a, &s, &t, &v);
	m = count(*a);
	if (!t && c == 1 && !s && !check_4(*a))
		return (algo_1(a, b, g));
	else if (((!v && !t && s) || m < 5) && c <= m / 2 && (c == s + 1 || c == s)
			&& (first(*a) == last(*a) - 1
				|| (first(*a) == max(*a) && last(*a) == min(*a))))
	{
		rra(a, b, g);
		if (last(*b) > prelast(*b))
			ss(a, b, g);
		else
			sa(a, b, g);
		return (1);
	}
	else if (((!v && !t && s) || m < 5)
			&& (((c == s + 1 || c == s) && s < m / 2) || (c <= s / 2 && m < 5)))
		return (algo_2(a, b, g));
	return (0);
}
