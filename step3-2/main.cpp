#include <bits/stdc++.h>

using namespace std;

long long a, b;

vector<long long> c;

bool check(long long mid)
{
    int count = 0;
    long long sum = 0;
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i]>mid)
        {
            return false;
        }
        sum += c[i];
        if (sum>mid)
        {
            count++;
            sum=c[i];
        }
    }
    return count<b;
}

int main()
{
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        long long ca;
        cin >> ca;
        c.push_back(ca);
    }
    long long high = 1e18, low = 0, mid;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (check(mid))
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