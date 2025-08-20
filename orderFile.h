//
// Created by 延年易廋 on 2025/8/20.
//
#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include "globalFile.h"

class OrderFile{
public:
    OrderFile();
    //更新预约记录
    void updateOrder();
    //记录的容器
    std::map<int,std::map<std::string,std::string>>m_OrderData;
    //预约记录的条数
    int m_size;

};