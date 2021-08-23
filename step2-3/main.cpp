#include <bits/stdc++.h>

using namespace std;

bool check(long long mid, long long a, long long b, long long c)
{
    mid -= min(b, c);
    if ((mid / b) + (mid / c)+1 >= a&&mid>=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    long long high = 1e17, low = 0, mid;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (check(mid, a, b, c))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    cout << high << endl;
}