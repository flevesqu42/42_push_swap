/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 00:33:35 by flevesqu          #+#    #+#             */
/*   Updated: 2016/03/08 05:10:30 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_gen	*gen;
	t_stack	*first;
	t_stack	*current;

	if (ac == 1)
		return (ft_printf("\n"));
	if (!(gen = (t_gen*)malloc(sizeof(t_gen))))
		error(1);
	gen->flags = 0;
	while (def_opt(av[ac - 1], gen))
		ac -= 1;
	first = new_stack(ps_atoi(av[ac - 1]));
	current = first;
	ac -= 1;
	while (--ac)
		if (!def_opt(av[ac], gen))
		{
			control_stack(ps_atoi(av[ac]), first);
			current->next = new_stack(ps_atoi(av[ac]));
			current = current->next;
		}
	def_pos(first);
	enter_game(first, gen);
	free_stack(first);
	return (0);
}

int		def_opt(char *av, t_gen *gen)
{
	if (*av == '-')
	{
		if (!*(av + 1))
			error(2);
		av += 1;
		while (*av)
		{
			if (*av == 'v')
				gen->flags |= 0x1;
			else if (*av == 'f')
				gen->flags |= 0x2;
			else if (*av == 'n')
				gen->flags |= 0x4;
			else if (*av == 'h')
				gen->flags |= 0x8;
			else if (*av >= '0' && *av <= '9')
				return (0);
			else
				error(2);
			av += 1;
		}
		return (1);
	}
	return (0);
}

void	control_stack(int nb, t_stack *first)
{
	while (first)
	{
		if (first->content == nb)
			error(1);
		first = first->next;
	}
}

void	display_stacks(t_stack *a, t_stack *b, t_gen *g)
{
	char	*str;

	str = ft_strdup("[");
	str = ft_strscat(str, ft_itoa(g->nb));
	str = ft_strscat(str, "]\n\x1B[32ma: ");
	while (a)
	{
		str = ft_strscat(str, ft_itoa(a->content));
		str = ft_strscat(str, " ");
		a = a->next;
	}
	str = ft_strscat(str, "\x1B[31m\nb: ");
	while (b)
	{
		str = ft_strscat(str, ft_itoa(b->content));
		str = ft_strscat(str, " ");
		b = b->next;
	}
	str = ft_strscat(str, "\x1B[0m\n");
	ft_putstr(str);
	free(str);
}

void	display_pos(t_stack *a, t_stack *b, t_gen *g)
{
	char	*str;

	str = ft_strdup("[");
	str = ft_strscat(str, ft_itoa(g->nb));
	str = ft_strscat(str, "]\n\x1B[32ma: ");
	while (a)
	{
		str = ft_strscat(str, ft_itoa(a->pos));
		str = ft_strscat(str, " ");
		a = a->next;
	}
	str = ft_strscat(str, "\x1B[31m\nb: ");
	while (b)
	{
		str = ft_strscat(str, ft_itoa(b->pos));
		str = ft_strscat(str, " ");
		b = b->next;
	}
	str = ft_strscat(str, "\x1B[0m\n");
	ft_putstr(str);
	free(str);
}
