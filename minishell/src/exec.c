/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:03:55 by msimard           #+#    #+#             */
/*   Updated: 2024/07/15 13:40:01 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Fonction qui verifie le type de la commande (Built-in ou executable)
void	ft_check_cmd(t_data *data)
{
	if ((pipe(data->fd)) == -1)
		ft_error("Error with pipe");
	else if (ft_strncmp(data->args[0], "env", 4) == 0)
		ft_env_cmd(data->envp);
	else if (ft_strncmp(data->args[0], "export", 7) == 0)
		ft_export_cmd(data);
	else if (ft_strncmp(data->args[0], "cd", 3) == 0)
		ft_chdir((data->input) + 3);
	else if (ft_strncmp(data->args[0], "exit", 5) == 0)
		ft_exit_cmd(data);
	else if (ft_strncmp(data->input, "unset", 6) == 0)
		ft_cmd_unset(data);
	else
		ft_execute(data->input, data->envp, data);
}

//Fonction qui execute une commande.
void	ft_execute(char *commands, char **envp, t_data *data)
{
	char	**cmd_list;
	char	*cmd_path;

	//cmd_list = ft_split(commands, ' ');
	(void)commands;
	cmd_list = data->args;
	cmd_path = ft_search_path(cmd_list[0], envp);
	if (!cmd_path)
		ft_isbuilt(cmd_list);
	else
	{
		data->pid = fork();
		if (data->pid > 0)
			wait(NULL);
		else if (execve(cmd_path, cmd_list, envp) == -1)
			ft_error("Wrong command");
	}
}

//Fonction pour trouver le chemin d'un excutable.
char	*ft_search_path(char *command, char **envp)
{
	char	**all_paths;
	char	*true_path;
	char	*tmp_path;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	all_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (all_paths[i])
	{
		tmp_path = ft_strjoin(all_paths[i], "/");
		true_path = ft_strjoin(tmp_path, command);
		free(tmp_path);
		if (access(true_path, F_OK) == 0)
			return (true_path);
		free(true_path);
		i++;
	}
	ft_free(all_paths, NULL);
	return (NULL);
}

//Fonction pour executer une commande implementer dans l'ordi.
void	ft_isbuilt(char **list)
{
	int		i;

	i = 0;
	while (list[i])
	{
		if (!ft_strncmp(list[i], "pwd", 3))
			ft_printf("%s\n", getcwd(NULL, 0));
		i++;
	}
}