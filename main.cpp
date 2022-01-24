#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int> adj[],int u,int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}
void printGraph(vector<int>adj[],int V)
{
  for(int i=1;i<V+1;i++)
  {
    cout<<"\n"<<i;
      for(auto it:adj[i])
      cout<<" -> "<<it;
    cout<<"\n";
  }
}
void CreateGraph(vector<int>adj[],int V)
{
  addedge(adj,1,2);
  addedge(adj,2,3);
  addedge(adj,2,4);
  addedge(adj,3,5);
  addedge(adj,4,5);
  addedge(adj,5,6);
  addedge(adj,6,7);
  addedge(adj,6,8);
  cout<<"\nAdjacemcy List: \n";
  printGraph(adj,V);
}
vector<int> isBFS(vector<int>adj[],int V,vector<int> &vis)
{
  vector<int> bfs;
  queue<int> q;
  for(int i=1;i<V+1;i++)
  {
    if(!vis[i])
    {
      q.push(i);
      vis[i]=1;
      while(!q.empty())
      {
        int node=q.front();
        q.pop();
        bfs.push_back(node);
          for(auto it:adj[node])
          {
            if(!vis[it])
            q.push(it);
            vis[it]=1;
          }
      }
    }
  }
  return bfs;
}
bool isCycle(vector<int> adj[],int V,vector<int>& vis)
{
  queue<pair<int,int> > q;
  for(int s=0;s<V+1;s++)
  {
    vis[s]=true;
    q.push({s,-1});
    while(!q.empty())
    {
      int node=q.front().first;
      int par=q.front().second;
      q.pop();
      for(auto it:adj[node])
        {
        if(!vis[it])
          {
          vis[it]=true;
          q.push({it,node});
          }
        else if(par!=it)
          return true;
        }
    }
  }
  return false;
}
bool isBipartite(vector<int> adj[],int V,vector<int>& color)
{
  queue<int> q;
  for(int s=1;s<=V;s++)
  {
    color[s]=1;
    q.push(s);
    while(!q.empty())
    {
      int node=q.front();
      q.pop();
      for(auto it:adj[node])
      {
        if(color[it]==-1)
        {
          color[it]=1-color[node];
          q.push(it);
        }
        else if(color[it]==color[node])
          return false;
      }
    }
  }
  return true;
}
int main()
{
  int V=8;
  vector<int>adj[V+1];
  vector<int>vis(V+1,0);
  vector<int>color(V+1,-1);
  CreateGraph(adj,V);

  vector<int>bfs;
  bfs=isBFS(adj,V,vis);
  cout<<"BFS traversal\n";
  cout<<"===============\n";
  for(int i=0;i<bfs.size();i++)
    cout<<bfs[i]<<" ";
  cout<<"\n";

  if(isCycle(adj,V,vis))
  cout<<"\n===============>   Cycle Exist";
  else
  cout<<"\n===============>   No Cycle Exist";
  cout<<"\n";

  if(isBipartite(adj,V,color))
  cout<<"\n===============>   Bipartite";
  else
  cout<<"\n===============>   Not Bipartite";
  cout<<"\n";

  return 0;
}