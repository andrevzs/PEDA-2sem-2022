""" Andre Schmidt - Atividade 02 - Pilhas =========
Tarefa: construir um codigo capaz de somar, item a
item, todos os inteiros entre 1 e 1.000.000. Isso 
deve ser executado atraves da criacao de uma pilha.
Os inteiros devem ser armazenados na pilha, entao
ela deve ser percorrida enquanto seus valores sao
somados. Nao se deve utilizar formulas matematicas
para realizar a soma.

Deve ser medido o tempo necessario para:
- inserir 1 milhao de inteiros na pilha;
- percorrer e somar 1 milhao de inteiros na pilha;
- garantir que determinado inteiro ja esta na pilha;

Estes tempos devem ser medidos percorrendo a pilha
em dois sentidos. De cima para baixo e de baixo para
cima. O resultado sera a media dos tempos gastos
para as operacoes citadas acima em, no minimo, 50 
operacoes de cada tipo.
============================================= """
import time

inicio_programa = time.time()
print('========= Andre Schmidt - PEDA Atividade 02 - Pilhas =========\n')

pilha = []
tamanho = int(input('Digite o tamanho da pilha: '))
inicio = time.time()
for i in range(0, tamanho):
    # A funcao append apresenta a mesma funcionalidade do push tradicional de listas
    pilha.append(i+1)
final = time.time()
tempo_preenchimento = final - inicio
print(f'\nTempo de preenchimento: {tempo_preenchimento*1000} ms')

print('\n--- SENTIDO CRESCENTE ---')
inicio = time.time()
soma = 0
for j in range(0, len(pilha)):
    soma += pilha[j]
final = time.time()

print('Soma:', soma)
tempo_soma = final - inicio
print(f'Tempo de percorrer e somar: {tempo_soma*1000} ms')

numero = int(input('\nDigite um inteiro para checar se esta na pilha: '))
numero_na_pilha = False
inicio = time.time()
for k in range(0, len(pilha)):
    if pilha[k] == numero:
        numero_na_pilha = True
        break
final = time.time()
tempo_checagem = final - inicio
if numero_na_pilha == True:
    print('O numero esta na pilha!')
    print(f'Tempo levado para checar: {tempo_checagem*1000} ms')
else:
    print('O numero nao esta na pilha!')
    print(f'Tempo levado para checar: {tempo_checagem*1000} ms')

print('\n--- SENTIDO DECRESCENTE ---')
soma = 0
for l in pilha[::-1]:
    soma += l
print('Soma:', soma)

numero = int(input('\nDigite um inteiro para checar se esta na pilha: '))
numero_na_pilha = False
inicio = time.time()
for m in pilha[::-1]:
    if pilha[m-1] == numero:
        numero_na_pilha = True
        break
final = time.time()
tempo_checagem = final - inicio
if numero_na_pilha == True:
    print('O numero esta na pilha!')
    print(f'Tempo levado para checar: {tempo_checagem*1000} ms')
else:
    print('O numero nao esta na pilha!')
    print(f'Tempo levado para checar: {tempo_checagem*1000} ms')

fim_programa = time.time()
tempo_programa = fim_programa - inicio_programa
print(f'Tempo de execucao do programa: {tempo_programa} s')
print('\n====================== FIM DO PROGRAMA ====================== ')
