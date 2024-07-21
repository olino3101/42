/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:16:04 by fcornill          #+#    #+#             */
/*   Updated: 2024/07/15 13:46:28 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_nulterminate_str(t_cmd *cmd)
{
	int			i;
	t_execcmd	*ecmd;
	t_pipecmd	*pcmd;
	
	i = 0;
	if (cmd == 0)
		return (0);
	if (cmd->type == EXEC)
	{
		ecmd = (t_execcmd *)cmd;
		while (ecmd->argv[i])
		{
			*ecmd->eargv[i] = 0;
			i++;
		}
	}
	else if (cmd->type == PIPE)
	{
		pcmd = (t_pipecmd *)cmd;
		ft_nulterminate_str(pcmd->left);
		ft_nulterminate_str(pcmd->right);
	}
	return (cmd);
}

size_t	ft_count_argc(char **begin, char *end)
{
	char	*tmp;
	size_t 	argc;
	int		token;
	char	*cur;
	char	*end_cur;

	tmp = *begin;
	argc = 0;
	while (!ft_check_token(&tmp, end, "|")) {
        if ((token = ft_add_token(&tmp, end, &cur, &end_cur)) == 0)
            break;
        argc++;
        tmp++;
    }
	ft_printf("argc : %d\n", argc);
	return (argc);
}