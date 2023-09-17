/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:01:56 by heddahbi          #+#    #+#             */
/*   Updated: 2023/09/17 12:46:50 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_child_process(t_command *cmd, int *fd, int old)
{
	close(fd[0]);
	if (cmd->next)
	{
		dup2(fd[1], 1);
		close(fd[1]);
	}
	if (old != -1)
	{
		dup2(old, 0);
		close(old);
	}
	handle_one_command(cmd);
}

void	protection(int *fd)
{
	if (pipe(fd) != 0)
	{
		perror("failed to create a pipe");
		return ;
	}
}

void	wait_for_all(t_command *cmd)
{
	int	s;

	s = 0;
	while (cmd)
	{
		waitpid(cmd->pid, &s, 0);
		cmd = cmd->next;
	}
	if (s != 0)
		g_exit_st.status = s / 256;
	if (s == 0 && g_exit_st.status != 130 && g_exit_st.status != 131)
		g_exit_st.status = 0;
}

void	close_old(int old, int *fd)
{
	close(fd[1]);
	if (old != -1)
		close(old);
}
