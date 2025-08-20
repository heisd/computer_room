//
// Created by 延年易廋 on 2025/8/20.
//
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "room.h"
#include "identity.h"
#include "globalFile.h"
#include "orderFile.h"
class student:public identity{
public:
    student(int id,std::string name,std::string password);
    student()=default;
    virtual void operMenu()override;
    //申请预约功能
    void applyOrder();
    //查看我的预约
    void showMyOrder();
    //查看所有预约
    void showAllOrder();
    //取消预约
    void cancelOrder();
    //学生类特有的信息--学号
    int m_s_id=0;
    std::vector<room>vroom;

};
