#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define MAX 2

using namespace std;

// Implementação da estrutura de dados
struct Node {
    string word;
    int* frequencies;
    Node* previous;
    Node* next;
}

struct List {
    Node* first;
    Node* last;
}

    // Funções

List* createList() {
    List* newList = new List;

    newList->first = newList->last = nullptr;

    return newList;
}

void addElement(List* list, string word) {
    Node* element = new Node;

    element->
}

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
