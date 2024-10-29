#include <stdlib.h>
struct lista {
	int info;
	struct lista *prox;
};
typedef struct lista Lista;

Lista* criarLista() {
	return NULL;
}

Lista* inserirOrdem(Lista* l, int i){
    Lista* novo = (Lista*) malloc(sizeof(l));
    novo -> info = i;
    if(l == NULL || l -> info >= i){
        novo->prox = l;
        return novo;
    }
    
    Lista* atual = l;
    while (atual -> prox != NULL && atual->prox->info < i){
        atual = atual->prox;
    }
    
    novo->prox = atual->prox;
    atual->prox = novo;
    return l;
}

Lista* inserirLista(Lista *lista, int i) {
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo -> info = i;
	novo -> prox = lista;
	return novo;
};
Lista *exibirLista(Lista *l) {
	Lista *p;
	for (p = l; p != NULL; p = p->prox) {
		printf("%d\n", p->info);
	}
}
int verificarVazia(Lista *l) {
	if(l == NULL) {
		return 1;
	} else {
		return 0;
	}
}
Lista *buscarLista(Lista *l, int v) {
	Lista *p;
	for(p = l; p != NULL; p = p->prox) {
		if(p->info == v) {
			return p;
		}
	}
	return NULL;
}
Lista *excluirLista(Lista *l, int v) {
	Lista *ant = NULL;
	Lista *p = l;
	while(p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
	}
	if(p == NULL) {
		return l;
	}
	if(ant == NULL) {
		l = p->prox;
	} else {
		ant->prox = p->prox;
	}
	free(p);
	return l;
}
void liberarLista(Lista **l) {
	Lista *p = *l;
	while(p != NULL) {
		Lista *t = p->prox;
		free(p);
		p = t;
	}
	*l = NULL;
}
