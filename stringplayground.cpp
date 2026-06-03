#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    unordered_map<string, int> votes;
vector<string> ballot = {"Alice", "Bob", "Alice", "Charlie"};
for (const string& vote : ballot) {
    votes[vote]++;
}
unordered_map<string, int> scores;
scores["player1"] = 10;
scores["player2"] = 15;
unordered_map<string, int> wordCount;
vector<string> words = {"apple", "banana", "apple", "orange", "banana"};
for (const string& word : words) {
    wordCount[word]++;
}
for(auto it = wordCount.begin(); it != wordCount.end(); it++) {
    cout<< wordCount[orange] << endl;
}
for(auto it = wordCount.begin(); it != wordCount.end(); it++) {
    cout << it->first << " " << it->second << endl;
}
unordered_map<string, int> freq;
    return 0;    
}

