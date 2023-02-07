#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<ctime>
#include<functional>
//常用排序算法：sort, random_shuffle, merge, reverse
//sort
class doprint{
    public:
    void operator()(int val){
        cout << val << " ";
    }
};
//sort
void test01(){
    vector<int>v;
    v.push_back(2);
    v.push_back(6);
    v.push_back(3);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    v.push_back(20);
    sort(v.begin(), v.end(), less<int>());
    for_each(v.begin(), v.end(), doprint());
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), doprint());
    cout << endl;
}

//random_shuffle
void test02(){
    srand((unsigned int)time(NULL));
    vector<int>v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }
    cout <<"未随机前："  <<endl;
    for_each(v.begin(), v.end(), doprint());
    cout << endl;

    cout << "随机后：" << endl;
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), doprint());
    cout << endl;
}
//merge
void test03(){
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
        v2.push_back(i+1);
    }
    vector<int>target;
    //记得要先分配内存空间
    target.resize(v1.size()+v2.size());
    //两个vector容器必须是有序且同序才能使用merge
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    for_each(target.begin(), target.end(), doprint());
}
//reverse
void test04(){
    vector<int>v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }
    cout << "未反转前：" << endl;
    for_each(v.begin(), v.end(), doprint());
    cout << endl;
    cout << "反转后：" << endl;
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), doprint());
    cout << endl;

}
int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    return 0;
}