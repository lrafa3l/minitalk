/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <lrafael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:42:31 by lrafael           #+#    #+#             */
/*   Updated: 2024/10/05 15:15:14 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	send_bits(char byte, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (byte & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		--i;
		usleep(50);
	}
}

int	ft_atoi(char *s)
{
	int	rt;

	rt = 0;
	while (*s && (*s >= '0' && *s <= '9'))
		rt = (rt * 10) + (*(s++) - '0');
	return (rt);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(1, "Usage:\n./client <PID> [string]\n", 32);
		return (0);
	}
	while (argv[2][i])
		send_bits(argv[2][i++], ft_atoi(argv[1]));
	send_bits('\n', ft_atoi(argv[1]));
	return (0);
}
