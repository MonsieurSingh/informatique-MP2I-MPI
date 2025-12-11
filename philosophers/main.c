//
//  main.c
//  philosophers
//
//  Created by Teghjyot Singh on 3/12/2025.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <semaphore.h>

void	think(void)
{
}

void	eat(void)
{
}

void	repeat(void)
{
}

void	philosopher(int i)
{
	while(true)
	{
		think();
		eat();
		repeat();
	}
}

int main(int argc, const char * argv[]) {
	// insert code here...
	printf("Hello, World!\n");
	return EXIT_SUCCESS;
}
