cmake_minimum_required(VERSION 3.19)
project(SerialPort)

set(CMAKE_CXX_STANDARD 11)

set(QT_VERSION 6)
#链接必要库文件
set(REQUIRED_LIBS Core Gui Widgets Multimedia)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Multimedia)
#查找对应功能包
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

add_executable(SerialPort_QT main.cpp SerialPort/SerialPort.cpp)
target_link_libraries(SerialPort_QT ${REQUIRED_LIBS_QUALIFIED})
