/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:22:57 by yessemna          #+#    #+#             */
/*   Updated: 2024/03/21 00:49:55 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int n);
void	put_char(char c);
void	print_error(char *str);
void	print_all(int *str);
int		check_bytes(int sum);
void	params(int *sum, int *checker, int *bits_num, int *curpid);
void	set_params(int *bits_num, int *index, int *cur, int curpid);
#endif