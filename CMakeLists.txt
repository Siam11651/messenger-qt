cmake_minimum_required(VERSION 3.16)
set(APP_ID "com.siam11651.messengerqt")
set(APP_VERSION "0.1.0")
project(messenger-qt VERSION ${APP_VERSION} LANGUAGES CXX)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets WebEngineWidgets)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
configure_file(
  "${PROJECT_SOURCE_DIR}/include/messenger/app-info.hpp.in"
  "${PROJECT_SOURCE_DIR}/include/messenger/app-info.hpp"
)
add_executable(${PROJECT_NAME}
  "src/main.cpp"
  "src/ui/menubar.cpp"
  "src/ui/menu/filemenu.cpp"
  "src/ui/menu/helpmenu.cpp"
  "src/ui/main_window.cpp"
  "src/ui/popup_page.cpp"
  "src/ui/webengine_page.cpp"
  "src/ui/webengine_profile.cpp"
  "src/ui/webengine_view.cpp"
)
target_include_directories(${PROJECT_NAME} PRIVATE "include")
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets Qt6::WebEngineWidgets)
file(REMOVE_RECURSE "${CMAKE_BINARY_DIR}/assets")
file(COPY "${CMAKE_SOURCE_DIR}/assets"
     DESTINATION "${CMAKE_BINARY_DIR}"
)
qt_standard_project_setup()