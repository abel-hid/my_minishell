/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:41:01 by abel-hid          #+#    #+#             */
/*   Updated: 2023/09/17 12:54:32 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	help_me(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
}

void	ft_echo(t_command *cmd)
{
	int		i;
	int		n;
	size_t	j;

	i = 1;
	n = 0;
	while (cmd->args[i] && cmd->args[i][0] == '-' && cmd->args[i][1] == 'n')
	{
		j = 1;
		while (cmd->args[i][j] && cmd->args[i][j] == 'n')
			j++;
		if (cmd->args[i][j] == '\0')
			n = 1;
		else
			break ;
		i++;
	}
	help_me(&cmd->args[i]);
	if (!n)
		ft_putstr_fd("\n", 1);
}
