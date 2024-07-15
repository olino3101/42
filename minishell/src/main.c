/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:20:03 by msimard           #+#    #+#             */
/*   Updated: 2024/07/15 13:40:05 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_history(char *cmd)
{
	HIST_ENTRY	*my_hist;
	
	if(!cmd || !*cmd)
	return ;
	add_history(cmd);
	my_hist = history_get(1);
}

static void	ft_parser(t_data *data)
{
	char	*str;
	int		check;

	str = data->input;
	check = ft_check_quote_dollar(str, data->envp);
	if (check)
		ft_get_cmd(ft_parsecmd(data->input), data);
}

bool alloc_envp(t_data *data, char **envp)
{
	int i = 0;

	while (envp[i])
		i++;
	data->envp = malloc(i * sizeof(char *));
	if (!data->envp)
		return (false);
	i = 0;
	while (envp[i])
	{
		data->envp[i] = ft_strdup(envp[i]);
		if (!data->envp[i])
		{
			ft_free(data->envp, "Error allocing memory");
			return (false);
		}
		i++;
	}
	data->envp[i] = NULL;
	return true;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	 
	signal(SIGQUIT, SIG_IGN);
	ft_init_signal();
	data = malloc(sizeof(t_data));
	if (!data && printf("Error allocing memory"))
		return (0);
	alloc_envp(data, envp);
	if (isatty(STDIN_FILENO)) //fonction qui verifie si shell en mode interactive, mais pas util, on peut enlever
	{
		while (argc && argv)
		{
			data->input = readline(PROMPT);
			if (data->input == NULL)
			{
				ft_printf("\nEXIT\n");
				break ;
			}
			else
				ft_history(data->input);
			ft_parser(data);
			free(data->input);//obligatoire sinon leaks!!
		}
	}
	return (0);
	//else // shell no interactive ?
	//free(data);
}