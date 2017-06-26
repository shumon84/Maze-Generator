#include"include/Maze.h"

int maze[HEIGHT][DEPTH][WIDTH]={}; // 迷路の状態。添え字は[z][y][x]になる

Edge* maze_cost_init()
{
  Edge *edge=(Edge*)calloc(sizeof(Edge),KRUSKAL_E);
  int i,j;

  for(i=j=0;i<KRUSKAL_E;i++)
    {
      if((i+1)%VW!=0)
	{
	  edge[j].u=i;
	  edge[j].v=i+1;
	  if(i==START || i+1==START || i==GOAL || i+1==GOAL)
 	    edge[j].cost=20000;
	  else
	    edge[j].cost=random_nm(1,10000);
	  j++;
 	}
      if((i/VW+1)%VD!=0)
	{
	  edge[j].u=i;
	  edge[j].v=i+VW;
	  if(i==START || i+VW==START || i==GOAL || i+VW==GOAL)
	    edge[j].cost=20000;
	  else
	    edge[j].cost=random_nm(1,10000);
	  j++;
	}
      if(i/(VW*VD)!=VH-1)
	{
	  edge[j].u=i;
	  edge[j].v=i+VW*VD;
	  if(i==START || i+VW*VD==START || i==GOAL || i+VW*VD==GOAL)
	    edge[j].cost=30000;
	  else
	    if(random_nm(0,99)<SPLIT_RATIO)
	      edge[j].cost=0;
	    else
	      edge[j].cost=30000;
	  j++;
	}
    }
  return edge;
}

int(* maze_generator(void))[DEPTH][WIDTH]
{
  Edge *edge;

  define_check(); //マクロが不正な値でないかチェック
    
  edge=maze_cost_init(); // 各辺にランダムコストを与える

  edge=kruskal(edge); // 最小全域木を構築
  int i;
  drep(i,KRUSKAL_E)printf("Edge[%d] : u=%3d,v=%3d\n",i,edge[i].u,edge[i].v);

  compression(maze,edge);

  return maze;
}
