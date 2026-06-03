#include <iostream>
class A
{
private:
    int abc;
    int def;

public:
    A(int a, int b) : abc(a), def(b)
    {
        std::cout << "A" << std::endl;
    }
    
};
class derievd : public A
{
private:
    int ghi;
    int jkl;

public:
    derievd(int a, int b, int c, int d) :ghi(c), jkl(d)
    {
        std::cout << "derievd" << std::endl;
    }
};
using namespace std;
int main()
{
}