#include "gtest/gtest.h"
#include "summary_results.h"

const std::vector<int> vec_even = {9, 2, 1, 4, 5, 8, 6, 7, 3, 10};

const std::vector<int> vec_odd = {9, 2, 1, 4, 5, 8, 11, 6, 7, 3, 10};

const std::vector<int> std_dev = {10, 40, 30, 50, 20};

TEST(SummaryStatisticsTestSuite, SummaryStatisticsTestSuite_Sumean_Test){
    statlib::summaries::SummaryStatistics stats = statlib::summaries::mean(vec_even);
    EXPECT_DOUBLE_EQ(stats.getProperties().getMean(), 5.5);
}

TEST(SummaryStatisticsTestSuite, SummaryStatisticsTestSuite_Sumedian_even_Test){
    EXPECT_DOUBLE_EQ(statlib::summaries::median(vec_even).getProperties().getMedian(), 5.5);
}

TEST(SummaryStatisticsTestSuite, SummaryStatisticsTestSuite_Sumedian_odd_Test){
    EXPECT_DOUBLE_EQ(statlib::summaries::median(vec_odd).getProperties().getMedian(), 6);
}

TEST(SummaryStatisticsTestSuite, SummaryStatisticsTestSuite_Sustandard_deviation_Test){
    statlib::summaries::SummaryStatistics stats = statlib::summaries::standard_deviation(std_dev);
    EXPECT_DOUBLE_EQ(stats.getProperties().getMean(), 30);
    EXPECT_NEAR(stats.getProperties().getStandardDeviation(), 14.1421, 0.001);
}