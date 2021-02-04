cmake_minimum_required(VERSION 3.17)
project(minishell C)

set(CMAKE_C_STANDARD 11)

# add libft
include_directories(./libft/includes)
include_directories(./includes)
add_subdirectory(./libft)
#add_subdirectory(./libft/srcs/ft_printf)

add_executable(minishell srcs/main.c)

#target_link_libraries(minishell libft libft/srcs/ft_printf)
target_link_libraries(minishell libft)