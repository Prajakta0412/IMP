#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {0, 4, 3, 2, 7, 8, 2, 3, 1};

    for(int i = 0; i < 9; i++)
    {
        arr[arr[i] % 9] = arr[arr[i] % 9] + 9;
    }

    for(int i = 0; i < 9; i++)
    {
        if(arr[i] >= 18)
        {
            cout << "Yes, there are repeated elements." << endl;
            break;
        }
    }
    cout << "Repeated elements are: ";
    for(int i = 0; i < 9; i++)
    {
        if(arr[i] >= 18)
        {
            cout << i <<" ";
        }
    }
    cout << endl;
    return 0;
}