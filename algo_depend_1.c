/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_depend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 03:37:17 by flevesqu          #+#    #+#             */
/*   Updated: 2016/03/08 05:36:34 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count(t_stack *s)
{
	int total;

	total = 0;
	while (s)
	{
		total += 1;
		s = s->next;
	}
	return (total);
}

int	check(t_stack *s)
{
	int	count;

	count = 0;
	while (s->next)
	{
		if (s->next->pos != s->pos + 1)
			count += 1;
		s = s->next;
	}
	return (count);
}

int	where_1(t_stack *s)
{
	int	w;

	w = 0;
	while (s->next)
	{
		w += 1;
		if (s->next->pos < s->pos)
			return (w);
		s = s->next;
	}
	return (0);
}

int	where_2(t_stack *s)
{
	int		w;
	int		mn;
	int		mx;
	t_stack *f;

	w = 0;
	f = s;
	mn = min(f);
	mx = max(f);
	while (s->next)
	{
		w += 1;
		if (s->next->pos == s->pos - 1 || (s->next->pos == mx && s->pos == mn))
			return (w);
		s = s->next;
	}
	if (f->pos == s->pos - 1 || (f->pos == mx && s->pos == mn))
		return (w + 1);
	return (0);
}

int	where_3(t_stack *s, int search)
{
	int w;

	w = 0;
	while (s)
	{
		w += 1;
		if (s->pos == search)
			return (w);
		s = s->next;
	}
	return (0);
}
