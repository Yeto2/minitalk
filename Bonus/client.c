/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:20:53 by yessemna          #+#    #+#             */
/*   Updated: 2024/03/08 21:58:05 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void print_error(char *str)
{
    ft_putendl_fd(str, 2);
    exit(1);
}
int is_valid_pid(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            print_error("invalid pid");
        i++;
    }
    return 1;
}

void kill_if_valid(int pid, int sig)
{
    if (kill(pid, 0) == -1)
        print_error("invalid pid");
    kill(pid, sig);
}

void send_bytes(int pid, unsigned char c)
{
    int i;
    int j;

    i = 0;
    j = 7;
    while (j >= 0)
    {
        if (((c >> j) & 1) == 0)
            kill_if_valid(pid, SIGUSR2);
            // kill(pid, SIGUSR2);
        else
            kill_if_valid(pid, SIGUSR1);
            // kill(pid, SIGUSR1);
        j--;
        usleep(500);
    }
}

int main(int argc, char *argv[])
{
    int pid;
    int i;
    // int j;
    // char c;
    char *str;

    i = 0;
    if (argc == 3)
    {
        is_valid_pid(argv[1]);
        pid = ft_atoi(argv[1]);
        
        str = argv[2];
        while (str[i])
            send_bytes(pid, str[i++]);
    }
    else
        print_error("invalid number of arguments");
    return 0;
}
/*

i = 0;
        while (argv[2][i])
        {
            c = argv[2][i];
            j = 7;
            while (j >= 0)
            {
                if (((c >> j) & 1) == 0)
                    kill(pid, SIGUSR2);
                else
                    kill(pid, SIGUSR1);
                j--;
                usleep(500);
            }
            i++;
        }

*/