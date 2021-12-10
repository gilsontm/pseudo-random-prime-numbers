#include <iostream>
#include <errno.h>
#include "xorshift.cpp"

/*
 * A função main espera dois inteiros:
 *          BITS = número de bits dos números que serão gerados
 *          NUMS = quantidade de números que será gerada
 * Retorna:
 *          0    = sucesso                     => imprime os números no terminal
 *          1    = erro (parâmetros inválidos) => não imprime nada
 */
int main(int argc, char* argv[]) {
    mpz_t res;                                                  // Inicializa variáveis.
    mpz_init(res);                                              //
    xorshift_t gen;                                             //

    if (argc < 3) return 1;                                     // Verifica os argumentos.
    unsigned int BITS = strtol(argv[1], NULL, 10);              //
    if (errno != 0 || strlen(argv[1]) == 0) return 1;           //
    unsigned int NUMS = strtol(argv[2], NULL, 10);              //
    if (errno != 0 || strlen(argv[2]) == 0) return 1;           //

    if (init_xorshift(&gen, (length_t) BITS) != 0) return 1;    // Inicializa gerador.

    for (int i = 0; i < NUMS; i++) {                            // Gera e imprime "NUMS" números.
        next_xorshift(&gen, res);                               //
        std::cout << mpz_get_str(NULL, 10, res) << std::endl;   //
    }                                                           //

    destroy_xorshift(&gen);                                     // Libera variáveis.
    mpz_clear(res);                                             //
    return 0;                                                   //
}
