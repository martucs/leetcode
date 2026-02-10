#include <iostream>
#include <vector>
#include <strings.h>

std::vector<int> twoSum(std::vector<int> arr, int target)
{
    std::vector<int> sol;
    
    bzero(&sol, 2);
    std::cout << "target = " << target << std::endl;

    int i = 0;
    while (i < 4)
    {
        if (i + 1 < 4 && arr[i] + arr[i + 1] == target)
        {
            std::cout << "found solution in i = " << i << std::endl;
            std::cout << arr[i] << " + " << arr[i + 1] << " = " << arr[i] + arr[i + 1] << std::endl;
            sol[0] = i;
            sol[1] = i + 1;
            return (sol);
        }
        i++;
    }
    std::cout << "did NOT find solution" << std::endl;
    return (sol);
}

void    printArray(std::vector<int> arr, int arrSize)
{
    if (!arr.empty())
    {
        int i = 0;
        while (i < arrSize)
        {
            if (i + 1 != arrSize )
                std::cout << arr[i] << ",";
            else
                std::cout << arr[i];
            i++;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "vector is empty" << std::endl;
}

int main(void)
{
    std::vector<int>  nums1;
    std::vector<int>::iterator  it = nums1.begin();
    nums1.insert(it, 2);
    it++;
    nums1.insert(it, 7);
    it++;
    std::cout << "hola" << std::endl;
    nums1.insert(it, 11);
    it++;
    nums1.insert(it, 15);

    int target1 = 9;
    
    std::vector<int>  nums2;
    
    nums2[0] = 3;
    nums2[1] = 2;
    nums2[2] = 4;

    int target2 = 6;

    std::vector<int> sol;
    
    bzero(&sol, 2);

    sol = twoSum(nums1, target1);
    if (!sol.empty())
        printArray(sol, 2);

   sol = twoSum(nums2, target2);
    if (!sol.empty())
        printArray(sol, 2);

    return (0);
}