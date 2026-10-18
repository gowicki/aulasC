# LeetCode 2 - Add Two Numbers

Autor: Gustavo Lacerda Owicki - M1

## Problema

Somar dois numeros dados como listas ligadas, um digito por no, em
ordem invertida (a unidade vem primeiro). A resposta tambem e uma
lista ligada invertida.

Exemplo: l1 = [2,4,3] (342), l2 = [5,6,4] (465) -> [7,0,8] (807).

Link: https://leetcode.com/problems/add-two-numbers/

## Arquivos

- `leetcode2.c` - solucao + testes
- `README.md`

Este trabalho foi feito todo em aula.

Observacao: o codigo esta no estilo Doom 3 (espaco dentro dos
parenteses, etc). Me confundi e achei que o estilo Doom 3 tinha que ser
usado tambem no codigo feito em aula, por isso entreguei assim.

## Casos que testei com sucesso

- [2,4,3] + [5,6,4] = [7,0,8]  (342 + 465 = 807)
- [9,9,9,9,9,9,9] + [9,9,9,9] = [8,9,9,9,0,0,0,1]  (tamanhos diferentes, carry ate o fim)
- [9,9] + [1] = [0,0,1]  (carry criando um no novo: 99 + 1 = 100)

Rodando o arquivo, passam os 10 testes.

## O que funciona e o que nao funciona

Funciona: passa nos 10 testes do arquivo e no Submit do LeetCode,
funciona com listas de tamanhos diferentes, cria o no extra quando
sobra carry no fim, e nao vaza memoria (Valgrind limpo).

Nao funciona: nao encontrei nenhum caso que falhe.

## A ideia

Ando nas duas listas ao mesmo tempo. Em cada passo:
soma = digito1 + digito2 + carry. O que fica e soma % 10, o que sobe
e soma / 10. Se uma lista acaba antes, o digito dela vira 0. Continuo
enquanto sobrar no em qualquer lista OU ainda tiver carry.

Pra montar a resposta uso um no "dummy" (de mentira) so pra ter onde
encostar o primeiro no. A resposta e o que vem depois dele.

## Complexidade

Tempo O(max(m, n)) e espaco O(max(m, n)), onde m e n sao os tamanhos
das listas. Passo uma vez por cada no, e a resposta tem no maximo
max(m, n) + 1 nos.

## Memoria

O codigo usa malloc para cada no da resposta. O Dr. Memory nao abriu no
meu Windows por um bug conhecido (dbghelp.dll), entao usei o Valgrind
pelo WSL:

    gcc -g leetcode2.c -o leetcode2_linux
    valgrind --leak-check=full ./leetcode2_linux


## Uso de IA e dificuldades

Usei a IA para roteiro do video, ajuda para explicar o codigo, fazer o readme e ajuda com o Valgrind.
