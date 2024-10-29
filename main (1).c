#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
int main() {
Lista* z;
Lista* y;
Lista* l = criarLista();
l = inserirOrdem(l,19);
l = inserirOrdem(l,50);
l = inserirOrdem(l,37);
l = inserirOrdem(l,5);
l = inserirOrdem(l,7);
l = inserirOrdem(l,12);
printf("elementos da lista:\n");
exibirLista(l);


l = excluirLista(l,12);

printf("lista após excluir o elemento 12 da lista:\n");
exibirLista(l);

z = buscarLista(l,37);
if(z != NULL){
    printf("elemento encontrado:\n%d",z-> info);
}else{
    printf("o elemento não foi encontrado\n");
}
liberarLista(&l);

exibirLista(l);
return 0;
}
