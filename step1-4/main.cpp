#include <bits/stdc++.h>
#include <vector>

long long a, b;
using namespace std;
vector<long long> c;

long long getupper(long long d)
{
    long long high = c.size(), low = -1, mid;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (c[mid] < d)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
   return high;
}

long long getlower(long long d)
{
    long long high = c.size(), low = -1, mid;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (c[mid] > d)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return low;
}

int main()
{
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int ca;
        cin >> ca;
        c.push_back(ca);
    }
    sort(c.begin(), c.end());
    cin >> b;
    int f, g;
    for (int i = 0; i < b; i++)
    {
        cin >> f >> g;
        int ff = getupper(f);
        int gg = getlower(g);
        cout << gg - ff + 1 << " ";
    }
}