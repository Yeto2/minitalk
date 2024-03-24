/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:20:53 by yessemna          #+#    #+#             */
/*   Updated: 2024/03/24 05:38:48 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	parse_pid(const char *str)
{
	int	pid;

	pid = 0;
	while (1)
	{
		if (*str == 0)
			return (pid);
		if ((*str < '0') || (*str > '9'))
			return (0);
		pid = 10 * pid + (*str++ - '0');
		if (pid > 99998)
			return (0);
	}
	return (0);
}

void	kill_if_valid(int pid, int sig)
{
	if (kill(pid, 0) == -1)
		print_error("invalid pid");
	kill(pid, sig);
}

void	send_bytes(int pid, unsigned char c)
{
	int	i;
	int	j;

	i = 0;
	j = 7;
	while (j >= 0)
	{
		if (((c >> j) & 1) == 0)
			kill_if_valid(pid, SIGUSR2);
		else
			kill_if_valid(pid, SIGUSR1);
		j--;
		usleep(500);
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		i;
	char	*str;

	i = 0;
	if (argc == 3)
	{
		str = argv[2];
		pid = parse_pid(argv[1]);
		if (pid <= 0)
			print_error("invalid PID!");
		while (str[i])
			send_bytes(pid, str[i++]);
	}
	else
		print_error("invalid number of arguments");
	return (0);
}
