#include <gmpxx.h>

/*
 * Função que gera um número aleatório no intervalo [2,p-2].
 * Esta função utiliza um gerador de números aleatórios da biblioteca GMP.
 * ATENÇÃO: É usada apenas para gerar um parâmetro no teste de Miller-Rabin.
 * Parâmetros:
 *          p     = número cuja primalidade está sendo testada
 *          state = estado do gerador interno da biblioteca GMP
 *          res   = variável onde o número aleatório será colocado
 */
void choose_random_number(mpz_t p, gmp_randstate_t state, mpz_t res) {
                                                                   // Gerar número aleatório no intervalo [2, p-2]:
    mpz_sub_ui(res, p, 4);                                         //     res = p - 4
    mpz_urandomm(res, state, res);                                 //     res = número aleatório no intervalo [0, p-4]
    mpz_add_ui(res, res, 2);                                       //     res = res + 2
}

/*
 * Função que implementa o teste de primalidade Miller-Rabin.
 * Parâmetros:
 *          p = número cuja primalidade será testada
 *          k = grau de confiança (número de vezes que o teste é repetido)
 * Retorna:
 *          true  = "p" é provavelmente primo
 *          false = "p" é definitivamente composto
 */
bool is_prime_miller_rabin(mpz_t p, int k) {
    if (mpz_even_p(p) != 0)                                        // Se p é par:
        return false;                                              //     Retorna "é composto".

    gmp_randstate_t state;                                         // ATENÇÃO: Inicializa estado do gerador de números aleatórios da biblioteca.
    gmp_randinit_mt(state);                                        // ATENÇÃO: Isto só é usado para obter um parâmetro do método Miller-Rabin.

    mpz_t d, a, x, p_minus_one;                                    // Inicializa variáveis
    mpz_inits(d, a, x, p_minus_one, NULL);                         //
    mpz_sub_ui(p_minus_one, p, 1);                                 // p_minus_one = p-1

    unsigned int r = 0;                                            // Escreve p = 2^r * d + 1
    mpz_set(d, p_minus_one);                                       //
    while (mpz_even_p(d)) {                                        //
        mpz_div_ui(d, d, 2);                                       //
        r++;                                                       //
    }                                                              //

    while (k--) {
        choose_random_number(p, state, a);                         // Escolhe "a" aleatório no intervalo [2, p-2]
        mpz_powm(x, a, d, p);                                      // x = a^d mod p
        if (mpz_cmp_ui(x, 1) == 0 || mpz_cmp(x, p_minus_one) == 0) // Se x == 1 ou x == p-1:
            continue;                                              //      Continua laço while
        for (int i = 0; i < r-1; i++) {                            // Repete r-1 vezes:
            mpz_powm_ui(x, x, 2, p);                               //     x = x^2 mod p
            if (mpz_cmp(x, p_minus_one) == 0)                      //     Se x == p-1:
                goto exit_inner_loop;                              //          Continua laço while
        }
        return false;                                              // Retorna "é composto"
        exit_inner_loop:;                                          //
    }
    return true;                                                   // Retorna "é provavelmente primo"
}
