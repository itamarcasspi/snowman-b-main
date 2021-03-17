#include "snowman.hpp"
#include <string>
#include <iostream>
using namespace ariel;
int main(){
    cout<<"Welcome to itamar caspi's excercise. Please press: \n";
    int menu = 1;
    int choice = 0;
    while(menu!=0){
        cout<<"Press : 1)To make a snowman, or any other number to exit"<<endl;
        cin>>menu;
        switch(menu){
            case 1:
                cout<<"Please enter the snowman input according to the 'catalog': ";
                cin>>choice;
                cout<<endl;
                try {
                    cout<<snowman(choice)<<endl;
                }catch(char const* error){
                    cout<<"An error has occured: '"<<error<<"'"<<endl;
                }
                
                break;
            case 2:
                cout<<"Thanks for reviewing the code. Goodbye!"<<endl;
                menu = 0;
                break;
        }

    }
    
    return 0;
}