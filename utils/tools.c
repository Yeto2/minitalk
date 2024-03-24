/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:55:52 by yessemna          #+#    #+#             */
/*   Updated: 2024/03/20 21:31:16 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	set_params(int *bits_num, int *index, int *cur, int curpid)
{
	*bits_num = 0;
	*index = 0;
	*cur = curpid;
}

void	print_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	print_all(int *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		put_char(str[i]);
		i++;
	}
}

int	check_bytes(int sum)
{
	int	j;
	int	x;

	j = 7;
	x = 0;
	while (j >= 0)
	{
		if (((sum >> j) & 1) == 0)
			return (x);
		else
			x++;
		j--;
	}
	return (x);
}

void	params(int *sum, int *checker, int *bits_num, int *curpid)
{
	if (*sum == 0)
	{
		put_char(*sum);
		kill(*curpid, SIGUSR1);
	}
	if (*checker == 0)
	{
		*bits_num = check_bytes(*sum);
		if (bits_num > 0)
			*checker = 1;
	}
}
