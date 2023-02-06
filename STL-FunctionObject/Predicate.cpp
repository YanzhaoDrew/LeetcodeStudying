#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
class GreaterFive{
    public:
    bool operator()(int v){
        return v > 5;
    }
};
class MyCompare{
    public:
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};
//one element
void test01(){
    vector<int>v1;
    for (int i = 1; i < 11; i++)
        v1.push_back(i);
    for (vector<int>::iterator it = v1.begin();it != v1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    vector<int>::iterator it = find_if(v1.begin(), v1.end(), GreaterFive());
    if (it != v1.end())
        cout << "已找到大于五的数字为：" << *it << endl;
    else {
        cout << "未找到大于五的数字" << endl;
    }
}
//two elements
void test02(){
    vector<int>v;
    v.push_back(200);
    v.push_back(300);
    v.push_back(400);
    v.push_back(500);
    v.push_back(100);
    for (vector<int>::iterator it = v.begin();it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    cout << "-------------------" << endl;
    sort(v.begin(), v.end(), MyCompare());
    for (vector<int>::iterator it = v.begin();it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
/*
int main(){
    test01();
    test02();
    return 0;
}
*/