/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:20:48 by yessemna          #+#    #+#             */
/*   Updated: 2024/03/02 17:21:49 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


static void handle_msg(int sig, siginfo_t *info, void *unused)
{
    static unsigned char c = 0;
    static int i = 0;
    static int cur_PID;

    if (cur_PID == 0)
        cur_PID = info->si_pid;
    else if(cur_PID != info->si_pid)
    {
        c = 0;
        i = 0;
        cur_PID = info->si_pid;
    }
    
    if (sig == SIGUSR1)
        c = c | (1 << 7);
    i++;
    if (i == 8)
    {
        if (c == 0)
            write(1, "\n", 1);
        else
            write(1, &c, 1);
        i = 0;
        c = 0;
    }
}

int main()
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_msg;
    printf("Server is running : %d\n", getpid());
    // signal(SIGUSR1, handle_msg);
    // signal(SIGUSR2, handle_msg);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return 0;
}