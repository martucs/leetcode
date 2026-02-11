#include <iostream>
#include <vector>
#include <strings.h>

std::vector<int> twoSum(std::vector<int> vec, int target)
{
    std::vector<int> sol;
    
    std::cout << "target = " << target << std::endl;

    size_t i = 0;
    int base = 0;
    while ((size_t)base < vec.size() - 1)
    {
        i = 0;
        std::cout << "base = " << base << std::endl;
        while (base + i + 1 != vec.size())
        {
            std::cout << "i = " << i << std::endl;
            if (vec[base] + vec[base + i + 1] == target)
            {
                // std::cout << "found solution in i = " << i << std::endl;
                // std::cout << vec[i] << " + " << vec[i + 1] << " = " << vec[i] + vec[i + 1] << std::endl;
                sol.push_back(base);
                sol.push_back(base + i + 1);
                return (sol);
            }
            i++;
        }
        base++;
    }
    std::cout << "did NOT find solution" << std::endl;
    return (sol);
}

void printVector(std::vector<int> vec)
{
    std::vector<int>::iterator it = vec.begin();
    if (vec.empty())
        std::cout << "vector is empty\n";
    while (!vec.empty() && it < vec.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

int main(void)
{
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    
    std::vector<int> nums3= {3,3};
    int target3= 6;

    std::vector<int> nums4 {1,3,3,4};
    int target4 = 7;

    std::vector<int> sol;

    sol = twoSum(nums1, target1);
    if (!sol.empty())
        printVector(sol);
    
    std::cout << std::endl;

    sol = twoSum(nums2, target2);
    if (!sol.empty())
        printVector(sol);
   
    std::cout << std::endl;

    sol = twoSum(nums3 ,target3);
    if (!sol.empty())
        printVector(sol);

    std::cout << std::endl;

    sol = twoSum(nums4,target4);
    if (!sol.empty())
        printVector(sol);

    return (0);
}