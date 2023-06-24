/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:56:05 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/18 13:56:05 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define FAILURE -1

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_signal
{
	int		bit_index;
	uint8_t	sum;
}	t_signal;

size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_isspace(int c);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);

#endif
