#include <bits/stdc++.h>
#include <vector>
using namespace std;

long long a, b;
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

int main()
{
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        int ca;
        cin>>ca;
        c.push_back(ca);
    }
    for (int i = 0; i < b; i++)
    {
        int d;
        cin>>d;
        cout<<getupper(d)+1<<endl;
    }
}