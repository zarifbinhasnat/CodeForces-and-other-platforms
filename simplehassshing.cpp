#include<iostream>
#include<vector>
using namespace std;
size_t simplehshing(string s){
    size_t hash =0;
    for(char c:s)
    {
        hash = hash*31 + c ;
    }
    return hash;
}
int main()
{
    string key ="example";
    cout<<"Hash value for '"<<key<<"'is:"<<simplehshing(key)<<endl;
    return 0;

}