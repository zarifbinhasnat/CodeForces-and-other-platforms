#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a < d && b <= c)
        {
            if (b <= a)
            {
                cout << "Gellyfish" << endl;
            }
            else
            {
                cout << "Flower" << endl;
            }
        }
        else if (a >= d && b <= c)
        {
            cout << "Gellyfish" << endl;
        }
        else if (a < d && b >= c + 1)
        {
            cout << "Flower" << endl;
        }
        else
        {
            if (d <= c)
            {
                cout << "Gellyfish" << endl;
            }
            else
            {
                cout << "Flower" << endl;
            }
        }
    }
    return 0;
}
