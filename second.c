/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 03:33:36 by flevesqu          #+#    #+#             */
/*   Updated: 2016/03/08 04:56:45 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_fstack(t_stack *a, t_stack *b)
{
	ft_putstr("\x1B[32ma: ");
	while (a)
	{
		ft_putnbr(a->content);
		ft_putchar(' ');
		a = a->next;
	}
	ft_putchar('\n');
	ft_putstr("\x1B[31mb: ");
	while (b)
	{
		ft_putnbr(b->content);
		ft_putchar(' ');
		b = b->next;
	}
	ft_putstr("\x1B[0m\n");
}

t_stack	*new_stack(int value)
{
	t_stack *new;

	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		error(1);
	new->next = NULL;
	new->content = value;
	return (new);
}

void	error(int r)
{
	if (r == 1)
		write(2, "Error\n", 6);
	else if (r == 2)
	{
		ft_putstr("Flags:\n-v = verbal mode.\n-f = display final stack.\n");
		ft_putstr("-h = hide moves.\n-n = display moves counter.\n");
	}
	exit(1);
}

void	def_pos(t_stack *a)
{
	t_stack *first;
	t_stack *current;

	first = a;
	current = first;
	while (current)
	{
		a = first;
		current->pos = count(first);
		while (a)
		{
			if (a->content < current->content)
				current->pos -= 1;
			a = a->next;
		}
		current = current->next;
	}
}

void	free_stack(t_stack *a)
{
	if (a->next)
		free_stack(a->next);
	free(a);
}
