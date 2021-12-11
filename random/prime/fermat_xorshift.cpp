#include <iostream>
#include "fermat.h"
#include "../xorshift.cpp"

/*
 * Gera números aleatórios usando Xorshift, e testa-os usando Fermat, até que um deles seja primo.
 * Então, escreve o número primo no argumento "res" e retorna.
 * O teste de Fermat é executado k vezes, onde escolheu-se k = 40.
 * Parâmetros:
 *          gen = gerador xorshift já inicializado
 *          res = variável onde será escrito o número primo gerado
 */
void next_prime_xorshift(xorshift_t* gen, mpz_t res) {
    do {                                                        // Gera números aleatórios até que um deles seja primo.
        next_xorshift(gen, res);                                // Termina quando gerar um número primo.
    } while (!is_prime_fermat(res, 40));                        // O resultado é colocado na variável "res".
}

/*
 * A função main espera dois inteiros:
 *          BITS  = número de bits dos números primos que serão gerados
 *          NUMS  = quantidade de números primos que será gerada
 *          PRINT = imprimir os números gerados? (sim: 1, não: 0)
 * Retorna:
 *          0    = sucesso                     => imprime os números no terminal
 *          1    = erro (parâmetros inválidos) => não imprime nada
 */
int main(int argc, char* argv[]) {
    mpz_t res;                                                      // Inicializa variáveis.
    mpz_init(res);                                                  //
    xorshift_t gen;                                                 //

    if (argc < 3) return 1;                                         // Verifica os argumentos.
    unsigned int BITS = strtol(argv[1], NULL, 10);                  //
    if (errno != 0 || strlen(argv[1]) == 0) return 1;               //
    unsigned int NUMS = strtol(argv[2], NULL, 10);                  //
    if (errno != 0 || strlen(argv[2]) == 0) return 1;               //
    unsigned int PRINT = 1;                                         //
    if (argc >= 4) {                                                //
        PRINT = strtol(argv[3], NULL, 10);                          //
    }                                                               //

    if (init_xorshift(&gen, (length_t) BITS) != 0) return 1;        // Inicializa gerador.

    while (NUMS--) {                                                // Gera e imprime "NUMS" números primos.
        next_prime_xorshift(&gen, res);                             //
        std::cout << mpz_get_str(NULL, 10, res) << std::endl;       //
    }                                                               //

    destroy_xorshift(&gen);                                         // Libera variáveis.
    mpz_clear(res);                                                 //
    return 0;                                                       //
}
