/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:46:26 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/08 09:52:05 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dejumble.h"

int main(int argc, char **argv)
{
	if (argc < 4)
	{
		printf("Please Enter at least three arguments.\n");
		printf("Usage: dejumble 039c : 0.2.1.3.\n");
		return (1);
	} else {

		u32 argcount = argc - 1;
		argcount = (argcount - 1) / 2;
		u32 colon_pos = argcount + 1;

		argv = &argv[1];
		u32 length = check_len(argv, colon_pos);
		if (argv[colon_pos - 1][0] == ':' && argv[colon_pos - 1][1] == '\0')
		{
			u32 **keymap = parse_keymap(&argv[colon_pos], length, argcount);
			
			print_key(argv, keymap, length, argcount);
		} else {
			printf("Error:\n");
			printf("Usage: dejumble 039c : 0.2.1.3.\n");
			exit (1);
		}
	}
	return (0);
}