//
//  knapsack.c
//  informatique-MP2I-MPI
//
//  Created by Teghjyot Singh on 27/11/2025.
//

#include "knapsack.h"
#include <stdlib.h>

static int	knapsack_aux(t_treasure *treasures, int n, int capacity, int k, int *iterations)
{
	int	value;
	int	weight;
	int	with;
	int	without;

	*iterations = *iterations + 1;
	if (k == n)
		return (0);
	value = treasures[k].value;
	weight = treasures[k].weight;
	without = knapsack_aux(treasures, n, capacity, k + 1, iterations);
	if (weight <= capacity)
	{
		with = value + knapsack_aux(treasures, n, capacity - weight, k + 1, iterations);
		if (with > without)
			return (with);
		else
			return (without);
	}
	else
		return (without);
}

static int	sum_values(t_treasure *treasures, int n)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < n)
		sum += treasures[i++].value;
	return (sum);
}

int	knapsack(t_treasure *treasures, int n, int capacity)
{
	int	*iterations;
	int	ret;

	iterations = (int *)malloc(sizeof(int) * 1);
	*iterations = 0;
	ret = knapsack_aux(treasures, n, capacity, 0, iterations);
	printf("iterations: %d\n", *iterations);
	return (ret);
}

int	knapsack_branch_n_bound(t_treasure *treasures, int size, int capacity, int i, int bound, int maximum, int *counter)
{
	int	with;
	int	without;

	*counter = *counter + 1;
	if (i == size)
	{
		if (bound > maximum)
			return (bound);
		else
			return (maximum);
	}
	else if (bound < maximum)
		return maximum;
	else
	{
		without = knapsack_branch_n_bound(treasures, size, capacity, i + 1,
										bound - treasures[i].value, maximum, counter);
		if (capacity < treasures[i].weight)
			return (without);
		with = knapsack_branch_n_bound(treasures, size, capacity - treasures[i].weight, i + 1,
									   bound, maximum, counter);
		if (with >= without)
			return (with);
		else
			return (without);
	}
}

int	knapsack_bnb(t_treasure *treasures, int n, int capacity)
{
	int	*iterations;
	int	ret;

	iterations = (int *)malloc(sizeof(int) * 1);
	*iterations = 0;
	ret = knapsack_branch_n_bound(treasures, n, capacity, 0, 128, -1, iterations);
	printf("iterations: %d\n", *iterations);
	return (ret);
}
