//
// Created by 延年易廋 on 2025/8/20.
//

#include "teacher.h"
teacher::teacher(){

}
teacher::teacher(int empId, std::string name, std::string password) {
    this->m_empId=empId;
    this->m_name=name;
    this->m_password=password;
}
void teacher::operMenu() {
    std::cout<<"欢迎教师"<<this->m_name<<"登录!"<<std::endl;
    std::cout<<"1.查看所有预约"<<std::endl;
    std::cout<<"2.审核预约"<<std::endl;
    std::cout<<"0.注销登录"<<std::endl;
    std::cout<<"请选择你的操作"<<std::endl;
}

void teacher::showAllOrder() {
    OrderFile file;
    if(file.m_size==0){
        std::cout<<"无预约记录"<<std::endl;
        system("pause");
        system("cls");
        return ;
    }
    for (int i = 0; i < file.m_size; ++i){
        std::cout<<i+1<<".";
        std::cout<<"预约日期: 周"<<file.m_OrderData[i]["date"];
        std::cout<<"时段"<<file.m_OrderData[i]["interval"];
        std::cout<<"机房"<<file.m_OrderData[i]["roomId"];
        std::string status ="状态";
        if(file.m_OrderData[i]["status"]=="1"){
            status+="审核中";
        }else if(file.m_OrderData[i]["status"]=="2"){
            status+="预约成功";
        }else if(file.m_OrderData[i]["status"]=="-1"){
            status+="审核未通过，预约失败";
        }else{
            status+="预约已经取消";
        }
        std::cout<<status<<std::endl;
    }
}

void teacher::validOrder() {
    OrderFile file;
    if(file.m_size==0){
        std::cout<<"无预约记录"<<std::endl;
        system("pause");
        system("cls");
        return ;
    }
    std::cout<<"待审核的预约记录如下 :"<<std::endl;
    std::vector<int>v;
    int index=1;
    for (int i = 0; i < file.m_size; ++i) {
        if(file.m_OrderData[i]["status"]=="1"){
            v.push_back(i);
            std::cout<<index++<<".";
            std::cout<<"预约日期: 周"<<file.m_OrderData[i]["date"];
            std::cout<<"时段"<<file.m_OrderData[i]["interval"];
            std::cout<<"机房"<<file.m_OrderData[i]["roomId"];
            std::string status ="状态";
            if(file.m_OrderData[i]["status"]=="1"){
                status+="审核中";
            }
            std::cout<<status<<std::endl;
        }

    }
    std::cout<<"请你输入审核的预约记录，0代表返回"<<std::endl;
    int select=0;
    int ret=0;
    while(true){
        std::cin>>select;
        if(select>=0&&select<=v.size()){
            if(select==0){
                break;
            }
            else{
                std::cout<<"请输入审核结果"<<std::endl;
                std::cout<<"1.通过"<<std::endl;
                std::cout<<"2.不通过"<<std::endl;
                std::cin>>ret;
                if(ret==1){
                    file.m_OrderData[v[select-1]]["status"]="2";
                    }
                else{
                    file.m_OrderData[v[select-1]]["status"]="-1";
                    }
                file.updateOrder();
                std::cout<<"审核完毕"<<std::endl;
                break;
                }

            }
        }
    }





