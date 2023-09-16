/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:41:50 by heddahbi          #+#    #+#             */
/*   Updated: 2023/08/11 19:49:35 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	line_managment(char *line)
{
	if (line && *line)
		add_history(line);
	if (line == NULL)
	{
		printf("exit\n");
		exit(0);
	}
}

void	free_stuff(char *line, t_lexer **lexer, t_command **cmd)
{
	free_lexer_list(lexer);
	free_cmd_list(cmd);
	free(line);
}

void	action(struct sigaction *sa)
{
	sigaction(SIGINT, sa, NULL);
	sigaction(SIGQUIT, sa, NULL);
}

int	minishell_prime(char *line)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (1);
	}
	return (0);
}

void	parsing_all(t_lexer **lexer, t_command **cmd, t_env **p_env, char **env)
{
	parse_args(lexer, cmd, p_env);
	g_exit_st.in_cmd = 1;
	execute_the_shot(*cmd, p_env, env);
	close_everythiang(cmd);
	g_exit_st.in_cmd = 0;
}
