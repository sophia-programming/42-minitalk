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

# define BIT_MAX 256
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
	pid_t	bit_index;
	pid_t	sum;
}	t_signal;

size_t	ft_strlen(char *str);
int		ft_putchar_fd(int c, char fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
int		ft_atoi(const char *str);

#endif