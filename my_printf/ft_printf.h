/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:48:51 by cmetee-b          #+#    #+#             */
/*   Updated: 2024/11/28 16:30:52 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_conv_base(char spec, long n, int base);
int		ft_put_adress_ptr(void *ptr);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(int nbr);

#endif
