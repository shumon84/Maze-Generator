#ifndef ___MAZE
#define ___MAZE

#include"Templet.h"
#include"Define.h"
#include"Union-Find.h"
#include"Random.h"
#include"Compression.h"
#include"Kruskal.h"

int veretx_x(int vertex); 	/* 頂点vertexのx座標を取得 */
int veretx_y(int vertex);	/* 頂点vertexのy座標を取得 */
int veretx_z(int vertex);	/* 頂点vertexのz座標を取得 */
int edge_x(int edge);		/* 辺edgeのx座標を取得 */
int edge_y(int edge);		/* 辺edgeのy座標を取得 */
int edge_z(int edge);		/* 辺edgeのz座標を取得 */
Edge* maze_cost_init(void);	/* 辺集合にランダムコストを与える */
Edge* maze_MST(void);		/* 迷路を生成して辺集合を返す */
int(* maze_generator(void))[DEPTH][WIDTH]; /* 迷路を生成して配列を返す */

#endif
