/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jumble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:06:10 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/02 10:34:40 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jumble.h"

u32 checklen(char **argv)
{
	u32 i = 0;
	u32 len = strlen(argv[0]);
	while (argv[i])
	{
		if (strlen(argv[i]) != len)
			return (0);
		i++;
	}
	return (len);
}

char **copyargs(char **argv, u32 argcount)
{
	u32 i = 0;
	char **array;
	array = malloc(sizeof(char *) * (argcount + 1));
	while (argv[i])
	{
		array[i] = strdup(argv[i]);
		i++;
	}
	array[i] = NULL;
	return (array);
}

void print1dchar(char **array)
{
	u32 i = 0;
	while (array[i])
	{
		printf("%s", array[i]);
		if (array[i+1] != NULL)
			printf("-");
		i++;
	}
}

char **jumble(char **array)
{
	u32 i = 0;
	u32 j = 0;
	u32 k = 0;
	char temp;

	while (array[i])
    {
        j = 0;
        while (array[i][j])
        {
            k = j + 1;
            while (array[i][k])
            {
                if (array[i][j] > array[i][k])
                {
                    temp = array[i][j];
                    array[i][j] = array[i][k];
                    array[i][k] = temp;
                }
                k++;
            }
            j++;
        }
        i++;
    }
	return (array);
}

void print2dchar(char **array)
{
	u32 i = 0;

	while (array[i])
	{
		printf("%s ", array[i]);
		i++;
	}
}

u32 **makemap(char **newkey, char **copy, u32 length, u32 argcount)
{
	u32 i = 0;
	u32 j = 0;
	u32 y = 0;

	u32 **keymap = malloc(sizeof(int *) * (argcount));

	while (copy[i])
	{
		keymap[i] = malloc(sizeof(int) * (length));
		j = 0;
		while (copy[i][j])
		{
			y = 0;
			while (newkey[i][y])
			{
				if (copy[i][j] == newkey[i][y])
				{
					newkey[i][y] = ':';
					copy[i][j] = ':';
					keymap[i][j] = y;
					break ;
				}
				y++;
			}
			j++;
		}
		i++;
	}
	return (keymap);
}

void print2dint(u32 **array, u32 length, u32 argcount)
{
	u32 i = 0;
	u32 j = 0;

	while (i < argcount)
	{
		j = 0;
		while (j < length)
		{
			printf("%d.", array[i][j]);
			j++;
		}
		printf(" ");
		i++;
	}
}