cmake_minimum_required(VERSION 3.5)

project(SystemMonitor LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES SystemMonitor_zh_CN.ts
    main.cpp
    mainwindow.cpp
    mainwindow.h
    netusageinfo.cpp
    netusageinfo.h
    memusageinfo.cpp
    memusageinfo.h
    diskinfo.cpp
    diskinfo.h
    cpuusageinfo.cpp
    cpuusageinfo.h
    osinfo.cpp
    osinfo.h
    systeminfo.cpp
    systeminfo.h
    img.qrc
    )

if(ANDROID)
  add_library(SystemMonitor SHARED
      diskinfo.cpp
      diskinfo.h
      cpuusageinfo.cpp
      cpuusageinfo.h
      main.cpp
      mainwindow.cpp
      memusageinfo.cpp
      memusageinfo.h
      netusageinfo.cpp
      netusageinfo.h
      osinfo.cpp
      osinfo.h
      systeminfo.cpp
      systeminfo.h
    mainwindow.ui
    img.qrc
    ${TS_FILES}
  )
else()
  add_executable(SystemMonitor
      diskinfo.cpp
      diskinfo.h
      cpuusageinfo.cpp
      cpuusageinfo.h
      main.cpp
      mainwindow.cpp
      memusageinfo.cpp
      memusageinfo.h
      netusageinfo.cpp
      netusageinfo.h
      osinfo.cpp
      osinfo.h
      systeminfo.cpp
      systeminfo.h
    mainwindow.ui
    img.qrc
    ${TS_FILES}
  )
endif()

target_link_libraries(SystemMonitor Qt5::Widgets)
target_link_libraries(SystemMonitor Qt5::Core)
target_link_libraries(SystemMonitor Qt5::Gui)
find_package(Qt5Charts)
target_link_libraries(SystemMonitor Qt5::Charts)
find_package(Qt5Network)
target_link_libraries(SystemMonitor Qt5::Network)
find_package(Qt5Sql)
target_link_libraries(SystemMonitor Qt5::Sql)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
