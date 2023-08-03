/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:15:09 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/03 09:55:46 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32;

u32 chumble(char *s)
{
	u32 i = 0;

	while (s[i + 1])
	{
		if (s[i] > s[i+1])
			return (0);
		i++;
	}
	return (1);
}

int main (int argc, char **argv)
{
	if (argc == 1)
	{
		printf("Please Enter Your Key\n");
		exit(1);
	} else {
		u32 i = 1;

		while (argv[i])
		{
			if (!chumble(argv[i]))
			{
				printf("No\n");
			} else {
				printf("Yes\n");
			}
			i++;
		}
	}
}