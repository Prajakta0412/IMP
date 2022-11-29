#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    int v;
    vector<pair<int,int>> *adj;
    Graph(int v)
    {
        this->v=v;
        adj=new vector<pair<int,int>>[v];
    }

    void addEdge(int u,int v,int w)
    {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    void prims()
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int src=0;
        vector<int>key(v,1e9);
        vector<int>parent(v,-1);
        vector<int>mst(v,0);
        pq.push({0,src});
        while(!pq.empty())
        {
            int node=pq.top().second;
            pq.pop();
            if(mst[node]==1){
                continue;
            }
            mst[node]=1;
            for(auto it:adj[node])
            {
                int v=it.first;
                int w=it.second;
                if(mst[v]==0 && w<key[v])
                {
                    key[v]=w;
                    pq.push({w,v});
                    parent[v]=node;
                }
            }
        }
        for(int i=1;i<v;i++)
        {
            cout<<parent[i]<<"->"<<i<<" ("<<key[i]<<")"<<endl;
        }
    }
};
int main()
{
    int v=10;
    Graph g(v);
    g.addEdge(0, 1, 15);
    g.addEdge(0, 8, 19);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 8, 7);
    g.addEdge(1, 3, 17);
    g.addEdge(2, 8, 16);
    g.addEdge(2, 4, 14);
    g.addEdge(3, 1, 17);
    g.addEdge(3, 8, 12);
    g.addEdge(3, 9, 20);
    g.addEdge(3, 5, 13);
    g.addEdge(4, 2, 14);
    g.addEdge(4, 8, 6);
    g.addEdge(4, 9, 9);
    g.addEdge(4, 6, 5);
    g.addEdge(5, 3, 13);
    g.addEdge(5, 9, 4);
    g.addEdge(5, 7, 2);
    g.addEdge(7, 6, 18);
    g.addEdge(6, 9, 1);
    g.addEdge(7, 9, 11);
    g.addEdge(9, 8, 3);
    g.prims();
    return 0;
}