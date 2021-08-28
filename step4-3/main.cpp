#include <bits/stdc++.h>
#include <vector>

using namespace std;
vector< pair<long long, long long> > c;

long long a, b;

bool check(double mid){
    vector<double> d(a);
    for (int i = 0; i < a; i++)
    {
        d[i]=c[i].first-c[i].second*mid;
    }
    sort(d.begin(),d.end());
    double e=0;
    for (int i = 1; i <= b; i++)
    {
        e+=d[a-i];
    }
    return e<=0;
}

int main()
{
    cin >> a >> b;
    c.resize(a);
    for (int i = 0; i < a; i++)
    {
        cin >> c[i].first >> c[i].second;
    }
    double high=1e18,low=-1,mid;
    for (int i = 0; i < 200; i++)
    {
        mid=(high+low)/2;
        if (check(mid))
        {
            high=mid;
        }
        else
        {
            low=mid;
        }
    }
    cout<<setprecision(10)<<fixed<<high<<endl;
}