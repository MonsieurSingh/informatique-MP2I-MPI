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
/*   deterministic.c                               |__ --==|'-''' '...;       */
/*                                                [  ]  :[|       |---\       */
/*   By: teghjyot <teghjyot@teghjyot.com>         |__| I=[|     .'    '.      */
/*                                                / / ____|     :       '._   */
/*   Created: 2025/11/20 11:46:40 by teghjyot    |-/.____.'      | :      :   */
/*   Updated: 2025/11/20 11:46:41 by teghjyot     /___ /___      '-'._----'   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	peut_etre_completee(t_solution sol, int nbl, int n)
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
	memset(sol, -1, n * sizeof(int));
	if (peut_etre_completee(sol, 0, n))
	{
//		printf("Une solution trouvee pour n = %d :\n", n);
//		print_board(sol, n);
	}
	else
		printf("Aucune solution trouvee pour n = %d.\n", n);
	free(sol);
}
