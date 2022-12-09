#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <map>

std::set<int> ProcessStringToSet(std::string& s){
    int dashseparator = s.std::string::find("-");
    std::set<int> newset;
    int startnumber = std::stoi(s.std::string::substr(0,dashseparator));
    int endnumber = std::stoi(s.std::string::substr(dashseparator+1,50));

    for(int iter = startnumber; iter <= endnumber; ++iter){
        newset.insert(iter);
    }

    return newset;
}

bool IsSubset(std::set<int>& set1,std::set<int>& set2){
    return (std::includes(set1.begin(), set1.end(), set2.begin(), set2.end()) ||
            std::includes(set2.begin(), set2.end(), set1.begin(), set1.end())); 
}

//this come from n(A u B) = n(A) + n(B) - n(A ∩ B)
//so
//n(A ∩ B) = n(A) + n(B) - n(A u B)
bool IsOverlap(std::set<int>& set1,std::set<int>& set2){
    std::set<int> setunion;
    std::merge(set1.begin(), set1.end(), set2.begin(), set2.end(),std::inserter(setunion,setunion.end()));
    //I give up. Will just use a map instead
    std::map<int,int> intersectmap;
    bool overlap = false;

    for(auto i = set1.begin(); i != set1.end() ; ++i){
        ++intersectmap[*i];
    }
    for(auto i = set2.begin(); i != set2.end() ; ++i){
        ++intersectmap[*i];
    }
    for(auto key : setunion) {
        --intersectmap[key];
    }

    for (auto i = intersectmap.begin(); i != intersectmap.end(); ++i){
        if (i->second == 1){
            overlap = true;
            break;
        }
    }

    return overlap;
}

std::tuple<std::set<int>,std::set<int>> IdentifySets(std::string& s){
    std::set<int> set1,set2;
    int commaseparator = s.std::string::find(",");
    std::string s1 = s.std::string::substr(0,commaseparator);
    std::string s2 = s.std::string::substr(commaseparator+1,50); //if npos is within bound the length can exceed maxium size and it will still be sucessfull

    set1 = ProcessStringToSet(s1);
    set2 = ProcessStringToSet(s2);

    return std::make_tuple(set1,set2);
}

int main(){
    std::fstream newfile;
    std::string line;
    std::set<int> set1,set2;
    int countsubsets = 0;
    int countoverlaps = 0;

    newfile.open("day4input.txt",std::ios::in);
    if (newfile.is_open()){
        while(std::getline(newfile,line)){
            std::tie(set1,set2) = IdentifySets(line);
            if (IsSubset(set1, set2)){
                ++countsubsets;
            }
            if (IsOverlap(set1,set2)){
                ++countoverlaps;
            }
        }
        newfile.close();
    } 
    std::cout << "total number of subset cases are: " << countsubsets << std::endl;
    std::cout << "total number of overlap cases are: " << countoverlaps << std::endl;
}