#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>

bool check_full_intersection(unsigned elf1_1, unsigned elf1_2, unsigned elf2_1,unsigned elf2_2)
{
    std::vector<unsigned> elf1(elf1_2 - elf1_1 + 1);
    std::iota(elf1.begin(), elf1.end(), elf1_1);

    std::vector<unsigned> elf2(elf2_2 - elf2_1 + 1);
    std::iota(elf2.begin(), elf2.end(), elf2_1);

    std::vector<unsigned> dump;

    std::set_intersection(elf1.begin(), elf1.end(), elf2.begin(), elf2.end(), std::back_inserter(dump));

    if (dump.size() == elf1.size())
        return true;
    
    if (dump.size() == elf2.size())
        return true;
    
    return false;
}

bool check_any_intersection(unsigned elf1_1, unsigned elf1_2, unsigned elf2_1,unsigned elf2_2)
{
    std::vector<unsigned> elf1(elf1_2 - elf1_1 + 1);
    std::iota(elf1.begin(), elf1.end(), elf1_1);

    std::vector<unsigned> elf2(elf2_2 - elf2_1 + 1);
    std::iota(elf2.begin(), elf2.end(), elf2_1);

    std::vector<unsigned> dump;

    std::set_intersection(elf1.begin(), elf1.end(), elf2.begin(), elf2.end(), std::back_inserter(dump));

    if (dump.size() != 0)
        return true;
    
    return false;
}

int main ()
{
    unsigned long full_sum = 0;
    unsigned long any_sum = 0;
    unsigned elf1_1, elf1_2, elf2_1, elf2_2;
    char a, b, c;
    std::ifstream workFile("day4data.txt");

    while (workFile >> elf1_1 >> a >> elf1_2 >> b >> elf2_1 >> c >> elf2_2)
    {
        if(check_full_intersection(elf1_1, elf1_2, elf2_1, elf2_2))
            full_sum++;
        
        if(check_any_intersection(elf1_1, elf1_2, elf2_1, elf2_2))
            any_sum++;
    }

    std::cout << "Part I:  " << full_sum << '\n';
    std::cout << "Part II: " << any_sum << '\n';

  return 0;
}