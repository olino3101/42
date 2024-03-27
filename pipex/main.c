/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:09:52 by onault            #+#    #+#             */
/*   Updated: 2024/03/27 13:59:01 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// < infile grep a1 | wc -w > outfile
// ==
//./pipex infile "grep a1" "wc -w" outfile
//		 <				  |		  >

// argv[1] == infile
// 2 == first cmd
// 3 third command

char *env_path(char **env)
{
	int i = 0;
	int j = 0;
	char *sub = NULL;
	while (env[i])
	{
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		ft_substr(sub, env[i][j], 4);
		if (ft_strncmp(sub, "PATH", 4) == 0)
			return env[i];
		i++;
	}
	return NULL;
}

char *get_path(char *cmd, char **env)
{
	char **every_path;
	int i = 0;
	char *try_path = NULL;
	char *command_path;

	every_path = ft_split(env_path(env), ':');
	while (every_path[i])
	{
		try_path = ft_strjoin(every_path[i], "/");
		command_path = ft_strjoin(try_path, cmd);
		free(try_path);
		if(access(command_path, X_OK) == 0)
			return command_path;
		free(command_path);
		i++;
	}
	return NULL;
}
void do_command(char *argv, char **env)
{
	char *cmd_path;
	char **cmd;

	cmd = ft_split(argv, ' ');
	cmd_path = get_path(cmd[0], env);
	if (cmd_path == NULL)
	{
		ft_putstr_fd("command not found: ", 1);
		ft_putendl_fd(cmd[0], 1);
		free(cmd);
		exit(0);
	}
	if (execve(cmd_path, cmd, env) == -1)
	{
		free(cmd);
		exit(0);
	}
	free(cmd_path);
}
void child(char **argv, int *fd, char **env)
{
	(void)fd;
	do_command(argv[2], env);	
}
// STDIN_FILENO
// STDOUT_FILENO
void parent(char **argv, int *fd, char **env)
{
	int		fd_r;
	int		fd_w;

	fd_r = open(argv[1], O_RDONLY);
	fd_w = open(argv[4],  O_WRONLY | O_CREAT | O_TRUNC);
	dup2(fd_r, STDIN_FILENO);
	dup2(fd_w, STDOUT_FILENO);
	// int status_wait;
	// wait(&status_wait);
	printf("child is first\n\n\n");
	do_command(argv[3], env);
	char buffer[25];
	read(fd[0], buffer, sizeof(buffer));
	printf("bufeerddddddddddrr %s\n\n", buffer);
}
int main(int argc, char *argv[], char **env)
{
	argc = 0;
	pid_t pid;
	int fd[2];
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		printf("sdf");
		// child(argv, fd, env);
	else
		parent(argv, fd, env);
}

// faire deux pipe avec f pipe et fork
	//  et les realiser un a la suite de lautre
	// grace au "deux main creer" et wait...