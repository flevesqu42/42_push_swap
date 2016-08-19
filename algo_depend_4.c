/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_depend_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 03:45:58 by flevesqu          #+#    #+#             */
/*   Updated: 2016/03/08 05:34:06 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3_bis(t_stack **a, t_stack **b, t_gen *g)
{
	int w;
	int c;

	w = where_3(*b, min(*b));
	c = count(*b);
	if (w <= c / 2)
		while (w > 0)
		{
			w -= 1;
			rrb(a, b, g);
		}
	else
		while (w < c)
		{
			w += 1;
			rb(a, b, g);
		}
	pa(a, b, g);
}

int		def_check(t_stack *a, int *s, int *t, int *v)
{
	*s = check_2(a);
	*t = check_3(a);
	*v = check_5(a);
	return (check(a));
}
