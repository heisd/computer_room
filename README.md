# computer_room

C++ 机房预约练习，按管理员、学生与教师划分代码模块，使用文本文件保存账号、机房和预约信息。

## 内容导航

- [admin.cpp](./admin.cpp)：管理员模块
- [student.cpp](./student.cpp)：学生模块
- [teacher.cpp](./teacher.cpp)：教师模块
- [orderFile.cpp](./orderFile.cpp)：预约文件读写
- [computerRoom.txt](./computerRoom.txt)：机房信息
- [globalFile.h](./globalFile.h)：数据文件路径
- [CMakeLists.txt](./CMakeLists.txt)：CMake 3.31 / C++20 构建配置

## 使用前检查

`globalFile.h` 中的数据文件路径固定在作者的本机目录，克隆后需要改为本机可用路径。请先检查程序入口与构建配置，再进行编译；当前 README 不将该练习描述为开箱即用的完整应用。

账号与预约数据位于仓库中的文本文件，调试前建议备份。
