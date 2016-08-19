/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 03:31:37 by flevesqu          #+#    #+#             */
/*   Updated: 2016/03/08 03:48:13 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, t_gen *g)
{
	if (!(g->flags & 0x8))
		g->aff = g->aff ? ft_strscat(g->aff, " pa") : ft_strdup("pa");
	push(b, a);
	g->nb += 1;
	if (g->flags & 0x1)
		display_stacks(*a, *b, g);
}

void	pb(t_stack **a, t_stack **b, t_gen *g)
{
	if (!(g->flags & 0x8))
		g->aff = g->aff ? ft_strscat(g->aff, " pb") : ft_strdup("pb");
	push(a, b);
	g->nb += 1;
	if (g->flags & 0x1)
		display_stacks(*a, *b, g);
}
