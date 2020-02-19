cmake_minimum_required(VERSION 3.1)
enable_language(CXX C)
set(CMAKE_CXX_STANDARD 17)

### 依存ライブラリを外部から取得するための設定
include(ExternalProject)

find_package(Threads REQUIRED)

project(CmakeExample)

### 依存ライブラリの格納先を指定
set(DEPEND_LIB_ROOT ${PROJECT_BINARY_DIR}/depend_libs)

### 依存ライブラリをまるっとインクルードしてしまう
include_directories(${DEPEND_LIB_ROOT}/include)
link_directories(${DEPEND_LIB_ROOT}/lib)

### ソースの格納先
add_subdirectory(src)

### テストの格納先
add_subdirectory(test)

