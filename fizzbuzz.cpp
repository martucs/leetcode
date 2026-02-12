#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cassert>

void printStrVector(const std::vector<std::string> vec)
{
    std::cout << "[" ;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
}

// O(n) for the initialization and the while loop, O(1) for each iteration
std::vector<std::string>    fizzbuzz(int n)
{
    // "FizzBuzz" -> if i is divisible by 3 and 5
    // "Fizz" -> if i is divisible by 3
    // "Buzz" -> if i is divisible by 5
    // i if not divisible by any of the above

    std::vector<std::string>    strings = {"FizzBuzz", "Fizz", "Buzz"};
    std::vector<std::string>    answer(n);

    int i = 0;
    while (i < n)
    { 
        if ((i + 1) % 15 == 0)
            answer[i] =  strings[0];
        else if ((i + 1) % 3 == 0)
            answer[i] =  strings[1];
        else if ((i + 1) % 5 == 0)
            answer[i] =  strings[2];
        else
            answer[i] = std::to_string(i + 1);
        i++;
    }
   return (answer);
}

void    tests()
{
    int num = 5;
    std::vector<std::string> sol = {"1", "2", "Fizz", "4", "Buzz"};

    assert(fizzbuzz(num) == sol);   

    num = 15;
    sol = {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"};

    assert(fizzbuzz(num) == sol);
}

int main(void)
{
    tests();
    std::cout << "fizzbuz() passed all tests!\n";
    return (0);
}