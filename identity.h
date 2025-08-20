//
// Created by 延年易廋 on 2025/8/20.
//
#pragma once
#include <iostream>
class identity{
public:
    //提供基类的操作菜单
    virtual void operMenu()=0;
    //提供子类有的信息
    //用户名和密码
    std::string m_name;
    std::string m_password;
    virtual ~identity();
};


