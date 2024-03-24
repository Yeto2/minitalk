/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:20:48 by yessemna          #+#    #+#             */
/*   Updated: 2024/03/20 21:32:45 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int		g_str[4];

void	set_vars(int *checker)
{
	g_str[0] = 0;
	g_str[1] = 0;
	g_str[2] = 0;
	g_str[3] = 0;
	*checker = 0;
}

void	handle_byte(int *checker, int *g_str, int *sum, int *curpid)
{
	static int	index;
	static int	bits_num;
	static int	cur;

	if (cur == 0)
		cur = *curpid;
	else if (cur != *curpid)
		set_params(&bits_num, &index, &cur, *curpid);
	params(sum, checker, &bits_num, &cur);
	if (*checker == 0)
		put_char(*sum);
	else
	{
		g_str[index++] = *sum;
		if (bits_num == 1)
		{
			print_all(g_str);
			bits_num = 0;
			*checker = 0;
			index = 0;
		}
		bits_num = bits_num - 1;
	}
	*sum = 0;
}

void	do_sum(int sig, int *sum, int *i)
{
	int	arr[8];

	arr[0] = 128;
	arr[1] = 64;
	arr[2] = 32;
	arr[3] = 16;
	arr[4] = 8;
	arr[5] = 4;
	arr[6] = 2;
	arr[7] = 1;
	if (sig == 30)
		*sum += arr[*i];
	*i = *i + 1;
}

static void	handle_msg(int sig, siginfo_t *info, void *unused)
{
	static int	i;
	static int	sum;
	static int	checker;
	static int	curpid;

	(void)unused;
	if (curpid == 0)
		curpid = info->si_pid;
	else if (curpid != info->si_pid)
	{
		sum = 0;
		i = 0;
		checker = 0;
		set_vars(&checker);
		curpid = info->si_pid;
	}
	do_sum(sig, &sum, &i);
	if (i == 8)
	{
		handle_byte(&checker, g_str, &sum, &curpid);
		i = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("Error : No arguments needed\n", 2);
		exit(1);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_msg;
	ft_putstr_fd("Server is running: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
