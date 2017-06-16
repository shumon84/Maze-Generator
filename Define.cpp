#include"include/Define.h"

void define_check(void)
{
  bool judge=false;

  if(WIDTH<1 || WIDTH%2==0)
    {
      fprintf(stderr,"WIDTHの値が不正です\n");
      judge=true;
    }
  if(DEPTH<1 || DEPTH%2==0)
    {
      fprintf(stderr,"DEPTHの値が不正です\n");
      judge=true;
    }
  if(HEIGHT<1)
    {
      fprintf(stderr,"HEIGHTの値が不正です\n");
      judge=true;
    }
  if(WIDTH<=START_X || START_X<0)
    if(START_X%2==0)
      {
	fprintf(stderr,"START_Xの値が不正です\n");
	judge=true;
      }
  if(DEPTH<=START_Y || START_Y<0)
    if(START_Y%2==0)
      {
	fprintf(stderr,"START_Yの値が不正です\n");
	judge=true;
      }
  if(HEIGHT<=START_Z || START_Z<0)
    {
      fprintf(stderr,"START_Zの値が不正です\n");
      judge=true;
    }
  if(WIDTH<=GOAL_X || GOAL_X<0)
    if(GOAL_X%2==0)
      {
	fprintf(stderr,"GOAL_Xの値が不正です\n");
	judge=true;
      }
  if(DEPTH<=GOAL_Y || GOAL_Y<0)
    if(GOAL_Y%2==0)
      {
	fprintf(stderr,"GOAL_Yの値が不正です\n");
	judge=true;
      }
  if(HEIGHT<=GOAL_Z || GOAL_Z<0)
    {
      fprintf(stderr,"GOAL_Zの値が不正です\n");
      judge=true;
    }
  if(SPLIT_RATIO<0 || 100<SPLIT_RATIO)
    {
      fprintf(stderr,"SPLIT_RATIOの値が不正です\n");
      judge=true;
    }

  if(judge)
    exit(0);
}
