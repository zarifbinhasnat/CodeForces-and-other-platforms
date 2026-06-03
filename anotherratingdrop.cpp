#include <bits/stdc++.h>
using namespace std;
// void tobinary(int i, char *arr, int size)
// {
//     int index = size - 1;
//     arr[index--] = '\0';

//     while (i > 0 && index >= 0)
//     {
//         arr[index--] = (char)('0' + (i % 2));
//         i /= 2;
//     }
// }

long long calculateUnfairness(long long n)
{
    long long unfairness = n;
    for (long long power = 2; power <= n; power *= 2)
    {
        unfairness += n / power;
    }
    return unfairness;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long result = calculateUnfairness(n);
        cout << result << endl;
    }
}