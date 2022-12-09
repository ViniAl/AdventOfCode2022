#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

std::map<char,int> MappingString(std::string& stringvar, int stringsize){
    std::map<char,int> mapped_string;
    for (int i = 0; i < stringsize; ++i){
        ++mapped_string[stringvar[i]];
    }
    return mapped_string;
}

bool my_isupper(char& ch){
    return std::isupper(static_cast<unsigned char>(ch));
}


//Uppercase item types A through Z have priorities 27 through 52. A - 65
int score_upper(char& ch){
    static const int scorethreshold = 38;
    return (static_cast<int>(ch) - scorethreshold);
}

//Lowercase item types a through z have priorities 1 through 26. a - 97
int score_lower(char& ch){
    static const int scorethreshold = 96;
    int result = static_cast<int>(ch) - scorethreshold;
    return result;
}

int ScorePriority(char& ch){
    int priority;

    if (my_isupper(ch)){
        priority = score_upper(ch);
    }
    else{
        priority = score_lower(ch);
    }

    return priority;
}

int DeterminePriorityRowPart1(std::string s){
    int strsize = s.std::string::size();
    int halfsize = strsize/2;
    std::string v1 = s.std::string::substr(0,halfsize);
    std::string v2 = s.std::string::substr(halfsize,halfsize);
    int points = 0;

    std::map<char,int> mapped_string1,mapped_string2;

    mapped_string1 = MappingString(v1,halfsize);
    mapped_string2 = MappingString(v2,halfsize);

    std::map<char,int>::iterator x;
    char commonletter;

    for(auto iter = mapped_string1.begin(); iter != mapped_string1.end(); ++iter){
        x = mapped_string2.find(iter->first);
        if (x != mapped_string2.end()){
            commonletter = x->first;
        }
    }

    points = ScorePriority(commonletter);

    return points;
}

int DeterminePriorityRowPart2(std::string& s1, std::string& s2, std::string& s3){
    int strsize1 = s1.std::string::size();
    int strsize2 = s2.std::string::size();
    int strsize3 = s3.std::string::size();
    int points = 0;

    std::map<char,int> mapped_string1,mapped_string2,mapped_string3;

    mapped_string1 = MappingString(s1,strsize1);
    mapped_string2 = MappingString(s2,strsize2);
    mapped_string3 = MappingString(s3,strsize3);

    std::map<char,int>::iterator x2,x3;
    char commonletter;

    for(auto iter = mapped_string1.begin(); iter != mapped_string1.end(); ++iter){
        x2 = mapped_string2.find(iter->first);
        x3 = mapped_string3.find(iter->first);
        if (x2 != mapped_string2.end() &&
            x3 != mapped_string3.end()){
                commonletter = iter->first;
        }
    }

    points = ScorePriority(commonletter);

    return points;
}


int main(){
    std::fstream newfile;
    std::string tp,line1,line2,line3;
    int pointspart1 = 0;
    int pointspart2 = 0;

    //part1
    newfile.open("day3input.txt",std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){ //checking whether the file is open
        while(std::getline(newfile, tp)){
            pointspart1 += DeterminePriorityRowPart1(tp);
        }; //read data from file object and put it into string.
        newfile.close(); //close the file object.
    }

    //part2
    newfile.open("day3input.txt",std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){ //checking whether the file is open
        while(std::getline(newfile, line1) && std::getline(newfile, line2) && std::getline(newfile, line3)){
            pointspart2 += DeterminePriorityRowPart2(line1,line2,line3);
        }; //read data from file object and put it into string.
        newfile.close(); //close the file object.
    }

    std::cout << "Part1: Sum of priorities is: " << pointspart1 << std::endl;
    std::cout << "Part2: Sum of Bagdes priorities is: " << pointspart2 << std::endl;

}