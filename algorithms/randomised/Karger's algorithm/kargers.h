//
//  kargers.h
//  informatique-MP2I-MPI
//
//  Created by Teghjyot Singh on 26/11/2025.
//

#ifndef kargers_h
#define kargers_h

#include <stdio.h>
#include "multigraph.h"
#include "union_find.h"
#include <time.h>

int karger_min_cut(t_multigraph_adj_list *graph);

#endif /* kargers_h */
