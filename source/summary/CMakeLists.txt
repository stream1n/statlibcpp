set(SOURCE_FILES src/summary_results.cpp)
include_directories(src)

add_library(summarystats STATIC ${SOURCE_FILES})
target_link_libraries(summarystats)

add_executable(SummaryStats_test test/SummaryStatisticsTest.cpp)

target_link_libraries(SummaryStats_test summarystats gtest gtest_main)