//
// Created by 延年易廋 on 2025/8/20.
//
#pragma once
#include <iostream>
#include "identity.h"
#include "orderFile.h"
#include <vector>
class teacher:public identity{
public:
    teacher();
    teacher(int empId,std::string name,std::string password);
    virtual void operMenu();
    void showAllOrder();
    void validOrder();
    int m_empId;

};
