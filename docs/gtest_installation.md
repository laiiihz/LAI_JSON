## Download[GoogleTest](https://github.com/google/googletest)Source Code
```bash
git clone https://github.com/google/googletest
```
## install GooleTest
GTEST_DIR is the GoogleTest directory
```bash
cd GTEST_DIR
mkdir BUILD && cd BUILD
cmake ..
make && sudo make install
```

##Using GoogleTest

in test file include the `gtest/gtest.h` header
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

Modify CMakeList.txt
```
cmake_minimum_required(VERSION 3.13) 
project(untitled)
set(CMAKE_CXX_STANDARD 14)
add_executable(untitled main.cpp) 
target_link_libraries(untitled /usr/local/lib64/libgtest.a /usr/local/lib64/libgtest_main.a -pthread )
```

result：
![test result](https://upload-images.jianshu.io/upload_images/5201589-83fa3a484cc81d51.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
