#include"include/Maze.h"

int maze[HEIGHT][DEPTH][WIDTH]={}; // 迷路の状態。添え字は[z][y][x]になる

int vertex_x(int vertex)
{
  if(vertex!=-1)
    return (vertex%VW)*2+1;
  else
    return -1;
}

int vertex_y(int vertex)
{
  if(vertex!=-1)
    return ((vertex/VW)%VD)*2+1;
  else
    return -1;
}

int vertex_z(int vertex)
{
  if(vertex!=-1)
    return vertex/(VW*VD);
  else
    return -1;
}

int edge_x(Edge edge)
{
  switch(edge.v-edge.u)
    {
    case 1     : return vertex_x(edge.u)+1;
    case VW    : return vertex_x(edge.u);
    case VW*VD : return -2;
    case 0     : return -1;
    default    : return -3;
    }
}

int edge_y(Edge edge)
{
  switch(edge.v-edge.u)
    {
    case 1     : return vertex_y(edge.u);
    case VW    : return vertex_y(edge.u)+1;
    case VW*VD : return -2;
    case 0     : return -1;
    default    : return -3;
    }
}

int edge_z(Edge edge)
{
  switch(edge.v-edge.u)
    {
    case VW*VD : return -2;
    case 0     : return -1;
    default    : return vertex_z(edge.u);
    }
}

Edge* maze_cost_init()
{
  const ui w=WIDTH/2;
  const ui d=DEPTH/2;
  const ui h=HEIGHT;
  const ui start=START_X*w+START_Y+START_Z*w*d;
  const ui goal=GOAL_X*w+GOAL_Y+GOAL_Z*w*d;

  Edge *edge=(Edge*)calloc(sizeof(Edge),KRUSKAL_E);
  int i,j;

  for(i=j=0;i<KRUSKAL_E;i++)
    {
      if((i+1)%w!=0)
	{
	  edge[j].u=i;
	  edge[j].v=i+1;
	  if(i==start || i+1==start || i==goal || i+1==goal)
 	    edge[j].cost=20000;
	  else
	    edge[j].cost=random_nm(0,10000);
	  j++;
 	}
      if((i/w+1)%d!=0)
	{
	  edge[j].u=i;
	  edge[j].v=i+w;
	  if(i==start || i+w==start || i==goal || i+w==goal)
	    edge[j].cost=2000;
	  else
	    edge[j].cost=random_nm(0,10000);
	  j++;
	}
      if(i/(w*d)!=h-1)
	{
	  edge[j].u=i;
	  edge[j].v=i+w*d;
	  if(i==start || i+w*d==start || i==goal || i+w*d==goal)
	    edge[j].cost=30000;
	  else
	    edge[j].cost=random_nm(100*(100-SPLIT_RATIO),10000);
	  j++;
	}
    }
  return edge;
}

Edge* maze_MST(void)
{
  Edge *edge;

  define_check();

  edge=maze_cost_init(); // 各辺にランダムコストを与える

  edge=kruskal(edge); // 最小全域木を構築

  return edge;
}

int(* maze_generator(void))[DEPTH][WIDTH]
{
  int i,j,k;
  int x,y,z;
  Edge *edge;
  
  edge=maze_MST();

  rep(k,HEIGHT)
    rep(j,DEPTH)
      rep(i,WIDTH)
        maze[k][j][i]=0;

  rep(k,VH)
    rep(j,VD)
      rep(i,VW)
        maze[k][j*2+1][i*2+1]=1;

  rep(i,KRUSKAL_E)
    {
      x=edge_x(edge[i]);
      y=edge_y(edge[i]);
      z=edge_z(edge[i]);
      maze[z][y][x]=1;
    }

  return maze;
}
