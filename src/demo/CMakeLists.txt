cmake_minimum_required(VERSION 3.5)

project(OCSFS VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 可执行文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/demo)

set(TS_FILES OCSFS_zh_CN.ts)

set(CMAKE_AUTOMOC_MOC_OPTIONS ${CMAKE_AUTOMOC_MOC_OPTIONS} -no-direct-extern-access)

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${OpenCV_INCLUDE_DIRS}
    dlib::dlib
)

add_executable(demo
    src/main.cpp
    src/ocsfs_window.cpp
    src/ocsfs_widget.cpp
    src/ocsfs_module_trainer.cpp
    src/ocsfs_face_recognition.cpp
    src/ocsfs_image_converter.cpp
    src/ocsfs_expression_recognition.cpp
    src/ocsfs_profileface_recognition.cpp
    ${TS_FILES}
)

target_link_libraries(demo
    PRIVATE Qt6::Widgets Qt6::Multimedia Qt6::MultimediaWidgets
    ${OpenCV_LIBS}
    dlib::dlib
)

