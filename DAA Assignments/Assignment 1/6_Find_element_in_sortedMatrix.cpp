#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v[3][3] = {{3, 30, 38},
                   {44, 52, 54},
                   {57, 60, 69}};
    int N = 3, M = 3;
    int i = 0, j = M - 1;
    int X = 60;
    int ans = 0;
    while (i < N && j >= 0)
    {
        if (X == v[i][j])
        {
            ans = 1;
            cout << "Element " << v[i][j] << " is present in matrix at index (" << i << ", " << j << ").";
            break;
        }
        if (X > v[i][j])
            i++;
        else
            j--;
    }
    if (ans != 1)
        cout << "Element is not present in matrix.";
    return 0;
}