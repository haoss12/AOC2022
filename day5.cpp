#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <sstream>

int main ()
{
    std::ifstream workFile("day5data.txt");
    std::stringstream s;
    std::string str, dump;
    int counter = 0;
    int stacks = 0;
    int number, from, to;
    std::string temp;

    //  counting how many lines we have to read and how many stacks are there
    while (std::getline(workFile, str))
    {
        std::cout << str << '\n';
        if (std::any_of(str.begin(), str.end(), ::isdigit)){
            std::sort(str.begin(), str.end());
            stacks = std::atoi(&str[str.length() - 1]);
            break;
        }
        counter++;
    }

    std::string stacks_vec[stacks]; // creating strings to store stacks values

    workFile.clear();   // clearing flags on ifstream
    workFile.seekg (0, std::ios::beg);  // jump back to beg. of stream

    // reading values on stack line by line
    while (counter != 0)
    {
        std::getline(workFile, str);
        for (int i = 0; i < stacks; i++)
        {
            if (str[4*i + 1] != ' ')
                stacks_vec[i] += (str[4*i + 1]);
        }
        counter--;
    }

    // reversing stacks order
    for (int i = 0; i < stacks; i++)
        std::reverse(stacks_vec[i].begin(), stacks_vec[i].end());

    std::getline(workFile, dump);   // getting out of useless trash
    std::getline(workFile, dump);

    std::string stacks_vec_2[stacks];   // copy for part 2
    std::copy(stacks_vec, stacks_vec + stacks, stacks_vec_2);

    while (workFile >> dump >> number >> dump >> from >> dump >> to)
    {
        // Part I
        for (int i = 0; i < number; i++)
        {
            stacks_vec[to-1].push_back(stacks_vec[from-1][stacks_vec[from-1].length() - 1]);
            stacks_vec[from-1].pop_back();
        }
        // Part II
        for (int i = 0; i < number; i++)
        {
            temp.push_back(stacks_vec_2[from-1][stacks_vec_2[from-1].length() - 1]);
            stacks_vec_2[from-1].pop_back();
        }
        std::reverse(temp.begin(), temp.end());
        stacks_vec_2[to-1] += temp;
        temp.clear();
    }

    // Part I
    std::cout << "Part I:  ";
    for (const auto i : stacks_vec)
    {
        std::cout << i[i.length() - 1]; //printing the top element of every stack 
    }
    std::cout << '\n';

    // Part II
    std::cout << "Part II: ";
    for (const auto i : stacks_vec_2)
    {
        std::cout << i[i.length() - 1];
    }
    std::cout << '\n';

  return 0;
}