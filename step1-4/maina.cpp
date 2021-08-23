#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n, k, start, end, low, high, mid, a, b;
    cin >> n;
    long long arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int z = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + z);

    cin >> k;
    while (k--)
    {
        cin >> start >> end;
        high = n;
        low = -1;
        while (high - low > 1)
        {
            mid = (high + low) >> 1;
            if (arr[mid] > end)
                high = mid;
            else
                low = mid;
        }
        b = low;
        high = n;
        low = -1;
        while (high - low > 1)
        {
            mid = (high + low) >> 1;
            if (arr[mid] < start)
                low = mid;
            else
                high = mid;
        }
        a = high;
        cout << (b - a) + 1 << " ";
    }

    return 0;
}