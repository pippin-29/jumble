/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dejumble.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:46:21 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/08 09:52:40 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEJUMBLE_H
#define DEJUMBLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

#define TERMINATOR 1

u32		check_len(char **argv, u32 colon_pos);
u32		**parse_keymap(char **argv, u32 length, u32 argcount);
void	print_key(char **argv, u32 **keymap, u32 length, u32 argcount);

#endif