/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:20:48 by yessemna          #+#    #+#             */
/*   Updated: 2024/03/08 16:48:16 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void put_str(char c)
{
    write(1,&c,1);
}
static void handle_msg(int sig, siginfo_t *info, void *unused)
{
    (void)unused;
    static int i;
    static int sum;
    static int cur_PID;
    int arr[]={128,64,32,16,8,4,2,1};

    if (cur_PID == 0)
        cur_PID = info->si_pid;
    else if(cur_PID != info->si_pid)
    {
        sum = 0;
        i = 0;
        cur_PID = info->si_pid;
    }
    if(sig == 30)
        sum+= arr[i];
    i++;
    if (i == 8)
    {
        if (sum == 0)
            write(1, "\n", 1);
        else
            put_str(sum);
        i = 0;
        sum = 0;
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