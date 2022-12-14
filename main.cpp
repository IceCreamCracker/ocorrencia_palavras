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
};

struct List {
    Node* first;
};

    // Funções

List* createList() {
    List* newList = new List;

    newList->first = nullptr;

    return newList;
}

/*
Adição ordenada de elemento
Complexidade: O(n), onde n é o tamanho da lista
Uso
Parâmetros: Lista (ponteiro) e palavra
Retorno: vazio
*/
void addElement(List* list, string word, int numberText, int qtdTexts) {
    Node* newElement = new Node;
    
    newElement->next = newElement->previous = nullptr;
    newElement->word = word;
    newElement->frequencies = new int[qtdTexts];
      
    for (int i = 0; i < qtdTexts; i++) {
        newElement->frequencies[i] = 0;
    }

    newElement->frequencies[numberText] = 1;

    Node* prev = nullptr;
    Node* current;
    
    for (
      current = list->first; 
      current != nullptr && current->word.compare(word) < 0; 
      current = current->next
      ) {
      prev = current;
    }
    
    newElement->previous = prev;
    newElement->next = current;
    
    if (current != nullptr) {
      current->previous = newElement;
    }
    
    if (prev != nullptr) {
      prev->next = newElement;
    } else {
      list->first = newElement;
    }
}

/* 
Busca sequencial
Complexidade: O(n)
Uso
Parâmetros: Lista (ponteiro) e palavra
Retorno: Nó onde a palavra desejada foi localizada ou nullptr, caso não
tenha sido encontrada
*/
Node* searchElement(List* list, string word) {
  Node* current;
  current = list->first;

  while(current != nullptr && current->word != word) {
    current = current->next;
  }

  return current;
}

/*
Imprimir lista
Complexidade: O(n)
Uso
Parâmetros: lista (ponteiro)
Retorno: vazio
*/
void printList(List* list, int qtdTexts) {
  for (Node* p = list->first; p != nullptr; p = p->next) {
    cout << p->word << " ";
    for (int i = 0; i < qtdTexts; i++) {
      cout << p->frequencies[i];
      if(i != qtdTexts - 1) cout << " ";
    }
    cout << endl;
  }
}
// Fim da implementação da estrutura de dados

string toLowerCase (string str){ // to lower case
    unsigned int f;
    string resultado = "";

    for (char c : str){
        f = int(c);
        if (f > 0xff) f = int(c) - 0xffffff00; //UTF-8 em CHAR adiciona muitos bytes
        if(f >= 0x41 && f <= 0x5a || f >= 0x80 && f <= 0x9c) resultado += char(int(c) + 0x20);
        else resultado += c;
    }

    return resultado;
}

int main(int argc, char* argv[]){
    string line;
    ifstream myFile;
    string word;//gata, você é um editor de texto? pq vc é meu word
    List* list = createList();

    for (int i = 1; i < argc; i++){
        int numberText = i - 1;
        myFile.open(argv[i]);
        if(myFile.is_open()){
            while (getline(myFile,line)){
                  //cout << line << endl;
                  //separa a frase em palavras
                  regex delimiters {"[\\,\\;\\:\\.\\?\\!\\s]+"};
                  sregex_token_iterator tokens_begin { line.begin(), line.end(), delimiters, -1 };
                  auto tokens_end = sregex_token_iterator {};
                  for (auto token_it = tokens_begin; token_it != tokens_end; token_it++) {
                      //cout << toLowerCase(*token_it) << endl; // funcionando até aqui
                      Node* element = searchElement(list, toLowerCase(*token_it));

                      if (element) {
                          element->frequencies[numberText]++;
                      } else {
                          addElement(list, toLowerCase(*token_it), numberText, argc - 1);
                      }
                  }    
            } 
            myFile.close();
        } else {
            cout << "Entrada inválida!" << endl;
            return -1;
        }
    }

    printList(list, argc - 1);


    return 0;
}
