#include <bits/stdc++.h>

using namespace std;

int compare(string s1, string s2)
{
    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
    {
        i++;
    }

    if (s1[i] > s2[i])
        return -1;
    
    return (s1[i] < s2[i]);
    
}

int search(string s[], string str, int first, int last)
{
    if (first > last)
        return -1;

    int mid = first + (last - first) / 2;

    if (s[mid].empty())
    {
        int left = mid - 1;
        int right = mid + 1;

        while(true)
        {
            if(left < right && right > last)
                return -1;
            
            if(right <= last && !s[right].empty())
            {
                mid = right;
                break;
            }
            if(left >= first && !s[left].empty())
            {
                mid = left;
                break;
            }
            right++;
            left--;
        }
    }
    if(compare(str, s[mid]) == 0)
        return mid;
    
    else if(compare(str, s[mid]) < 0)
        return search(s, str, mid + 1, last);
    
    return search(s, str, first, mid - 1);
}
int main()
{
    string s[] = {"at", "", "", "ball", "", "", "car", "", "", "dad", "", ""};

    string target = "a";

    int n = sizeof(s) / sizeof(s[0]);
    if(search(s, target, 0, n - 1) == -1)
        cout << "Given string is not present." << endl;
    else
        cout << "Given string is present at index: " << search(s, target, 0, n - 1);

    return 0;
}