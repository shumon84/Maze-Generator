#ifndef ___MAZE
#define ___MAZE

#include"Templet.h"
#include"Define.h"
#include"Union-Find.h"
#include"Random.h"
#include"Compression.h"
#include"Kruskal.h"

Edge* maze_cost_init(void);	/* 辺集合にランダムコストを与える */
int(* maze_generator(void))[DEPTH][WIDTH]; /* 迷路を生成して配列を返す */

#endif
