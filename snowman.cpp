#include <iostream>
#include <string>
#include <array>
#include "snowman.hpp"
using namespace std;

//{"","","",""};

constexpr int SNOWMAN_LENGTH = 8,MIN_RANGE = 0, MAX_RANGE = 4;
constexpr int H = 0, N = 1, L = 2, R = 3, X = 4, Y = 5, T = 6, B = 7;

array<string,MAX_RANGE> HATS = {" _===_\n","  ___\n .....\n","   _\n  /_\\\n","  ___ \n (_*_)\n" };
array<string,MAX_RANGE> NOSE = {",",".","_"," "};
array<string,MAX_RANGE> LEFT_EYE = {".","o","O","-"};
array<string,MAX_RANGE> RIGHT_EYE = {".","o","O","-"};
array<string,MAX_RANGE> UPPER_LEFT_ARM = {" ","\\"," "," "};
array<string,MAX_RANGE> LOWER_LEFT_ARM = {"<"," ","/"," "};
array<string,MAX_RANGE> UPPER_RIGHT_ARM = {" ","/"," "," "};
array<string,MAX_RANGE> LOWER_RIGHT_ARM = {">"," ","\\"," "};
array<string,MAX_RANGE> TORSO = {"( : )","(] [)","(> <)","(   )"};
array<string,MAX_RANGE> BASE = {" ( : )\n"," (\" \")\n"," (___)", " (   )\n"};

//HNLRXYTB
namespace ariel
{

    array<int,SNOWMAN_LENGTH> validate(int num){
        string snum = to_string(num);//convert input int to string so we can 1) check for the correct length 2) easily translate it into an array.
        array<int,SNOWMAN_LENGTH> numArray = {0,0,0,0,0,0,0,0};
        int current = 0;
        if(snum.length()>SNOWMAN_LENGTH){throw "Error: input too long";}
        if(snum.length()<SNOWMAN_LENGTH){throw "Error: input too short";}
        if(num<0){throw "Error: negative input";}
        for (int i = 0; i < snum.length(); i++)
        {
            current = snum.at(i)-'0'; // turns the char at index i to an int
            if(current<MIN_RANGE || current>MAX_RANGE){throw "Error: out of range";}
            current--;//reduce the intex to fit the "catalog" range
            numArray.at(i) = current;         
        }
        cout<<endl;
        return numArray;
        
    }

    void buildHat(array<int,SNOWMAN_LENGTH> numArray,string *snowman){
        *snowman += HATS.at(numArray.at(H));
    }

    void buildHead(array<int,SNOWMAN_LENGTH> numArray,string *snowman){
        //head format X(LNR)Y
        *snowman+=UPPER_LEFT_ARM.at(numArray.at(X))+"("+LEFT_EYE.at(numArray.at(L))+NOSE.at(numArray.at(N))+RIGHT_EYE.at(numArray.at(R))+")"+UPPER_RIGHT_ARM.at(numArray.at(Y))+"\n";
    }

    void buildTorso(array<int,SNOWMAN_LENGTH> numArray,string *snowman){
        //torso format X(TTT)Y
       *snowman+=LOWER_LEFT_ARM.at(numArray.at(X))+TORSO.at(numArray.at(T))+LOWER_RIGHT_ARM.at(numArray.at(Y))+"\n";
    }

    void buildBase(array<int,SNOWMAN_LENGTH> numArray, string *snowman){
        *snowman+=BASE.at(numArray.at(B));
    }
    

    string snowman(int num)
    { 
        array<int,SNOWMAN_LENGTH> numArray = validate(num); //validates that the input is indeed correct, and returns an array.
        string snowman;
        buildHat(numArray,&snowman);
        buildHead(numArray,&snowman);
        buildTorso(numArray,&snowman);
        buildBase(numArray,&snowman);
        return snowman;
    }

    

}

