cmake_minimum_required(VERSION 3.1)

### CTestを有効にする
enable_testing()

### ソースディレクトリに依存してしまう。ここはグローバルに決めたほうが良いかも
include_directories(${PROJECT_SOURCE_DIR}/src)

### デバッグのときだけカバレッジオプションを有効にする
if( NOT MSVC)
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} --coverage")
   set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --coverage")
endif()

### 実行ファイルごとの設定
add_executable(example_test_1
	${OTHER_SOURCES}
	example_test_1.cpp
)

target_link_libraries(example_test_1
	Threads::Threads
	gmock_main
	gmock
	gtest
)

add_dependencies(example_test_1
	GoogleTest
)

add_test(
	NAME example_test_1
	COMMAND $<TARGET_FILE:example_test_1>
)

### GoogleTestさっぱりわからん
#include(GoogleTest)
#
#gtest_add_tests(
#	TARGET example_test_1
#)

### GoogleTest を読み込む
# ${DEPEND_LIB_ROOT}の下に導入する
ExternalProject_Add(
	### Target name
	GoogleTest
	### Path to Git repository
	GIT_REPOSITORY https://github.com/google/googletest
	### Specify TAG
	GIT_TAG master
	### Path to source tree
	SOURCE_DIR ${PROJECT_BINARY_DIR}/GoogleTest_src
	### Specify Generator
	### CMAKE_GENERATOR "Ninja"
	### Add cmake args CMAKE_ARGS -DCMAKE_INSTALL_PREFIX= -DCMAKE_BUILD_TYPE=Release
	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${DEPEND_LIB_ROOT}
	### Path to build tree
	BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/GoogleTest_build
	### BUILD_COMMAND ninja install
)

