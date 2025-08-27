from lista_circular import ListaCircular, Elemento

lista = ListaCircular()

lista.adicionar_item_cabeca(1)
lista.adicionar_item_cabeca(2)
lista.adicionar_item_cabeca(3)
lista.adicionar_item_calda(4)

lista.remover(lista.cabeca)
lista.buscar_e_remover(3)
lista.inserir_item_por_index(5, 4)

print(lista.buscar(5).info)
print(lista.buscar_por_index(4).info)

print(lista)