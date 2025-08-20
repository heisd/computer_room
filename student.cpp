//
// Created by 延年易廋 on 2025/8/20.
//

#include "student.h"
student::student(int id, std::string password, std::string name) {
    this->m_s_id=id;
    this->m_password=password;
    this->m_name=name;
    std::ifstream file;
    file.open(COMPUTER_FILE,std::ios::in);
    room r;
    while(file>>r.m_id&&file>>r.m_MaxNum){
        vroom.push_back(r);
    }
    file.close();
}
void student::operMenu() {
    std::cout<<"欢迎学生代表"<<this->m_name<<"登录"<<std::endl;
    std::cout<<"1.申请预约"<<std::endl;
    std::cout<<"2.查看我的预约"<<std::endl;
    std::cout<<"3.查看所有预约"<<std::endl;
    std::cout<<"4.取消预约"<<std::endl;
    std::cout<<"0.注销登录"<<std::endl;
    std::cout<<"请输入你的操作";
}
void student::applyOrder() {
    std::cout<<"机房开放时间为周一到周五"<<std::endl;
    std::cout<<"请你输入申请预约的时间"<<std::endl;
    std::cout<<"1.周一"<<std::endl;
    std::cout<<"2.周二"<<std::endl;
    std::cout<<"3.周三"<<std::endl;
    std::cout<<"4.周四"<<std::endl;
    std::cout<<"5.周五"<<std::endl;
    int date=0;
    int interval=0;
    int room=0;
    while(true){
        std::cin>>date;
        if(date>=1&&date<=5){
            break;
        }
        std::cout<<"输入错误请重新输入"<<std::endl;
    }
    std::cout<<"请输入申请的时间段"<<std::endl;
    std::cout<<"1.上午"<<std::endl;
    std::cout<<"2.下午"<<std::endl;
    while(true){
        std::cin>>interval;
        if(interval>=1&&interval<=2){
            break;
        }
        std::cout<<"输入错误请重新输入"<<std::endl;
    }
    std::cout<<"请选择机房 :"<<std::endl;
    std::cout<<"1号机房容量"<<vroom[0].m_MaxNum<<std::endl;
    std::cout<<"2号机房容量"<<vroom[1].m_MaxNum<<std::endl;
    std::cout<<"3号机房容量"<<vroom[2].m_MaxNum<<std::endl;
    while(true){
        std::cin>>room;
        if(room>=1&&room<=3){
            break;
        }
        std::cout<<"输入有误,请重新输入"<<std::endl;
    }
    std::cout<<"预约成功！审核中"<<std::endl;
    //写入文件
    std::ofstream file;
    file.open(ORDER_FILE,std::ios::app);
    file<<"date: "<<date<<" ";
    file<<"interval: "<<interval<<" ";
    file<<"stuId: "<<this->m_s_id<<" ";
    file<<"roomId: "<<room<<" ";
    //1号状态代表审核中
    file<<"status: "<<1<<std::endl;
    file.close();
    system("pause");
    system("cls");
}
void student::showMyOrder() {
    OrderFile file;
    if(file.m_size==0){
        std::cout<<"无预约记录"<<std::endl;
        system("pause");
        system("cls");
        return ;
    }
    for (int i = 0; i < file.m_size; ++i) {
        if(atoi(file.m_OrderData[i]["stuId"].c_str())==this->m_s_id){
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
    system("pause");
    system("cls");
}
void student::showAllOrder() {
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
void student::cancelOrder() {
    OrderFile file;
    if(file.m_size==0){
        std::cout<<"无预约记录"<<std::endl;
        system("pause");
        system("cls");
        return ;
    }
    std::cout<<"审核中或者预约成功的记录可以取消,请输入要取消的记录"<<std::endl;
    std::vector<int>v;
    int index=1;
    for (int i = 0; i < file.m_size; ++i) {
        //判断是不是自身的
        if(atoi(file.m_OrderData[i]["stuId"].c_str())==this->m_s_id){
            if(file.m_OrderData[i]["status"]=="1"||file.m_OrderData[i]["status"]=="2"){
                v.push_back(i);
                std::cout<<index++<<".";
                std::cout<<"预约日期: 周"<<file.m_OrderData[i]["date"];
                std::cout<<"时段"<<file.m_OrderData[i]["interval"];
                std::cout<<"机房"<<file.m_OrderData[i]["roomId"];
                std::string status ="状态";
                if(file.m_OrderData[i]["status"]=="1"){
                    status+="审核中";
                }else if(file.m_OrderData[i]["status"]=="2") {
                    status += "预约成功";
                }
                std::cout<<status<<std::endl;

            }
        }
    }
    std::cout<<"请输入要取消的记录,0代表返回"<<std::endl;
    while(true) {
        int select = 0;
        std::cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                break;
            } else {
                file.m_OrderData[v[select - 1]]["status"] = "0";
                file.updateOrder();
                std::cout << "已经取消预约" << std::endl;
                break;
            }
        }
        std::cout<<"输入有误请重新输入"<<std::endl;
    }

}
