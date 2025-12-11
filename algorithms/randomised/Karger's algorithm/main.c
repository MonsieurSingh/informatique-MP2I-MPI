//
//  main.c
//  Karger's algorithm
//
//  Created by Teghjyot Singh on 26/11/2025.
//

#include "kargers.h"

int main(int argc, const char * argv[])
{
	t_multigraph_adj_list	*graph;

	srand((unsigned int)time(0));
	graph = create_multigraph_adj_list(5);
	add_undirected_multigraph_list_edge(graph, 1, 2);
	add_undirected_multigraph_list_edge(graph, 2, 3);
	add_undirected_multigraph_list_edge(graph, 3, 4);
	add_undirected_multigraph_list_edge(graph, 0, 1);
	int min_cut = karger_min_cut(graph);
	printf("The minimum cut is %d\n", min_cut);
	free(graph);
	return (0);

}
