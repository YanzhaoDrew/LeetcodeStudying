#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
void test01(){
    vector<bool>v;
    v.push_back(true);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    
    vector<bool>v1;
    v1.resize(v.size());//设置好容量，够位置放
    transform(v.begin(), v.end(), v1.begin(), logical_not<bool>());
    for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
/*
int main(){
    test01();
    return 0;
}
*/