#include<iostream>
#include<algorithm>  // Include for reverse function
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        
        // Swap 'p' and 'q' characters
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] == 'p')
                s[i] = 'q';
            else if(s[i] == 'q')
                s[i] = 'p';
        }
        
        // Reverse the string
        reverse(s.begin(), s.end());
        
        // Output the modified string
        cout << s << endl;
    }
}
