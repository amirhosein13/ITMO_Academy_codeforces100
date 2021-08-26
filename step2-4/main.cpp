#include <bits/stdc++.h>

using namespace std;

bool check(long long mid, long long a, long long b, long long c[][3])
{
    long long result = 0;
    for (int i = 0; i < b; i++)
    {
        long long asd = c[i][0] * c[i][1] + c[i][2];
        long long fakea = (mid / asd) * c[i][1];
        result += fakea;
        long long fake = mid % (long long)((c[i][0] * c[i][1]) + c[i][2]);
        fake = min(fake, (asd - c[i][2]));
        result += fake / c[i][0];
    }
    if (result >= a)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    long long a, b;
    cin >> a >> b;
    long long c[b][3];
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> c[i][j];
        }
    }
    if (a == 0)
    {
        cout << 0 << endl;
        for (int i = 0; i < b; i++)
        {
            cout << 0 << " ";
        }
    }
    else
    {
        long long high = 1e17, low = -1e17, mid;
        while (high - low > 1)
        {
            mid = (high + low) / 2;
            if (check(mid, a, b, c))
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        cout << high << endl;
        for (int i = 0; i < b; i++)
        {
            int result = 0;
            long long asd = c[i][0] * c[i][1] + c[i][2];
            long long fakea = (high / asd) * c[i][1];
            result += fakea;
            long long fake = high % (long long)((c[i][0] * c[i][1]) + c[i][2]);
            fake = min(fake, (asd - c[i][2]));
            result += fake / c[i][0];
            cout << result << " ";
        }
    }
}