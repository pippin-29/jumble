/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:24:01 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/03 10:24:27 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jumble.h"


int main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("Enter Key As Argument.\n");
		printf("Usage: jumble 09fr thaj 2jat bc93\n");
		printf("Usage: jumble oaks83hj5ndfkc94j\n");
		printf("Arguments must be all the same length.\n");
		return (1);
	} else {
		checkargs(&argv[1]);
		u32 argcount = (argc - 1);
		u32 length = checklen(&argv[1]);
		if (length == 0)
		{
			printf("Enter uniform key\n");
			exit(1);
		}

		char **original = copyargs(&argv[1], argcount);

		printf("Original: ");
		print1dchar(original);
		printf("\n\n");

		char **newkey = jumble(original);

		printf("New Key:\n");
		print2dchar(newkey);
		printf("\n");

		char **copy = copyargs(&argv[1], argcount);
		u32 **keymap = makemap(newkey, copy, length, argcount);

		print2dint(keymap, length, argcount);
		printf("\n");

		free(newkey);
		free(copy);
		free(keymap);
	
	}
	return (0);
		
}