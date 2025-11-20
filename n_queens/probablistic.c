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
/*   probablistic.c                                |__ --==|'-''' '...;       */
/*                                                [  ]  :[|       |---\       */
/*   By: teghjyot <teghjyot@teghjyot.com>         |__| I=[|     .'    '.      */
/*                                                / / ____|     :       '._   */
/*   Created: 2025/11/20 11:46:31 by teghjyot    |-/.____.'      | :      :   */
/*   Updated: 2025/11/20 11:46:32 by teghjyot     /___ /___      '-'._----'   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	positions_valides(t_solution sol, int nbl, int n, int *tab_pos)
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
		positions = positions_valides(tab_sol, i, n, tab_pos);
		if (positions == 0)
		{
			free(tab_pos);
			return (false);
		}
		tab_sol[i] = tab_pos[rand() % positions];
		i++;
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
