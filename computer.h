//
// Created by 延年易廋 on 2025/8/20.
//
#pragma once
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "globalFile.h"
#include "admin.h"
#include <fstream>
void adminMenu(identity*&adminer);
void studentMenu(identity*&students);
void LoginIN(const std::string& fileName,int type);
void teacherMenu(identity*&teachers);