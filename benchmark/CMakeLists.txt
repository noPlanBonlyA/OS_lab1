get_filename_component(DMITRIEVMYSHELL_BENCH_SOURCE_PATH "./${PROJECT_NAME}" ABSOLUTE)

set(DMITRIEVMYSHELL_BENCH_TARGET_BASE "${PROJECT_NAME}-bench")

macro(DMITRIEVMYSHELL_BENCH_DECLARE suffix file)
    add_executable(
        ${DMITRIEVMYSHELL_BENCH_TARGET_BASE}-${suffix}
        ${DMITRIEVMYSHELL_BENCH_SOURCE_PATH}/${file}
    )

    target_link_libraries(
        ${DMITRIEVMYSHELLBENCH_TARGET_BASE}-${suffix}
        ${PROJECT_NAME}
        benchmark::benchmark
    )
endmacro()

DMITRIEVMYSHELL_BENCH_DECLARE(hello-world HelloWorldBench.cpp)
