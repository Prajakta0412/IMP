#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    int v;
    vector<vector<int>> adj;
    Graph(int v)
    {
        this->v = v;
       
    }

    void addEdge(int u,int v,int w)
    {
        adj.push_back({w,u,v});
    }
    
    void dijkstra(){
        int src=0;
        unordered_map<int,list<pair<int,int>>>eg;
        for(int i=0;i<adj.size();i++)
        {
            int w=adj[i][0];
            int u=adj[i][1];
            int v=adj[i][2];
            eg[u].push_back({v,w});
            eg[v].push_back({u,w});
        }
        vector<int>dist(v,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty())
        {
            int no=pq.top().second;
            int ndis=pq.top().first;
            pq.pop();
            for(auto it:eg[no])
            {
                int node=it.first;
                int weight=it.second;
                if(dist[node]>(dist[no]+weight))
                {
                    
                    dist[node]=dist[no]+weight;
                    pq.push({dist[node],weight});
                }
            }
        }
        cout<<"Started"<<endl;
        for(int i=0;i<dist.size();i++)
        {
            cout<<i<<": "<<dist[i]<<endl;
        }
    }
};
int main()
{
    int v=4;
    Graph g(v);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 8);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 2, 9);
    g.addEdge(2, 3, 6);
   
  
    g.dijkstra();
    return 0;
}