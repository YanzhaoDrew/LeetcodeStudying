#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
#include"Speaker.h"
#include<functional>
#include<algorithm>
#include<deque>
#include<numeric>

class SpeechManager{
public:
    //构造函数
    SpeechManager();
    //菜单功能
    void show_Menu();
    //退出系统
    void exitSystem();
    //析构函数
    ~SpeechManager();
    //初始化容器与属性
    void initSpeech();
    //初始化创建12名选手
    void creatSpeaker();
    //开始比赛 比赛整个流程的控制函数
    void startSpeech();
    //抽签功能
    void speechDraw();
    //比赛
    void speechContest();
    //显示晋级结果
    void showScore();
    //保存记录
    void saveRecord();
    //读取记录
    void loadRecord();
    //判断文件是否为空
    bool fileIsEmpty;
    //存放往届记录的容器
    map<int, vector<string>>m_Record;
    //显示往届得分
    void showRecore();
    //清空文件
    void clearRecord();

    //成员函数
    //保存第一轮比赛选手编号容器 12 人
    vector<int>v1;
    //第一轮晋级选手编号容器 6 人
    vector<int>v2;
    //胜出前三名选手编号容器 3 人
    vector<int>vVictory;
    //存放编号以及对应具体选手容器
    map<int, Speaker>m_Speaker;

    //存放比赛轮数
    int Index;
};