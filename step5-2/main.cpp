#include <bits/stdc++.h>

using namespace std;
long long a, b;

bool check(long long mid){
    long long count=0;
    for (int i = 1; i <= a; i++)
    {
        if (mid%i==0)
        {
            count+=min(a,mid/i-1);
        }
        else
        {
            count+=min(a,mid/i);
        }        
    }
    return count<b;
}

int main()
{
    cin >> a >> b;
    long long high=a*a+1,low=0,mid;
    while (high-low>1)
    {
        mid=(high+low)/2;
        if (check(mid))
        {
            low=mid;
        }
        else
        {
            high=mid;
        }
    }
    cout<<low<<endl;
}