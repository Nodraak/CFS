add_subdirectory(lib/)

add_executable(
    demo
    main.c modules.c
)
include_directories(lib/inc/)
target_link_libraries(demo cfs-lib)
