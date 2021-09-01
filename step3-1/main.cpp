#include <bits/stdc++.h>

using namespace std;

long long a;
vector<int> b, c;


bool check(double mid){
    double l=-1e10+10;
    double r=1e10+10;
    for (int i = 0; i <  a; i++)
    {
        double ll=b[i]-mid*c[i];
        double rr=b[i]+mid*c[i];

        l=max(l,ll);
        r=min(r,rr);

        if (l>r)
        {
            return false;
        }
    }
    return true;

}



int main()
{
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int ba, ca;
        cin >> ba >> ca;
        b.push_back(ba);
        c.push_back(ca);
    }

    double low=0,high=1e18,mid;

    for (int i = 0; i < 100; i++)
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
    
    cout<<setprecision(10)<<high<<endl;
    
}