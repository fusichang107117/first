
add_executable(run main.c)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
#else()
#    list(APPEND flags "-fPIC" "-Wall")
#    target_compile_options(run PRIVATE ${flags})
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")


MESSAGE(STATUS "Hello This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "Hello This is SOURCE dir " ${PROJECT_SOURCE_DIR})

INSTALL(TARGETS run RUNTIME DESTINATION ${PROJECT_SOURCE_DIR})

add_test(test_run1 run 1 2)
add_test(test_run2 run 1 3)
#add_test(NAME test_run2 COMMAND run --arg1=1 --arg2=3)

set_tests_properties(test_run1 PROPERTIES PASS_REGULAR_EXPRESSION "is 3")
set_tests_properties(test_run2 PROPERTIES PASS_REGULAR_EXPRESSION "is 4")

ADD_CUSTOM_TARGET(memcheck
    COMMAND cp ${PROJECT_SOURCE_DIR}/DartConfiguration.tcl ./
    COMMAND sed -i.bak s+/usr/bin/valgrind+`which valgrind`+ DartConfiguration.tcl
    COMMAND ctest -O memcheck.log -D ExperimentalMemCheck
    COMMAND tail -n1 memcheck.log | grep 'Memory checking results:' > /dev/null
    COMMAND rm -f memcheck.log
    COMMAND mv DartConfiguration.tcl.bak DartConfiguration.tcl
)
