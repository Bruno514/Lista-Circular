from __future__ import annotations

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
        