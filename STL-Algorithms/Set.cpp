#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include<algorithm>
//常用集合算法：set_intersection, set_union, set_difference
class DoPrint{
    public:
    void operator()(int val){
        cout << val << " ";
    }
};
void test01(){
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    for_each(v1.begin(), v1.end(), DoPrint());
    cout << endl;
    for_each(v2.begin(), v2.end(), DoPrint());
    cout << endl;

    //set_intersection
    cout << "两个容器的交集为：" << endl;
    vector<int>target1;
    target1.resize(min(v1.size(), v2.size()));
    vector<int>::iterator itEnd1 = 
        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), target1.begin());
    for_each(target1.begin(), itEnd1, DoPrint());
    cout << endl;

    cout << "----------------------" << endl;
    //set_union
    cout<<"两个容器的并集为：" << endl;
    vector<int>target2;
    target2.resize(v1.size() + v2.size());
    vector<int>::iterator itEnd2 = 
        set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), target2.begin());
    for_each(target2.begin(), itEnd2, DoPrint());
    cout << endl;

    cout << "-----------------------" << endl;
    //set_difference
    cout << "v1和v2的差集为：" << endl;
    vector<int>target3;
    target3.resize(max(v1.size(), v2.size()));
    vector<int>::iterator itEnd3 = 
        set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), target3.begin());
    for_each(target3.begin(), itEnd3, DoPrint());
    cout << endl;
    cout << "v2和v1的差集为：" << endl;
    vector<int>target4;
    target4.resize(max(v1.size(), v2.size()));
    vector<int>::iterator itEnd4 = 
        set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), target4.begin());
    for_each(target4.begin(), itEnd4, DoPrint());
    cout << endl;

}
int main(){
    test01();
    return 0;
}