/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfedorys <mfedorys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:33:37 by mfedorys          #+#    #+#             */
/*   Updated: 2024/05/09 17:02:53 by mfedorys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_str(char *str)
{
	int j;
	j = 0;
	while(str[j] != '\0')
	{
		write(1, &str[j], 1);
		j++;
	}
	return(j);
}

int ft_printf_spec_if (char c, va_list arguments_list)
{
	int count;

	count = 0;
	if(c == '%')
		 count += ft_print_c('%'); 
	else if(c == 's')
		count += print_str(va_arg(arguments_list, char *));
	else if(c == 'c')
		count += ft_print_c(va_arg(arguments_list, int));
	else if(c == 'i' || c == 'd')
		count += ft_putnbr(va_arg(arguments_list, int));
	else if(c == 'x')
 		count += ft_putnbr_hex(va_arg(arguments_list, unsigned int), 0);
	else if(c == 'X')
 		count += ft_putnbr_hex(va_arg(arguments_list, int), 1);
	else if(c == 'u')
		count += ft_putnbr(va_arg(arguments_list, unsigned int));
	else if(c == 'p')
	{
		count += print_str("0x");
		count += ft_putnbr_hex((long long)va_arg(arguments_list, void *), 0);
	}
	return(count);
}

int ft_printf_spec(const char *str, va_list arguments_list)
{
	int	count_writes;
	int i;

	i = 0;
	count_writes = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '%')
		{
			count_writes += ft_printf_spec_if(str[i+1], arguments_list);
			i += 2;
		}
		else 
		{
			write(1, &str[i], 1);
			count_writes++;
			i++;
		}
	}
	return(count_writes);
}