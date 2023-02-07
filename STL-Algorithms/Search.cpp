#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>
//查找算法: find, find_if, adjacent_find, binary_search, count, count_if

class Person{
    public:
    Person(const string &name, const int &age){
        this->name = name;
        this->age = age;
    }
    bool operator==(const Person& p){
        return p.age == this->age; 
    }
    string name;
    int age;
};
class MyCompare{
    public:
    bool operator()(int val){
        return val > 8;
    }
};
class PersonCompare{
    public:
    bool operator()(const Person& p){
        return p.age >= 19; 
    }
};
//find, find_if
void test01(){
    //find
    vector<int>v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }
    vector<int>::iterator pos = find(v.begin(), v.end(), 5);
    if (pos != v.end()){
        cout << "已找到元素为： " << *pos << endl;
    }
    else {
        cout << "未找到元素" << endl;
    }
    
    vector<Person>v1;
    Person p1("Tom", 24);
    Person p2("Ryan", 26);
    Person p3("pearlie", 19);
    Person p4("Tommy", 35);
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p4);
    v1.push_back(p3);
    
    Person p("Tina", 19);
    vector<Person>::iterator pos1 = find(v1.begin(), v1.end(), p);
    if (pos1 != v1.end()){
        cout << "已找到与Tina相同年龄的人为: " << (*pos1).name << "  age: " << (*pos1).age << endl;
    }
    else
        cout << "未找到与Tina相同年龄的人" << endl;

    cout << "---------------------------" << endl;
    //find_if
    vector<int>v2;
    for (int i = 0; i < 10; i++){
        v2.push_back(i);
    }
    vector<int>::iterator pos2 = find_if(v2.begin(), v2.end(), MyCompare());
    if (pos2 != v2.end()){
        cout << "已找到元素为： " << *pos2 << endl;
    }
    else {
        cout << "未找到元素" << endl;
    }

    vector<Person>::iterator pos3 = find_if(v1.begin(), v1.end(), PersonCompare());
    if (pos3 != v1.end()){
        cout << "已找到与大于等于19岁的人为: " << (*pos3).name << "  age: " << (*pos3).age << endl;
    }
    else
        cout << "未找到与大于等于19岁的人" << endl;
}

//adjacent_find
void test02(){
    vector<int>v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    v.push_back(9);
    v.push_back(3);
    v.push_back(9);
    
    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos != v.end()){
        cout << "已找到相同相邻元素为：" << *pos << endl;
    }
    else
        cout << "未找到相同相邻元素" << endl;
}

//binary_search
void test03(){
    vector<int>v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }
    bool pos = binary_search(v.begin(), v.end(), 8);
    if (pos)
        cout << "已找到元素7" << endl;
    else
        cout << "未找到元素7" << endl;
}

//count, count_if
class Greater2{
    public:
    bool operator()(int val){
        return val > 2;
    }
};
class Less20{
    public:
    bool operator()(const Person&p){
        return p.age < 20;
    }
};
void test04(){
    vector<int>v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(7);
    v.push_back(4);
    v.push_back(4);
    v.push_back(9);

    int times = count(v.begin(), v.end(), 4);
    cout << "数字4出现的次数为：" << times << endl;

    cout << "---------------------" << endl;
    vector<int>v1;
    v1.push_back(4);
    v1.push_back(2);
    v1.push_back(7);
    v1.push_back(4);
    v1.push_back(4);
    v1.push_back(9);
    
    int times1 = count_if(v.begin(), v.end(), Greater2());
    cout << "已找到大于2的元素个数为：" << times1 << endl; 

    vector<Person>v2;
    Person p1("Tom", 24);
    Person p2("Ryan", 26);
    Person p3("pearlie", 19);
    Person p4("Tommy", 35);
    Person p5("James", 24);
    Person p6("Kyrie", 19);
    Person p7("Tina", 24);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    v2.push_back(p5);
    v2.push_back(p6);
    v2.push_back(p7);
    int situation20 = count_if(v2.begin(), v2.end(), Less20());
    cout << "已找到小于20岁的人数：" << situation20 << endl;
}
int main(){
    //test01();
    //test02();
    //test03();
    test04();
    return 0;
}

