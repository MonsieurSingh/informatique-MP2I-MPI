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
				printf("#");
			else
				printf("X");
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

bool	peut_etre_completee(t_solution sol, int nbl, int n)
{
	int	i;

	if (nbl == n)
		return (true);
	i = 0;
	while (i < n)
	{
		if (est_extension_valide(sol, nbl, i))
		{
			sol[nbl] = i;
			if (peut_etre_completee(sol, nbl + 1, n))
				return (true);
		}
		i++;
	}
	sol[nbl] = -1;
	return (false);
}

void	resolution_deterministe(int n)
{
	t_solution	sol;

	sol = (t_solution)malloc(n * sizeof(int));
	memset(sol, -1, sizeof(int) * n);
	if (peut_etre_completee(sol, 0, n))
	{
		printf("Une solution trouvee pour n = %d :\n", n);
		print_board(sol, n);
	}
	else
		printf("Aucune solution trouvee pour n = %d.\n", n);
	free(sol);
}

int	positions_valides(t_solution sol, int nbl, int n, int* tab_pos)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < n)
	{
		if (est_extension_valide(sol, nbl, i))
			tab_pos[count++] = i;
		i++;
	}
	return (count);
}

bool	generation_aleatoire(int n, t_solution tab_sol)
{
	t_solution	tab_pos;
	int			i;
	int			positions;

	tab_pos = (t_solution)malloc(sizeof(int) * n);
	memset(tab_pos, -1, sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		i++;
	}
	for (int ligne = 0; ligne < n; ligne++) {
		
		positions = positions_valides(tab_sol, ligne, n, tab_pos);
		
		if (positions == 0)
		{
			free(tab_pos);
			return (false);
		}
		tab_sol[ligne] = tab_pos[rand() % positions];
	}
	free(tab_pos);
	return (true);
}

void	resolution_probabiliste(int n)
{
	t_solution	sol;

	srand((unsigned int)time(NULL));
	sol = (t_solution)malloc(sizeof(int) * n);
	while (!generation_aleatoire(n, sol))
	{
	}
	printf("Solution probabiliste trouvee pour n = %d :\n", n);
	print_board(sol, n);
	free(sol);
}

int	main(int argc, const char *argv[])
{
	int			n;
	int			i;

	(void)argv;
	(void)argc;
	n = 50;
	i = 4;
	while (i < n)
	{
		resolution_probabiliste(i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		resolution_deterministe(i);
		i++;
	}
	return (EXIT_SUCCESS);
}
