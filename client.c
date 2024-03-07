/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:20:53 by yessemna          #+#    #+#             */
/*   Updated: 2024/03/06 12:32:06 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


int main(int argc, char *argv[])
{
    int pid;
    int i;
    int j;
    char c;
    if (argc > 1)
    {
        pid = atoi(argv[1]);
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
    }
    return 0;
}
