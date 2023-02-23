/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:08:32 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/02/23 11:32:27 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

int		cmd_exec(char *argv, char **envp);
char	**cmd_parsing(char **envp);
int		exec_error(char **cmd_args);
void	create_pipe(int infile_fd, int outfile_fd, char **argv, char **envp);
void	child_process1(int outfile_fd, int *pipe_fd, char **argv, char **envp);
void	child_process2(int infile_fd, int *pipe_fd, char **argv, char **envp);
void	print_error(char *msg);
void	init_error(void);

#endif
