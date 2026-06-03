#include <iostream>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
#endif

    int n;
    cin >> n;
    
    int ans = 0;
    int tot = 0;
    
    while (n--) {
        int temp;
        cin >> temp;
        
        if (temp == -1) {
            if (tot == 0)
                ans++;
            else
                tot--;
        } else {
            tot += temp;
        }
    }
    
    cout << ans << endl;
    return 0;
}
