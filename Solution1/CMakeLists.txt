cmake_minimum_required(VERSION 3.26)
project(Solution1)

# Указываем стандарт C++ (C++20 для std::format)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



set(HEADERS
        include/Point.h
        include/Vector.h
        include/Tmp.h
)

set(SOURCES
        src/Point.cpp
        src/Vector.cpp
        src/Tmp.cpp
        src/main.cpp
)

set(SOLUTION ${SOURCES} ${HEADERS}
        include/stdafx.h)

# Включаем директорию с заголовочными файлами
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${SOLUTION})

target_precompile_headers(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include/stdafx.h)
