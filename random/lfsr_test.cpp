#include <iostream>
#include <errno.h>
#include "lfsr.cpp"

/*
 * A função main espera dois inteiros:
 *          BITS  = número de bits dos números que serão gerados
 *          NUMS  = quantidade de números que será gerada
 *          PRINT = imprimir os números gerados? (sim: 1, não: 0)
 * Retorna:
 *          0    = sucesso                     => imprime os números no terminal
 *          1    = erro (parâmetros inválidos) => não imprime nada
 */
int main(int argc, char* argv[]) {
    mpz_t res;                                                      // Inicializa variáveis.
    mpz_init(res);                                                  //
    lfsr_t gen;                                                     //

    if (argc < 3) return 1;                                         // Verifica os argumentos.
    unsigned int BITS = strtol(argv[1], NULL, 10);                  //
    if (errno != 0 || strlen(argv[1]) == 0) return 1;               //
    unsigned int NUMS = strtol(argv[2], NULL, 10);                  //
    if (errno != 0 || strlen(argv[2]) == 0) return 1;               //
    unsigned int PRINT = 1;                                         //
    if (argc >= 4) {                                                //
        PRINT = strtol(argv[3], NULL, 10);                          //
    }                                                               //

    if (init_lfsr(&gen, (length_t) BITS) != 0) return 1;            // Inicializa gerador.

    while (NUMS--) {                                                // Gera e imprime "NUMS" números.
        next_lfsr(&gen, res);                                       //
        if (PRINT != 0)                                             //
            std::cout << mpz_get_str(NULL, 10, res) << std::endl;   //
    }

    destroy_lfsr(&gen);                                             // Libera variáveis.
    mpz_clear(res);                                                 //
    return 0;                                                       //
}
