#include <iostream>

void say_hi(){
     TString output = getenv("OUTPUT");
     TString input = getenv("INPUT");
     cout << "OUTPUT: " << output << endl;
     cout << "INPUT: " << input << endl;
}
