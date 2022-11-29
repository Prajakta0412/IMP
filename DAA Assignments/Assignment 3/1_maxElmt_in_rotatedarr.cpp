#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] ={8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int l = 0, h = 10, mid = 0, ans = 0;
    while(l <= h)
    {
        mid = l + (h - l) / 2;
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            ans = arr[mid];
            break;
        }
        else if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
        {
            l = mid + 1;
        }
        else if(arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            h = mid - 1;
        }
    }
    cout << ans;
    return 0;
}