/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_depend_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 03:43:36 by flevesqu          #+#    #+#             */
/*   Updated: 2016/03/08 05:34:52 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_stack *s)
{
	int max;

	max = s->pos;
	while (s)
	{
		if (s->pos > max)
			max = s->pos;
		s = s->next;
	}
	return (max);
}

int	min(t_stack *s)
{
	int min;

	min = s->pos;
	while (s)
	{
		if (s->pos < min)
			min = s->pos;
		s = s->next;
	}
	return (min);
}

int	first(t_stack *s)
{
	return (s->pos);
}

int	last(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s->pos);
}

int	prelast(t_stack *s)
{
	if (!s->next)
		return (s->content);
	while (s->next->next)
		s = s->next;
	return (s->pos);
}
