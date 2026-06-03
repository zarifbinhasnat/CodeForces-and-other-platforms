#include <bits/stdc++.h>
using namespace std;
void printSubsequence(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    printSubsequence(input.substr(1), output + input[0]);
    printSubsequence(input.substr(1), output);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string output = "";
    string input = "abcd";
    printSubsequence(input, output);

    return 0;
}
