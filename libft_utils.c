/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:56:37 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/21 22:56:37 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putchar_fd(char c, int fd)
{
	ssize_t	ret;

	ret = write(fd, &c, 1);
	if (ret == -1)
		ft_putstr_fd("Error: write()", 2);
}

void	ft_putstr_fd(char *s, int fd)
{
	ssize_t	ret;

	if (s == NULL)
		return ;
	ret = write(fd, s, ft_strlen(s));
	if (ret == -1)
		ft_putstr_fd("Error: write()", 2);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	ft_putchar_fd((nb % 10) + '0', fd);
}
