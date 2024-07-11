/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:14:02 by fcornill          #+#    #+#             */
/*   Updated: 2024/07/10 17:45:56 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//Modifie une variable deja existante
void	ft_export_modif(char *argv, char **env_cpy)
{
	// int size_of_var;
	// char *var_to_modif;
	// size_of_var = ft_strchr(argv, '\0');
	// var_to_modif = malloc(size_of_var + 1);

	while (env_cpy)
	argv = NULL;

}

//add une variable dans l'environement
void	ft_export_add(char *argv, char **env_cpy)
{
	char **new_env;

	//printf("\n\n\n\n\n\n\n\n\n\n\n\n/n\n\\n\n\n\n\n/\n\n\n\\n/n/\n\n\\N\\n\n/n");
	int size_env = 0;
	int i = 0;
	while (env_cpy[size_env])
		size_env++;
	new_env = malloc(size_env + 2);
	while (i != size_env)
	{
		new_env[i] = malloc(ft_strlen(env_cpy[i]));
		ft_strlcpy(new_env[i], env_cpy[i], ft_strlen(env_cpy[i]));
		i++;
	}
	new_env[i] = argv;
	new_env[++i] = NULL;
	ft_free(env_cpy , NULL);
	env_cpy = new_env;
}

//Cherche dans l'environement si la variable existe. Si non, la creer
void	ft_export_search(char *argv, char **env_cpy)
{
	size_t	i;
	int		x;
	int		flag;

	x = 0;
	flag = 0;
	i = ft_equal_sign(argv);
	while (env_cpy[x])
	{
		if (ft_strnstr(env_cpy[x++], argv, i))
		{
			flag = 1;
			ft_export_modif(argv, env_cpy);
		}
		else
			x++;
	}
		if (!flag)
			ft_export_add(argv, env_cpy);
}

//Tri l'environement en ordre alpha
void	ft_export_tri(char *tmp, char **cpy_envp, int y)
{
	while(cpy_envp[y]) //tri a bulle dans le cas ou export est appelé sans args (la commande tri les variables d'env par ordre ascii)
	{
		if (ft_strncmp(cpy_envp[y], cpy_envp[y + 1], 1) > 0)
		{
			tmp = cpy_envp[y];
			cpy_envp[y] = cpy_envp[y + 1];
			cpy_envp[y + 1] = tmp;
			y = 0;
		}
		else
			y++;
	}
	y = 0;
	while (cpy_envp[y])
		ft_printf("declare -x %s\n", cpy_envp[y++]);
	y = 0;
	ft_free(cpy_envp, NULL);
}

//Reception de la commande "export"
void	ft_export_cmd(t_data *data)
{
	int		y;
	char	*v_value;
	char	**cpy_envp;
	char	*var_name;

	y = 1;
	cpy_envp = ft_get_envp_cpy(data->envp);
	v_value = NULL; //erreur de compilation
	if (data->arg_count > 1)// si on a splitter l'input et trouvé plusieurs tokens
	{
		while (data->args[y])
		{
			var_name = ft_substr(data->args[y], 0, ft_equal_sign(data->args[y]));
			if (!ft_valid_name(var_name))
			{
				free(var_name);
				ft_error("Not a valid identifier");
			}
			if (ft_strchr(data->args[y], '='))
				ft_export_search(var_name, cpy_envp);//A verifier pour le '='
			else
				//L'environement reste le meme, seulement le "read" est different sans le '='
				//Je doit storer le nom de la variable et sa valeur a part. time(nom)=24h(valeur)
			free(var_name);
			y++;
		}
	}
	else
		ft_export_tri(v_value, cpy_envp, y - 1);
}
