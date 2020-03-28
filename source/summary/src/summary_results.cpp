#include "summary_results.h"
#include <numeric>

namespace statlib {
    namespace summaries {

        double calc_mean(const std::vector<int> nums) {
            return std::accumulate(nums.begin(), nums.end(), 0) / static_cast<double>(nums.size());
        }

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

        SummaryStatistics mean(const std::vector<int> nums) {
            return SummaryStatistics::SummaryStatisticsBuilder().mean(calc_mean(nums)).Build();
        }

        SummaryStatistics median(const std::vector<int> nums) {
            return SummaryStatistics::SummaryStatisticsBuilder().median(calc_median(nums)).Build();
        }
    }
}