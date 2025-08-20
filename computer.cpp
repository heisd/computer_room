//
// Created by 延年易廋 on 2025/8/20.
//

#include "computer.h"

void teacherMenu(identity*&teachers){
    while(true){
        teachers->operMenu();
        teacher *tea=(teacher*)teachers;
        int select=0;
        std::cin>>select;
        if(select==1){
            tea->showAllOrder();
        }else if(select==2){
            tea->validOrder();
        }else{
            delete teachers;
            std::cout<<"注销成功"<<std::endl;
            system("pause");
            system("cls");
            return ;
        }
    }
}
void studentMenu(identity*&students){
    while(true){
        //调用学生子菜单
        students->operMenu();
        //使用子类指针
        student *stu =(student *)students;
        int select=0;
        std::cin>>select;
        if(select==1){
            stu->applyOrder();
        } else if(select==2){
            stu->showMyOrder();
        } else if(select==3){
            stu->showAllOrder();
        } else if(select==4){
            stu->cancelOrder();
        } else {
            //注销登录
            delete students;
            std::cout<<"注销成功"<<std::endl;
            system("pause");
            system("cls");
            return ;
        }
    }
}
void adminMenu(identity*&adminer){
    while(true){
        //调用管理员子菜单
        adminer->operMenu();
        //将父类指针转换成子类指针,为了调用子类中的其他接口
        admin * man=(admin*)adminer;
        int select=0;
        std::cin>>select;
        if(select==1){
            man->addPerson();
        }else if(select==2){
            man->showPerson();
        }else if(select==3){
            man->showComputer();
        }else if(select==4){
            man->cleanFile();
        }else{
            //退出模块
            delete adminer;
            std::cout<<"注销对象"<<std::endl;
            system("pause");
            system("cls");
            return ;
        }


    }
}
void LoginIN(const std::string& fileName,int type){
    std::cerr << "尝试打开文件: " << fileName << std::endl; // 添加此行
    //创建一个父类的指针，用于指向子类对象
    identity *person= nullptr;
    std::ifstream file;
    //读文件
    file.open(fileName,std::ios::in);
    //判断文件是否存在

    if(!file.is_open()){
        std::cerr<<"文件读取失败: " << fileName << std::endl; // 修改此行
        return;
    }
    //准备接收用户信息
    int id=0;
    std::string name;
    std::string password;
    //判断身份
    if(type==1){
        std::cout<<"请输入你的学号"<<std::endl;
        std::cin>>id;

    }
    else if(type==2){
        std::cout<<"请输入你的职工号"<<std::endl;
        std::cin>>id;
    }
    std::cout<<"请输入用户名"<<std::endl;
    std::cin>>name;
    std::cout<<"请输入密码"<<std::endl;
    std::cin>>password;
    if(type==1){
        //学生身份验证
        int fId;
        std::string fName;
        std::string fPassword;
        while(file>>fId&&file>>fName&&file>>fPassword){
            if(id==fId&&name==fName&&password==fPassword){
                std::cout<<"学生登录成功"<<std::endl;
                system("pause");
                system("cls");
                person =new student(id,name,password);
                studentMenu(person);
                file.close(); // Added this line
                return ;
            }
        }
    }else if(type==2){
        //老师身份验证
        int fId;
        std::string fName;
        std::string fPassword;
        while(file>>fId&&file>>fName&&file>>fPassword){
            if(id==fId&&name==fName&&password==fPassword){
                std::cout<<"老师登录成功"<<std::endl;
                system("pause");
                system("cls");
                person =new teacher(id,name,password);
                teacherMenu(person);
                file.close(); // Added this line
                return ;
            }
        }
    }else if(type==3){
        //管理员身份验证

        std::string fName;
        std::string fPassword;
        std::cout << "用户名: '" << fName << "', 密码: '" << fPassword << "'" << std::endl;
        while(file>>fName&&file>>fPassword){
            if(name==fName&&password==fPassword){
                std::cout<<"管理员登录成功"<<std::endl;
                system("pause");
                system("cls");
                person =new admin(name,password);
                adminMenu(person);
                file.close(); // Added this line
                return ;
            }

        }

    }
    file.close(); // Added this line
    std::cout<<"验证登录失败！"<<std::endl;
    system("pause");
    system("cls");
}
int main(){
    int choice=0;
    while(true) {
        std::cout << "\n========= 机房预约系统 =========" << std::endl;
        std::cout << "0. 退出系统" << std::endl;
        std::cout << "1. 学生身份登录" << std::endl;
        std::cout << "2. 老师身份登录" << std::endl;
        std::cout << "3. 管理员身份登录" << std::endl;
        std::cout << "请输入您的选择: ";
        std::cin >> choice;
        switch (choice) {
            case 0:
                std::cout<<"欢迎下一次使用"<<std::endl;
                system("pause");
                return 0;
            case 1:
                std::cout<<"学生身份"<<std::endl;
                LoginIN(STUDENT_FILE,1);
                break;
            case 2:
                std::cout<<"老师身份"<<std::endl;
                LoginIN(TEACHER_FILE,2);
                break;
            case 3:
                std::cout<<"管理员身份"<<std::endl;
                LoginIN(ADMIN_FILE,3);
            default:
                std::cout<<"输入错误请重新输入"<<std::endl;
                system("pause");
                system("cls");
                break;
        }
    }
        system("pause");
    return 0;
}