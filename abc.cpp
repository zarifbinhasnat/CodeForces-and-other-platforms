#include<bits/stdc++.h>
using namespace std;

float FindSmallest(float num1, float num2, float num3) {
    return min(min(num1, num2), num3);
}

float FindLargest(float num1, float num2, float num3) {
    return max(max(num1, num2), num3);
}

int CalculateSum(int largestnum) {
    int i = 0, a;
    while (largestnum != 0) {
        i += largestnum % 10;
        largestnum = largestnum / 10;
    }
    return i;
}

//int IsNice(int num1) {
//    int cnt = 0, m = 0;
//    while (num1 != 0) {
//        int a = num1 % 10;
//        if (a % 2 == 0)
//            cnt++;
//        else
//            m++;
//        num1 = num1 / 10;
//    }
//    if (num1 ==0 ||cnt==m)
//    return 1;
//    else return 0;
//
//}
int IsNice(int num1){
     if(num1==0){
          return 0;
     }
     if(num1<0){
          num1*=-1;
     }

     int a=num1,o=0,e=0;
     while(a>0){
          int d=a%10;
          if(d%2==0){
               e++;
          }
          else{
               o++;
          }
          a/=10;
     }
     if(e==o){
          return 1;
     }
     else{
          return 0;
     }
}

int NiceCount(int start, int end) {
    int c = 0;
    for (int i = start; i <= end; i++) {
        if (IsNice(i))              
            c++;
    }
    return c;
}

int main() {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    float num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    cout << "The smallest number is " << FindSmallest(num1, num2, num3) << endl;
    cout << "The largest number is " << FindLargest(num1, num2, num3) << endl;
    cout << "Digit Sum " << abs(CalculateSum(FindLargest(num1, num2, num3))) << endl;
    cout << "Nice number count between " << NiceCount(FindSmallest(num1, num2, num3), FindLargest(num1, num2, num3));
}
