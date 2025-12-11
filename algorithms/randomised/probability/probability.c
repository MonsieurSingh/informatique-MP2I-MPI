//
//  probability.c
//  probability
//
//  Created by Teghjyot Singh on 20/11/2025.
//

#include "probability.h"

void	init_rand(void)
{
	srand((unsigned int)time(NULL));
}

float	r(void)
{
	return ((float)rand() / (float)RAND_MAX);
}

int	bernouilli(float p)
{
	if (r() < p)
		return (true);
	else
		return (false);
}

int	geometrique(float p)
{
	return ((int)floor(log(1 - r()) / log(1 - p)) + 1);
}

int	binomiale(int n, float p)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < n)
	{
		if (bernouilli(p))
			k++;
		i++;
	}
	return (k);
}

int main(int argc, const char * argv[])
{
	(void)argc;
	(void)argv;
	init_rand();
	printf("Measured probability: %d\n", binomiale(500000, 0.5));
	return EXIT_SUCCESS;
}
