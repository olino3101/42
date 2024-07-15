/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:30:57 by fcornill          #+#    #+#             */
/*   Updated: 2024/07/12 19:02:42 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define EXEC    1
# define PIPE    2
# define REDIR   3
# define APPEND  4
# define HEREDOC 5

/**
 * @param input String de commandes.
 * @param args Liste d'arguments.
 * @param envp Environement.
 * @param fd Descipteurs de fichiers pipe.
 * @param pid ID process pour le fork.
 * @param arg_count nb d'arguments.
 * */
typedef struct s_data
{
	char	*input;
	char	**args;
	char	**envp;
	int		fd[2];
	int		arg_count;
	pid_t	pid;
}			t_data;

typedef struct s_cmd
{
	int	type;
}		t_cmd;

typedef struct s_pipecmd
{
	int		type;
	t_cmd	*left;
	t_cmd	*right;
}			t_pipecmd;

typedef struct s_execcmd
{
	int		type;
	char	**argv;
	char	**eargv;
}			t_execcmd;

typedef struct s_redircmd
{
	int		type;
	t_cmd	*cmd;
	char	*file;
	char	*efile;
	int		mode; //O_RDONLY, ..
	int		fd;
}			t_redircmd;


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcornill <fcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:30:57 by fcornill          #+#    #+#             */
/*   Updated: 2024/07/10 18:53:36 by fcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define EXEC    1
# define PIPE    2
# define REDIR   3
# define APPEND  4
# define HEREDOC 5
/**
 * @param input String de commandes
 * @param args Liste d'arguments
 * @param envp Environement
 * @param fd Descipteurs de fichiers pipe
 * @param pid ID process pour le fork
 * */
typedef struct s_data
{
	char	*input;
	char	**args;
	char	**envp;
	int		fd[2];
	int		arg_count;
	pid_t	pid;
}			t_data;

typedef struct s_cmd
{
	int	type;
}		t_cmd;

typedef struct s_pipecmd
{
	int		type;
	t_cmd	*left;
	t_cmd	*right;
}			t_pipecmd;

typedef struct s_execcmd
{
	int		type;
	char	**argv;
	char	**eargv;
}			t_execcmd;

typedef struct s_redircmd
{
	int		type;
	t_cmd	*cmd;
	char	*file;
	char	*efile;
	int		mode; //O_RDONLY, ..
	int		fd;
}			t_redircmd;


#endif
