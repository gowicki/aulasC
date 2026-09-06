# LeetCode 43 - Multiply Strings

Autor: Gustavo Lacerda Owicki - M1

## Problema

Multiplicar dois numeros que vem como string e devolver o resultado tambem
como string, sem usar BigInteger e sem converter a entrada para um tipo
nativo. Como os numeros podem ter ate 200 digitos, eles nao cabem em long
long, entao a conta e feita digito por digito, como no papel.

Link: https://leetcode.com/problems/multiply-strings/

## Arquivos

- `leetcode43` - versao feita em aula
- `casa.c` - versao feita em casa (estilo Doom 3)
- `README.md`

## Resultado no LeetCode
https://leetcode.com/problems/multiply-strings/submissions/2132230179

## Como rodar

    gcc -g casa.c -o casa
    ./casa

## Casos que testei

- "2" * "3" = "6"
- "123" * "456" = "56088"
- "98765432109876543210" * "12345678901234567890" = "1219326311370217952237463801111263526900"

O ultimo caso ja estoura o long long nas entradas, entao mostra que nao tem
atalho de converter para tipo nativo.

## Memoria

O codigo usa malloc/calloc/free. Tentei o Dr. Memory mas ele nao abriu no meu
Windows por um bug conhecido (dbghelp.dll). Usei o Valgrind pelo WSL:

    gcc -g casa.c -o casa_linux
    valgrind --leak-check=full ./casa_linux

==2094==
==2094== HEAP SUMMARY:
==2094==     in use at exit: 0 bytes in 0 blocks
==2094==   total heap usage: 39 allocs, 39 frees, 1,603 bytes allocated
==2094==
==2094== All heap blocks were freed -- no leaks are possible
==2094==
==2094== For lists of detected and suppressed errors, rerun with: -s

## O que funciona

Passa nos 10 testes do arquivo, trata o caso de fator zero e os zeros a
esquerda, e nao vaza memoria.


## Uso de IA

Precisei de bastante ajuda de IA. Travei principalmente no começo, onde eu nao sabia
onde começar. Usei a IA para entender a ideia e depois estudei o codigo para tentar explicar.
Tambem usei IA para tentar arrumar o Dr Memory, mas ja é um bug conhecido deles, sem solução ainda.