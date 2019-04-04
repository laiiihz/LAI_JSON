## 下载[googletest](https://github.com/google/googletest)源码
```bash
git clone https://github.com/google/googletest
```
## 安装GooleTest
GTEST_DIR 为GoogleTest目录
```bash
cd GTEST_DIR
mkdir BUILD && cd BUILD
cmake ..
make && sudo make install
```
至此向Linux中安装GoogleTest完成

## 使用GoogleTest

在测试文件中引入gtest/gtest.h
```
#include <gtest/gtest.h>
TEST(TESTA,TESTA_A){
    EXPECT_EQ(12,12);

}
 int main(int args,char** argv) {
    testing::InitGoogleTest(); //初始化GoogleTest
    return RUN_ALL_TESTS();
}
```

修改CMakeList.txt
```
cmake_minimum_required(VERSION 3.13) //cmake 最低版本需求
project(untitled)  //项目名称
set(CMAKE_CXX_STANDARD 14) //项目C版本
add_executable(untitled main.cpp) 
target_link_libraries(untitled /usr/local/lib64/libgtest.a /usr/local/lib64/libgtest_main.a -pthread ) //将目标文件与库文件进行链接
```

>注意：add_executable要写在target_link_libraries前

结果：
![测试结果](https://upload-images.jianshu.io/upload_images/5201589-83fa3a484cc81d51.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
