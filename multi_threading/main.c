//
//  main.c
//  multi_threading
//
//  Created by Teghjyot Singh on 11/12/2025.
//

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void	*execute_work(void *arg)
{
	int i;

	i = *((int *)arg);
	printf("Thread %d: started\n", i);
	printf("Thread %d: ended\n", i);
	return (EXIT_SUCCESS);
}

void	execute_threads(int num_threads, pthread_t *threads, int *thread_args)
{
	int	i;
	int	status;

	i = 0;
	while (i < num_threads)
	{
		thread_args[i] = i + 1;
		status = pthread_create(&threads[i], NULL, &execute_work, (void *)&thread_args[i]);
		if (status != 0)
		{
			perror("Can't create thread");
			free(threads);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < num_threads)
	{
		pthread_join (threads[i], NULL);
		i++;
	}
}

int main(int argc, const char * argv[])
{
	int	n;
	pthread_t	*threads;
	int			*thread_args;

	if (argc!=2)
	{
		printf("(main) Usage: %s number_of_threads\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	n = atoi(argv[1]);
	if (n < 1)
	{
		printf ("(main) Incorrect number of threads!\n");
		exit(EXIT_FAILURE);
	}
	thread_args = (int *)calloc (n, sizeof(int));
	threads = (pthread_t*)malloc(n * sizeof(pthread_t));
	execute_threads(n, threads, thread_args);
	printf("(main) program has ended\n");
	free(thread_args);
	free(threads);
	return (EXIT_SUCCESS);
}
