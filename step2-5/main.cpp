#include<bits/stdc++.h>

using namespace std;

double c;

bool check(double x)
{
	return pow(x,2)+pow(x,0.5)>=c;	
}

int main()
{
	double low,high,mid;
	cin>>c;
	
	low=0,high=c;
	
	for(int i=0;i<100;i++)
	{
		mid=(high+low)/2;
		if(check(mid))
			high=mid;
		else
			low=mid;
	}
	
	cout<<setprecision(10)<<high;
	
	return 0;
}