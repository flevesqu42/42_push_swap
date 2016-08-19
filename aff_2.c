/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 03:28:20 by flevesqu          #+#    #+#             */
/*   Updated: 2016/03/08 05:37:06 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **a, t_stack **b, t_gen *g)
{
	if (!(g->flags & 0x8))
		g->aff = g->aff ? ft_strscat(g->aff, " rr") : ft_strdup("rr");
	rotate(a);
	rotate(b);
	g->nb += 1;
	if (g->flags & 0x1)
		display_stacks(*a, *b, g);
}

void	rra(t_stack **a, t_stack **b, t_gen *g)
{
	if (!(g->flags & 0x8))
		g->aff = g->aff ? ft_strscat(g->aff, " rra") : ft_strdup("rra");
	rev_rotate(a);
	g->nb += 1;
	if (g->flags & 0x1)
		display_stacks(*a, *b, g);
}

void	rrb(t_stack **a, t_stack **b, t_gen *g)
{
	if (!(g->flags & 0x8))
		g->aff = g->aff ? ft_strscat(g->aff, " rrb") : ft_strdup("rrb");
	rev_rotate(b);
	g->nb += 1;
	if (g->flags & 0x1)
		display_stacks(*a, *b, g);
}

void	rrr(t_stack **a, t_stack **b, t_gen *g)
{
	if (!(g->flags & 0x8))
		g->aff = g->aff ? ft_strscat(g->aff, " rrr") : ft_strdup("rrr");
	rev_rotate(a);
	rev_rotate(b);
	g->nb += 1;
	if (g->flags & 0x1)
		display_stacks(*a, *b, g);
}
