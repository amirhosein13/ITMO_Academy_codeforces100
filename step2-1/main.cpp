#include <bits/stdc++.h>

using namespace std;

long long w, h, n;

bool f(long long x){
	if (x < w || x < h)
		return false;

	if (x / w > n || x / h > n)
		return true;

	return (x / w) * (x / h) >= n;
}

int main(){
	cin >> w >> h >> n;
	
	long long low = 0, high = 1e18+10;
	while (high - low > 1){
		long long mid = (low + high) >> 1;
		if (f(mid))
			high = mid;
		else 
			low = mid;
	}

	cout << high << endl;

	return 0;
}
