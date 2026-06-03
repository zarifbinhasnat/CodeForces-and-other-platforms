#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sum = 0;
    int maxsum = INT_MIN;
    int ansstart = -1, ansend = -1;
    int temstart = 0;
    vector<int> v(5);
    v = {-1, -2, 3, 0, 4};
    for (int i = 0; i < 5; i++)
    {
        sum += v[i];
        
            if (sum < 0){
                temstart = i + 1;
            sum = 0;
        }
        if (sum > maxsum)
        {
            maxsum = sum;
            ansstart = temstart;
            ansend = i;
        }
    }
    cout << "Max sum: " << maxsum << "\n";
    cout << "Start index: " << ansstart << ", End index: " << ansend << "\n";

    return 0;
}
