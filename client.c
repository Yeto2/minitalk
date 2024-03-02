/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:20:53 by yessemna          #+#    #+#             */
/*   Updated: 2024/03/02 17:22:00 by yessemna         ###   ########.fr       */
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
        // if(kill(pid, 0) == -1)
        // {
        //     printf("Error: Invalid PID\n");
        //     return 1;
        // }
        i = 0;
        while (argv[2][i])
        {
            c = argv[2][i];
            j = 0;
            while (j < 8)
            {
                if (c & 1)
                    kill(pid, SIGUSR1);
                else
                    kill(pid, SIGUSR2);
                printf("c = %d\n", c & 1);
                c = c >> 1;
                j++;
                usleep(500);
            }
            i++;
        }
    }
    return 0;
}