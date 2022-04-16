add_subdirectory(common/)

add_library(
    cfs-lib
    INTERFACE
)

target_link_libraries(cfs-lib INTERFACE cfs-lib-common)

if("${CFS_TARGET}" STREQUAL "Linux")
    add_subdirectory(Linux/)
    target_link_libraries(cfs-lib INTERFACE cfs-lib-Linux)
elseif("${CFS_TARGET}" STREQUAL "RTEMS")
    add_subdirectory(RTEMS/)
    target_link_libraries(cfs-lib INTERFACE cfs-lib-RTEMS)
endif()
