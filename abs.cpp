#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int n ;
    cin>>n;
while(n--)
{
    int k,sum=1;
    cin>>k;
    int arr[k];
    for  (int i=0;i<k;i++)
    {
        cin>>arr[i];
    }
    for  (int i=0;i<k;i++)
    {
        sum*=arr[i];
    }
    if (k > 0) {
        int maxElement = arr[0];
        int maxIndex = 0;

        for (int i = 1; i < k; ++i) {
            if (arr[i] > maxElement) {
                maxElement = arr[i];
                maxIndex = i;
            }
        }
    if (sum<=0)
    {
        cout<<'0'<<endl;
    }

    if(sum>0)
    {
        cout<<'1'<<endl;
        cout<<'1'<<" "<<'0'<< endl;
    }
    
}
    
}
return 0;
}