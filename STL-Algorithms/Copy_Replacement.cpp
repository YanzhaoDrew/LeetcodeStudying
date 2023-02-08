#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
//常用拷贝和替换算法：copy, replace, replace_if, swap
class Doprint{
    public:
    void operator()(int val){
        cout << val << " ";
    }
};
//copy
void test01(){
    vector<int>v;
    for (int i = 0; i <10; i++){
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), Doprint());
    cout << endl;
    vector<int>target;
    target.resize(v.size());
    copy(v.begin(), v.end(), target.begin());
    for_each(target.begin(), target.end(), Doprint());
    cout << endl;
    
}

class Greater40{
    public:
    bool operator()(int val){
        return val > 40;
    }
};
//replace, replace_if
void test02(){
    //replace
    vector<int>v1;
    v1.push_back(30);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(30);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(50);
    cout << "未替换前：" << endl;
    for_each(v1.begin(), v1.end(), Doprint());
    cout << endl;
    //30 替换为 100
    cout << "替换后：" << endl;
    replace(v1.begin(), v1.end(), 30, 100);
    for_each(v1.begin(), v1.end(), Doprint());
    cout << endl;

    cout << "---------------------" << endl;
    //replace_if
    vector<int>v2;
    v2.push_back(90);
    v2.push_back(80);
    v2.push_back(60);
    v2.push_back(10);
    v2.push_back(70);
    v2.push_back(40);
    v2.push_back(30);
    cout << "替换前：" << endl;
    for_each(v2.begin(), v2.end(), Doprint());
    cout << endl;
    //将大于40的替换为88
    cout << "替换后：" << endl;
    replace_if(v2.begin(), v2.end(), Greater40(), 88);
    for_each(v2.begin(), v2.end(), Doprint());
    cout << endl;
}

//swap
void test03(){
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+100);
    }
    cout << "交换前：" << endl;
    for_each(v1.begin(), v1.end(), Doprint());
    cout << endl;
    for_each(v2.begin(), v2.end(), Doprint());
    cout << endl;
    cout << "交换后：" << endl;
    swap(v1, v2);
    for_each(v1.begin(), v1.end(), Doprint());
    cout << endl;
    for_each(v2.begin(), v2.end(), Doprint());
    cout << endl;
}
int main(){
    //test01();
    //test02();
    test03();
    return 0;
}