/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 02:25:53 by flevesqu          #+#    #+#             */
/*   Updated: 2016/03/03 18:25:58 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*current_a;
	t_stack *current_b;

	current_a = *a;
	current_b = *b;
	if (!*a)
		return ;
	while (current_a->next && current_a->next->next)
		current_a = current_a->next;
	if (current_b)
	{
		while (current_b->next)
			current_b = current_b->next;
		if (current_a->next)
			current_b->next = current_a->next;
		else
			current_b->next = current_a;
	}
	else
		*b = current_a->next;
	if (current_a->next)
		current_a->next = NULL;
	else
		*a = NULL;
}

void	swap(t_stack *s)
{
	int	tmp;

	if (!s || !s->next)
		return ;
	while (s->next->next)
		s = s->next;
	tmp = s->content;
	s->content = s->next->content;
	s->next->content = tmp;
	tmp = s->pos;
	s->pos = s->next->pos;
	s->next->pos = tmp;
}

void	rev_rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*current;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	*s = (*s)->next;
	current = *s;
	while (current->next)
		current = current->next;
	current->next = first;
	current->next->next = NULL;
}

void	rotate(t_stack **s)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!*s || !(*s)->next)
		return ;
	current = *s;
	while (current->next->next)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = *s;
	*s = tmp;
}

int		ps_atoi(char *str)
{
	long	result;
	char	sign;

	result = 0;
	if (*str == '+' || *str == '-')
	{
		sign = *str;
		str += 1;
	}
	else
		sign = '+';
	if (!*str)
		error(1);
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str += 1;
	}
	if (sign == '-')
		result = -result;
	if (*str || result > 2147483647 || result < -2147483648)
		error(1);
	return (result);
}
