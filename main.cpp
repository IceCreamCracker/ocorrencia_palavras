#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]){
    string line;
    ifstream myFile;

    for (int i = 1; i < argc; i++){
        
        myFile.open(argv[i]);
        if(myFile.is_open()){
            while (getline(myFile,line)) cout << line << endl;
            myFile.close();
        } else cout << "o luigi é um ...to be continued";
    }
}
