/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:43:03 by jbodson           #+#    #+#             */
/*   Updated: 2020/03/11 13:26:54 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

void     ft_parsing(const char *format, t_list *lst, int *i, va_list val)
{
    *i += 1;
    while ((format[*i] == '.' || format[*i] == '*' || format [*i] == '0' ||
     (format[*i] >= '0' && format[*i] <= '9') || format[*i] == '-') && format[*i])
    {
        if (format[*i] == '-' || format[*i] == '0')
        {
            if (format[*i] == '-')
                lst->neg = 1;
            while (format[*i + 1] == '-')
                *i += 1;
            if (format[*i] == '0')
                lst->zero = 1;
            *i += 1;
        }
        while (format[*i] >= '0' && format[*i] <= '9' && format[*i])
        {
            lst->nb1 = lst->nb1 * 10;
            lst->nb1 = lst->nb1 + format[*i] - 48;
            *i += 1;
        }
        if (format[*i] == '*')
        { 
            lst->star1 = va_arg(val, int);
            *i += 1;
            if(lst->star1 < 0)
                lst->neg = 1;
        }
        if (format[*i] == '.')
        {
            lst->prec = 1;
            *i += 1;
        }
        if (format[*i] == '*')
        {
            lst->star2 = va_arg(val, int);
            *i += 1;
        }
        while (format[*i] >= '0' && format[*i] <= '9' && format[*i])
        {
            lst->nb2 = lst->nb2 * 10;
            lst->nb2 = lst->nb2 + format[*i] - 48;
            *i += 1;
        }
    }
}
void  lstinit(t_list *lst)
{
    lst->zero = 0;
    lst->neg = 0;
    lst->nb1 = 0;
    lst->nb2 = 0;
    lst->prec = 0;
    lst->len = 0;
    lst->star1 = 0;
    lst->star2 = 0;
    lst->i = 0;
    lst->he = 0;
    lst->retour = 0;
}

int     ft_printf(const char *format, ...)
{
    int i;
    int len;
    va_list val;
    t_list lst;

    len = 0;
    lstinit(&lst);
    va_start(val, format);
    i = 0;
    while (format[i])
    {
        while (format[i] != '%' && format[i])
        {
            write(1, &format[i], 1);
            len++;
            i++;
            if (format[i] == '\0')
                return (len);
        }
        if (format[i] == '%')
        {
            lstinit(&lst);
            ft_parsing(format, &lst, &i, val);
            if (format[i] == '%')
            {
                ft_ifc('%', &lst);
                if (format[i + 1] == '-')
                    write(1, "-", 1);
                if (format[i + 1] == '0')
                    write(1, "0", 1);
                if (format[i + 1] == '*')
                    write(1, "*", 1);
            }
            if (format[i] == '%' && (format[i + 1] == 'c'|| format[i + 1] == 'd' || format[i + 1] == 'i'||
            format[i + 1] == 's' || format[i + 1] == 'p' || format[i + 1] == 'x' || format[i + 1] == 'X' ||
            format[i + 1] == 'u'))
                ft_ifc(format[i + 1], &lst);
            if (format[i] == 'c')
                ft_ifc(va_arg(val, int), &lst);
            if (format[i] == 's')
                ft_ifs(va_arg(val, char*), &lst);
            if (format[i] == 'd' || format[i] == 'i')
                ft_isdori(va_arg(val, int), &lst);
            if (format[i] == 'u')
                ft_isdori(va_arg(val, unsigned int), &lst);
            if (format[i] == 'x')
                ft_ifx(va_arg(val, unsigned int), &lst, 1);
            if (format[i] == 'X')
                ft_ifx(va_arg(val, unsigned int), &lst, 0);
            if (format[i] == 'p')
                ft_ifp((unsigned long)va_arg(val, void*), &lst);
            len = len + lst.retour;
        }
        i++;
        if (format[i + 1] == '%' && (format[i + 1] == 'c'|| format[i + 1] == 'd' || format[i + 1] == 'i'||
            format[i + 1] == 's' || format[i + 1] == 'x' || format[i + 1] == 'X' ||
            format[i + 1] == 'u'))
            i++;
    }
    va_end(val);
    return (len);
}