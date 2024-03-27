/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:24:35 by onault            #+#    #+#             */
/*   Updated: 2024/03/25 18:07:17 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_col
{
	int	*sizeofc;
	int	*c;
}	t_col;
void	five_less(t_col *cola, t_col *colb);
void	pa_pb(t_col *cola, t_col *colb);
void	rra_rrb(t_col *col);
void	ra_rb(t_col *col);
void	insert_into_a(t_col *cola, char **argv);
void	free_col(t_col *cola, t_col *colb);
void	remove_gap(t_col *cola);
void	sa_sb(t_col *col);
void	three(t_col *cola);
int		is_semi_sorted(t_col *cola);
int		ft_strncmp(const char *s1, const char *s2);
int		ft_isalpha(int c);
int		check_arg(char **argv);
int		init_col(t_col *cola, t_col *colb, int argc);
int		is_sorted(t_col *cola);
long	ft_atoi(const char *str);

#endif
