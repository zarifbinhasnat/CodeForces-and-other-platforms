#include <bits/stdc++.h>
using namespace std;

/**
 * The main function is the entry point of the program.
 * It reads input from a file named "input.txt" and writes output to a file named "output.txt".
 * It performs a specific operation on an array of characters based on the given input.
 * The operation swaps adjacent elements in the array if the current element is 'G' and the previous element is 'B'.
 * Finally, it prints the modified array to the console.
 *
 * @return 0 indicating successful execution of the program.
 */
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, t;
    cin >> n >> t;
    char ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    for (int i = 0; i < t; i++)
    {
        for (int i = 1; i < n; i++)
        {
            
              if (ar[i] == 'G' && ar[i-1] == 'B')
                swap(ar[i-1], ar[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ar[i];
    }

    return 0;
}
