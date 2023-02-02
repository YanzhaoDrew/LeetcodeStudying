#include<iostream>
#include<string>
#include<list>
using namespace std;

class Person{
public:
    string name;
    int age;
    int height;
    Person(string name, int age, int height){
        this->name = name;
        this->age = age;
        this->height = height;
    }
};

void print_list(const list<Person>&l){
    for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++){
        cout << "姓名为：" << (*it).name << "   年龄为：" << (*it).age << " 身高为：" << (*it).height << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
}
bool compare(Person p1, Person p2){
    if (p1.age != p2.age)
        return p1.age < p2.age;
    else
        return p1.height > p2.height;
}
int main(){
    Person p1("Tommy", 25, 172);
    Person p2("Victor", 30, 170);
    Person p3("Amy", 22, 160);
    Person p4("Ryan", 27, 175);
    Person p5("Tina", 22, 163);

    list<Person>l;
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);

    cout << "未排序前：" << endl;
    print_list(l);
    
    l.sort(compare);
    cout << "排序后：" << endl;
    print_list(l);
}