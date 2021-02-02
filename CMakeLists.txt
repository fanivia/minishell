cmake_minimum_required(VERSION 3.17)
project(minishell C)

set(CMAKE_C_STANDARD 11)

# add libft
add_subdirectory(./libft)


add_executable(minishell srcs/main.c)

target_link_libraries(${PROJECT_NAME} ft)