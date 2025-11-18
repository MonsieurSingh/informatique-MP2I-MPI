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
				printf("# ");
			else
				printf("X ");
			j++;
		}
		printf("\n");
		i++;
	}
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
	t_solution	sol;
	int			n;

	(void)argv;
	(void)argc;
	n = 8;
	sol = malloc(sizeof(int) * n);
	memset(sol, -1, sizeof(int) * n);
	sol[0] = 4;
	sol[1] = 7;
	sol[2] = 0;
	sol[3] = -1;
	print_board(sol, 4);
	printf("Placable sur %d, %d: %d\n", 3, 0, est_extension_valide(sol, 3, 0));
	printf("Placable sur %d, %d: %d\n", 3, 1, est_extension_valide(sol, 3, 1));
	printf("Placable sur %d, %d: %d\n", 3, 2, est_extension_valide(sol, 3, 2));
	free(sol);
	return (EXIT_SUCCESS);
}
