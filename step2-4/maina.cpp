#include<bits/stdc++.h>

using namespace std;

long long m,n,cur;
long long t[15001],z[15001],y[15001],ans[15001];

bool good(long long time)
{
	long long i,temp=time;
	cur=0;
	memset(ans,0,sizeof(0));
	for(i=0;i<n;i++)
	{
		time=temp;
		if(time/t[i]>z[i])
		{
			ans[i]=z[i]*(time/((t[i]*z[i])+y[i]));
			time=time%((t[i]*z[i])+y[i]);
			if(time/t[i]>z[i])
				ans[i]+=z[i];
			else
				ans[i]+=(time/t[i]);
		}
		else
			ans[i]=time/t[i];
		cur+=ans[i];
	}
	return cur>=m;
}

int main()
{
	long long i,l,r,mid;
	cin>>m>>n;
	
	for(i=0;i<n;i++)
		cin>>t[i]>>z[i]>>y[i];
	
	if(m==0)
	{
		cout<<0<<endl;
		for(i=0;i<n;i++)
			cout<<0<<" ";
		return 0;
	}
	
	l=0,r=1e9;
	
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(good(mid))
			r=mid;
		else
			l=mid;
	}
	bool last=good(r);
	long long c=m;

	cout<<r<<endl;
	for(i=0;i<n;i++)
	{
		cout<<max((long long)0,min(c,(long long)ans[i]))<<" ";
		c-=ans[i];
	}
	return 0;
}
