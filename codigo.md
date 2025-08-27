# Lista Encadeda

## Codigo em c

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "lista_circular.h"

typedef struct elemento
{
  int info;
  struct elemento *proximo;
} Elemento;

typedef struct lista_circular
{
  Elemento *cabeca;
} ListaCircular;

ListaCircular *criar_lista()
{
  ListaCircular *lista;
  lista = malloc(sizeof(ListaCircular));
  lista->cabeca = NULL;

  return lista;
}

void imprimir_lista(ListaCircular *lista)
{
  if (lista->cabeca == NULL)
  {
    return;
  }

  Elemento *atual;
  atual = lista->cabeca;

  while (atual->proximo != lista->cabeca)
  {
    printf("%d -> ", atual->info);
    atual = atual->proximo;
  }

  printf("%d\n", atual->info);
}

void adicionar_item_cabeca(int x, ListaCircular *lista){
  Elemento *novo;
  novo = malloc(sizeof(Elemento));

  novo->info = x;

  if (lista->cabeca == NULL)
  {
    lista->cabeca = novo;
    novo->proximo = lista->cabeca;

    return;
  }

  Elemento *atual;
  atual = lista->cabeca;

  while (atual->proximo != lista->cabeca)
  {
    atual = atual->proximo;
  }

  novo->proximo = lista->cabeca;
  atual->proximo = novo;

  lista->cabeca = novo;
}

void adicionar_item_calda(int x, ListaCircular *lista)
{
  Elemento *novo;
  novo = malloc(sizeof(Elemento));

  novo->info = x;

  if (lista->cabeca == NULL)
  {
    lista->cabeca = novo;
    novo->proximo = lista->cabeca;

    return;
  }

  Elemento *atual;
  atual = lista->cabeca;

  while (atual->proximo != lista->cabeca)
  {
    atual = atual->proximo;
  }

  novo->proximo = lista->cabeca;
  atual->proximo = novo;
}

// Insere um elemento com o valor especificado após o index
void inserir_item_por_index(int x, int index, ListaCircular *lista)
{
  if (index < 0)
  {
    return;
  }

  int contador = 0;
  Elemento *novo, *atual;

  atual = lista->cabeca;

  novo = malloc(sizeof(Elemento));
  novo->info = x;

  if (lista->cabeca == NULL)
  {
    lista->cabeca = novo;
    novo->proximo = lista->cabeca;

    return;
  }

  while (1)
  {
    if (contador++ == index)
    {
      novo->proximo = atual->proximo;

      atual->proximo = novo;

      return;
    }

    atual = atual->proximo;
  } 
}

// Remove elemento que procede ao parâmetro
void remover(ListaCircular *lista, Elemento *elemento)
{
  Elemento *lixo;

  if (elemento == NULL)
    return;

  if (elemento->proximo == NULL)
    return;

  lixo = elemento->proximo;

  // Caso o elemento a ser deletado seja o mesmo que a cabeça da lista 
  if (elemento == lixo)
  {
    lista->cabeca = NULL;
    free(lixo);

    return;
  }

  // Caso o elemento a ser removido se referir à cabeça da lista, apontar para o proximo
  if (lixo == lista->cabeca)
  {
    lista->cabeca = lixo->proximo;
    elemento->proximo = lista->cabeca;
    free(lixo);

    return;
  }

  elemento->proximo = lixo->proximo;
  free(lixo);

  return;
}

bool buscar_e_remover(int x, ListaCircular *lista)
{
  if (lista->cabeca == NULL)
  {
    return false;
  }

  Elemento *atual, *proximo;

  atual = lista->cabeca;
  proximo = atual->proximo;
  while (1)
  {
    if (proximo->info == x)
    {
      remover(lista, atual);

      return true;
    }

    if (proximo == lista->cabeca)
    {
      return false;
    }

    atual = proximo;
    proximo = proximo->proximo;
  };

  return false;
}

Elemento *buscar(int x, ListaCircular *lista)
{
  if (lista->cabeca == NULL)
  {
    return NULL;
  }

  Elemento *atual;

  atual = lista->cabeca;

  do
  {
    if (atual->info == x)
    {
      return atual;
    }

    atual = atual->proximo;
  } while (atual != lista->cabeca);

  return NULL;
}

Elemento *buscar_por_index(int index, ListaCircular *lista)
{
  if (index < 0)
  {
    return NULL;
  }

  if (lista->cabeca == NULL)
  {
    return NULL;
  }

  int contador = 0;
  Elemento *atual;

  atual = lista->cabeca;

  while (1)
  {
    if (contador++ == index)
    {
      return atual;
    }

    atual = atual->proximo;
  } 
}
```

## Codigo em python

```python
class Elemento:
    def __init__(self, info : int = None, proximo : Elemento = None):
        self.info = info
        self.proximo = proximo
    

class ListaCircular:
    def __init__(self, cabeca : Elemento = None):
        self.cabeca : Elemento = cabeca

        if self.cabeca != None:
            self.cabeca.proximo = self.cabeca

    def __str__(self):
        representacao = ""

        if self.cabeca == None:
            return "Vazia" 
            
        atual = self.cabeca
        
        while atual.proximo != self.cabeca:
            representacao += f"{atual.info}->"

            atual = atual.proximo

        representacao += str(atual.info)

        return representacao

    def adicionar_item_cabeca(self, x : int):
        novo = Elemento(x)

        if self.cabeca == None:
            self.cabeca = novo
            novo.proximo = self.cabeca

            return

        atual = self.cabeca

        while atual.proximo != self.cabeca:
            atual = atual.proximo

        novo.proximo = self.cabeca
        atual.proximo = novo

        self.cabeca = novo

    def adicionar_item_calda(self, x : int):
        novo = Elemento(x)

        if self.cabeca == None:
            self.cabeca = novo
            novo.proximo = self.cabeca

            return

        atual = self.cabeca

        while atual.proximo != self.cabeca:
            atual = atual.proximo

        novo.proximo = self.cabeca
        atual.proximo = novo

    def inserir_item_por_index(self, x : int, index : int):
        if index < 0:
            return

        contador = 0
        novo = Elemento(x)

        atual = self.cabeca

        if self.cabeca == None:
            self.cabeca = novo
            novo.proximo = self.cabeca

            return

        while True:
            if contador == index:
                novo.proximo = atual.proximo

                atual.proximo = novo

                return
            
            contador += 1
            atual = atual.proximo
        
    def remover(self, elemento : Elemento):
        if elemento == None:
            return

        if elemento.proximo == None:
            return

        lixo = elemento.proximo

        # Caso o elemento a ser deletado seja a cabeça e o único elemento da lista
        if elemento == lixo:
            self.cabeca = None

            return

        # Caso o elemento a ser deletado seja a cabeça da lista 
        if lixo == self.cabeca:
            self.cabeca = lixo.proximo
            elemento.proximo = self.cabeca

            return
            
        elemento.proximo = lixo.proximo
        
        return

    def buscar_e_remover(self, x : int) -> bool:
        if self.cabeca == None:
            return False

        atual = self.cabeca
        proximo = atual.proximo

        while True:
            if proximo.info == x:
                self.remover(atual)

                return True

            if proximo == self.cabeca:
                return False

            atual = proximo
            proximo = proximo.proximo

        return False

    def buscar(self, x : int) -> Elemento:
        if self.cabeca == None:
            return None;

        atual = self.cabeca

        while True:
            if atual.info == x:
                return atual

            atual = atual.proximo

            if atual == self.cabeca:
                break
        
        return None
    
    def buscar_por_index(self, index : int) -> Elemento:
        if index < 0:
            return None
        
        if self.cabeca == None:
            return None

        contador = 0
        atual = self.cabeca

        while True:
            if contador == index:
                return atual

            contador += 1
            atual = atual.proximo
        
```
