/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jumble.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:27:40 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/02 10:03:36 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef JUMBLE_H
#define JUMBLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

u32		checklen(char **argv);
char	**copyargs(char **argv, u32 argcount);
void	print1dchar(char **array);
char	**jumble(char **array);
void	print2dchar(char **array);
u32		**makemap(char **newkey, char **copy, u32 length, u32 argcount);
void	print2dint(u32 **array, u32 length, u32 argcount);


#endif
