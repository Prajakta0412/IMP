#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
{
    vector<vector<int>> edges;

    for(int i = 0; i < buildings.size(); i++)
    {
        int x = edges.size();
        edges.push_back(vector<int>());
        edges[x].push_back(buildings[i][0]);
        edges[x].push_back(-buildings[i][2]);
        edges[x].push_back(buildings[i][1]);
    }

    for(int i =0; i < buildings.size(); i++)
    {
        int x = edges.size();
        edges.push_back(vector<int>());
        edges[x].push_back(buildings[i][1]);
        edges[x].push_back(0);
        edges[x].push_back(1e9);
    }

    sort(edges.begin(), edges.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> prevHighest;
    prevHighest.push({0, 1e9});

    vector<vector<int>> skyLine;

    for(int i = 0; i < edges.size(); i++)
    {
        int start = edges[i][0];
        int currHeight = -1 * edges[i][1];
        int end = edges[i][2];

        while(prevHighest.top().second <= start)
        {
            prevHighest.pop();
        }

        if(currHeight > 0)
        {
            prevHighest.push({-currHeight, end});
        }

        if(skyLine.size() == 0)
        {
            skyLine.push_back(vector<int>());
            skyLine[0].push_back(start);
            skyLine[0].push_back(-prevHighest.top().first);
        }
        else if(skyLine.back()[1] != -prevHighest.top().first)
        {
            int x = skyLine.size();
            skyLine.push_back(vector<int>());
            skyLine[x].push_back(start);
            skyLine[x].push_back(-prevHighest.top().first);
        }
    }
    return skyLine;
}

int main()
{
    vector<vector<int>> buildings = {{1, 5, 11}, {2, 7, 6}, {3, 9, 13}, {12, 16, 7}, {14, 25, 3}, {19, 22, 18}, {23, 29, 13}, {24, 28, 4}};

    vector<vector<int>> ans = getSkyline(buildings);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    
    return 0;
}