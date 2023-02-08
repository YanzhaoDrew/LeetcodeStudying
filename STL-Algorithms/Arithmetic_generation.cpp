#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include<algorithm>
//常用算术生成算法：accumulate, fill
class DoPrint{
    public:
    void operator()(int val){
        cout << val << " ";
    }
};
//accumulate
void test01(){
    vector<int>v;
    for (int i = 1; i < 101; i++){
        v.push_back(i);
    }
    int result = accumulate(v.begin(), v.end(), 0);
    cout << "vector容器中的元素总和为：" << result << endl;
}
//fill
void test02(){
    vector<int>v;
    v.resize(11);
    for_each(v.begin(), v.end(), DoPrint());
    cout << endl;
    fill(v.begin(), v.end(), 88);
    for_each(v.begin(), v.end(), DoPrint());
    cout << endl;
}
int main(){
    //test01();
    test02();
    return 0;
}