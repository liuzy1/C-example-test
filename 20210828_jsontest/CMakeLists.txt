cmake_minimum_required(VERSION 2.8.3)
project(json_test)
add_compile_options(-std=c++14)
include_directories(
	include
	${PROJECT_SOURCE_DIR}/src/json
	${PROJECT_SOURCE_DIR}/src/config
)
add_executable(${PROJECT_NAME}_node 
	src/main.cpp
	src/json/CJsonObject.cpp
	src/json/cJSON.c
	src/config/studentInfo_config.cpp
)
