/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:06:23 by bpichyal          #+#    #+#             */
/*   Updated: 2026/05/20 17:52:27 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*read_file(int fd, char *bowl);
char	*read_tukar(int fd, char *bowl, char *bucket, int *byte_read);
char	*extract_line(char *s);
char	*save_leftovers(char *s);
char	*get_next_line(int fd);

size_t	gnl_strlen(const char *s);
int		has_fish(char *s);
char	*gnl_strdup(char *src);
char	*gnl_strjoin(char *s1, char const *s2);

#endif
