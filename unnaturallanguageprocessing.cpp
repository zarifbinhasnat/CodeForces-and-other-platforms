#include<bits/stdc++.h>
using namespace std;
 void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string res = "";
	while (!s.empty()) {
		int x;
		if (s.back() == 'a' || s.back() == 'e') {x = 2;}
		else {x = 3;}
		
		while (x--) {
			res += s.back();
			s.pop_back();
		}
		res += '.';
	}
	res.pop_back();//removes the last extra dot
	reverse(res.begin(), res.end());
	cout << res << '\n';
}
int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; 
    for (int i = 1; i <= tt; i++)
     {
        solve();
     }


    return 0;
}
