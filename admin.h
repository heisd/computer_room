//
// Created by 延年易廋 on 2025/8/20.
//
#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "student.h"
#include "teacher.h"
#include "globalFile.h"
#include "room.h"
#include "identity.h"
class admin:public identity{
public:
    admin()=default;
    admin(std::string name,std::string password);
    void operMenu()override;
    void addPerson();
    void showPerson();
    void showComputer();
    void cleanFile();
    //去重操作
    void initVector();
    std::vector<student> vStu;
    std::vector<teacher> vTea;
    std::vector<room> vroom;
    bool checkRepeat(int id,int type);
};


