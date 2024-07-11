/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:20:03 by msimard           #+#    #+#             */
/*   Updated: 2024/07/10 17:00:53 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static void	ft_parser(t_data *data)
{
	char	*str;
	int		check;

	str = data->input;
	check = ft_check_quote(str);
	if (check)
	{
		ft_parsecmd(data->input);
		ft_check_cmd(data);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	 
	signal(SIGQUIT, SIG_IGN);
	ft_init_signal();
	data = malloc(sizeof(t_data));
	data->envp = envp;
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
				add_history(data->input);
			ft_parser(data);
			free(data->input);//obligatoire sinon leaks!!
		}
	}
	return (0);
	//else // shell no interactive ?
	//free(data);
}