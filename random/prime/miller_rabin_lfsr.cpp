#include <iostream>
#include "miller_rabin.h"
#include "../lfsr.cpp"

/*
 * Gera números aleatórios usando LFSR, e testa-os usando Miller-Rabin, até que um deles seja primo.
 * Então, escreve o número primo no argumento "res" e retorna.
 * A probabilidade de retornar um número não-primo é de 1/(4^k), e escolheu-se k = 40.
 * Parâmetros:
 *          gen = gerador LFSR já inicializado
 *          res = variável onde será escrito o número primo gerado
 */
void next_prime_lfsr(lfsr_t* gen, mpz_t res) {
    do {                                                        // Gera números aleatórios até que um deles seja primo.
        next_lfsr(gen, res);                                    // Termina quando gerar um número primo.
    } while (!is_prime_miller_rabin(res, 40));                  // O resultado é colocado na variável "res".
}

/*
 * A função main espera dois inteiros:
 *          BITS = número de bits dos números primos que serão gerados
 *          NUMS = quantidade de números primos que será gerada
 * Retorna:
 *          0    = sucesso                     => imprime os números no terminal
 *          1    = erro (parâmetros inválidos) => não imprime nada
 */
int main(int argc, char* argv[]) {
    mpz_t res;                                                  // Inicializa variáveis.
    mpz_init(res);                                              //
    lfsr_t gen;                                                 //

    if (argc < 3) return 1;                                     // Verifica os argumentos.
    unsigned int BITS = strtol(argv[1], NULL, 10);              //
    if (errno != 0 || strlen(argv[1]) == 0) return 1;           //
    unsigned int NUMS = strtol(argv[2], NULL, 10);              //
    if (errno != 0 || strlen(argv[2]) == 0) return 1;           //

    if (init_lfsr(&gen, (length_t) BITS) != 0) return 1;        // Inicializa gerador.

    while (NUMS--) {                                            // Gera e imprime "NUMS" números primos.
        next_prime_lfsr(&gen, res);                             //
        std::cout << mpz_get_str(NULL, 10, res) << std::endl;   //
    }                                                           //

    destroy_lfsr(&gen);                                         // Libera variáveis.
    mpz_clear(res);                                             //
    return 0;                                                   //
}
