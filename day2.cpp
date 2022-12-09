#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

int main ()
{
    long sum = 0;
    std::ifstream workFile("day2data.txt");
    char strOpp;
    char strPlayer;
    char dump;
    int i = 0;

// part 1 
// applied ifology...

    //X - rock, Y - paper, Z - scissors => Player
    //A - rock, B - paper, C - scissors => Opp

    while (workFile >> strOpp >> strPlayer)
    {
        if(strPlayer == 'X'){   //rock
            sum += 1;
            if(strOpp == 'A')   //rock
                sum += 3;
            if(strOpp == 'B')   //paper
                sum += 0;
            if(strOpp == 'C')   //scissors
                sum += 6;              
        }
        if(strPlayer == 'Y'){   //paper
            sum += 2;
            if(strOpp == 'A')   //rock
                sum += 6;
            if(strOpp == 'B')   //paper
                sum += 3;
            if(strOpp == 'C')   //scissors
                sum += 0;
        }
        if(strPlayer == 'Z'){
            sum += 3;        
            if(strOpp == 'A')   //rock
                sum += 0;
            if(strOpp == 'B')   //paper
                sum += 6;
            if(strOpp == 'C')   //scissors
                sum += 3;        
        }    
    }
    
std::cout << "Sum: " << sum << '\n';

// part 2

    //X - lose, Y - draw, Z - win => Player
    //A - rock 1, B - paper 2, C - scissors 3 => Opp

workFile.clear();
workFile.seekg (0, std::ios::beg);
sum = 0;

    while (workFile >> strOpp >> strPlayer)
    {
        if(strOpp == 'A'){          //rock
            if(strPlayer == 'X')    //lose so scissors
                sum += 3 + 0;
            if(strPlayer == 'Y')    //draw so rock
                sum += 1 + 3;
            if(strPlayer == 'Z')    //win so paper
                sum += 2 + 6;              
        }
        if(strOpp == 'B'){          //paper
            if(strPlayer == 'X')    //lose so rock
                sum += 1 + 0;
            if(strPlayer == 'Y')    //draw so paper
                sum += 2 + 3;
            if(strPlayer == 'Z')    //win so scissors
                sum += 3 + 6;              
        }
        if(strOpp == 'C'){          //scissors
            if(strPlayer == 'X')    //lose so paper
                sum += 2 + 0;
            if(strPlayer == 'Y')    //draw so scissors
                sum += 3 + 3;
            if(strPlayer == 'Z')    //win so rock
                sum += 1 + 6;              
        }   
    }

std::cout << "Sum: " << sum << '\n';

  return 0;
}