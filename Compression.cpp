 #include"include/Compression.h"

int compression_temp[HEIGHT+2][DEPTH+2][WIDTH+2];

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
    case VW*VD : return vertex_x(edge.u);
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
    case VW*VD : return vertex_y(edge.u);
    case 0     : return -1;
    default    : return -3;
    }
}

int edge_z(Edge edge)
{
  switch(edge.v-edge.u)
    {
    case 0     : return -1;
    default    : return vertex_z(edge.u);
    }
}

void extract(int n)
{
  switch(extract_split(n))
    {
    case SPLIT_NOTHING : dprintf("       ");break;
    case SPLIT_UP      : dprintf("UP     ");break;
    case SPLIT_DOWN    : dprintf("DOWN   ");break;
    case SPLIT_DOUBLE  : dprintf("DOWBLE ");break;
    }
  switch(extract_road(n))
    {
    case ROAD_NOTHING  : dprintf("NOTHING ,"); break;
    case ROAD_STREIGHT : dprintf("STREIGHT,"); break;
    case ROAD_CORNER   : dprintf("CORNER  ,"); break;
    case ROAD_BRANCH   : dprintf("BRANCH  ,"); break;
    case ROAD_CROSS    : dprintf("CROSS   ,"); break;
    case ROAD_STOP     : dprintf("STOP    ,"); break;
    case ROAD_GOAL     : dprintf("GOAL    ,"); break;
    case ROAD_START    : dprintf("START   ,"); break;	    
    }
  dprintf("%3d度,",extract_rotate(n));
  dprintf("(X,Y,Z) : (%3d,%3d,%3d)\n",extract_x(n),extract_y(n),extract_z(n));
}

void compression_init(Edge *edge)
{
  int i,j,k;
  int x,y,z;
  rep(k,HEIGHT+2)
    rep(j,DEPTH+2)
      rep(i,WIDTH+2)        
        compression_temp[k][j][i]=0;

  rep(k,VH)
    rep(j,VD)
      rep(i,VW)
        compression_temp[k+1][j*2+2][i*2+2]=1;

  rep(i,KRUSKAL_E)
    {
      x=edge_x(edge[i]);
      y=edge_y(edge[i]);
      z=edge_z(edge[i]);
      dprintf("edge[%2d] : x=%2d,y=%2d,z=%d\n",i,x,y,z);
      if(edge[i].v-edge[i].u==VW*VD)
	{
	  compression_temp[z+1][y+1][x+1]+=1;
	  compression_temp[z+2][y+1][x+1]+=1;
	}
      compression_temp[z+1][y+1][x+1]+=1;
    }
}

int compression_direct(int x,int y,int z)
{
  int direct=0;
  if(compression_temp[z][y][x+1])direct+=DIRECT_RIGHT;
  if(compression_temp[z][y][x-1])direct+=DIRECT_LEFT;
  if(compression_temp[z][y+1][x])direct+=DIRECT_FRONT;
  if(compression_temp[z][y-1][x])direct+=DIRECT_BACK;
  return direct;
}

int compression_stairway(int x,int y,int z)
{
  int split=0;

  switch(compression_temp[z+1][y][x])
    {
    case 4:split+=SPLIT_DOUBLE;
    case 3:split+=SPLIT_UP;
    case 2:split+=SPLIT_DOWN;
    case 1:split+=SPLIT_NOTHING;
    }
  return split;
}

int compression_stop(int direct)
{
  int rotate;
  switch(direct)
    {
    case DIRECT_FRONT : rotate=0; break;
    case DIRECT_LEFT  : rotate=90; break;
    case DIRECT_BACK  : rotate=180; break;
    case DIRECT_RIGHT : rotate=270; break;
    }
  return rotate;
}

int compression_streight(int direct)
{
  int rotate;
  switch(direct)
    {
    case DIRECT_FRONT | DIRECT_BACK  : rotate=0; break;
    case DIRECT_LEFT  | DIRECT_RIGHT : rotate=90; break;
    }
  return rotate;
}

int compression_corner(int direct)
{
  int rotate;
  switch(direct)
    {
    case DIRECT_FRONT | DIRECT_LEFT  : rotate=0; break;
    case DIRECT_LEFT  | DIRECT_BACK  : rotate=90; break;
    case DIRECT_BACK  | DIRECT_RIGHT : rotate=180; break;
    case DIRECT_RIGHT | DIRECT_FRONT : rotate=270; break;
    }
  return rotate;
}

int compreesion_branch(int direct)
{
  int rotate;
  switch(direct)
    {
    case DIRECT_FRONT | DIRECT_LEFT  | DIRECT_BACK  : rotate=0; break;
    case DIRECT_LEFT  | DIRECT_BACK  | DIRECT_RIGHT : rotate=90; break;
    case DIRECT_BACK  | DIRECT_RIGHT | DIRECT_FRONT : rotate=180; break;
    case DIRECT_RIGHT | DIRECT_FRONT | DIRECT_LEFT  : rotate=270; break;
    }
  return rotate;
}

int compression_road(int direct)
{
  int road;
  switch(popcount(direct))
    {
    case 0 : road=ROAD_NOTHING; break;
    case 1 : road=ROAD_STOP; break;
    case 2 :
      switch(direct)
	{
	case  DIRECT_FRONT|DIRECT_BACK  :
	case  DIRECT_LEFT |DIRECT_RIGHT : road=ROAD_STREIGHT; break;
	default                         : road=ROAD_CORNER; break;
	}
      break;
    case 3 : road=ROAD_BRANCH; break;
    case 4 : road=ROAD_CROSS; break;
    }
  return road;
}

int compression_split(int stairway)
{
  int split;
  switch(stairway)
    {
    case DIRECT_NOTHING        : split=SPLIT_NOTHING; break;
    case DIRECT_UP             : split=SPLIT_UP; break;
    case DIRECT_DOWN           : split=SPLIT_DOWN; break;
    case DIRECT_UP|DIRECT_DOWN : split=SPLIT_DOUBLE; break;
    }
  return split;
}

int compression_rotate(int direct,int road)
{
  int rotate;
  switch(road)
    {
    case ROAD_STOP     : rotate=compression_stop(direct); break;
    case ROAD_STREIGHT : rotate=compression_streight(direct); break;
    case ROAD_CORNER   : rotate=compression_corner(direct); break;
    case ROAD_BRANCH   : rotate=compreesion_branch(direct); break;
    default            : rotate=0; break;
    }
  return rotate;
}

int compression_maze(int x,int y,int z)
{
  int direct,stairway;
  int road,split,rotate;
  direct=compression_direct(x,y,z);
  stairway=compression_stairway(x,y,z);

  dprintf("(%2d,%2d,%2d) = ",x,y,z);
  dprintf("%d\n",stairway);

  road=compression_road(direct);
  split=compression_split(stairway);
  rotate=compression_rotate(direct,road);

  return compress(road,split,rotate,x,y,z);	
}

void compression(int maze[HEIGHT][DEPTH][WIDTH],Edge *edge)
{
  int i,j,k;
  compression_init(edge);
  dprintf("階段の有無\n");
  rep(i,HEIGHT)
    rep(j,DEPTH)
      rep(k,WIDTH)
        maze[i][j][k]=compression_maze(k+1,j+1,i+1);

  rep(i,HEIGHT)
    rep(j,DEPTH)
      rep(k,WIDTH)
        if(compression_temp[i+1][j+1][k+1]==0)
          maze[i][j][k]=0;

  drep(i,HEIGHT)
    drep(j,DEPTH)
    　drep(k,WIDTH)
    　　{
    　　  dprintf("%2d,%2d,%2d : ",k,j,i);
    　　  extract(maze[i][j][k]);
    　　}

  drep(i,HEIGHT+2)
    {
      drep(j,DEPTH+2)
	{
	  drep(k,WIDTH+2)
	    switch(compression_temp[i][j][k])
	      {
	      case 4:dprintf("\033[45mo");break;
	      case 3:dprintf("\033[41mu");break;
	      case 2:dprintf("\033[44md");break;
	      case 1:dprintf("\033[47m ");break;
	      case 0:dprintf("\033[49m.");break;
	      }
	  dprintf("\n");
	}
      dprintf("\n");
    }
}
