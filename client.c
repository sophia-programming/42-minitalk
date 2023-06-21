/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:56:00 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/18 13:56:00 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(int pid, char *literal)
{
	int	i;
	int	ch;

	while (*literal)
	{
		i = 0;
		while (i < 8)
		{
			usleep(1000);
			if (((*literal >> i) & 1) == 1)
				ch = kill(pid, SIGUSR1);
			else
				ch = kill(pid, SIGUSR2);
			if (ch == FAILURE)
			{
				ft_putstr_fd("error\n", 2);
				exit(1);
			}
			i++;
		}
		literal++;
	}
}

void	print_sent_message(int fd, char *message, char *arg)
{
	ft_putstr_fd(message, fd);
	ft_putnbr_fd(ft_strlen(arg), fd);
	ft_putchar_fd('\n', fd);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr_fd("error\n", 2);
		exit(1);
	}
	print_sent_message(1, "Sent    : ", argv[2]);
	pid = ft_atoi(argv[1]);
	send_sig(pid, argv[2]);
	return (0);
}
