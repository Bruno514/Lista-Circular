from lista_circular import ListaCircular, Elemento

lista = ListaCircular()

print("Adicionar itens de 1 a 5 à calda da lista: ");
for i in range(1, 6):
    lista.adicionar_item_calda(i)
print(lista)

print("\nAdicionar itens de 1 a 5 à cabeça da lista: ");
for i in range(1, 6):
    lista.adicionar_item_cabeca(i)
print(lista)

print("\nInserir o valor 0 depois do index 4 da lista: ");
lista.inserir_item_por_index(0, 4)
print(lista)

print("\nRemover elemento que procede a cabeça: ");
lista.remover(lista.cabeca)
print(lista)

print("\nBuscar e remover o elemento de valor 4: ");
lista.buscar_e_remover(4)
print(lista)

print("\nBuscar o elemento no index 4: ");
elemento = lista.buscar_por_index(4)
print(f"Valor: {elemento.info}")