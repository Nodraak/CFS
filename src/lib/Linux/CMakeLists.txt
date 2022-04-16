add_library(
    cfs-lib-Linux
    task.c
)
include_directories(../inc/)
target_link_libraries(cfs-lib-Linux pthread)
