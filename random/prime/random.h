#include <gmpxx.h>

/*
 * Função que gera um número aleatório no intervalo [2,p-2].
 * Esta função utiliza um gerador de números aleatórios da biblioteca GMP.
 * ATENÇÃO: Esta função é usada apenas para gerar um parâmetro do testes de primalidade.
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
