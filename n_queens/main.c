/* ************************************************************************** */
/*                                                                            */
/*                           .                      .                   ·     */
/*        .    __ _o|                        .                ·               */
/*            |  /__|===--        .                                  ·        */
/*     *      [__|______~~--._                      .                         */
/*      .    |\  `---.__:====]-----...,,_____                *          ·     */
/*           |[>-----|_______<----------_____;::===--             .==.        */
/*           |/_____.....-----'''~~~~~~~                         ()''()-.     */
/*      +               ·                           .---.         ;--; /      */
/*                                                .'_:___". _..'.  __'.       */
/*   main.c                                        |__ --==|'-''' '...;       */
/*                                                [  ]  :[|       |---\       */
/*   By: teghjyot <teghjyot@teghjyot.com>         |__| I=[|     .'    '.      */
/*                                                / / ____|     :       '._   */
/*   Created: 2025/11/18 22:15:51 by teghjyot    |-/.____.'      | :      :   */
/*   Updated: 2025/11/18 22:15:53 by teghjyot     /___ /___      '-'._----'   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_board(t_solution sol, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		printf("|\t%d\t", i);
		j = 0;
		while (j < n)
		{
			if (sol[i] != -1 && sol[i] == j)
				printf(" #");
			else
				printf(" X");
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

bool	est_extension_valide(t_solution sol, int nbl, int col)
{
	int	i;

	i = 0;
	while (i < nbl)
	{
		if (sol[i] == col || abs(nbl - i) == abs(col - sol[i]))
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, const char *argv[])
{
	int		n;
	int		i;
	clock_t	begin;
	clock_t	end;

	(void)argv;
	(void)argc;
	n = 150;
	i = 4;
	while (i < n)
	{
		begin = clock();
//		resolution_deterministe(i);
		end = clock();
		printf("Processing time: %lf s pour n = %d\n", (double)((end - begin) / CLOCKS_PER_SEC), i);
		begin = clock();
		resolution_probabiliste(i);
		end = clock();
		printf("Processing time: %lf s pour n = %d\n", (double)((end - begin) / CLOCKS_PER_SEC), i);
		i++;
	}
	return (EXIT_SUCCESS);
}
