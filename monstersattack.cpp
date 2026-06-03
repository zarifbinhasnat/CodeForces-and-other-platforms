#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n>>k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        vecotr<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        //take the abs of all the elements of the second array
        for(int i=0;i<n;i++){
            a[i]=abs(a[i]);
        }
        //sort the second array in descending order
        sort(a.begin(),a.end(),greater<int>());
        //sum of the elements in the first array
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        //k divided by sum of the elements in the first array
        int x=k/sum;
        //if k is bigger than the biggest value of the second array
        if(k>a[0]){
            cout<<"NO<<endl;
        }
        else 
        cout<<"YES"<<endl;
        }
        


    return 0;
}
