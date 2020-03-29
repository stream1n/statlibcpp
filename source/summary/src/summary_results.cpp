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

        std::vector<double> calc_squared_diffs(const std::vector<int> nums, double mean) {
            std::vector<double> squared_diffs(nums.size());

            double count = 0;
            for( auto it : nums ) {
                double squared_diff = (it - mean) * (it - mean);
                squared_diffs[count++] = squared_diff;
            }

            return squared_diffs;
        }

        SummaryStatistics mean(const std::vector<int> nums) {
            return SummaryStatistics::SummaryStatisticsBuilder().mean(calc_mean<int>(nums)).Build();
        }

        SummaryStatistics median(const std::vector<int> nums) {
            return SummaryStatistics::SummaryStatisticsBuilder().median(calc_median(nums)).Build();
        }

        SummaryStatistics standard_deviation(const std::vector<int> nums) {
            double mean = calc_mean<int>(nums);
            std::vector<double> squared_diffs = calc_squared_diffs(nums, mean);
            double mean_squared_diffs = calc_mean<double>(squared_diffs);
            double std_dev = sqrt(mean_squared_diffs);
            return SummaryStatistics::SummaryStatisticsBuilder().mean(mean).standard_deviation(std_dev).Build();
        }
    }
}