/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:01:59 by fcornill          #+#    #+#             */
/*   Updated: 2024/07/15 13:39:58 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	ft_cmd_unset(t_data *data)
{
	int i = 0;

	while (data->envp[i])
    {
        if (strncmp(data->envp[i], data->args[1], ft_strlen(data->args[1])) == 0 && data->envp[i][ft_strlen(data->args[1])] == '=')
        {
			printf("finndddd, %s\n", data->args[1]);
			while (data->envp[i + 1])
			{
				free(data->envp[i]);
				data->envp[i] = ft_strdup(data->envp[i + 1]);
				if (!data->envp[i] && printf("Error with allocing memory\n"))
					return ;
				i++;
			}
			data->envp[i] = NULL;
			free(data->envp[i + 1]);
            return ;
        }
        i++;
    }
}

void	ft_env_cmd(char **envp)
{
	int	y;
	
	y = 0;
	while (envp[y])
	{
		if (ft_strchr(envp[y], '='))
			ft_printf("%s\n", envp[y]);
		y++;
	}
}

void	ft_exit_cmd(t_data *data)
{
	free(data->input);//sinon leaks dans le cas ou on ne tape de commande valide
	free(data);
	exit (EXIT_SUCCESS);
}

void	ft_pwd_cmd(void)
{
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	ft_printf("%s\n", cwd);
}

int	ft_chdir(char *path)
{
	printf("%s\n", path);
	if (chdir(path))
		perror("cd");
	return (0);
}