#include<iostream>
#include<limits.h>
using namespace std;
#define V 9
int posofmin(int distance[V],bool shdistiden[V])
{
    int mini = INT_MAX;
    int index;
    for(int i=0 ; i<V ; i++)
    {
        if(shdistiden[i]==0)
        {  if(distance[i]<=mini)
           {
            mini = distance[i];
            index = i;
           }
        }
    }
    return(index);
}
void dijkstra(int graph[V][V],int start)
{
   int distance[V];
   bool shdistiden[V];
   for(int i=0 ; i<V ; i++)
      {
          distance[i]   = INT_MAX ;
          shdistiden[i] = false ;
      }
  distance[0] = 0;
  int u = posofmin(distance,shdistiden);
  //cout<<u;
  shdistiden[u] = true;
}
int main()
{
    int graph[V][V]=  {
                      {0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0,  0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14,10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1,  6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7,  0}
                      };
    dijkstra(graph,0);
    return(0);
}

