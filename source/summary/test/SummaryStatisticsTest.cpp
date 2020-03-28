#include "gtest/gtest.h"
#include "summary_results.h"

const std::vector<int> vec_even = {9, 2, 1, 4, 5, 8, 6, 7, 3, 10};
const std::vector<int> vec_odd = {9, 2, 1, 4, 5, 8, 11, 6, 7, 3, 10};

TEST(SummaryStatisticsTestSuite, SummaryStatisticsTestSuite_Sumean_Test){
    statlib::summaries::SummaryStatistics stats = statlib::summaries::mean(vec_even);
    GTEST_ASSERT_EQ(stats.getProperties().getMean(), 5.5);
}

TEST(SummaryStatisticsTestSuite, SummaryStatisticsTestSuite_Sumedian_even_Test){
    GTEST_ASSERT_EQ(statlib::summaries::median(vec_even).getProperties().getMedian(), 5.5);
}

TEST(SummaryStatisticsTestSuite, SummaryStatisticsTestSuite_Sumedian_odd_Test){
    GTEST_ASSERT_EQ(statlib::summaries::median(vec_odd).getProperties().getMedian(), 6);
}