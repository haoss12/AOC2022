#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

int main ()
{
    long sum = 0;
    long top3sum = 0;
    std::ifstream workFile("day1data.txt");
    std::string str;
    std::vector<long> vec;

    while (std::getline(workFile, str))
    {
        if (!str.empty())
        {
            sum += std::stol(str, 0, 10);
        } else
        {
            vec.push_back(sum);
            sum = 0;
        }
    }
    std::sort(vec.begin(), vec.end());
    top3sum = vec[vec.size()-1] + vec[vec.size()-2] + vec[vec.size()-3];
    std::cout << "Task1 ans: " << vec[vec.size()-1] << '\n';
    std::cout << "Task2 ans: " << top3sum << '\n';

  return 0;
}