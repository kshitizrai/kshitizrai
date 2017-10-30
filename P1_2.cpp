#include <iostream>
using namespace std;

template<class T , class Y , class N>
Y& abc(T a , Y b , N c)
{
    Y x=a+b+c;
    return(x);
}

int main()
{
    double x=(12.33);
    int y=(12.15);
    float z=(12.85);
    cout<<abc(x,y,z);
}
