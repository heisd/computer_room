//
// Created by 延年易廋 on 2025/8/20.
//

#include "orderFile.h"
OrderFile::OrderFile() {
    std::ifstream file;
    file.open(ORDER_FILE, std::ios::in);
    std::string data;
    std::string interval;
    std::string stuId;
    std::string stuName;
    std::string roomId;
    std::string status;

    this->m_size = 0;
    while (file >> data && file >> interval && file >> stuId && file >> stuName && file >> roomId && file >> status) {
        std::string key;
        std::string value;
        std::map<std::string, std::string> m;
        size_t pos = data.find(":"); // Changed int to size_t
        if (pos != std::string::npos) { // Changed -1 to std::string::npos
            key = data.substr(0, pos);
            value = data.substr(pos + 1, data.size() - pos);
            m.insert(std::make_pair(key, value));
        }
        pos = interval.find(":");
        if (pos != std::string::npos) {
            key = interval.substr(0, pos);
            value = interval.substr(pos + 1, data.size() - pos);
            m.insert(std::make_pair(key, value));
        }
        pos = stuId.find(":");
        if (pos != std::string::npos) {
            key = stuId.substr(0, pos);
            value = stuId.substr(pos + 1, data.size() - pos);
            m.insert(std::make_pair(key, value));
        }
        pos = stuName.find(":");
        if (pos != std::string::npos) {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos + 1, data.size() - pos);
            m.insert(std::make_pair(key, value));
        }
        pos = roomId.find(":");
        if (pos != std::string::npos) {
            key = roomId.substr(0, pos);
            value = roomId.substr(pos + 1, data.size() - pos);
            m.insert(std::make_pair(key, value));
        }
        pos = stuId.find(":"); // This seems like a copy-paste error, should be status.find(":") based on context?
        if (pos != std::string::npos) {
            key = stuId.substr(0, pos);
            value = stuId.substr(pos + 1, data.size() - pos);
            m.insert(std::make_pair(key, value));
        }
        pos = status.find(":");
        if (pos != std::string::npos) {
            key = status.substr(0, pos);
            value = status.substr(pos + 1, data.size() - pos);
            m.insert(std::make_pair(key, value));
        }
        this->m_OrderData.insert(std::make_pair(this->m_size, m));
        this->m_size++;
    }

}

void OrderFile::updateOrder() {
    if(this->m_size==0){
        return ;
    }
    std::ofstream file;
    file.open(ORDER_FILE,std::ios::trunc);
    for (int i = 0; i < m_size; ++i) {
        file<<"date: "<<this->m_OrderData[i]["date"]<<" ";
        file<<"interval: "<<this->m_OrderData[i]["interval"]<<" ";
        file<<"stuId: "<<this->m_OrderData[i]["stuId"]<<" ";
        file<<"stuName: "<<this->m_OrderData[i]["stuName"]<<" ";
        file<<"roomId: "<<this->m_OrderData[i]["roomId"]<<" ";
        file<<"status: "<<this->m_OrderData[i]["status"]<<std::endl;
    }
    file.close();
}