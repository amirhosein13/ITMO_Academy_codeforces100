#include <bits/stdc++.h>

using namespace std;

long long aa, bb;
vector<long long> a;

bool check(long long x)
{
    long long cc = x;
    x *= aa;
    for (int i = 0; i < a.size(); i++)
    {
        x -= min(cc, a[i]);
    }
    return x <= 0;
}

int main()
{
    cin >> aa >> bb;
    a.resize(bb);
    for (int i = 0; i < bb; i++)
    {
        cin >> a[i];
    }
    long long low=0, high=1e12, mid;
    while (high-low>1)
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