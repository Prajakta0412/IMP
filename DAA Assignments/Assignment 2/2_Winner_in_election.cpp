#include <bits/stdc++.h>
using namespace std;

void findWinner(int arr[], int n)
{
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    int max = INT_MIN;
    int winner;
    for(auto i: m)
    {
        int key = i.first;
        int val = i.second;
        if(val > max)
        {
            max = val;
            winner = key;
        }
    }
    cout << "Winner: " << winner << endl;
    cout << "Maximum votes: " << max << endl;
}

int main()
{
    int arr[] = {4, 6, 5, 6, 4, 5, 3, 3, 4, 6, 3, 6, 4};
    findWinner(arr, 13);
    return 0;
}