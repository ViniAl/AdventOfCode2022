#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <regex>

class BoxStacks{
    private:
    
    public:
    std::map<int,std::vector<std::string>> stackmaps;
    
    //class constructor
    BoxStacks(){
        stackmaps[1] = {"R", "S", "L", "F", "Q"};
        stackmaps[2] = {"N", "Z", "Q", "G", "P","T"};
        stackmaps[3] = {"S","M","Q","B"};
        stackmaps[4] = {"T","G","Z","J","H","C","B","Q"};
        stackmaps[5] = {"P","H","M","B","N","F","S"};
        stackmaps[6] = {"P","C","Q","N","S","L","V","G"};
        stackmaps[7] = {"W","C","F"};
        stackmaps[8] = {"Q","H","G","Z","W","V","P","M"};
        stackmaps[9] = {"G","Z","D","L","C","N","R"};
    }

    void MoveBox(int& quantity, int& origin, int& destination){
        std::string movedletter;

        for (int i = 0; i < quantity; i++)
        {
            movedletter = this->stackmaps[origin].back();
            this->stackmaps[origin].pop_back();
            this->stackmaps[destination].std::vector<std::string>::push_back(movedletter);
        }
    }

    void MoveBoxPart2(int& quantity, int& origin, int& destination){
        std::string movedletter;
        std::vector<std::string> tempvector = {};

        for (int i = 0; i < quantity; i++){
            movedletter = this->stackmaps[origin].back();
            this->stackmaps[origin].pop_back();
            tempvector.std::vector<std::string>::push_back(movedletter);
        }

        for (int i = 0; i < quantity; i++){
            movedletter = tempvector.back();
            tempvector.pop_back();
            this->stackmaps[destination].std::vector<std::string>::push_back(movedletter);
        }
    }

    int ExtractNumber(std::string partofline){
        std::smatch numbermatch;
        std::regex numberexp("[0-9]+");

        std::regex_search(partofline, numbermatch,numberexp);

        return std::stoi(numbermatch.str(0));
    }

    std::tuple<int,int,int> IdentifyLines(std::string line){
        std::regex moveexpr("move [0-9]+");
        std::regex fromexpr("from [0-9]+");
        std::regex toexpr("to [0-9]+");
        std::regex numexp("[0-9]+");

        std::smatch regexpmatch;
        std::string matchstring;

        std::regex_search(line, regexpmatch, moveexpr);
        matchstring = regexpmatch.str(0);
        int quantity = ExtractNumber(matchstring);

        std::regex_search(line, regexpmatch, fromexpr);
        matchstring = regexpmatch.str(0);
        int origin = ExtractNumber(matchstring);

        std::regex_search(line, regexpmatch, toexpr);
        matchstring = regexpmatch.str(0);
        int destination = ExtractNumber(matchstring);

        return std::make_tuple(quantity,origin,destination);
    }

    void ProcessCommand(std::string& line){
        int quantity;
        int origin;
        int destination;

        std::tie(quantity,origin,destination) = IdentifyLines(line);

        MoveBox(quantity, origin, destination);
    }

    void ProcessCommandPart2(std::string& line){
        int quantity;
        int origin;
        int destination;

        std::tie(quantity,origin,destination) = IdentifyLines(line);

        MoveBoxPart2(quantity, origin, destination);
    }

};

int main(){
    std::fstream newfile;
    std::string line1;
    BoxStacks boxes,boxespart2;
    
    newfile.open("day5input.txt",std::ios::in);
    if(newfile.is_open()){

        //process the bin queue
        while(std::getline(newfile,line1)){
            //process bin initial state later
            if (line1.std::string::find("move") == std::string::npos){

            }
            // process move line present
            else{
                boxes.ProcessCommand(line1);
                boxespart2.ProcessCommandPart2(line1);
            }
            ;
        }
        
        //move boxes

        newfile.close();
    }

    //first part solution
    std::cout << "first part solution is: ";
    for(auto i = 1; i < 10; ++i){
        std::cout << boxes.stackmaps[i].back();
    }
    std::cout << std::endl << "second part solution is :";
    //second part solution
    for(auto i = 1; i < 10; ++i){
        std::cout << boxespart2.stackmaps[i].back();
    }
}