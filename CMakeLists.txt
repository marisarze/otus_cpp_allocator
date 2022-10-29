cmake_minimum_required(VERSION 3.00)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

include(FetchContent)
FetchContent_Declare(fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG master
)
FetchContent_MakeAvailable(fmt)


project(allocator VERSION ${PROJECT_VESRION})

AUX_SOURCE_DIRECTORY(src SOURCES) 

add_executable(allocator main.cpp ${SOURCES} linked_list.h pool_allocator.h)

target_include_directories(allocator
    PUBLIC "${CMAKE_CURRENT_BINARY_DIR}" include src
)

target_link_libraries(allocator fmt) 

set_target_properties(allocator
    PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)



if (MSVC)
    target_compile_options(allocator PRIVATE
        /W4
    )
else ()
    target_compile_options(allocator PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS allocator RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
