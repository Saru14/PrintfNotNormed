/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdori.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:20:04 by jbodson           #+#    #+#             */
/*   Updated: 2020/03/11 13:27:25 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_isdori(long long nb, t_list *lst)
{
    int i;
	int x;
	int y;
	int numb1;
    int numb2;
	long long nb2;
	int k;
	int u;
	int o;
	int f;
	int g;
	int n;

	nb2 = nb;
    numb1 = 0;
    numb2 = 0;
	x = 0;
	y = 0;
	i = -1;
	u = 0;
	n = 0;
	if (lst->star1 > 0 || lst->star1 < 0)
        numb1 = lst->star1;
    else if (lst->nb1 > 0 || lst->nb1 < 0)
    {
        numb1 = lst->nb1;
    }
    if (lst->star2 > 0 || lst->star2 < 0)
        numb2 = lst->star2;
    else if (lst->nb2 > 0 || lst->nb2 < 0)
    {
        numb2 = lst->nb2;
    }
	k = numb2;
	if (numb2 < 0)
	{	
		lst->prec = 0;
		numb2 = 0;
	}
	if (!numb2 && !nb && lst->prec)
	{
		while (++i < numb1)
		{
			write(1, lst->zero ? "0" : " ", 1);
			lst->retour++;
		}
		return (numb1);
	}
	i =	ft_putnbr(nb, lst);
	o = numb2;

	if(nb < 0 && lst->prec == 1 && numb1 > numb2 && i < numb1 && lst->neg == 0)
			numb1--;
	while (lst->prec == 1 && numb1 > numb2 && i < numb1 && lst->neg == 0)
	{
		ft_putchar(' ', lst);
		numb1--;
	}
	if (lst->prec == 1 && i >= numb2 && nb < 0)
		ft_putchar('-', lst);
	while (lst->prec == 1 && i < numb2)
	{
		if (nb < 0 && x == 0)
		{
			ft_putchar('-', lst);
			x++;
		}
		ft_putchar('0', lst);
		numb2--;
	}
	if (lst->zero == 1 && nb < 0 && lst->prec == 0)
	{
		ft_putchar('-', lst);
		x++;
	}
	while (i < numb1 && lst->neg == 0 && lst->prec == 0)
	{
		if (lst->zero == 1)
		{
			if (x == 0 && nb < 0)
			{
				ft_putchar('-', lst);
				x++;
			}
			else if ((lst->zero == 1 && x == 0) || (lst->zero == 1 && i < numb1 - 1 && x == 1))
				ft_putchar('0', lst);
		}
		if (lst->zero == 0)
			ft_putchar(' ', lst);
		i++;
	}
	ft_putnbr2(nb2, lst, i);
	if (lst->neg == 1 && o >= i)
		u = -1;	
	f = 0;
	g = i;
	while (numb2 < g - 1)
	{	
		f++;
		g--;
	}
	if (lst->neg == 1 && lst->prec == 1)
	{
		i = k + 1 + u + f;
	}
	if (nb < 0 && lst->prec == 1 )
		i++;
	if (numb1 < 0)
	numb1 = -numb1;
	if (lst->zero == 1 && lst->prec == 0 && nb < 0)	
		i++;
	while (i < numb1 && lst->neg == 1)
	{
		ft_putchar(' ', lst);
		i++;
	}
	return (lst->retour);
}

void		ft_putchar(char c, t_list *lst)
{
	write (1, &c, 1);
	lst->retour++;
}

long long		ft_putnbr(long long nb, t_list *lst)
{
	static int i;
	if (lst->he == 0)
		i = 0;
	lst->he = 1;

	if (nb < 10 && nb >= 0)
		i++;
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10, lst);
		i++;
		if (nb < 0)
			if (lst->prec == 0 && lst->zero == 0)
				i++;
	}
	else
	{
		if (lst->prec == 0 && lst->zero == 0)
			i++;
		ft_putnbr(nb * -1, lst);
	}
		return(i);
}

long long		ft_putnbr2(long long nb, t_list *lst, int i)
{
	if (nb < 10 && nb >= 0)
	{
		ft_putchar(nb + '0', lst);
	}
	else if (nb >= 10)
	{
		ft_putnbr2(nb / 10, lst, i);
		ft_putchar(nb % 10 + '0', lst);
		if (nb < 0)
		{
			if (lst->prec == 0 && lst->zero == 0)
				ft_putchar('-', lst);
		}	
	}
	else
	{
		if (lst->prec == 0 && lst->zero == 0)
			ft_putchar('-', lst);
		ft_putnbr2(nb * -1, lst, i);
	}
	return (0);
} 