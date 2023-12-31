/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:41:25 by abel-hid          #+#    #+#             */
/*   Updated: 2023/09/16 16:41:28 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	error_ambiguous(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ambiguous redirect\n", 2);
}

int	ambiguous_redirect(char *str, t_env **g_env, char *str_next)
{
	char	*str1;

	(void)g_env;
	str1 = ft_strdup(str);
	str_next = ft_delete(str_next);
	str = del_quote(str, '\'', '\"');
	if (!is_dquote(str_next) && more_than_one(str) == 1)
	{
		error_ambiguous(str1);
		return (1);
	}
	free(str1);
	return (0);
}
