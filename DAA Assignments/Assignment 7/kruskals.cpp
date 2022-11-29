#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    int v;
    vector<vector<int>> adj;
    Graph(int v)
    {
        this->v=v;
       
    }

    void addEdge(int u,int v,int w)
    {
        adj.push_back({w,u,v});
    }
    void makeset(vector<int> &parent,vector<int> &rank)
    {
        for(int i=0;i<v;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
        
    }
    int findparent(vector<int> &parent,int n){
        if(parent[n]==n)
        return n;
        return parent[n]=findparent(parent,parent[n]);
    }
   void uni(int u,int v,vector<int> &parent,vector<int> &rank)
   {
     u=findparent(parent,u);
     v=findparent(parent,v);
    if(rank[u]>rank[v])
    {
        parent[v]=u;
    }
    else if(rank[v]>rank[u])
    {
        parent[u]=v;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }

   }
    void kruskals(){
        int mincost=0;
        vector<int>parent(v);
        vector<int>rank(v);
        makeset(parent,rank);
        sort(adj.begin(),adj.end());
        for(auto it:adj)
        {
            int n1=findparent(parent,it[1]);
            int n2=findparent(parent,it[2]);
            int w=it[0];
            if(n1!=n2)
            {
                uni(n1,n2,parent,rank);
                mincost+=w;
                cout<<"("<<it[1]<<"->"<<it[2]<<")"<<"->"<<w<<endl;
            }
        }
        cout<<mincost;

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
    g.kruskals();
    return 0;
}