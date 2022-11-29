#include <bits/stdc++.h>
using namespace std;

bool sorted(pair<int, int> &a, pair<int, int> &b)
{
    float d1 = (float) a.first / a.second;
    float d2 = (float) b.first / b.second;
    return (d1 > d2);
}

int main()
{
    vector<pair<int,int>> v = {{25, 18}, {24, 15}, {15, 10}};
    // vector<pair<int,int>> v = {{18, 25}, {15, 24}, {10, 15}};
    int capacity = 20;
    float ans = 0;
    // sort(v.begin(), v.end(), greater<>());
    // sort(v.begin(), v.end());
    sort(v.begin(), v.end(), sorted);
    int i = 0;
    while (capacity != 0)
    {
        if(capacity >= v[i].second)
        {
            ans += v[i].first;
            capacity -= v[i].second;
        }
        else
        {
            int c = capacity;
            float x = (float) capacity / v[i].second;
            float y = x * v[i].first;
            ans += y;
            capacity -= c;
        }
        // if(capacity >= v[i].first)
        // {
        //     ans += v[i].second;
        //     capacity -= v[i].first;
        // }
        // else
        // {
        //     float x = (float) capacity / v[i].first;
        //     float y = x * v[i].second;
        //     ans += y;
        //     capacity -= capacity;
        // }
        i++;
    }

    cout << "The maximum profit is: " << ans << endl;
    // cout << "The minimum weight is: " << ans << endl;
    
    return 0;
}