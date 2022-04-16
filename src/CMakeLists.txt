add_executable(
    demo
    main.c
    task.c
    scheduler.c
    modules.c
)

target_link_libraries(demo pthread)
