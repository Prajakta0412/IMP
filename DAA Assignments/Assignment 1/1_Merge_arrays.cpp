// C++ program to merge two sorted arrays/
#include <bits/stdc++.h>
using namespace std;

void mergeArrays(int arr1[], int arr2[], int n1, int n2)
{
    int n3 = n1 + n2 - 1;
    int i = n1 - 1;
    int j = n2 - 1;

    while(j >= 0)
    {
        if(i >= 0 && arr1[i] > arr2[j])
        {
            arr1[n3] = arr1[i];
            i--;
        }
        else{
            arr1[n3] = arr2[j];
            j--;
        }
        n3--;
    }
}

// Driver code
int main()
{
    int arr1[] = {1, 3, 5, 7, -1, -1, -1, -1};
    int n1 = 4;

    int arr2[] = {2, 3, 6, 8};
    int n2 = 4;

    mergeArrays(arr1, arr2, n1, n2);

    cout << "Array after merging" << endl;
    for (int i = 0; i < 8; i++)
        cout << arr1[i] << " ";

    return 0;
}