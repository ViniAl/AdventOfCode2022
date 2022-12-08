#include <iostream>
#include <fstream>
#include <string>


//score
//A Rock
//B Paper
//C Scissors

//Y Paper - 2
//X Rock - 1
//Z Scissors - 3
int DetermineResultPart1(std::string s){
    std::string v1 = s.std::string::substr(0,1);
    std::string v2 = s.std::string::substr(2,1);
    int points = 0;

    if(v1.compare("A") == 0){
        if(v2.compare("Y") == 0){
            points = 8;
        }
        else if(v2.compare("X") == 0){
            points = 4;
        }
        else{
            points = 3;
        }
    }
    else if(v1.compare("B") == 0){
        if(v2.compare("Y") == 0){
            points = 5;
        }
        else if(v2.compare("X") == 0){
            points = 1;
        }
        else{
            points = 9;
        }
    }
    else{
        if(v2.compare("Y") == 0){
            points = 2;
        }
        else if(v2.compare("X") == 0){
            points = 7;
        }
        else{
            points = 6;
        }
    }

    return points;
}

//score
//A Rock
//B Paper
//C Scissors

//Paper - 2
//Rock - 1
//Scissors - 3

//Y DRAW
//X LOSE
//Z WIN 
int DetermineResultPart2(std::string s){
    std::string v1 = s.std::string::substr(0,1);
    std::string v2 = s.std::string::substr(2,1);
    int points = 0;

    if(v1.compare("A") == 0){
        if(v2.compare("Y") == 0){
            points = 4;
        }
        else if(v2.compare("X") == 0){
            points = 3;
        }
        else{
            points = 8;
        }
    }
    else if(v1.compare("B") == 0){
        if(v2.compare("Y") == 0){
            points = 5;
        }
        else if(v2.compare("X") == 0){
            points = 1;
        }
        else{
            points = 9;
        }
    }
    else{
        if(v2.compare("Y") == 0){
            points = 6;
        }
        else if(v2.compare("X") == 0){
            points = 2;
        }
        else{
            points = 7;
        }
    }

    return points;
}


int main(){
    std::fstream newfile;
    std::string tp;
    int TotalPointsPart1 = 0;
    int TotalPointsPart2 = 0;

    newfile.open("day2input.txt",std::ios::in);
    if (newfile.is_open()){
        while(std::getline(newfile, tp)){
            TotalPointsPart1 += DetermineResultPart1(tp);
            TotalPointsPart2 += DetermineResultPart2(tp);
        }    
        newfile.close();
    }
    std::cout << "Part1: Total points are:" << TotalPointsPart1 << std::endl;
    std::cout << "Part2: Total points are:" << TotalPointsPart2 << std::endl;
}