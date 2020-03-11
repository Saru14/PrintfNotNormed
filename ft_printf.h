/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:54:29 by jbodson           #+#    #+#             */
/*   Updated: 2020/03/10 19:04:17 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdarg.h>

typedef struct s_list
{
    int zero;
    int neg;
    int nb1;
    int nb2;
    int prec;
    int len;
    int star1;
    int star2;
    int i;
    int he;
    int retour;
}               t_list;

int		    ft_printf(const char *format, ...);
void        ft_ifs(char *str, t_list *lst);
int         ft_ifp(unsigned long nb, t_list *lst);
int         ft_ifx(long nb, t_list *lst, int t);
int         ft_isdori(long long nb, t_list *lst);
void	    ft_putchar(char c, t_list *lst);
long long	ft_putnbr(long long nb, t_list *lst);
int         ft_ifc(int c, t_list *lst);
void        lstinit(t_list *lst);
long long	ft_putnbr2(long long nb, t_list *lst, int i);
int         ft_putnumberbase(long nb, t_list *lst);
void        ft_putnumberbase2(long nb, int t, t_list *lst);
void		ft_putcharbase(char c, t_list *lst);
void        ft_putnumberbase2p(unsigned long nb, t_list *lst);
int         ft_putnumberbasep(unsigned long nb, t_list *lst);
void		ft_putcharbasep(char c, t_list *lst);

#endif