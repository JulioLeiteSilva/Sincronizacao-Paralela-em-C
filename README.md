# Programação Paralela em C

Este repositório contém estudos e implementações de conceitos fundamentais de sincronização e coordenação em programação paralela, utilizando a linguagem C e `pthreads`. Cada conceito possui sua própria pasta com anotações teóricas e exemplos práticos.

## Estrutura

- `readers_writers/` - Conceito de Leitores e Escritores
- `barriers/` - Conceito de Barreiras
- `signals/` - Conceito de Sinais
- `deadlocks/` - Conceito de Deadlocks

Cada pasta contém:
- `notes.md` - Explicações teóricas e referências
- `code/` - Implementação prática em C

---

## Conceitos Abordados

1. **Leitores e Escritores** - Controle de acesso em cenários de leitura/escrita simultânea.
2. **Barreiras** - Sincronização de threads em pontos específicos de execução.
3. **Sinais** - Comunicação entre threads usando sinais.
4. **Deadlocks** - Problemas de bloqueio mútuo e estratégias para evitá-los.

## Como Executar

1. Navegue até a pasta `code` de cada conceito.
2. Compile o código com `gcc -pthread nome_do_arquivo.c -o nome_do_executavel`.
3. Execute o programa com `./nome_do_executavel`.

---

## Referências

- [Documentação pthread](https://man7.org/linux/man-pages/man7/pthreads.7.html)
