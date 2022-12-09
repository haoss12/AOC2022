#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

int main ()
{
    long sum = 0;
    std::ifstream workFile("day3data");
    std::string str;
    size_t halfStrSize = 0;

    // part 1

while (std::getline(workFile, str))
{   
    halfStrSize = str.size()/2;

        auto left = str.substr(0, halfStrSize);
        auto right = str.substr(halfStrSize, halfStrSize);
        std::sort(left.begin(), left.end());
        std::sort(right.begin(), right.end());
        auto dump = std::string{};

    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(dump));
    sum += ((isupper(dump[0])) ? ((int)dump[0] - 38) : ((int)dump[0] - 96));
}

    std::cout << sum << '\n';

    // part 2

    sum = 0; 
    std::string str1;
    std::string str2;
    std::string str3;
    workFile.clear();
    workFile.seekg (0, std::ios::beg);

while (std::getline(workFile, str1))
{   
    std::getline(workFile, str2);
    std::getline(workFile, str3);

        std::sort(str1.begin(), str1.end());
        std::sort(str2.begin(), str2.end());
        std::sort(str3.begin(), str3.end());

        auto dump1 = std::string{};
        auto dump2 = std::string{};
    std::set_intersection(str1.begin(), str1.end(), str2.begin(), str2.end(), std::back_inserter(dump1));
    std::set_intersection(dump1.begin(), dump1.end(), str3.begin(), str3.end(), std::back_inserter(dump2));

    sum += ((isupper(dump2[0])) ? ((int)dump2[0] - 38) : ((int)dump2[0] - 96));
}
    std::cout << sum << '\n';

  return 0;
}