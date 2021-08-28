#include <bits/stdc++.h>

using namespace std;

long long a, b;

pair<int, int> check(vector<int> &c, double mid)
{
    vector<double> de(a + 1), dm(a + 1);
    vector<int> di(a + 1);

    de[0] = c[0] - mid;
    dm[0] = de[0];
    di[0] = 0;

    for (int i = 1; i <= a; i++)
    {
        de[i] = de[i - 1] + c[i] - mid;

        if (de[i] < dm[i - 1])
        {
            dm[i] = de[i];
            di[i] = i;
        }
        else
        {
            dm[i] = dm[i - 1];
            di[i] = di[i - 1];
        }
    }
    for (int i = b; i <= a; i++)
    {
        if (de[i] >= dm[i - b])
        {
            int l = di[i - b] + 1;
            return {l, i};
        }
    }
    return {-1, -1};
}

int main()
{
    cin >> a >> b;
    vector<int> c(a + 1);
    for (int i = 1; i <= a; i++)
    {
        cin >> c[i];
    }
    double high = 101, low = -1,mid;
    pair<int, int> result, co;
    for (int i = 0; i < 40; i++)
    {
         mid = (high + low) / 2;
        co = check(c, mid);
        if (co.first == -1)
        {
            high = mid;
        }
        else
        {
            result = co;
            low = mid;
        }
    }
    cout << result.first << " " << result.second << endl;
}