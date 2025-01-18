get_filename_component(DMITRIEVMYSHELL_TEST_INCLUDE_PATH "." ABSOLUTE)
get_filename_component(DMITRIEVMYSHELLTEST_SOURCE_PATH "./${PROJECT_NAME}" ABSOLUTE)

set(DMITRIEVMYSHELL_TEST_TARGET "${PROJECT_NAME}-test")

# Собираем все файлы тестов
file(GLOB_RECURSE DMITRIEVMYSHELL_TEST_SOURCES CONFIGURE_DEPENDS *.hpp *.cpp)

# Создаём исполняемый файл для тестов
add_executable(${DMITRIEVMYSHELL_TEST_TARGET} ${DMITRIEVMYSHELL_TEST_SOURCES})

# Указываем директорию с заголовочными файлами
target_include_directories(${DMITRIEVMYSHELL_TEST_TARGET} PUBLIC ${DMITRIEVMYSHELL_TEST_INCLUDE_PATH})

include(GoogleTest)

# Линкуем GTest и основной проект
target_link_libraries(
    ${DMITRIEVMYSHELL_TEST_TARGET} PRIVATE
    ${PROJECT_NAME}  # Основной проект
    GTest::gtest     # Google Test
    GTest::gmock     # Google Mock (если используется)
)

# Автоматически регистрируем тесты для CTest
gtest_discover_tests(${DMITRIEVMYSHELL_TEST_TARGET})
