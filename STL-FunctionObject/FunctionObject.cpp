#include<iostream>
#include<vector>
#include<string>
using namespace std;
class MyAdd{
    public:
    int operator()(int a, int b){
        return a + b;
    }
};
class MyPrint{
    public:
    MyPrint(){this->flag = 0;}
    void operator()(const string&test){
        cout << test<< endl;
        this->flag++;
    }
    int flag = 0;
};
//1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01(){
    MyAdd myAdd;
    cout << myAdd(10, 20) << endl;
}
//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
void test02(){
    MyPrint myPrint;
    myPrint("hello slam");
    myPrint("hello slam");
    myPrint("hello slam");
    myPrint("hello slam");
    cout << "打印次数为：" << myPrint.flag << endl;
}
//3.函数对象可以作为参数传递
void doPrint(MyPrint &mp, const string &s){
    mp(s);
    mp(s);
    mp(s);
}
void test03(){
    MyPrint myPrint;
    doPrint(myPrint, "Have a nice day!");
}
/*
int main(){
    test01();
    test02();
    test03();    
    return 0;
}
*/