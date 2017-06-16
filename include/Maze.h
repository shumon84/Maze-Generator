#ifndef ___MAZE
#define ___MAZE

#include"Templet.h"
#include"Define.h"
#include"Union-Find.h"
#include"Random.h"
#include"Compression.h"
#include"Kruskal.h"

#define MAZE_TYPE   (START_Z)
#define MAZE_TYPE_A (HEIGHT-1)
#define MAZE_TYPE_B (HEIGHT)
#define MAZE_TYPE_C (1)
#define MAZE_TYPE_D (0)

int maze_separate(Edge *edge,int start);
Edge* maze_cost_init();
int maze_stop(Edge *edge,int start);

#endif
