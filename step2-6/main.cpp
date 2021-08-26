#include <bits/stdc++.h>

using namespace std;

string s, ss;
vector<int> a;

bool check(int n)
{
    string sss = "", temp = s;

    for (int i = 0; i < n; i++)
    {
        temp[a[i] - 1] = '0';
    }
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp[i] != '0')
            sss += temp[i];
    }
   int i = 0,j = 0;
    while (i < sss.length() && j < ss.length())
    {
        if (sss[i] == ss[j])
            j++;
        i++;
    }

    return j == ss.length();
}

int main()
{

    cin >> s >> ss;

    a.resize(s.length());

    for (int i = 0; i < s.length(); i++)
        cin >> a[i];

    int low = 0, high = s.length() - ss.length() + 1, mid;

    while (high - low > 1)
    {
        mid = (low + high) / 2;
        if (check(mid))
            low = mid;
        else
            high = mid;
    }

    cout << low;

    return 0;
}