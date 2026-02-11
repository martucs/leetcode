#include <iostream>
#include <vector>
#include <array>

char    **fizzbuzz(int n)
{
    std::string fizzBuzz = "FizzBuzz";
    std::string fizz = "Fizz";
    std::string buzz = "Buzz";

    std::cout << "starting the fizzbuzz function with n = " << n << std::endl;

    for (char c : fizz)
        std::cout << c;
    std::cout << std::endl;
   
   return (NULL);
}

void printVector(std::vector<int> vec)
{
    std::cout << std::endl << "printing vector.." << std::endl;
    std::cout << "vector capacity is "<< vec.capacity() << std::endl;

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

void    printIntArray(int *array, int arrSize)
{
    if (array)
    {
        int i = 0;
        while (i < arrSize)
            std::cout << array[i++] ;
        std::cout << std::endl;
    }
    else
        std::cout << "array's pointer is null" << std::endl;
}

void    printArray(std::array<int, 3> arr, int arrSize)
{
    
}

int main(void)
{
    int n = 3;

    fizzbuzz(n);

    std::vector<int> intVector;
    std::vector<int>::iterator it = intVector.begin();
    
    //intVector.insert(it, 3);
    //it++;
    intVector.assign(sizeof(double), 11);

    int array[10];

    for (int i = 0; i < 10; i++)
        array[i] = i;

    std::array<int, 3>  arr(1, 2, 3);

    printIntArray(array, 5);
    printArray(arr, 3);
    printVector(intVector);

    return (0);
}