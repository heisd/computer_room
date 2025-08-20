//
// Created by 延年易廋 on 2025/8/20.
//

#include "admin.h"
void printStudent(student &s){
    std::cout<<"学号 :"<<s.m_s_id<<"姓名 :"<<s.m_name<<"密码 :"<<s.m_password<<std::endl;
}
void printTeacher(teacher &t){
    std::cout<<"职工编号 :"<<t.m_empId<<"姓名 :"<<t.m_name<<"密码 :"<<t.m_password<<std::endl;
}
admin::admin(std::string name, std::string password) {
    this->m_name=name;
    this->m_password=password;
    //初始化容器
    this->initVector();
    //获取机房信息
    std::ifstream file;
    file.open(COMPUTER_FILE,std::ios::in);
    room r;
    while (file>>r.m_id&&file>>r.m_MaxNum){
        vroom.push_back(r);
    }
    std::cout<<"当前机房数量为 :"<<r.m_id<<std::endl;
    file.close();
}

void admin::operMenu() {
    std::cout<<"欢迎管理员"<<this->m_name<<"登录"<<std::endl;
    std::cout<<"1.添加账号"<<std::endl;
    std::cout<<"2.查看账号"<<std::endl;
    std::cout<<"3.查看机房"<<std::endl;
    std::cout<<"4.清空预约"<<std::endl;
    std::cout<<"0.退出登录"<<std::endl;
    std::cout<<"请选择你的操作"<<std::endl;
}

void admin::addPerson() {
    std::cout<<"请你输入要添加的类型"<<std::endl;
    std::cout<<"1.添加学生"<<std::endl;
    std::cout<<"2.添加老师"<<std::endl;
    std::string fileName;
    std::string tip;
    std::ofstream file;
    int select=0;
    std::cin>>select;
    std::string errorTip;
    if(select==1){
        fileName=STUDENT_FILE;
        tip="请输入学号 :";
        errorTip="学号重复,请重新输入 :";
    }else{
        fileName=TEACHER_FILE;
        tip="请输入职工编号 :";
        errorTip="职工号重复,请重新输入 :";
    }
    file.open(fileName,std::ios::out|std::ios::app);
    int id;
    std::string name;
    std::string password;
    std::cout<<tip<<std::endl;
    while(true){
        std::cin>>id;
        bool ret=this->checkRepeat(id,select);
        if(ret){
            //有重复的情况
            std::cout<<errorTip<<std::endl;
        }
        else{
            break;
        }
    }

    std::cout<<"请输入姓名 :"<<std::endl;
    std::cin>>name;
    std::cout<<"请输入密码 :"<<std::endl;
    std::cin>>password;
    file<<id<<" "<<name<<" "<<password<<" "<<std::endl;
    std::cout<<"添加成功"<<std::endl;
    system("pause");
    system("cls");

    file.close();
    this->initVector();
}

void admin::showPerson() {
    std::cout<<"请选择查看内容"<<std::endl;
    std::cout<<"1.查看所有学生"<<std::endl;
    std::cout<<"2.查看所有老师"<<std::endl;
    int select=0;
    std::cin>>select;
    if(select==1){
        std::cout<<"所有学生信息如下 :"<<std::endl;
        for_each(vStu.begin(),vStu.end(), printStudent);
    }else{
        std::cout<<"所有老师信息如下 :"<<std::endl;
        for_each(vTea.begin(),vTea.end(), printTeacher);
    }
    system("pause");
    system("cls");
}
void admin::showComputer() {
    std::cout<<"机房信息如下"<<std::endl;
    for(auto it=vroom.begin();it!=vroom.end();it++){
        std::cout<<"机房编号 :"<<it->m_id<<"机房最大容器 :"<<it->m_MaxNum<<std::endl;
    }
    system("pause");
    system("cls");
}
void admin::cleanFile() {
    std::ofstream file;
    file.open(ORDER_FILE,std::ios::trunc);
    file.close();
    std::cout<<"清空成功"<<std::endl;
    system("pause");
    system("cls");
}
void admin::initVector() {
    std::ifstream  file;
    file.open(STUDENT_FILE,std::ios::in);
    if(!file.is_open()){
        std::cerr<<"文件读取失败"<<std::endl;
        return;
    }
    vStu.clear();
    vTea.clear();
    //获取学生信息
    student s;
    while(file>>s.m_s_id&&file>>s.m_name&&file>>s.m_password){
        vStu.push_back(s);
    }
    std::cout<<"当前学生数量为"<<vStu.size()<<std::endl;
    file.close();
    file.open(TEACHER_FILE,std::ios::in);
    if(!file.is_open()){
        std::cerr<<"文件读取失败"<<std::endl;
        return;
    }
    vStu.clear();
    vTea.clear();
    teacher t;
    while(file>>t.m_empId&&file>>t.m_name&&file>>t.m_password){
        vTea.push_back(t);
    }
    std::cout<<"当前老师数量为"<<vStu.size()<<std::endl;
    file.close();
}
bool admin::checkRepeat(int id, int type) {
    if(type==1){
        for(auto it=vStu.begin();it!=vStu.end();it++){
            if(id==it->m_s_id){
                return true;
            }
        }
    }else{
        for(auto it=vTea.begin();it!=vTea.end();it++){
            if(id==it->m_empId){
                return true;
            }
        }
    }
    return false;
}