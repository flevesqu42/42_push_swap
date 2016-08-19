/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_depend_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 03:40:46 by flevesqu          #+#    #+#             */
/*   Updated: 2016/03/08 05:30:42 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_where_2(t_stack *s)
{
	int		l;
	int		w;
	int		mn;
	int		mx;
	t_stack *f;

	w = 0;
	l = 0;
	f = s;
	mn = min(f);
	mx = max(f);
	while (s->next)
	{
		w += 1;
		if (s->next->pos == s->pos - 1 || (s->next->pos == mx && s->pos == mn))
			l = w;
		s = s->next;
	}
	if (f->pos == s->pos - 1 || (f->pos == mx && s->pos == mn))
		l = w + 1;
	return (l);
}

int	check_2(t_stack *s)
{
	int		c;
	int		mi;
	int		ma;
	t_stack *f;

	c = 0;
	f = s;
	mi = min(f);
	ma = max(f);
	while (s->next)
	{
		if (s->next->pos == s->pos - 1 || (s->next->pos == ma && s->pos == mi))
		{
			if (s->next->next && (s->next->next->pos == s->next->pos - 1
						|| (s->next->next->pos == ma && s->next->pos == mi)))
				c += 1;
			c += 1;
		}
		s = s->next;
	}
	if (f->pos == s->pos - 1 || (f->pos == ma && s->pos == mi))
		c += 1;
	return (c);
}

int	check_3(t_stack *s)
{
	int		c;
	int		i;
	int		a;
	t_stack *f;

	c = 0;
	f = s;
	i = min(f);
	a = max(f);
	while (s->next->next)
	{
		if (s->next->pos == s->pos - 1 || (s->next->pos == a && s->pos == i))
		{
			if (s->next->next->pos == s->next->pos - 1
					|| (s->next->next->pos == a && s->next->pos == i))
				c += 1;
		}
		s = s->next;
	}
	if (((s->next->pos == s->pos - 1 || (s->next->pos == a && s->pos == i))
		&& (f->pos == s->next->pos - 1 || (f->pos == a && s->next->pos == i)))
		|| ((f->pos == s->next->pos - 1 || (f->pos == a && s->next->pos == i))
		&& (f->next->pos == f->pos - 1 || (f->next->pos == a && f->pos == i))))
		c += 1;
	return (c);
}

int	check_4(t_stack *a)
{
	int	mi;
	int	ma;

	ma = max(a);
	mi = min(a);
	while (a->next)
	{
		if (a->next->pos < a->pos && (a->next->pos != mi || a->pos != ma))
			return (1);
		a = a->next;
	}
	return (0);
}

int	check_5(t_stack *a)
{
	int	mi;
	int	ma;
	int	count;

	mi = min(a);
	ma = max(a);
	count = 0;
	while (a->next)
	{
		if (a->next->pos == a->pos - 1 && (a->next->next
				&& a->next->next->pos != a->pos + 1
				&& a->next->next->pos != a->pos + 2))
			count += 1;
		a = a->next;
	}
	return (count);
}
