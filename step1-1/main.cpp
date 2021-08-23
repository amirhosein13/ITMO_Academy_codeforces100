#include <iostream>

using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n], b[k];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < k; i++)
    {
        int low = 0, high = n - 1, mid = (low + high) / 2;
        while (high - low != 1)
        {
            if (b[i] > a[mid])
            {
                low = mid;
                mid = (low + high) / 2;
            }
            else if (b[i] < a[mid])
            {
                high = mid;
                mid = (low + high) / 2;
            }
            if (high - low == 1)
            {
                cout << "NO" << endl;
            }
            if (b[i] == a[mid] || b[i] == a[low] || b[i] == a[high])
            {
                cout << "YES" << endl;
                high = low + 1;
            }
        }
    }
}