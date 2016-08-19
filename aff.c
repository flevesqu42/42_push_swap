/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 02:12:03 by flevesqu          #+#    #+#             */
/*   Updated: 2016/03/08 03:49:06 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, t_stack **b, t_gen *g)
{
	if (!(g->flags & 0x8))
		g->aff = g->aff ? ft_strscat(g->aff, " sa") : ft_strdup("sa");
	swap(*a);
	g->nb += 1;
	if (g->flags & 0x1)
		display_stacks(*a, *b, g);
}

void	sb(t_stack **a, t_stack **b, t_gen *g)
{
	if (!(g->flags & 0x8))
		g->aff = g->aff ? ft_strscat(g->aff, " sb") : ft_strdup("sb");
	swap(*b);
	g->nb += 1;
	if (g->flags & 0x1)
		display_stacks(*a, *b, g);
}

void	ss(t_stack **a, t_stack **b, t_gen *g)
{
	if (!(g->flags & 0x8))
		g->aff = g->aff ? ft_strscat(g->aff, " ss") : ft_strdup("ss");
	swap(*a);
	swap(*b);
	g->nb += 1;
	if (g->flags & 0x1)
		display_stacks(*a, *b, g);
}

void	ra(t_stack **a, t_stack **b, t_gen *g)
{
	if (!(g->flags & 0x8))
		g->aff = g->aff ? ft_strscat(g->aff, " ra") : ft_strdup("ra");
	rotate(a);
	g->nb += 1;
	if (g->flags & 0x1)
		display_stacks(*a, *b, g);
}

void	rb(t_stack **a, t_stack **b, t_gen *g)
{
	if (!(g->flags & 0x8))
		g->aff = g->aff ? ft_strscat(g->aff, " rb") : ft_strdup("rb");
	rotate(b);
	g->nb += 1;
	if (g->flags & 0x1)
		display_stacks(*a, *b, g);
}
