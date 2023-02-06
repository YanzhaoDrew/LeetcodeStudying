#include<iostream>
#include<functional>
using namespace std;
//算术仿函数
void test01(){
    //加法仿函数
    plus<int>p;
    cout << p(2, 6) << endl;
    
    //取反仿函数
    negate<int>n;
    cout << n(80) << endl;
}
/*
int main(){
    test01();
    return 0;
}
*/