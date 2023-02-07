#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
//常用遍历算法
void myPrint(int a){
    cout << a << " ";
}
class MyPrint{
    public:
    void operator()(int a){
        cout << a << " ";
    }
};
//for_each
void test01(){
    vector<int>v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    for_each(v.begin(),v.end(), MyPrint());
    cout << endl;

}
//transform
class Transform{
    public:
    int operator()(int val){
        return val;
    }
};
void test02(){
    vector<int>v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(), MyPrint());
    cout << endl;

    vector<int>target;
    target.resize(v.size());
    transform(v.begin(), v.end(), target.begin(), Transform());
    for_each(target.begin(),target.end(), MyPrint());
    cout << endl;
}
int main(){
    test01();

    test02();

    return 0;
}