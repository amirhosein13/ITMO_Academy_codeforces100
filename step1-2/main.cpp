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
        if (n <= 2)
        {
            if (b[i] == a[high])
            {
                cout << high + 1 << endl;
            }
            else if (b[i] == a[low])
            {
                while (a[low + 1] == a[low])
                {
                    low++;
                }
                cout << low + 1 << endl;
            }
            else if (b[i] >= a[high])
            {
                cout << high + 1 << endl;
            }
            else if (b[i] <= a[low])
            {
                cout <<0<< endl;
            }
            else if (b[i] >= a[low] && b[i] <= a[high])
            {
                cout << low + 1 << endl;
            }
        }
        else
        {

            while (high - low != 1)
            {
                if (b[i] == a[high])
                {
                    cout << high + 1 << endl;
                    break;
                }
                else if (b[i] == a[low])
                {
                    while (a[low + 1] == a[low])
                    {
                        low++;
                    }
                    cout << low + 1 << endl;
                    break;
                }

                if (b[i] == a[mid])
                {
                    while (a[mid + 1] == a[mid])
                    {
                        mid++;
                    }

                    cout << mid + 1 << endl;
                    break;
                }
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
                    if (b[i] > a[low] && b[i] < a[high])
                    {
                        while (a[low + 1] == a[low])
                        {
                            low++;
                        }
                        cout << low + 1 << endl;
                    }
                    else if (b[i] > a[high])
                    {
                        cout << n << endl;
                    }
                    else
                    {
                        cout << 0 << endl;
                    }
                    break;
                }
            }
        }
    }
}