# C++ 机房预约系统

基于控制台和文本文件的机房预约练习。项目使用管理员、学生、教师三类身份组织操作，以抽象基类与派生类练习多态，并将账号、机房信息和预约状态保存在本地文件中。

## 角色与业务流程

| 角色 | 菜单中的功能 |
| --- | --- |
| 学生 | 申请预约、查看自己的预约、查看全部预约、取消预约 |
| 教师 | 查看全部预约、审核预约 |
| 管理员 | 添加账号、查看账号、查看机房、清空预约 |

典型流程为“管理员准备账号与机房 → 学生申请 → 教师审核 → 学生查看结果”。申请界面按周一至周五选择日期，并记录时段、学生信息、机房与状态。

## 代码结构

| 文件 | 职责 |
| --- | --- |
| [computer.cpp](./computer.cpp) | 主程序 `main()`、登录验证与各角色菜单分派 |
| [identity.h](./identity.h) / [identity.cpp](./identity.cpp) | 身份抽象基类与虚析构函数定义 |
| [admin.cpp](./admin.cpp) | 账号与机房管理 |
| [student.cpp](./student.cpp) | 学生预约申请、查询与取消 |
| [teacher.cpp](./teacher.cpp) | 预约查看与审核 |
| [orderFile.cpp](./orderFile.cpp) | 预约记录解析与回写 |
| [room.h](./room.h) / [room.cpp](./room.cpp) | 机房对象 |
| [globalFile.h](./globalFile.h) | 所有数据文件路径宏 |
| [CMakeLists.txt](./CMakeLists.txt) | CMake 3.31+、C++20 的构建目标 |

## 首次构建前必须调整的两处配置

### 1. 数据路径

`globalFile.h` 当前写死了作者本机 CLion 项目目录。需要将以下宏指向你自己的数据文件：

| 宏 | 文件 |
| --- | --- |
| `ADMIN_FILE` | `admin.txt` |
| `STUDENT_FILE` | `student.txt` |
| `TEACHER_FILE` | `teacher.txt` |
| `COMPUTER_FILE` | `computerRoom.txt` |
| `ORDER_FILE` | `order.txt` |

可以使用自己的绝对路径，或改为文件名并从仓库根目录启动程序。选择相对路径后，IDE 的工作目录也需保持一致。

### 2. 构建源文件列表

`identity.h` 声明了虚析构函数，其定义位于 `identity.cpp`；现有 CMake 的 `add_executable` 列表未包含该实现文件。构建前应把 `identity.cpp` 加入目标，否则可能出现析构函数未定义的链接错误。

程序入口已经位于 `computer.cpp`，无需另行添加新的 `main()`。

## 构建与启动

完成上面两项配置后，使用支持 C++20 的编译器：

```bash
git clone --branch main https://github.com/heisd/computer_room.git
cd computer_room
cmake -S . -B build
cmake --build build --config Debug
```

Windows / Visual Studio 生成器的常见运行方式：

```powershell
.\build\Debug\computer_room.exe
```

其他生成器的程序位置可能是 `build/computer_room.exe`。源码使用 `system("pause")` 与 `system("cls")`，跨平台运行需要调整。

## 数据与使用方式

账号使用文本文件读写，登录验证从相应身份文件中逐项读取信息。预约文件使用带字段名的记录，`OrderFile` 负责解析与保存；手工编辑时不要随意改变字段结构。

建议先备份五个数据文件，再按以下顺序检查：

1. 从程序首页选择身份并登录。
2. 管理员查看机房与账号是否成功读取。
3. 学生申请一条预约。
4. 教师查询并审核。
5. 学生再次查看状态，最后重启程序确认数据仍可读取。

账号以明文文件保存，适用于本地教学练习；请使用专门的示例密码。

## 常见问题

| 现象 | 优先检查 |
| --- | --- |
| 登录始终失败 | 路径是否仍指向作者本机、文件格式是否与读取顺序一致 |
| undefined reference / unresolved external symbol | `identity.cpp` 是否已加入构建目标 |
| 机房或预约列表为空 | 对应文件是否存在、有内容且路径正确 |
| 修改文件后程序读到旧数据 | 是否启动了另一份程序，或运行目录与预期不同 |
| 管理员退出后出现输入错误提示 | 检查主菜单 `case 3` 的分支控制，源码仍有练习性质 |

本次文档按源码说明已有功能与构建前提，未修改上述路径或构建文件。
