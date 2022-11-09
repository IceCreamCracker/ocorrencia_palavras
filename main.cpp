#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>

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

string paraMaisBaixo (string str){ // to lower case
    unsigned int f;
    string resultado = "";

    for (char c : str){
        f = int(c);
        if (f > 0xff) f = int(c) - 0xffffff00; //UTF-8 em CHAR adiciona muitos bytes
        if(f >= 0x41 && f <= 0x5a || f >= 0x80 && f <= 0x9c) resultado += char(int(c) + 0x20);
        else resultado += c;
}

int main(int argc, char* argv[]){
    string line;
    ifstream myFile;
    string word;//gata, você é um editor de texto? pq vc é meu word 
    //stringstream ss;

    for (int i = 1; i < argc; i++){
        myFile.open(argv[i]);
        if(myFile.is_open()){
            while (getline(myFile,line)){
                  cout << line << endl;

                  //separa a frase em palavras
                  regex delimiters { "(\\,|\\;|\\:|\\.|\\?|\\!|\\s)+" };
                  sregex_token_iterator tokens_begin { line.begin(), line.end(), delimiters, -1 };
                  auto tokens_end = sregex_token_iterator {};
                  for (auto token_it = tokens_begin; token_it != tokens_end; token_it++)
                        cout << "* [" << *token_it << "]\n";
                
            } 
            myFile.close();
        } else {
            cout << "Entrada inválida!";
            return -1;
        } 
    }
}
