import time
from lista_circular import ListaCircular, Elemento

tempo_comeco = time.perf_counter()

lista = ListaCircular()

for i in range(10000):
    lista.adicionar_item_calda(i)

print(lista)

tempo_final = time.perf_counter()
tempo_corrido= tempo_final - tempo_comeco 

print(f"Tempo corrido: {tempo_corrido:.6f} segundos")