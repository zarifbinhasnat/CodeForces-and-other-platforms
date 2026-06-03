#include <bits/stdc++.h>
using namespace std;

int threewayminret(vector<int> &a, int l, int r)
{
    if (l == r)
        return a[l];
    if (r - l == 1)
        return min(a[l], a[r]);

    int len = r - l + 1;
    int mid1 = l + len / 3;
    int mid2 = l + 2 * len / 3;

    int leftMin = threewayminret(a, l, mid1 - 1);
    int middleMin = threewayminret(a, mid1, mid2 - 1);
    int rightMin = threewayminret(a, mid2, r);

    return min({leftMin, middleMin, rightMin});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Example usage:
    vector<int> a = {5, 2, 8, 1, 6, 3};
    cout << threewayminret(a, 0, a.size() - 1) << endl;

    return 0;
}