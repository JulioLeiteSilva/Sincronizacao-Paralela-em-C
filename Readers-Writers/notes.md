# Leitores e Escritores (Readers-Writers)

## Definição

O problema dos Leitores e Escritores trata de gerenciar o acesso simultâneo de threads a um recurso compartilhado, permitindo que múltiplos leitores acessem o recurso ao mesmo tempo, mas apenas um escritor por vez. Esse conceito é essencial em sistemas onde a leitura é frequente e a escrita é menos comum.

## Aplicação Prática

Esse conceito é comumente aplicado em sistemas de banco de dados, onde vários usuários podem ler dados simultaneamente, mas a escrita deve ser controlada para garantir consistência.

## Implementação

A implementação utiliza mutexes e variáveis de condição para gerenciar o acesso. Um contador de leitores ativos é usado para controlar a entrada de leitores, enquanto um mutex é usado para proteger o recurso durante a escrita.

## Referências

- [Problema dos Escritores e Leitores em C | Threads e Semáforos | - Sistemas Operacionais - UFC](https://www.youtube.com/watch?v=lznnby8uv_M&ab_channel=MateusAndrade)
