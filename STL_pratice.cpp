#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>
#include<deque>

void MyPrint(const int& val){
    cout << val << endl;
}
//int数据类型vector三种遍历方式尝试
void test01(){
    vector<int>v;
    v.push_back(2003);
    v.push_back(12);
    v.push_back(10);
    //第一种
    vector<int>::iterator itbegin = v.begin();
    vector<int>::iterator itend = v. end();
    while (itbegin != itend){
        cout << *itbegin << endl;
        itbegin++;
    }
    cout <<"--------------------" << endl;
    
    //第二种
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << endl;
    }
    cout <<"---------------------" << endl;

    //第三种
    for_each(v.begin(), v.end(), MyPrint);
    cout <<"---------------------" << endl;
}

//不同数据类型的vector遍历，例如类，指针
/*
class Person{
    public:
    string name;
    int age;
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
};
//类
void test02(){
    vector<Person>v;

    Person p1("Henry", 23);
    Person p2("Tom", 19);
    Person p3("Victor", 21);
    Person p4("Nancy", 18);
    
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout <<"His or Her name: "<< it->name <<", His or Her age: " << it->age << endl;
        //另一种写法也行
        //cout <<"His or Her name: "<< (*it).name <<" His or Her age: " << (*it).age << endl;
    }
    cout << "----------------------" << endl;
}
//类指针
void test03(){
    vector<Person*>v;

    Person p1("Henry", 23);
    Person p2("Tom", 19);
    Person p3("Victor", 21);
    Person p4("Nancy", 18);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++){
        cout <<"His or her name: "<< (*it)->name << ", his or her age:" <<(*it)->age << endl;
    }
    cout << "----------------------" << endl;
}
*/
//嵌套vector
void test04(){
    vector<vector<int>>v;

    vector<int>v1;
    vector<int>v2;
    vector<int>v4;
    vector<int>v3;

    for(int i = 0; i < 4; i++){
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for(vector< vector<int>>::iterator it = v.begin(); it != v.end(); it++){
        for(vector<int>::iterator itt = (*it).begin(); itt != (*it).end(); itt++){
            cout << *itt << " ";
        } 
        cout << endl;
    }
}

//vector类
void print_vector(vector<int> &v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void information_vector(vector<int> &v){
    if (v.empty()){
        cout << "该vector数组为空" << endl;
    }
    else
    {
        cout << "该vector数组的容量为：" << v.capacity() << endl;
        cout << "该vector数组的大小为：" << v.size() << endl;
    }
}
void test001(){
    //构造
    vector<int>v1;
    for(int i = 0; i< 10; i++){
        v1.push_back(i);
    }
    print_vector(v1);

    vector<int>v2(v1.begin(), v1.end());
    print_vector(v2);

    vector<int>v3(v2);
    print_vector(v3);

    vector<int>v4(10, 99);
    print_vector(v4);

    cout << endl;//赋值
    vector<int>v5;
    v5 = v3;
    print_vector(v5);

    vector<int>v6;
    v6.assign(v5.begin(), v5.end());
    print_vector(v6);

    v6.assign(10, 88);
    print_vector(v6);

    cout << endl;//容量与大小, 以v6为example
    information_vector(v6);
    v6.resize(12);//多出的长度默认用零填充
    print_vector(v6);
    information_vector(v6);
    
    v6.resize(0);//尝试清空数组
    information_vector(v6);
    
    v6.resize(14, 99);//多出的长度用99填充
    print_vector(v6);
    information_vector(v6);

    cout << endl;//插入与删除, use v6 array for example
    v6.push_back(100);//尾插法
    v6.push_back(100);
    v6.pop_back();//尾删法
    print_vector(v6);

    v6.insert(v6.begin(), 100);//插入法，第一参数是迭代器
    print_vector(v6);
    vector<int>::iterator it = v6.begin();
    it = it + 2;
    v6.insert(it, 2, 1000);
    print_vector(v6);
    
    v6.erase(v6.begin());//删除指定迭代器所指元素
    print_vector(v6);
    it++;
    v6.erase(v6.begin(), it);//删除两个迭代器所指区间
    print_vector(v6);
    /*
    v6.clear();//清空数组
    information_vector(v6);
    */
    
    cout << endl;//数据存取
    for (int i = 0 ; i < v6.size(); i++)//用[]读取
        cout << v6[i] << " ";
    cout << endl;
    for (int i = 0; i < v6.size(); i++)//用vector.at()读取
        cout << v6.at(i) << " ";
    cout << endl;

    v6.insert(v6.begin(), 11);
    v6.insert(v6.end(), 12);
    print_vector(v6);
    cout << "v6数组第一元素为：";
    cout << v6.front();
    cout << endl << "v6数组最后一个元素为：";
    cout << v6.back() << endl;

    cout << endl;//互换容器
    vector<int>vv1;
    for(int j = 1; j < 11; j++){
        vv1.push_back(j);
    }
    print_vector(vv1);
    vector<int>vv2;
    for (int j = 10; j > 0; j--){
        vv2.push_back(j);
    }
    print_vector(vv2);
    vv1.swap(vv2);
    print_vector(vv1);
    print_vector(vv2);

    cout<< endl;//预留空间
    vv2.reserve(100000);
    information_vector(vv2);//vv2的大小远远小于容量，浪费内存
    //采取操作
    vector<int>(vv2).swap(vv2);//使得大小与容量匹配
    information_vector(vv2);
}

//string类
void test05(){
    //赋值操作
    string s1;
    s1.assign("stupid");
    cout << s1 << endl;

    string s2;
    s2.assign(5, 'E');
    cout << s2 << endl;
    
    //拼接操作
    s1.append(s2);
    cout << s1 << endl;

    s1.append("AAAAA", 2);
    cout << s1 << endl;

    s1.append("BCDFG", 2 , 2);
    cout << s1 << endl;

    //查找操作
    string s3;
    s3.append("abcdefabcdef");
    //从左开始查找
    int pos = s3.find("cd");
    cout << pos << endl;
    //从右开始查找
    int rpos = s3.rfind("cd");
    cout << rpos << endl;

    //替换操作(替换其中选定的字符串或字符)
    s3.replace(2, 3, "12345");
    cout << s3 << endl;

    //比较
    string s4;
    s4.append("abcdefg");
    string s5;
    s5.append("xbcdefg");
    //s5.append("abcdefg");
    if (s4.compare(s5) == 0)
        cout << "两字符串相等" << endl;
    else if (s4.compare(s5) > 0)
        cout << "s4 > s5" << endl;
        else
        cout << "s4 < s5" << endl;
    
    //两种读取操作
    for (int i = 0; i < s4.size(); i++)
        cout << s4[i] << " " ;
    cout << endl;
    for (int i = 0; i < s4.size(); i++)
        cout << s4.at(i) << " ";
    cout<< endl;
    
    //插入与删除操作
    s4.insert(3, "12345");
    cout <<s4 << endl;
    s4.erase(3, 5);
    cout << s4 << endl;
    
    //获取操作
    string s6 = s4.substr(2, 3);
    cout << s6<<endl;
    
    //获取邮箱中的用户名称
    string email = "lihua@sina.com";
    int pos2 = email.find('@');
    string name = email.substr(0, pos2);
    cout << name << endl;
}

//deque数组的打印
void print_deque(const deque<int> &d){
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
        cout << *it << " ";
    cout << endl;
}
//大小
void judge_deque(const deque<int> &d){
    if(d.empty())
    {
        cout << "该deque数组为空" << endl;
    }
    else{
        cout << "该deque数组不为空"<< endl;
        cout << "大小为" << d.size() << endl;
    }
}
//deque类使用
void test06(){
    //构造
    deque<int>d1;
    for (int i = 1; i < 11; i++){
        d1.push_back(i);
    }
    print_deque(d1);
    deque<int>d2(d1.begin(), d1.end());
    print_deque(d2);
    deque<int>d3(10, 99);
    print_deque(d3);
    deque<int>d4(d2);
    print_deque(d4);

    //赋值
    d4.assign(d3.begin(), d3.end());
    print_deque(d4);
    d4.assign(8,88);
    print_deque(d4);
    d4 = d3;
    print_deque(d4);

    //大小
    judge_deque(d4);
    d4.resize(15);
    print_deque(d4);
    judge_deque(d4);
    d4.resize(20, 100);
    print_deque(d4);
    judge_deque(d4);

    //插入与删除
    deque<int>d5;
    d5.push_back(10);
    d5.push_back(20);
    d5.push_front(30);
    d5.push_front(40);
    print_deque(d5);

    d5.pop_back();
    d5.pop_front();
    print_deque(d5);
    
    d5.insert(d5.begin(), 99);
    d5.insert(d5.begin(), 2, 77);
    d5.insert(d5.end(), d4.begin(), d4.end());
    print_deque(d5);
    d5.erase(d5.end());
    print_deque(d5);
    d5.clear();
    print_deque(d5);
    judge_deque(d5);

    //deque数据存取
    for(int i = 0; i < d4.size(); i++){
        cout << d4[i] << " ";
    }
    cout << endl;

    for (int j = 0 ; j < d4.size(); j++){
        cout << d4.at(j) << " ";
    }
    cout << endl;
    cout <<"deque first element is : " << d4.front() << endl;
    cout << "deque last element is : " << d4.back() << endl;

    //排序sort, deque or vector is avaliable
    deque<int> d6;
    d6.push_back(20);
    d6.push_back(30);
    d6.push_front(40);
    d6.push_front(60);
    print_deque(d6);
    sort(d6.begin(), d6.end());
    print_deque(d6);
}

//STL_1 case:评委打分
class Person{
public:
    string name;
    int score;
    Person(const string &name, const int &score);
};
Person::Person(const string &name, const int &score){
        this->name = name;
        this->score = score;
}
void creatPerson(vector<Person>& v){
    string nameset;
    nameset.assign("ABCDE");
    int flag = 0;
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        Person("成员", 0);
        (*it).name += nameset[flag];
        flag++;
    }
}
void setscore(vector<Person> &v){
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++){
    deque<int>d;
        for (int j = 0; j < 10; j++){
            int s = rand()%31 + 70;
            d.push_back(s); 
        } 
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        int add = 0;
        for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
        add += *it;
        }
        int average = add / d.size();
        it->score = average;
    }
}
void printScore(vector<Person> &v){
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << "姓名为：" << (*it).name << " 得分为：" << (*it).score << endl;
    }
}
void test07(){
    //创建成员
    vector<Person>v;
    creatPerson(v);
    //测试
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << "姓名为：" << it->name << " 得分为：" << it->score << endl;
    }
    //评委打分
    setscore(v);
    //输出成员评分
    printScore(v);
}
int main(){
    //test01();

    //test02();

    //test03();

    //test04();

    //test05();

    //test001();
    
    //test06();
    
    test07();
    return 0;
}