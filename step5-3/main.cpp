#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
long long c, d;
vector<long long> a, b;

bool check(long long mid)
{
    long long count = 0;
    for (long long i = 0; i < c; i++)
    {
        if (a[i] >= mid)
            continue;
        count += lower_bound(b.begin(), b.end(), mid - a[i]) - b.begin();
    }
    return count < d;
}

int main(void)
{
    cin >> c >> d;
    a.resize(c);
    b.resize(c);
    for (int i = 0; i < c; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < c; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long high = 1e18, low = 0, mid;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (check(mid))
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    cout << low << endl;
}