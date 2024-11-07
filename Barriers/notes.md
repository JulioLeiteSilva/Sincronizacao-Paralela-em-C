# Barreiras (Barriers)

## Definição

Uma barreira é um ponto de sincronização onde várias threads devem aguardar até que todas tenham alcançado este ponto antes de prosseguir. Esse mecanismo é útil para dividir o trabalho em fases, garantindo que todas as threads tenham concluído uma fase antes de iniciar outra.

## Aplicação Prática

Utilizado em algoritmos paralelos, onde múltiplas threads realizam operações que dependem do estado das outras threads em certos pontos.

## Implementação

A implementação em C usa variáveis de condição e mutexes para garantir que todas as threads atinjam a barreira antes de prosseguir.

## Referências

- [Barrier Synchronization](https://en.wikipedia.org/wiki/Barrier_(computer_science))
