cmake_minimum_required(VERSION 3.1)

### カバレッジ取得のため、ソースリストを親CMakeListに公開する

### mainを含まないソース群のリストを作成
file(GLOB OTHER_SOURCES
	${PROJECT_SOURCE_DIR}/src/other_func.cpp
)

### ソースリストをテスト側からも見えるようにする
set(OTHER_SOURCES ${OTHER_SOURCES} PARENT_SCOPE)

### メイン関数を含むファイルのみ別にリンクする
add_executable(cmake_example main.cpp
	${OTHER_SOURCES}
)

### リンクライブラリの設定
target_link_libraries(cmake_example Threads::Threads)

### 依存先の設定
# add_dependencies(cmake_example ...)

