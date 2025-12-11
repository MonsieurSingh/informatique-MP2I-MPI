//
//  main.c
//  matrix_mul_multi_threaded
//
//  Created by Teghjyot Singh on 9/12/2025.
//

#include <stdlib.h>
#include <stdio.h>

void	mat_print(int **matrix, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			printf("%3hd", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int		**mat_create(int n)
{
	int	**matrix;
	int	i;
	int	j;

	i = 0;
	matrix = (int **)malloc(sizeof(int *) * n);
	while (i < n)
	{
		matrix[i] = (int *)malloc(sizeof(int) * n);
		j = 0;
		while (j < n)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}

void	mat_destroy(int **matrix, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	mat_transpose(int **matrix, int n)
{
	int	i;
	int	j;
	int	**transposed;

	transposed = mat_create(n);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			transposed[i][j] = matrix[j][i];
			j++;
		}
		i++;
	}
}

int		**mat_sum(int **a, int **b, int n)
{
	int	**c;
	int	i;
	int	j;

	c = mat_create(n);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c[i][j] = a[i][j] + b[i][j];
			j++;
		}
		i++;
	}
	return (c);
}

int		**mat_difference(int **a, int **b, int n)
{
	int	**c;
	int	i;
	int	j;
	
	c = mat_create(n);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c[i][j] = a[i][j] - b[i][j];
			j++;
		}
		i++;
	}
	return (c);
}

int		**mat_product(int **a, int **b, int n)
{
	int	**c;
	int	i;
	int	j;
	int	k;
	
	c = mat_create(n);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c[i][j] = 0;
			k = 0;
			while (k < n)
			{
				c[i][j] += a[i][k] + b[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (c);
}

int main(int argc, const char * argv[])
{
	int	**matrix;

	matrix = mat_create(4);
	mat_print(matrix, 4);
	mat_destroy(matrix, 4);
	printf("Program running with leaked memory. Check with 'leaks a.out' in another terminal\n");
	printf("Press Enter to exit...\n");
	getchar();  // Keeps program alive
	return (EXIT_SUCCESS);
}
