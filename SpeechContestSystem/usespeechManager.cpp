#include"speechManager.cpp"
#include<ctime>
int main(){
    //随机数种子
    srand((unsigned int)time(NULL));
    //创建管理类对象
    SpeechManager sm;
    
    //用于测试输入成员
    /*
    for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
        cout << "选手编号：" << (*it).first << " 姓名：" << (*it).second.name << " 成绩：" << (*it).second.score << endl;
    */
    int choice = 0;//用于存储用户输入
    
    while(true){
    sm.show_Menu();
    
    cout << "请输入你的选择： " << endl;
    
    cin >> choice;
    switch (choice)
    {
    case 1: // 开始比赛
        sm.startSpeech();
        break;
    case 2: // 查看往届比赛记录
        sm.loadRecord();
        sm.showRecore();
        break;
    case 3: // 清空比赛记录
        sm.clearRecord();
        break;
    case 0: // 退出系统
        sm.exitSystem();
    default:
        system("clear");
        break;
    }
    }
    return 0;
}