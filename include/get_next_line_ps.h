/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ps.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:40:14 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 00:45:05 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_PS_H
# define GET_NEXT_LINE_PS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "checker.h"
# include  "push_swap.h"

# define BUFF_SIZE 50
# define MAX_FD 4864

char	*get_next_line_ps(int fd, t_stacks *stacks);

char	*ft_gnl_strjoin(char *str_1, char *str_2);
char	*ft_gnl_strchr(const char *str, int ch);

#endif