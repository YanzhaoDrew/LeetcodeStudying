#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>
#include<deque>
#include<time.h>

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
//五名选手ABCDE，10个评委分别对每个选手打分，去除最高分和最低分，取平均分
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
//创建选手
void creatPerson(vector<Person>& v){
    string nameset;
    nameset.assign("ABCDE");
    for (int flag = 0; flag < 5; flag++){
        Person p("选手", 0);
        p.name += nameset[flag];
        v.push_back(p);
    }
}
//评委评分，确定平均分
void setscore(vector<Person> &v){
    //使得每次的随机数都不同
    srand((unsigned int)time(NULL));

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++){
    deque<int>d;
        for (int j = 0; j < 10; j++){
            int s = rand()%21 + 70;//使用随机数，并且控制在70到90之间
            //但这个随机数是确定的，每次都一样
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
//输出每个选手的成绩
void printScore(vector<Person> &v){
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << "姓名为：" << (*it).name << " 得分为：" << (*it).score << endl;
    }
}
void test07(){
    //创建成员
    vector<Person>v;
    creatPerson(v);
    //评委打分
    setscore(v);
    //输出成员评分
    printScore(v);
}
#include<stack>
//stack使用
void test08(){
    stack<int>s;
    for (int i = 0; i < 10; i++)
        s.push(i);
    cout << s.size() << endl;
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl << s.size() << endl;
}

#include<queue>
//queue使用
void test09(){
    queue<int>q1;
    //构造
    //queue<int>q2(q1);
    //q2 = q1;
    q1.push(40);
    q1.push(20);
    q1.push(30);
    q1.push(10);
    cout << q1.size() << endl;
    while (!q1.empty())
    {
        cout << "队头元素为：" <<q1.front() << endl;
        cout << "队尾元素为：" << q1.back() << endl;
        q1.pop();
    }
    cout << q1.size() << endl;
}

#include<list>
void print_list(const list<int>&l){
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
        cout << *it << " ";
    cout << endl;
}
void information_list(const list<int>&l){
    if (l.empty()){
        cout << "list 为空" << endl;
    }
    else{
        cout << "list 不为空"<< endl;
        cout << "list 元素个数为："<< l.size() << endl;
    }
}
bool compare(int a, int b){
    return a > b;
}
void test10(){
    //构造
    list<int>l;
    l.push_back(20);
    l.push_back(10);
    l.push_back(50);
    l.push_back(30);
    print_list(l);

    list<int>l1(l.begin(), l.end());
    print_list(l1);

    list<int>l2(l1);
    //l2 = l;
    print_list(l2);
    
    list<int>l3(10, 99);
    print_list(l3);

    //赋值与交换
    l1.assign(l3.begin(), l3.end());
    print_list(l1);

    l1.assign(10, 33);
    print_list(l1);

    l1 = l2;
    cout << "交换前：" << endl;
    print_list(l1);
    print_list(l3);
    l1.swap(l3);
    cout << "l1与l3交换后：" << endl;
    print_list(l1);
    print_list(l3);
    
    //大小
    cout << "对于l："<< endl;
    print_list(l);
    information_list(l);
    l.resize(10, 88);
    print_list(l);
    information_list(l);
    l.resize(2);
    print_list(l);
    information_list(l);

    cout << "------------------" << endl;
    //插入与删除
    list<int>l4;
    l4.assign(l3.begin(), l3.end());
    print_list(l4);
    l4.push_back(100);
    l4.push_front(200);
    l4.push_front(100);
    l4.push_back(200);
    print_list(l4);
    
    l4.pop_front();
    l4.pop_back();
    l4.insert(l4.begin(), 66);
    l4.insert(l4.end(), 2, 55);
    print_list(l4);
    list<int>::iterator it = l4.begin();
    it++;
    it++;
    l4.erase(it);
    print_list(l4);

    //特殊功能，能够移除指定元素的作用域
    l4.remove(55);
    print_list(l4);

    l4.clear();
    information_list(l4);

    //list数据存取
    list<int>l5;
    //srand((unsigned int)time(NULL));
    for( int i = 0 ; i < 8; i++){
        l5.push_back(rand()%10);
    }
    print_list(l5);
    cout << "第一个元素为：" << l5.front() << endl;
    cout << "最后一个元素为：" << l5.back() << endl;

    //反转与排序！！！----- 使用l5作为例子
    l5.reverse();
    print_list(l5);
    
    //list无法用algorithm库中的sort()来排序，因为list的迭代器不是随机的，是双向的
    l5.sort();//默认从小到大
    print_list(l5);

    l5.sort(compare);//改为从大到小
    print_list(l5);
}

//set容器
#include<set>
void print_set(const set<int>&s){
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void information_set(const set<int>&s){
    if (s.empty())
        cout << "set为空" << endl;
    else
    {
        cout << "set不为空" << endl;
        cout << "set大小为：" <<s.size() << endl;        
    }
}
void judge_set(pair<set<int>::iterator, bool> &judge){
    if (judge.second){
        cout << "插入成功" << endl;
        cout << "插入元素为：" << *judge.first << endl;
    }
    else
        cout << "插入失败" << endl;
}
class Mycompare{
    public:
    bool operator()(int a, int b){
        return a > b;
    }
};
class ComparePerson{
    public:
    bool operator()(const Person&p1,const Person&p2){
        return p1.score < p2.score;
    }
};
void test11(){
    //构造与赋值
    set<int>s;
    s.insert(30);
    s.insert(10);
    s.insert(40);
    s.insert(20);
    print_set(s);

    //大小与交换
    information_set(s);
    set<int>s1;
    s1.insert(300);
    s1.insert(100);
    s1.insert(400);
    s1.insert(200);
    cout << "交换前："<<endl;
    print_set(s);
    print_set(s1);
    s.swap(s1);
    cout << "交换后：" << endl;
    print_set(s);
    print_set(s1);
    
    cout << "--------------------" << endl;
    //插入与删除，以s1为例子
    print_set(s1);
    s1.erase(s1.begin());//删除的是排序后的第一个元素
    cout << "第一次删除：" << endl;
    print_set(s1);
    s1.erase(30);//指定元素删除
    cout << "第二次删除: " << endl;
    print_set(s1);
    //相当于s1.clear();
    s1.erase(s1.begin(), s1.end());
    cout << "set清空后的状态：" << endl;
    information_set(s1);

    cout << "----------------" << endl;
    //查找与统计
    set<int>s2;
    s2.insert(20);
    s2.insert(30);
    s2.insert(40);
    s2.insert(10);
    print_set(s2);
    set<int>::iterator pos = s2.find(30);
    if(pos != s2.end())
        cout << "已找到元素：" << *pos << endl;
    else
        cout << "未找到元素" << endl;
    
    pos = s2.find(100);
    if(pos != s2.end())
        cout << "已找到元素：" << *pos << endl;
    else
        cout << "未找到元素" << endl;
    
    cout << "从set中找到20的统计次数为：" << s2.count(20) << endl;
    cout << "从set中找到100的统计次数为：" << s2.count(100) << endl;
    //对于set的统计次数，只可能是1或0，因为set不接受重复的元素

    cout << "------------------" << endl;
    //set 和 multiset的区别
    //set不接受重复的数据
    set<int>s3;
    pair<set<int>::iterator, bool> judge = s3.insert(10);
    judge_set(judge);
    judge = s3.insert(10);
    judge_set(judge);
    //multiset接受重复数据，且返回值为该值进入multiset后位置的迭代器
    multiset<int>s4;
    s4.insert(20);
    s4.insert(10);
    s4.insert(30);
    multiset<int>::iterator it = s4.insert(20);
    for (multiset<int>::iterator it = s4.begin(); it != s4.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    cout << "插入multiset中的元素为" << *it << endl;

    cout << "------------------------" << endl;
    //pair对组的创建
    pair<string, int> p("Tommy", 20);
    cout << "Name: " << p.first << " Age: " << p.second << endl;
    pair<string, int> p1 = make_pair("Tina", 18);
    cout << "Name: " << p1.first << " Age: " << p1.second << endl;

    cout << "------------------------" << endl;
    //内置类型指定排序规则
    set<int, Mycompare>s5;
    s5.insert(30);
    s5.insert(20);
    s5.insert(40);
    s5.insert(10);
    for (set<int, Mycompare>::iterator it = s5.begin(); it != s5.end(); it++){
        cout << *it <<" ";
    }
    cout << endl;

    //自定义数据类型指定排序规则
    set<Person, ComparePerson>s6;
    Person t1("Tommy", 7);
    Person t2("Victor", 5);
    Person t3("Ryan", 6);
    Person t4("Tina", 2);


    s6.insert(t1);
    s6.insert(t2);
    s6.insert(t3);
    s6.insert(t4);

    for(set<Person, ComparePerson>::iterator it = s6.begin(); it != s6.end(); it++){
        cout << "姓名为：" << (*it).name << " 得分为：" << (*it).score << endl;
    }
}
//map容器,插入后根据key值进行排序
#include<map>
    void print_map(const map<int, int>&m){
        for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++){
            cout << "Key: " << (*it).first << " Value: " << (*it).second << endl;
        }
        cout << endl;
    }
    void information_map(const map<int, int> &m){
        if (!m.empty()){
            cout <<"map容器不为空" << endl;
            cout << "map容器大小为: " << m.size() << endl;
        }
        else
            cout << "map容器为空" << endl;
    }
    class mapCompare{
        public:
        bool operator()(int a, int b){
            return a > b;
        }
    };
    void print_map(const map<int, int, mapCompare>&m){
        for (map<int, int, mapCompare>::const_iterator it = m.begin(); it != m.end(); it++){
            cout << "Key: " << (*it).first << " Value: " << (*it).second << endl;
        }
        cout << endl;
    }
    class PersonCompare{
        public:
        bool operator()(const Person &p1, const Person &p2){
            return p1.score > p2.score;
        }
    };
void test12(){
    //构造
    map<int, int>m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 10));
    m1.insert(pair<int, int>(3, 10));
    m1.insert(pair<int, int>(4, 10));
    print_map(m1);

    map<int, int>m2(m1);
    print_map(m2);

    map<int, int>m3;
    m3 = m1;
    print_map(m3);
    m3.clear();

    //大小与交换
    m3.insert(map<int, int>::value_type(5, 100));
    m3.insert(map<int, int>::value_type(7, 100));
    m3.insert(map<int, int>::value_type(6, 100));
    cout <<"交换前：" << endl;
    print_map(m1);
    information_map(m1);
    print_map(m3);
    information_map(m3);

    m1.swap(m3);

    cout<<"交换后："<<endl;
    print_map(m1);
    information_map(m1);
    print_map(m3);
    information_map(m3);
    
    cout<<"-------------------------" << endl;
    //插入与删除
    print_map(m3);
    //三种插入方法
    //第一种
    m3.insert(pair<int, int>(5, 500));
    //第二种
    m3.insert(make_pair(6, 80));
    //第三种
    m3.insert(map<int, int>::value_type(7, 50));
    print_map(m3);

    m3.erase(m3.begin());
    print_map(m3);
    m3.erase(5);
    print_map(m3);

    //和m3.clear();一样的作用
    //m3.erase(m3.begin(), m3.end());
    //information_map(m3);

    cout <<"----------------------------" << endl;
    //查找与统计
    map<int, int>::iterator pos = m3.find(4);

    if (pos != m3.end()){
        cout << "找到相应key值为： " << (*pos).first << " 对应value为：" << (*pos).second <<endl;
    }
    else
        cout << "未找到相应key值。" << endl;

    cout << "统计map容器中 key=7 出现的次数为：" << m3.count(7) << endl;

    //排序
    map<int, int, mapCompare>m4;
    m4.insert(pair<int, int>(1, 60));
    m4.insert(pair<int, int>(5, 30));
    m4.insert(pair<int, int>(4, 40));
    m4.insert(pair<int, int>(2, 20));
    m4.insert(pair<int, int>(3, 90));
    print_map(m4);

    //value represent age
    map<Person, int, PersonCompare>m5;
    Person p1("Tom", 8);
    Person p2("Tina", 5);
    Person p3("Ryan", 2);
    Person p4("Kyrie", 10);
    m5.insert(pair<Person, int>(p1, 24));
    m5.insert(pair<Person, int>(p2, 19));
    m5.insert(pair<Person, int>(p3, 23));
    m5.insert(pair<Person, int>(p4, 20));
    for (map<Person, int, PersonCompare>::iterator it = m5.begin(); it != m5.end(); it++){
            cout << "name：" << (*it).first.name << " socore：" << (*it).first.score << " Value: " << (*it).second << endl;
        }
        cout << endl;
}
int main(){
    //test01();

    //test02();

    //test03();

    //test04();

    //test05();

    //test001();
    
    //test06();
    
    //test07();

    //test08();
    
    //test09();

    //test10();
    
    //test11();

    test12();

    return 0;
}