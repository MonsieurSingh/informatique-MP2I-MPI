//
//  main.c
//  concurrency
//
//  Created by Teghjyot Singh on 2/12/2025.
//

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>

static int	g_counter = 0;
static pthread_mutex_t	g_mutex;

static void	*increment(void *x)
{
	int	i;
	int	*n;
	
	n = (int *)x;
	i = 0;
	while (i < 1000000)
	{
		g_counter++;
		i++;
	}
	return (NULL);
}

static void	*increment_with_mutex(void *x)
{
	int	i;
	int	*n;
	
	n = (int *)x;
	i = 0;
	while (i < 1000000)
	{
		pthread_mutex_lock(&g_mutex);
		g_counter++;
		pthread_mutex_unlock(&g_mutex);
		i++;
	}
	return (NULL);
}

static void f(void *func)
{
	int			n0;
	int			n1;
	pthread_t	t0;
	pthread_t	t1;
	clock_t		start, finish;

	n0 = 1;
	n1 = 2;
	g_counter = 0;
	start = clock();
	pthread_mutex_init(&g_mutex, NULL);
	pthread_create(&t0, NULL, func, (void *)&n0);
	pthread_create(&t1, NULL, func, (void *)&n1);
	pthread_join(t0, NULL);
	pthread_join(t1, NULL);
	finish = clock();
	printf("counter: %d\n", g_counter);
	printf("%lf\n", (double)(finish - start) / CLOCKS_PER_SEC);
}

int main(int argc, const char * argv[])
{
	f(increment);
	printf("FINSI\n");
	f(increment_with_mutex);
	return (EXIT_SUCCESS);
}
