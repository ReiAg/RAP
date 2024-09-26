cmake_minimum_required(VERSION 3.16)

# Set the project name and version
project(RAP VERSION 1.3.0 LANGUAGES CXX)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Config.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/headers/Config.h")
# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Find the Qt6 package
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Multimedia)

# Add the main executable
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/AudioPlayer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/ImageLabel.cpp)

# Link the Qt6 libraries to your executable
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Multimedia)

# Set the target properties (e.g., output directory, name, etc.)
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Include the Qt headers
target_include_directories(${PROJECT_NAME} PRIVATE ${Qt6Widgets_INCLUDE_DIRS})

# Enable automatic MOC and UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

