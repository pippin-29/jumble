/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dejumble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:59:13 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/08 09:52:23 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dejumble.h"

u32 check_len(char **argv, u32 colon_pos)
{
	u32 i = 0;
	u32 length = strlen(argv[0]);

	while (i < colon_pos - 1)
	{
		if (length != strlen(argv[i]))
		{
			printf("Please Enter Uniform Key\n");
			exit (1);
		}
		i++;
	}
	return (length);
}

u32 **parse_keymap(char **argv, u32 length, u32 argcount)
{
	if (length > 10)
	{
		printf("Please rewrite dejumble to accept keymap integers larger than 9.\n");
		exit (1);
	} else {
		u32 **keymap = malloc (sizeof (int *) * (argcount));
		u32 i = 0;
		u32 j = 0;
		u32 count = 0;

		while (argv[i])
		{
			keymap[i] = malloc (sizeof (int) * (length));
			j = 0;
			count = 0;
			while (argv[i][j])
			{
				if (argv[i][j] == '.')
					j++;
				else if (argv[i][j] >= '0' && argv[i][j] <= '9')
				{
					keymap[i][count] = argv[i][j] - 48;
					count++;
					j++;
					if (argv[i][j] != '.')
					{
						printf("Stop! Dot must follow integer.\n");
						exit(1);
					}
				} else {
					printf("Invalid character: %c\n", argv[i][j]);
					exit (1);
				}
			}
			i++;
		}
		if (count != length)
		{
			printf("Keymap Incorrect.\n");
			printf("Stop.\n");
			exit (1);
		}
		return (keymap);
	}
}

void print_key(char **argv, u32 **keymap, u32 length, u32 argcount)
{	
	char **orig = malloc(sizeof (char *) * (argcount + TERMINATOR));
	u32 i = 0;
	u32 j = 0;
	u32 k = 0;

	while (i < argcount)
	{
		orig[i] = malloc(sizeof(char) * (length + TERMINATOR));
		j = 0;
		while (j < length)
		{
			k = 0;
			while (j != keymap[i][k])
				k++;
			orig[i][k] = argv[i][j];
			j++;
		}
		orig[i][j] = '\0';
		printf("%s ", orig[i]);
		i++;
	}
	orig[i] = NULL;
	printf("\n");
	free(orig);
	free(keymap);
}
