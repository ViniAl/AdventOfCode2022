#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::fstream newfile;
    std::string tp;
    int PosLineBreak;
    int TempSum = 0;
    int MaxSumPos1 = 0;
    int MaxSumPos2 = 0;
    int MaxSumPos3 = 0;
    int ItNum = 0;

    newfile.open("day1Input.txt",std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){ //checking whether the file is open
        while(std::getline(newfile, tp)){
            PosLineBreak = tp.std::string::find('\r');
            if(PosLineBreak == 0){ //empty line
                if (TempSum > MaxSumPos3){
                    if (TempSum > MaxSumPos2){
                        if (TempSum > MaxSumPos1){
                            MaxSumPos3 = MaxSumPos2;
                            MaxSumPos2 = MaxSumPos1;
                            MaxSumPos1 = TempSum;
                            TempSum = 0;
                        }
                        else{
                            MaxSumPos3 = MaxSumPos2;
                            MaxSumPos2 = TempSum;
                            TempSum = 0;                            
                        }
                    }
                    else{
                        MaxSumPos3 = TempSum;
                        TempSum = 0;
                    } 
                }
                else{
                    TempSum = 0;
                } 
            } 
            else{ //number present
                ItNum = std::stoi(tp.std::string::substr(0,tp.std::string::size()-1));
                TempSum += ItNum;
            } 
        }; //read data from file object and put it into string.
        newfile.close(); //close the file object.
    }
    std::cout << MaxSumPos1 << std::endl;
    std::cout << MaxSumPos1 + MaxSumPos2 + MaxSumPos3 << std::endl;
}