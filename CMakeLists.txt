cmake_minimum_required(VERSION 3.8)

project("c-hoc-memoized-factorial" C)

add_executable(${PROJECT_NAME}
    "src/main.c"
)

target_link_options(${PROJECT_NAME} PRIVATE "-static")
