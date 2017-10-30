#include<iostream>
using namespace std;
class test
{
    private : int a ;
              static int count;
    public  : void getdata(int b)
              {
               a = b;
               count++;
              }
              void putdata(void)
              {
                cout<<count;
              }
};
int test::count;
int main()
{
    test t1,t2,t3;
    t1.putdata();
    t2.putdata();
    t3.putdata();
    t1.getdata(100);
    t2.getdata(2);
    t3.getdata(3);
      t1.putdata();
    t2.putdata();
    t3.putdata();
}
