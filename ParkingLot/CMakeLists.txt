cmake_minimum_required(VERSION 3.5)

project(ParkingLot LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets  REQUIRED)
find_package(Qt5 COMPONENTS Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        queue.h
        parkingSpot.h
        car.h
        worker.h
        work.cpp
        parkinglot.h
        myExceptions.h
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ParkingLot
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(ParkingLot SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(ParkingLot
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ParkingLot PRIVATE Qt${QT_VERSION_MAJOR}::Widgets )
target_link_libraries(ParkingLot PRIVATE Qt5::Sql)
