# André Vinícius Zicka Schmidt - Calculadora RPN
"""
Você deverá desenvolver um programa, na sua linguagem de programação favorita, que leia 
uma string de entrada e execute a operação matemática contida nesta string. Esta string irá 
representar operações matemáticas segundo uma variação da RPN, que inclui obrigatoriamente 
parênteses para limitar as operações, conforme exemplos a seguir:
a) (2 3 +) = 5
b) (3 4 *) = 12
c) (4 2 2 /) = 1
d) ((4 2 +) 3 *) = 18

O seu programa deverá ser capaz de realizar as seguintes operações: 
• Adição representada por +;
• Subtração representada por -;
• Multiplicação representada por *;
• Divisão representada por /;
"""

pilha = []

conta = input('Digite uma conta em RPN: ')

for i in range(len(conta)):        
    if conta[i] == ' ':
        # ignorar espaços
        pass
        
    elif conta[i].isdigit():
        # push dos numeros na pilha
        pilha.append(conta[i])
        
    elif conta[i] == '+':
        # soma dos dois ultimos elementos da pilha
        resultado = int(pilha.pop()) + int(pilha.pop())
        pilha.append(resultado)
        
    elif conta[i] == '-':
        # subtração dos dois ultimos elementos da pilha
        resultado = abs(int(pilha.pop()) - int(pilha.pop()))
        pilha.append(resultado)
        
    elif conta[i] == '*':
        # multiplicação dos dois ultimos elementos da pilha
        resultado = int(pilha.pop()) * int(pilha.pop())
        pilha.append(resultado)
        
    elif conta[i] == '/':
        # divisão dos dois ultimos elementos da pilha
        resultado = int(pilha.pop()) / int(pilha.pop())
        pilha.append(resultado)

print('Resultado:', pilha[0])
