//
//  main.c
//  Knapsack
//
//  Created by Teghjyot Singh on 27/11/2025.
//

#include "knapsack.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{
	t_treasure	*treasures;
	int			capacity;
	int			size;

	capacity = 5;
	size = 3;
	treasures = malloc(sizeof(t_treasure) * size);
	treasures[0].value = 45;
	treasures[0].weight = 5;
	treasures[1].value = 48;
	treasures[1].weight = 8;
	treasures[2].value = 35;
	treasures[2].weight = 3;
	printf("res: %d\n", knapsack(treasures, size, capacity));
	printf("res: %d\n", knapsack_bnb(treasures, size, capacity));
    return EXIT_SUCCESS;
}
