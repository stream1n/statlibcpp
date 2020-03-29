#include "summary_results.h"
#include <math.h>

namespace statlib {
    namespace summaries {

        double calc_median(const std::vector<int> nums) {
            std::vector<int> _nums(nums);

            std::nth_element(_nums.begin(), _nums.begin() + (_nums.size()/2), _nums.end());

            if( nums.size() % 2 != 0) {
                return _nums[_nums.size()/2];
            } else {
                std::nth_element(_nums.begin() + (_nums.size()/2) + 1, _nums.begin() + (_nums.size()/2) + 1, _nums.end());
                return (_nums[(_nums.size()/2)-1] + _nums[(_nums.size()/2)]) / static_cast<double>(2);
            }

        }

        double calc_standard_deviation(const std::vector<int> nums, double mean) {
            std::vector<double> diffs(nums.size());
            std::transform(nums.begin(), nums.end(), diffs.begin(), [mean](double x){ return x - mean;});
            double squared_diffs = std::inner_product(diffs.begin(), diffs.end(), diffs.begin(), 0.);
            return sqrt(squared_diffs / nums.size());
        }

        SummaryStatistics mean(const std::vector<int> nums) {
            return SummaryStatistics::SummaryStatisticsBuilder().mean(calc_mean<int>(nums)).Build();
        }

        SummaryStatistics median(const std::vector<int> nums) {
            return SummaryStatistics::SummaryStatisticsBuilder().median(calc_median(nums)).Build();
        }

        SummaryStatistics standard_deviation(const std::vector<int> nums) {
            double mean = calc_mean<int>(nums);
            double stdev = calc_standard_deviation(nums, mean);
            return SummaryStatistics::SummaryStatisticsBuilder().mean(mean).standard_deviation(stdev).Build();
        }
    }
}