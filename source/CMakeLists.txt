
get_filename_component(DMITRIEVMYSHELL_INCLUDE_PATH "." ABSOLUTE)
get_filename_component(DMITRIEVMYSHELL_SOURCE_PATH "./${PROJECT_NAME}" ABSOLUTE)


file(GLOB_RECURSE DMITRIEVMYSHELL_SOURCES CONFIGURE_DEPENDS *.hpp *.cpp)


set(DMITRIEVMYSHELL_LIB_SOURCES
    ${DMITRIEVMYSHELL_SOURCES}
    dmitrievmyshell/Shell.cpp
    dmitrievmyshell/EmaSearch.cpp
    dmitrievmyshell/Dedup.cpp
)

set(DMITRIEVMYSHELL_APP_SOURCES dmitrievmyshell/app/Main.cpp)


add_library(${PROJECT_NAME} STATIC ${DMITRIEVMYSHELL_LIB_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${DMITRIEVMYSHELL_INCLUDE_PATH})


add_executable(${PROJECT_NAME}-app ${DMITRIEVMYSHELL_APP_SOURCES})
set_property(TARGET ${PROJECT_NAME}-app PROPERTY OUTPUT_NAME ${PROJECT_NAME})


target_link_libraries(
    ${PROJECT_NAME}-app PRIVATE
    ${PROJECT_NAME}
)
