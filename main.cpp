#include <iostream>
#include <cassert>
#include <unordered_map>
#include <vector>
#include <string>

// Write an algorithm that returns the first non-repeated character in a
// string. For example:

// "ABCA" -> returns B
// "BCABAC" -> returns null
// "BAC" -> returns B
// "GlovoOnGlovo" -> returns O
// "What is the first non-repeated character?" -> returns W

void printVector(std::vector<char> vec)
{
    std::cout << std::endl
              << "printing vector.." << std::endl;

    std::vector<char>::iterator it = vec.begin();
    if (vec.empty())
        std::cout << "vector is empty\n";
    while (!vec.empty() && it < vec.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

bool findCharInVector(std::vector<char> &vec, char c)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == c)
            return true;
    }
    return false;
}

char findNonRepeated(const std::string& str)
{
    std::unordered_map<char, unsigned char> charMap;
    charMap.reserve(str.size());

    for (const char& c : str)
    {
        unsigned char& value = charMap[c]; // single lookup

        if (value == 0) // the map was empty
            value = 1;
        else
            value = 2;
    }
    for (const char& c : str)
    {
        if (charMap[c] == 1)
            return c;
    }
    return '\0';
}


/*char    findNonRepeated(std::string &str)
{
    int i = 0;
    char current;
    std::unordered_map<char, int>  charMap;
    for (i = 0; i < str.size(); i++)
    {
        if (charMap.find(str[i]) == charMap.end())
            charMap[str[i]] = 1;
        else
            charMap[str[i]] = 2;
    }
    for (i = 0; i < str.size(); i++)
    {
        if (charMap[str[i]] == 1)
            return (str[i]);
    }
    return ('\0');
}*/


/*char findNonRepeated(std::string &str)
{
    int i = 0;
    char current = '\0';
    std::vector<char> repeatedChars;
    while (i < str.size())
    {
        current = str[i];
        if (findCharInVector(repeatedChars, current))
        {
            i++;
            continue;
        }
        int j = 0;
        while (j < str.size())
        {
            if (i != j && str[j] == current)
            {
                if (findCharInVector(repeatedChars, current) == false)
                    repeatedChars.push_back(current);
                break;
            }
            j++;
        }
        if (j == str.size())
        {
            // printVector(repeatedChars);
            return (current);
        }
        i++;
    }
    // printVector(repeatedChars);
    return ('\0');
}*/
// O(n²) time complexity


/*char    findNonRepeated(std::string &str)
{
    int i = 0;
    char current = '\0';

    while (i < str.size())
    {
        current = str[i];
        std::cout << "i = " << i << std::endl;
        int j = 0;
        // miramos string de inicio a fin buscando una coincidencia del current
        // si la encontramos, significa que el caracter está repetido, por tanto,
        // movemos la i hacia el sguiente caracter de la string
        while (j < str.size())
        {
            std::cout << "j = " << j << std::endl;
            if (i != j && str[j] == current)
                break;
            j++;
        }
        if (j == str.size()) // no hemos encontrado coincidencias con current en toda la string, no hace falta seguir mirando el resto de caracteres
        {
            std::cout << "returning " << current << std::endl;
            return (current);
        }
        i++;
    }
    std::cout << "returning null\n";
    return ('\0');
}*/
// no es eficiente porque una vez hemos descartado un caracter porque ya lo hemos visto repetido,
// luego cuando seguimos iterando por la string con el current, volvemos a encontrar el caracter repetido y volvemos a checkear si está repetido o no
// O(n²) time complexity

/*char    findNonRepeated(std::string str)
{
    char    c;
    size_t  i = 0;
    while ( i < str.size())
    {
        c = str[i];
        for (size_t j = i + 1; j < str.size(); j++)
        {
            if (str[j] == c)
                break ;
        }
        return (c);
        i++;
    }
    return ('\0');
}*/

void findNonRepeated_test(void)
{
    std::string str = "ABCA";
    char c = 'B';

    assert(findNonRepeated(str) == c);

    str = "BCABAC";
    c = '\0';
    assert(findNonRepeated(str) == c);

    str = "BAC";
    c = 'B';
    assert(findNonRepeated(str) == c);

    str = "GlovoOnGlovo";
    c = 'O';
    assert(findNonRepeated(str) == c);

    str = "What is the first non-repeated character?";
    c = 'W';
    assert(findNonRepeated(str) == c);
}

int main(void)
{
    findNonRepeated_test();
    std::cout << "every test was okay\n";
    return (0);
}