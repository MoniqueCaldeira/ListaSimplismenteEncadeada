#include <iostream>
#include <stdlib.h>

using namespace std;
//define um novo tipo de dado (struct Tlista)

typedef struct lista Tlista;
//registro contendo um dado e um ponteito prox que aponta para o proximo elemento do registro Tlista
struct lista{
    int dado;
    Tlista *prox;
};
//define uma lista apontando para NULL (nada, vazio)
Tlista *lista = NULL;

//fun��o para inserir elementos da lista, passando o come�o da lista e o dado
void insere(Tlista *&l, int d){
    //cria um ponteiro auxiliar para percorrer a lista
    Tlista *aux;

    //insere um elemento quando a lista est� vazia
    if(l == NULL){
        //aloca um espa�o de memoria para inserir o valor d
        l = new(Tlista);
        l->dado = d;
        l->prox = NULL;
    }

    //caso j� tenha algum elemento na lista
    else{
        //aloca um espa�o de memoria para inserir o valor d
        aux = new(Tlista);
        aux->dado = d;
        aux->prox = l;
        //faz o ponteiro l receber o come�o da lista
        l = aux;
    }
}

//exibe todos os elementos da lista
void exibe(Tlista *l){
    //cria um auxiliar e faz ele receber o come�o da lista
    Tlista *aux = l;

    //se/enquanto o auxilia for diferente de NULL
    if(aux != NULL){
        //exibe o dado do ponteiro auxiliar
        cout << "Dado da lista: " << aux->dado << endl;
        //faz uma chamada recursiva passando o proximo elemento do ponteiro auxiliar
        exibe(aux->prox);
    }
}


int main(){

    //chama a fun��o insere, passando o ponteiro lista e o dado
    insere(lista, 10);
    insere(lista, 20);
    insere(lista, 30);
    insere(lista, 40);

    //chama a fun��o exibe passando o ponteiro lista
    exibe(lista);

    return 0;
}
