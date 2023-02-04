#include"Personnel.cpp"
#include<vector>
#include<map>
#include<time.h>
#include<string>
int main(){
    vector<Personnel>v;
    creatPersonnel(v);
    
    //测试
    //for(vector<Personnel>::iterator it = v.begin(); it != v.end(); it++){
        //cout << (*it).name << "的工资为：" << (*it).wage << endl;
    //}

    //遍历vector容器分配部门
    multimap<int, Personnel>m;
    creatapartment(v, m);
    print_Personnel(m);
}