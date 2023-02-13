#include"speechManager.h"
#include<fstream>
//构造函数
SpeechManager::SpeechManager(){
    //初始化容器和属性
    this->initSpeech();
    this->creatSpeaker();
}

//打印编号
class DoPrint{
    public:
    void operator()(int val){
        cout << val << " ";
    }
};
//菜单功能
void SpeechManager::show_Menu(){
    cout << "***********************************" << endl;
    cout << "********* 欢迎参加演讲比赛 ********" << endl;
    cout << "********* 1. 开始演讲比赛 *********" << endl;
    cout << "********* 2. 查看往届记录 *********" << endl;
    cout << "********* 3. 清空比赛记录 *********" << endl;
    cout << "********* 0. 退出比赛程序 *********" << endl;
    cout << endl; 
}

//退出系统
void SpeechManager::exitSystem(){
    cout << "欢迎下次使用" << endl;
    //system("read -p 'Press Enter to continue...' var");
    exit(0);
}

void SpeechManager::initSpeech(){
    //容器都置空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    //初始化比赛轮数
    this->Index = 1;

    //将记录的容器 也清空
    this->m_Record.clear();
}
void SpeechManager::creatSpeaker(){
    string nameSeed;
    nameSeed.assign("ABCDEFGHIJKL");
    for (int i = 0; i < nameSeed.size(); i++){
    
        string name("成员");
        name += nameSeed[i];
        Speaker sp;
        sp.name = name;
        for (int i =0; i< 2; i++){
            sp.score[i] = 0;
        }
    //12名选手编号
    this->v1.push_back(i + 1001);
    //选手编号 以及对应的选手 存放到map容器中
    this->m_Speaker.insert(pair<int, Speaker>(i + 1001, sp));
    
    }
}

//抽签功能
void SpeechManager::speechDraw(){
    if (this->Index == 1){
        //第一轮比赛
        cout << "第《" << Index << "》轮比赛选手正在抽签" << endl;
        cout << "---------------------------------------" << endl; 
        random_shuffle(this->v1.begin(), this->v1.end());
        cout << "抽签后演讲顺序如下：" << endl;
        for_each(v1.begin(), v1.end(), DoPrint());
        cout << endl;
        cout << "---------------------------------------" << endl; 
    }
    else
    {   
        //第二轮比赛
        cout << "第《" << Index << "》轮比赛选手正在抽签" << endl;
        cout << "---------------------------------------" << endl; 
        random_shuffle(v2.begin(), v2.end());
        cout << "抽签后演讲顺序如下：" << endl;
        for_each(v2.begin(), v2.end(), DoPrint());
        cout << endl;
        cout << "---------------------------------------" << endl;
    }
    system("read -p 'Press Enter to continue...' var");
}

//比赛
void SpeechManager::speechContest(){
    cout << "---------------第" << this->Index << "轮正式比赛开始：------------" << endl;

    //临时容器，保存Key分数 value 选手编号
    multimap<double, int, greater<double>>groupScore;

    int num = 0;//记录人员数：6个为1组

    vector<int>v_Src;//比赛的人员容器
    if (this->Index == 1){
        v_Src = v1;
    }
    else{
        v_Src = v2;
    }

    //遍历所有参赛选手
    for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++){
        num++;

        //评委打分
        deque<double>d;
        for (int i = 0; i < 10; i++){
            double score = (rand()%401 + 600) / 10.f;
            //cout << score << " ";
            d.push_back(score);
        }
        //cout << endl;

        sort(d.begin(), d.end(), greater<double>());
        d.pop_front();
        d.pop_back();

        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double average = sum / (double)d.size();
        //每个人平均分
        //cout << "编号：" << *it << " 姓名：" << this->m_Speaker[*it].name << " 平均分为：" << average << endl;
        this->m_Speaker[*it].score[Index - 1] = average;
        
        //6个人一组，用临时容器保存
        groupScore.insert(make_pair(average, *it));
        if (num % 6 == 0)
        {
            cout << "第" << num/6 << "小组比赛名次: "<< endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();it != groupScore.end(); it++)
            {
                cout << "编号：" <<it->second << " 姓名：" << this->m_Speaker[it->second].name << " 成绩： "<<this->m_Speaker[it->second].score[this->Index - 1] << endl;
            }

            int count = 0;
            //取前三名
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++){
                if (this->Index == 1)
                    v2.push_back((*it).second);
                else    
                    vVictory.push_back((*it).second);
            }
            groupScore.clear();

            cout << endl;
        }
    }
    cout << "-------------第" << this->Index <<"轮比赛完毕 --------------" << endl;
    system("read -p 'Press Enter to continue...' var");
}

//显示晋级结果
void SpeechManager::showScore(){
    cout << "------------第" << Index << "轮晋级选手信息如下：--------------" << endl;
    vector<int>v;
    if (Index == 1){
        v = v2;
    }
    else
    {
        v = vVictory;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << "选手编号：" << *it << " 姓名：" << this->m_Speaker[*it].name << " 得分：" << this->m_Speaker[*it].score[Index - 1] << endl;
    }
    cout << endl;

    system("read -p 'Press Enter to continue...' var");
    system("clear");
    this->show_Menu();
}
//保存前三名选手分数
void SpeechManager::saveRecord(){
    ofstream ofs;
    ofs.open("speech.csv", ios::out| ios::app);//用追加的方式写文件

    //将每个选手数据 写入到文件中
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++){
        ofs << *it << "," <<this->m_Speaker[*it].score[1] << ",";
    }
    ofs << endl;

    //关闭
    ofs.close();
    cout << "记录已经保存" << endl;
    //有记录了文件不为空
    this->fileIsEmpty = false;
}

//读取往届记录
void SpeechManager::loadRecord(){
    ifstream ifs("speech.csv", ios::in);//读文件
    //判断是否有此文件
    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        //cout << "文件不存在 " << endl;
        ifs.close();
        return;
    }

    //文件清空情况
    char ch;
    ifs >> ch;
    if (ifs.eof()){
        //cout << "文件为空" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //文件不为空
    this->fileIsEmpty = false;

    ifs.putback(ch);//将上面读取的单个字符 放回来

    string data;
    int index = 0;
    while (ifs >> data)
    {
        vector<string>v;//存放6个字符串
        //cout << data << endl;
        int pos = -1;//查到“，”位置的变量
        int start = 0;
        while(true)
        {
        pos = data.find(",", start);
        if (pos == -1){
            //没有找到情况
            break;
        }
        string temp = data.substr(start, pos - start);
        //cout << temp << endl;
        v.push_back(temp);
        start = pos + 1;
        }
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
    cout << "---------------------------------" << endl;
    //for(map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++){
        //cout << "第" << it->first << "届冠军编号: " << it->second[0] << " 分数：" << it->second[1] << endl;
    //}
    //system("read -p 'Press Enter to continue...' var");
    //system("clear");
}

//
void SpeechManager::showRecore()
{
    if(this->fileIsEmpty)
    {
        cout << "文件为空或者文件不存在!" << endl;
    }
    else{
    for (int i = 0; i < this->m_Record.size(); i++){
        cout << "第" << i+1 << "届: "<< endl 
        << "冠军编号:" << this->m_Record[i][0] << "得分：" << this->m_Record[i][1] << endl
        << "亚军编号:" << this->m_Record[i][2] << "得分：" << this->m_Record[i][3] << endl
        << "季军编号:" << this->m_Record[i][4] << "得分：" << this->m_Record[i][5] << endl << endl;
    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");
    }
}

//清空文件
void SpeechManager::clearRecord(){
    cout << "是否确定删除文件？" << endl;
    cout << "1、是" << endl;
    cout << "2、否" <<endl;
    
    int select = 0;

    cin >> select;

    if (select == 1){
        //确认清空
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        //初始化属性
        this->initSpeech();
        //创建选手
        this->creatSpeaker();
        //获取往届记录
        this->loadRecord();

        cout << "清空成功!" << endl;
        system("read -p 'Press Enter to continue...' var");
        system("clear");
    }
}
void SpeechManager::startSpeech(){
    //第一轮比赛
    //1、抽签
    speechDraw();
    //2、比赛
    speechContest();
    //3、显示晋级结果
    showScore();
    //第二轮比赛
    this->Index++;
    //1、抽签
    speechDraw();
    //2、比赛
    speechContest();
    //3、显示最终结果
    showScore();
    //4、保存分数到文件
    saveRecord();
    //重置比赛
    //初始化属性
    this->initSpeech();
    //创建选手
    this->creatSpeaker();
    //获取往届记录
    this->loadRecord();

    cout << "本届比赛完毕！" << endl;
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

//析构函数
SpeechManager::~SpeechManager(){
    
}