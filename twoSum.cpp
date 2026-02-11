#include <iostream>
#include <vector>
#include <strings.h>
#include <cassert>

std::vector<int> twoSum(std::vector<int> vec, int target)
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

void printVector(std::vector<int> vec)
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

void    runDebugTest(std::vector<int> nums, int target,  std::vector<int> sol)
{
    std::cout << "target = " << target << std::endl;
    sol = twoSum(nums, target);
    if (!sol.empty())
        printVector(sol);
    else
        std::cout << "error: did NOT find solution" << std::endl;
    std::cout << std::endl;
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
    int target4 = 7;

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