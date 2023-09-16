/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 03:02:05 by heddahbi          #+#    #+#             */
/*   Updated: 2023/08/11 03:02:49 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_evetng_except(int fd1, int fd2, int fd3)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		if (i != fd1 && i != fd2 && i != fd3)
			close(i);
		i++;
	}
}

void	close_everythiang(t_command **cmd)
{
	t_command	*tmp;
	t_command	*tmp2;

	tmp = *cmd;
	close_evetng_except(0, 1, 2);
	while (tmp)
	{
		tmp2 = tmp->next;
		if (tmp->fd.fd_in != 0)
			close(tmp->fd.fd_in);
		if (tmp->fd.fd_out != 1)
			close(tmp->fd.fd_out);
		tmp = tmp2;
	}
}
