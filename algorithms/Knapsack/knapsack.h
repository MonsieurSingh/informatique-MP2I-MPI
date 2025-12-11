//
//  knapsack.h
//  informatique-MP2I-MPI
//
//  Created by Teghjyot Singh on 27/11/2025.
//

#ifndef KNAPSACK_H
# define KNAPSACK_H

# include <stdio.h>

typedef struct s_treasure
{
	int	value;
	int	weight;
}	t_treasure;

int	knapsack(t_treasure *treasures, int n, int capacity);
int	knapsack_bnb(t_treasure *treasures, int n, int capacity);
# endif // !KNAPSACK_H
