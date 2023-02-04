#include<iostream>
using namespace std;
class Personnel{
public:
    string name;
    int wage;
    Personnel(const string& name, const int &wage){
        this->name = name;
        this->wage = wage;
    }
};