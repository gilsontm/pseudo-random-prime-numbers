#include <gmpxx.h>
#include "seed.h"

/*
 * Struct que representa um gerador LFSR.
 * Membros:
 *          n    = número de bits dos números que serão gerados
 *          tape = fita que representa o registrador do método
 *          mask = máscara que é aplicada à fita a cada rodada
 */
typedef struct {
    length_t n;
    mpz_t tape;
    mpz_t mask;
} lfsr_t;

/*
 *  Função que inicializa um gerador LFSR.
 *  Parâmetros:
 *          gen = ponteiro da struct que representa o gerador
 *          n   = número de bits dos números que serão gerados
 *  Retorna:
 *          0   = sucesso
 *          1   = erro (parâmetro inválido)
 */
int init_lfsr(lfsr_t* gen, length_t n);

/*
 * Função que gera o próximo número aleatório.
 * Parâmetros:
 *          gen = ponteiro da struct que representa o gerador
 *          res = destino do número que será gerado
 */
void next_lfsr(lfsr_t* gen, mpz_t res);

/*
 *  Função que destrói um gerador LFSR.
 *  Parâmetros:
 *          gen = ponteiro da struct que representa o gerador
 */
void destroy_lfsr(lfsr_t* gen);

/*
 * Parâmetros do método LFSR para número de bits.
 * Extraído de: https://datacipy.cz/lfsr_table.pdf.
 */
const int LFSR_PARAM_40[]   = {40, 37, 36, 35};
const int LFSR_PARAM_56[]   = {56, 54, 52, 49};
const int LFSR_PARAM_80[]   = {80, 78, 76, 71};
const int LFSR_PARAM_128[]  = {128, 127, 126, 121};
const int LFSR_PARAM_168[]  = {168, 162, 159, 152};
const int LFSR_PARAM_224[]  = {224, 222, 217, 212};
const int LFSR_PARAM_256[]  = {256, 254, 251, 246};
const int LFSR_PARAM_512[]  = {512, 510, 507, 504};
const int LFSR_PARAM_1024[] = {1024, 1015, 1002, 1001};
const int LFSR_PARAM_2048[] = {2048, 2035, 2034, 2029};
const int LFSR_PARAM_4096[] = {4096, 4095, 4081, 4069};

/*
 * Função auxiliar de escolha de parâmetros dado o número de bits.
 * Parâmetros:
 *          n = número de bits
 */
const int * get_lfsr_parameters(length_t n) {
    switch (n) {
        case BITS_40:   return LFSR_PARAM_40;
        case BITS_56:   return LFSR_PARAM_56;
        case BITS_80:   return LFSR_PARAM_80;
        case BITS_128:  return LFSR_PARAM_128;
        case BITS_168:  return LFSR_PARAM_168;
        case BITS_224:  return LFSR_PARAM_224;
        case BITS_256:  return LFSR_PARAM_256;
        case BITS_512:  return LFSR_PARAM_512;
        case BITS_1024: return LFSR_PARAM_1024;
        case BITS_2048: return LFSR_PARAM_2048;
        case BITS_4096: return LFSR_PARAM_4096;
        default:        return NULL;
    }
}
