# Trabalho de Segurança de Computação (INE5429).

## Dependências

- Biblioteca GMP (C++).

## Como executar?

O Makefile compila os executáveis nas pastas `random` e `random/prime`.
Todos os executáveis esperam os argumentos `BITS`, `NUMS` e `PRINT`:

- `BITS`: tamanho em bits do número a ser gerado (40, 56, 80, 128, 168, 224, 256, 512, 1024, 2048, 4096).
- `NUMS`: quantidade de números a ser gerada (um inteiro)
- `PRINT`: imprimir os números na tela? (1: sim, 0: não)

## Exemplo

```
> cd random
> make
> ./lfsr.out 128 10 1
92725635635256318625995123797401701885
74979657789669104860346077061741240175
209171274310457512270718829203615329216
165989988208625061130399727533204190079
9152335984804104330798569194664044542
130242345132492636869945092475525793995
287128702396870408445199634584753692575
12554460850798795011310462136003744089
178983254875910157484262513793233787471
257898484193696834603296704802988777486
```

## Script test.sh

Arquivo bash usado para gerar relatórios dos tempos de execução de cada algoritmo.

