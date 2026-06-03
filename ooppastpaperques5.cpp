#include <bits/stdc++.h>
using namespace std;
class RationalNumber
{
private:
    int numerator;
    int denominator;

public:
bool assign(int num, int deno)
{
    if (deno == 0)
    {
        return false;
    }
    numerator = num;
    denominator = deno;
    return true;
}
double convert()
{
    return (double)numerator / denominator;
}
void invert()
{
    if (numerator == 0)
    {
        cout << "Error: Division by zero is not possible." << endl;
        return;
    }
    swap(numerator, denominator);
}
//copy constructor 
RationalNumber(const RationalNumber &r)
{
    numerator = r.numerator;
    denominator = r.denominator;
    cout << "Copy constructor called" << endl;
}
//assignment operator overloading

RationalNumber &operator=(const RationalNumber &r)
{
    numerator = r.numerator;
    denominator = r.denominator;
    cout << "Assignment operator called" << endl;
    return *this;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
};
int main()
{
}