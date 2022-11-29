#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n)
{
    int arr_max = arr[0];
    for(int i = 0; i < n; i++)
    {
        arr_max = max(arr_max, arr[i]);
    }
    return arr_max;
}

void countSort(int arr[], int n, int pos)
{
    int output[n];
    int count[10] = {0};

    for(int i = 0; i < n; i++)
    {
        count[(arr[i] / pos) % 10]++;
    }

    for(int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0; i--)
    {
        output[--count[(arr[i] / pos) % 10]] = arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);

    for(int pos = 1; m / pos > 0; pos *= 10)
    {
        countSort(arr, n, pos);
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }   

    radixSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}