#include <iostream>
#include <vector>
#include <strings.h>
#include <cassert>
#include <map>

// Hash map -> O(n) Time & space complexity
std::vector<int> twoSumBetter(const std::vector<int> &vec, int target)
{
    std::map<int, int> valueToIndex;

    for (int i = 0, i < vec.size(), i++)
    {
        int current = vec[i];:
        int x = target - current;

    }

}

// Brute froce -> O(n^2) Time complexity, O(1) Space complexity
std::vector<int> twoSum(const std::vector<int> &vec, int target)
{
    std::vector<int> sol;

    size_t i = 0;
    size_t base = 0;
    while (base < vec.size() - 1)
    {
        i = 0;
        // std::cout << "base = " << base << std::endl;
        while (base + i + 1 != vec.size())
        {
            // std::cout << "i = " << i << std::endl;
            if (vec[base] + vec[base + i + 1] == target)
            {
                sol.push_back(base);
                sol.push_back(base + i + 1);
                return (sol);
            }
            i++;
        }
        base++;
    }
    return (sol);
}

void printVector(const std::vector<int> &vec)
{
    if (vec.empty())
    {
        std::cout << "error: vector is empty\n";
        return ;
    }
    std::cout << "[" ;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
}

void    runDebugTest(const std::vector<int> &nums, int target, const std::vector<int> &sol)
{
    std::cout << "target = " << target << std::endl;
    std::vector<int> res;

    res = twoSum(nums, target);
    if (res.empty())
    {
        std::cout << "error: did NOT find solution\n";
        return ;
    }
    if (res == sol)
    {
        printVector(res);
        std::cout << "result is correct!\n\n";
    }
    else
    {
        std::cout << " !WARNING: there is a mismatch in results!\n";
        std::cout << "my result:\n";
        printVector(res);
        std::cout << "solution:\n";
        printVector(sol);
    }
}

void    debugTests(void)
{
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    
    std::vector<int> nums3= {3,3};
    int target3= 6;

    std::vector<int> nums4 {1,3,3,4};
    int target4 = 5;

    std::vector<int> sol = {0,1};
    runDebugTest(nums1, target1, sol);

    sol = {1,2};
    runDebugTest(nums2, target2, sol);
    
    sol = {0,1};
    runDebugTest(nums3, target3, sol);
    
    sol = {0,3};
    runDebugTest(nums4, target4, sol);
}

void    tests()
{
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    
    std::vector<int> nums3= {3,3};
    int target3= 6;

    std::vector<int> nums4 {1,3,3,4};
    int target4 = 5;

    std::vector<int> sol {0,1};
    assert(twoSum(nums1, target1) == sol);
    
    sol = {1,2};
    assert(twoSum(nums2, target2) == sol);

    sol = {0,1};
    assert(twoSum(nums3, target3) == sol);

    sol = {0,3};
    assert(twoSum(nums4, target4) == sol);
}

int main(void)
{
    // debugTests();
    tests();
    std::cout << "twoSum() passed all tests successfully!\n";

    return (0);
}