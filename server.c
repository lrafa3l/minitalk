/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <lrafael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:42:48 by lrafael           #+#    #+#             */
/*   Updated: 2024/10/05 15:15:18 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	handle(int sig)
{
	static int	i = 0;
	static char	ch = 0;

	ch = ch << 1;
	ch = ch | (sig == SIGUSR2);
	i++;
	if (i == 8)
	{
		write(1, &ch, 1);
		ch = 0;
		i = 0;
	}
}

void	ft_nbr(int n)
{
	if (n > 9)
		ft_nbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	main(void)
{
	ft_nbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, handle);
		signal(SIGUSR2, handle);
	}
	return (0);
}
