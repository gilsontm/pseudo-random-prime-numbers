/*
 * Parâmetros do método LFSR para número de bits.
 * Extraído de: https://datacipy.cz/lfsr_table.pdf.
 */
const int PARAM_40[]   = {40, 37, 36, 35};
const int PARAM_56[]   = {56, 54, 52, 49};
const int PARAM_80[]   = {80, 78, 76, 71};
const int PARAM_128[]  = {128, 127, 126, 121};
const int PARAM_168[]  = {168, 162, 159, 152};
const int PARAM_224[]  = {224, 222, 217, 212};
const int PARAM_256[]  = {256, 254, 251, 246};
const int PARAM_512[]  = {512, 510, 507, 504};
const int PARAM_1024[] = {1024, 1015, 1002, 1001};
const int PARAM_2048[] = {2048, 2035, 2034, 2029};
const int PARAM_4096[] = {4096, 4095, 4081, 4069};

/*
 * Enum que define os possíveis números de bits aceitos.
 */
enum length_t {
    BITS_40   = 40,
    BITS_56   = 56,
    BITS_80   = 80,
    BITS_128  = 128,
    BITS_168  = 168,
    BITS_224  = 224,
    BITS_256  = 256,
    BITS_512  = 512,
    BITS_1024 = 1024,
    BITS_2048 = 2048,
    BITS_4096 = 4096,
};

/*
 * Função auxiliar de escolha de parâmetros dado o número de bits.
 * Parâmetros:
 *          n = número de bits
 */
const int * get_lfsr_parameters(length_t n) {
    switch (n) {
        case BITS_40:   return PARAM_40;
        case BITS_56:   return PARAM_56;
        case BITS_80:   return PARAM_80;
        case BITS_128:  return PARAM_128;
        case BITS_168:  return PARAM_168;
        case BITS_224:  return PARAM_224;
        case BITS_256:  return PARAM_256;
        case BITS_512:  return PARAM_512;
        case BITS_1024: return PARAM_1024;
        case BITS_2048: return PARAM_2048;
        case BITS_4096: return PARAM_4096;
        default:        return NULL;
    }
}