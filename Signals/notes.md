# Sinais (Signals)

## Definição

Sinais são mecanismos de comunicação entre threads, usados para interromper ou notificar uma thread sobre eventos importantes. No contexto de `pthread`, sinais permitem que uma thread envie uma notificação para outra, desencadeando uma ação específica.

## Aplicação Prática

Sinais são amplamente utilizados para comunicação entre threads, especialmente em situações onde uma thread precisa notificar outra de que um recurso está disponível ou que uma tarefa foi concluída.

## Implementação

A implementação em C utiliza a função `pthread_kill` para enviar sinais entre threads, e a função `signal()` para definir o comportamento ao receber o sinal.

## Referências

- [Signal (IPC)](https://en.wikipedia.org/wiki/Signal_(IPC))
