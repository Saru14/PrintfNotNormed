/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:11:07 by jbodson           #+#    #+#             */
/*   Updated: 2020/03/10 19:18:01 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putcharbase(char c, t_list *lst)
{
	write (1, &c, 1);
	lst->retour++;
}

int ft_ifx(long nb, t_list *lst, int t)
{
    int i;
	int x;
	int y;
	int numb1;
    int numb2;
	long nb2;
	int k;
	int u;
	int o;
	int f;
	int g;

	nb2 = nb;
    numb1 = 0;
    numb2 = 0;
	x = 0;
	y = 0;
	i = -1;
	u = 0;
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
	if(numb2 < 0)
		lst->prec = 0;
	k = numb2;
	if (numb1 < 0)
	numb1 = -numb1;
	if (!numb2 && !nb && lst->prec)
	{
		while (++i < numb1)
		{		
			write(1, lst->zero ? "0" : " ", 1);
			lst->retour++;
		}
		return (numb1);
	}
	i =	ft_putnumberbase(nb, lst);
	if (nb == 0 && lst->prec == 0)
		i++;
	o = numb2;
	while (lst->prec == 1 && numb1 > numb2 && i < numb1 && lst->neg == 0)
	{
		if(nb < 0 && y == 0)
		{
			y++;
			numb1--;
		}
		ft_putcharbase(' ', lst);
		numb1--;
	}
	if (lst->prec == 1 && i >= numb2 && nb < 0)
		ft_putcharbase('-', lst);
	while (lst->prec == 1 && i < numb2)
	{
		if (nb < 0 && x == 0)
		{
			ft_putcharbase('-', lst);
			x++;
		}
		ft_putcharbase('0', lst);
		numb2--;
	}
	if (lst->zero == 1 && nb < 0 && lst->prec == 0)
	{
		ft_putcharbase('-', lst);
		x++;
	}
	if(i == numb2)
		i--;
	while (i < numb1 && lst->neg == 0 && lst->prec == 0)
	{
		if (lst->zero == 1)
		{
			if (x == 0 && nb < 0)
			{
				ft_putcharbase('-', lst);
				x++;
			}
			else if ((lst->zero == 1 && x == 0) || (lst->zero == 1 && i < numb1 - 1 && x == 1))
				ft_putcharbase('0', lst);
		}
		if (lst->zero == 0)
			ft_putcharbase(' ', lst);
		i++;
	}
	ft_putnumberbase2(nb2, t, lst);
	if (lst->neg == 1 && o > i)
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
	while (i < numb1 && lst->neg == 1)
	{
		ft_putcharbase(' ', lst);
		i++;
	}
    return (1);
}

int    ft_putnumberbase(long nb, t_list *lst)
{
      int i;
      char str[5000];
 
      i = 0;
      if (nb < 0)
      {
          nb = -nb;
          lst->i++;
      }
      while (nb)
      {
          str[i] = nb % 16;
          nb = nb / 16;
          i++;
      }
      while (--i >= 0)
          lst->i++;
	  return (lst->i);
}
 
void    ft_putnumberbase2(long nb, int t, t_list *lst)
{
      int i;
	  int j;
      char str[1234];
	  char *base;
	  
	  j = 0;
	  if (t == 1)
	  	base = "0123456789abcdef";
	  else
		base = "0123456789ABCDEF";
      i = 0;
      if (nb == 0 && lst->prec == 0 && j == 0)
	  {	
		  ft_putcharbase('0', lst);
		  return ;
	  }
	  if (nb < 0)
      {
          nb = -nb;
		  j++;
          ft_putcharbase('-', lst);
      }
      while (nb)
      {
          str[i] = nb % 16;
          nb = nb / 16;
          i++;
		  j++;
      }
      while (--i >= 0)
          ft_putcharbase (base[(int)str[i]], lst);
}
