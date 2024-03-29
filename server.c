/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:56:15 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/18 13:56:15 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_signal	g_signal;

void	reset_signal(void)
{
	g_signal.sum = 0;
	g_signal.bit_index = 8;
}

void	print_pid(void)
{
	ft_putstr_fd("pid:", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_signal.sum += (0b100000000 >> g_signal.bit_index);
	if (g_signal.bit_index == 1)
	{
		ft_putchar_fd(g_signal.sum, 1);
		reset_signal();
		return ;
	}
	g_signal.bit_index--;
}

int	main(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	reset_signal();
	print_pid();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
