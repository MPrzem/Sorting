#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "IntrospectiveSort.h"
#include<vector>
#include<algorithm>
#include <math.h>  
#include <iostream>
// TEST_CASE("Sorting 1,2,3 should give 1,2,3","[sort]"){
// int input[]{4,2,6,8,3,1,0,7,9};
// IntroSort(input, 0 , 8,2*std::log2(9));
// std::vector<int> output;
// std::copy(std::begin(input), std::end(input), std::back_inserter(output));

// REQUIRE_THAT(output,Catch::Matchers::Equas(std::vector<int>{0,1,2,3,4,6,7,8,9}));
// }

SCENARIO("Array should be sorted","[sorting]"){
    GIVEN("Unsorted array of int, and copy of is for std::sort"){
        auto input_vec=GENERATE(std::vector<int>{4,2,6,8,3,1,0,7,9},std::vector<int>{},std::vector<int>{1,1,1,1,1,1,1,1,1},std::vector<int>{0,1,2,3,4,5,6,7,8},std::vector<int>{-1,-2,-78,-2,7,9});
        int input[input_vec.size()];
        std::cout<<input_vec.size();
        std::copy(std::begin(input_vec), std::end(input_vec),input);
        WHEN("Array is sorted by IntroSort"){
            IntroSort(input, 0 , input_vec.size()-1,2*std::log2(input_vec.size()-1));
            THEN("Array sorted by IntroSort are equal to array sorted by std::sort"){
                std::vector<int> v(input, input+input_vec.size());
                std::sort(input_vec.begin(),input_vec.end());
                REQUIRE_THAT(input_vec,Catch::Matchers::Equals(v));
            }
        }
    }
}
