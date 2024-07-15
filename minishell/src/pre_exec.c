/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:51:27 by fcornill          #+#    #+#             */
/*   Updated: 2024/07/15 13:40:07 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_get_cmd(t_cmd *cmd, t_data *data)
{
	//t_pipecmd	*pcmd;
	t_execcmd	*ecmd;
	//t_redircmd	*rcmd;

	//checker si !cmd et si cmd->type == 0
	
	if (cmd->type == EXEC)
	{
		ecmd = (t_execcmd *)cmd;
		data->args = ecmd->argv;
		ft_check_cmd(data);
	}
}