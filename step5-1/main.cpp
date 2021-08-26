#include <bits/stdc++.h>

using namespace std;
long long a, b;
vector< pair<long long, long long> > c;


bool check(long long mid){
    long long count=0;
    for (int i = 0; i < a; i++)
    {
        if (mid>c[i].second)
        {
            count+=min(c[i].second,mid)-c[i].first+1;
        }
        else if(mid>c[i].first)
        {
            count+=mid-c[i].first;
        }
    }
    return count<=b;
}


int main()
{
    cin >> a >> b;
    c.resize(a);
    for (int i = 0; i < a; i++)
    {
        cin>>c[i].first>>c[i].second;
    }
    long long high=1e10,low=-1e10,mid;
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