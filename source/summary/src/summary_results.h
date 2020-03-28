#ifndef STATLIBCPP_SUMMARY_RESULTS_H
#define STATLIBCPP_SUMMARY_RESULTS_H

#include <vector>


namespace statlib {
    namespace summaries {

        class SummaryStatistics {

        private:

            class SummaryStatisticsProperties {

            private:

                SummaryStatisticsProperties() : mean(0.),
                                                median(0.),
                                                mode(0.),
                                                weighted_mean(0.),
                                                first_quartile(0.),
                                                second_quartile(0.),
                                                third_quartile(0.),
                                                inter_quartile_range(0.),
                                                standard_deviation(0.) {}

                double mean, median, mode, weighted_mean, first_quartile, second_quartile, third_quartile, inter_quartile_range, standard_deviation;

                friend class SummaryStatistics;

            public:
                double getMean() const { return mean; }
                double getMedian() const { return median; }
                double getMode() const { return mode; }
                double getWeightedMean() const { return weighted_mean; }
                double getFirstQuartile() const { return first_quartile; }
                double getSecondQuartile() const { return second_quartile; }
                double getThirdQuartile() const { return third_quartile; }
                double getInterQuartileRange() const { return inter_quartile_range; }
                double getStandardDeviation() const { return standard_deviation; }
            };


        public:

            class SummaryStatisticsBuilder {

            public:

                SummaryStatisticsBuilder() {}

                SummaryStatisticsBuilder &mean(double i_mean) {
                    properties.mean = i_mean;
                    return *this;
                }

                SummaryStatisticsBuilder &median(double i_median) {
                    properties.median = i_median;
                    return *this;
                }

                SummaryStatisticsBuilder &mode(double i_mode) {
                    properties.mode = i_mode;
                    return *this;
                }

                SummaryStatisticsBuilder &weighted_mean(double i_weighted_mean) {
                    properties.weighted_mean = i_weighted_mean;
                    return *this;
                }

                SummaryStatisticsBuilder &first_quartile(double i_first_quartile) {
                    properties.first_quartile = i_first_quartile;
                    return *this;
                }

                SummaryStatisticsBuilder &second_quartile(double i_second_quartile) {
                    properties.second_quartile = i_second_quartile;
                    return *this;
                }

                SummaryStatisticsBuilder &third_quartile(double i_third_quartile) {
                    properties.third_quartile = i_third_quartile;
                    return *this;
                }

                SummaryStatisticsBuilder &inter_quartile_range(double i_inter_quartile_range) {
                    properties.inter_quartile_range = i_inter_quartile_range;
                    return *this;
                }

                SummaryStatisticsBuilder &standard_deviation(double i_standard_deviation) {
                    properties.standard_deviation = i_standard_deviation;
                    return *this;
                }

                SummaryStatistics Build() {
                    return SummaryStatistics(properties);
                }

            private:

                SummaryStatisticsProperties properties;
            };


        private:

            SummaryStatistics(const SummaryStatisticsProperties &i_properties) : properties(i_properties) {
            }

            SummaryStatisticsProperties properties;

        public:
            SummaryStatisticsProperties getProperties() const { return this->properties;}
        };

        double calc_mean(const std::vector<int>);
        double calc_median(const std::vector<int>);
        SummaryStatistics mean(const std::vector<int>);
        SummaryStatistics median(const std::vector<int>);

    }
}

#endif //STATLIBCPP_SUMMARY_RESULTS_H
