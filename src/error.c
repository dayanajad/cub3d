/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by bpichyal          #+#    #+#             */
/*   Updated: 2026/06/08 23:21:37 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	if (message && *message)
	{
		ft_putstr_fd(message, 2);
		ft_putstr_fd("\n", 2);
	}
}

void	cub_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	if (msg && *msg)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(EXIT_FAILURE);
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		cub_error("Malloc failed");
	return (ptr);
}
