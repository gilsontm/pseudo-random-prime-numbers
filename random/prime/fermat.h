#include <gmpxx.h>
#include "random.h"

/*
 * Função que implementa o teste de primalidade de Fermat.
 * Parâmetros:
 *          p = número cuja primalidade será testada
 *          k = grau de confiança (número de vezes que o teste é repetido)
 * Retorna:
 *          true  = "p" é provavelmente primo
 *          false = "p" é definitivamente composto
 */
bool is_prime_fermat(mpz_t p, int k) {
    if (mpz_even_p(p) != 0)                                        // Se p é par:
        return false;                                              //     Retorna "é composto".

    gmp_randstate_t state;                                         // ATENÇÃO: Inicializa estado do gerador de números aleatórios da biblioteca.
    gmp_randinit_mt(state);                                        // ATENÇÃO: Isto só é usado para obter um parâmetro do método de Fermat.

    mpz_t a, p_minus_one;                                          // Inicializa variáveis
    mpz_inits(a, p_minus_one, NULL);                               //
    mpz_sub_ui(p_minus_one, p, 1);                                 // p_minus_one = p-1

    while (k--) {
        choose_random_number(p, state, a);                         // Escolhe "a" aleatório no intervalo [2, p-2]
        mpz_powm(a, a, p_minus_one, p);                            // a = a^(p-1) mod p
        if (mpz_cmp_ui(a, 1) != 0)                                 // Se a != 1:
            return false;                                          //      Retorna "é composto"
    }
    return true;                                                   // Retorna "é provavelmente primo"
}
