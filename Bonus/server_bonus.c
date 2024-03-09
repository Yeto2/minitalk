/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:20:48 by yessemna          #+#    #+#             */
/*   Updated: 2024/03/09 22:28:38 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int str[4];

void put_str(char c)
{
    write(1,&c,1);
}

int check_bytes(int sum)
{
    int j = 7;
    int x = 0;
    while (j >= 0)
    {
        if (((sum >> j) & 1) == 0)
            return x;
        else
            x++;
        j--;
    }
    return x;
}
void print_all(int *str)
{
    int i = 0;
    while (str[i])
    {
        put_str(str[i]);
        i++;
    }
    
}
void set_vars(int *bits_num, int *checker, int *index)
{
    str[0] = 0;
    str[1] = 0;
    str[2] = 0;
    str[3] = 0;
    *bits_num = 0;
    *checker = 0;
    *index = 0;
}
static void handle_msg(int sig, siginfo_t *info, void *unused)
{
    (void)unused;
    static int i;
    static int sum;
    static int checker;
    static int bits_num;
    static int index;
    static int cur_PID;
    int arr[]={128,64,32,16,8,4,2,1};
    if (cur_PID == 0)
        cur_PID = info->si_pid;
    else if(cur_PID != info->si_pid)
    {
        sum = 0;
        i = 0;
        checker = 0;
        set_vars(&bits_num, &checker, &index);
        
        cur_PID = info->si_pid;
    }
    if(sig == 30)
        sum+= arr[i];
    i++;
    if (i == 8)
    {
        if(checker == 0)
        {
            bits_num = check_bytes(sum);
            if(bits_num > 0)
                checker = 1;
        }
        if(checker == 0)
            put_str(sum);
        else
        {
            str[index] = sum;
            index++;
            if(bits_num == 1)
            {
                print_all(str);
                set_vars(&bits_num, &checker, &index);
            }
            bits_num--;
        }
        i = 0;
        sum = 0;
    }
}


//10110000 00000000 00000000 00000000
// int s[4]={11110000, 00000000, 00000000, 00000000};
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