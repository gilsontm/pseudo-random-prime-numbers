#include <iostream>
#include <gmp.h>
#include "lfsr_params.h"

/*
 * Função que gera o próximo número aleatório.
 * Parâmetros:
 *          n      = número de bits do número
 *          result = número que será gerado
 *          tape   = fita atual
 *          mask   = máscara que depende dos parâmetros iniciais
 */
void generate_next_number(length_t n, mpz_t result, mpz_t tape, mpz_t mask) {
    unsigned int bit;
    mpz_set_ui(result, 0);                      // Atribui zero ao resultado.
    for (int i = 0; i < n; i++) {               // Repete n vezes:
        bit = mpz_tstbit(tape, 0);              //      Atribui ao "bit" o bit menos significativo da fita.
        mpz_mul_2exp(result, result, 1);        //      Faz um shift-left em "result".
        mpz_fdiv_q_2exp(tape, tape, 1);         //      Faz um shift-right na fita.
        if (bit) {                              //      Se "bit" for 1:
            mpz_setbit(result, 0);              //          Atribui "bit" ao bit menos significativo de "result".
            mpz_xor(tape, tape, mask);          //          Faz um XOR entre a fita e os bits da máscara.
        }
    }
}

/*
 *  Função que gera "amount" números aleatórios de "n" bits cada.
 *  Parâmetros:
 *          n      = número de bits dos números
 *          amount = quantidade de números a ser gerada
 */
void galois_lfsr(length_t n, unsigned int amount) {

    mpz_t tape, mask, result;                   // Inicializa variáveis.
    mpz_init(tape);                             //
    mpz_init(mask);                             //
    mpz_init(result);                           //

    mpz_setbit(tape, n-1);                      // Atribui 1 ao bit mais significativo da fita.
    mpz_setbit(tape, 0);                        // Atribui 1 ao bit menos significativo da fita.

    const int * param = get_lfsr_parameters(n); // Atribui 1 aos bits da máscara de acordo com os parâmetros.
    mpz_setbit(mask, param[0]-1);               // Note que os parâmetros dependem do número de bits n.
    mpz_setbit(mask, param[1]-1);               //
    mpz_setbit(mask, param[2]-1);               //
    mpz_setbit(mask, param[3]-1);               //

    while (amount--) {                          // Gera e imprime "amount" números aleatórios.
        generate_next_number(n, result, tape, mask);
        std::cout << mpz_get_str(NULL, 10, result) << std::endl << std::endl;
    }

    mpz_clear(tape);                            // Libera variáveis.
    mpz_clear(mask);                            //
    mpz_clear(result);                          //
}

/*
 * Função main.
 */
int main() {
    galois_lfsr(BITS_4096, 100);
    return 0;
}
