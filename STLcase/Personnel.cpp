#include"Personnel.h"
#include<map>
#include<string>
#include<vector>
#include<map>
#define CHEHUA 1
#define MEISHU 2
#define YANFA 3
void creatPersonnel(vector<Personnel> &v){
    srand((unsigned int)time(NULL));
    string setname;
    setname.assign("ABCDEFGHIJ");
    for (int i = 0; i < 10; i++){
        string firstname("员工");
        firstname += setname.at(i);
        Personnel p(firstname, rand()%8000);
        v.push_back(p);
    }
}
//1----策划
//2----美术
//3----研发
void creatapartment(const vector<Personnel>&v, multimap<int, Personnel>&m){
    srand((unsigned int)time(NULL));
    for (vector<Personnel>::const_iterator it = v.begin(); it != v.end(); it++){
        m.insert(pair<int, Personnel>(rand()%3+1, *it));
    }
}
void print_Personnel(const multimap<int, Personnel>&m){
    //改进方法
    cout << "策划部门：" << endl;
    multimap<int, Personnel>::const_iterator flag = m.find(CHEHUA);
    int times = m.count(CHEHUA);
    int index = 0;
    for (;flag != m.end() && index < times; index++, flag++){
        cout << (*flag).second.name << " 工资为：" << (*flag).second.wage << endl;
    }
    cout << "------------------------------" << endl;
    cout << "美术部门：" << endl;
    flag = m.find(MEISHU);
    times = m.count(MEISHU);
    index = 0;
    for (;flag != m.end() && index < times; index++, flag++){
        cout << (*flag).second.name << " 工资为：" << (*flag).second.wage << endl;
    }
    cout << "------------------------------" << endl;
    cout << "研发部门：" << endl;
    flag = m.find(YANFA);
    times = m.count(YANFA);
    index = 0;
    for (;flag != m.end() && index < times; index++, flag++){
        cout << (*flag).second.name << " 工资为：" << (*flag).second.wage << endl;
    }
    //原始方法
    /*cout << "策划部门：" << endl;
    for (multimap<int, Personnel>::const_iterator it = m.begin();it != m.end(); it++){
        if((*it).first != 1)
            break;
        cout << (*it).second.name << " 工资为：" << (*it).second.wage << endl;
    }
    cout << "美术部门：" << endl;
    for (multimap<int, Personnel>::const_iterator it = m.begin();it != m.end(); it++){
        if((*it).first == 3)
            break;
        if((*it).first == 2)
            cout << (*it).second.name << " 工资为：" << (*it).second.wage << endl;
    }
    cout << "美术部门：" << endl;
    for (multimap<int, Personnel>::const_iterator it = m.begin();it != m.end(); it++){
        if((*it).first == 3)
            cout << (*it).second.name << " 工资为：" << (*it).second.wage << endl;
    }
    */
}