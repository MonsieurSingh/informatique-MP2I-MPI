//
//  kargers.c
//  informatique-MP2I-MPI
//
//  Created by Teghjyot Singh on 26/11/2025.
//

#include "kargers.h"

static t_multigraph_edge	*get_random_edge(t_multigraph_adj_list *graph)
{
	int					src;
	t_multigraph_edge	*edge;
	int					edge_count;
	t_multigraph_edge*	temp;
	int					random_index;
	int					i;

	src = rand() % graph->num_vertices;
	edge = graph->adj_lists[src];
	if (!edge)
		return (NULL);
	edge_count = 0;
	temp = edge;
	while (temp != NULL)
	{
		edge_count++;
		temp = temp->next;
	}
	random_index = rand() % edge_count;
	i = 0;
	while (i < random_index && edge)
	{
		edge = edge->next;
		i++;
	}
	return (edge);
}

static void contract(t_multigraph_edge *edge, t_union_find *uf, int *vertices)
{
	int	subset1;
	int	subset2;

	subset1 = uf_find(uf, edge->dest);
	subset2 = uf_find(uf, edge->next->dest);
	if (subset1 != subset2)
	{
		uf_union(uf, subset1, subset2);
		(*vertices)--;
		printf("Contracting edge %d-%d\n", edge->dest, edge->next->dest);
	}
}

static int count_edges_cut(t_multigraph_adj_list *graph, t_union_find *uf)
{
	int	edges_cut;
	int	i;

	edges_cut = 0;
	i = 0;
	while (i < graph->num_vertices)
	{
		t_multigraph_edge *edge = graph->adj_lists[i];
		while (edge && edge->next)
		{
			if (uf_find(uf, i) != uf_find(uf, edge->dest))
				edges_cut++;
			edge = edge->next;
		}
		i++;
	}
	return (edges_cut);
}

int karger_min_cut(t_multigraph_adj_list *graph)
{
	int					vertices;
	t_union_find		*uf;
	t_multigraph_edge	*edge;
	int					edges_cut;

	vertices = graph->num_vertices;
	uf = uf_create(vertices);
	while (vertices > 2)
	{
		edge = get_random_edge(graph);
		if (!edge)
			continue;
		contract(edge, uf, &vertices);
	}
	edges_cut = count_edges_cut(graph, uf);
	uf_destroy(uf);
	return (edges_cut);
}
