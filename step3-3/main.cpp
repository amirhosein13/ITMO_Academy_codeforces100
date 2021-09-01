#include <bits/stdc++.h>

using namespace std;

long long a, b;
vector<long long>c;

bool check(long long mid)
{
    long long count=1;
    long long p=0;
    for (int i = 1; i < a; i++)
    {
        if (c[i]-c[p]>=mid)
        {
            p=i;
            count++;
        }
    }
    
    return count>=b;
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
    long long low = 0, high = 1e10, mid;
    while (high - low > 1)
    {
        mid = (high + low) >>1;
        if (check(mid))
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

   cout<<low<<endl;
}