#include <stdio.h>
#include <stdlib.h>

struct Carta {
    char nomePais[50];
    unsigned long int populacao;
    float area;
    float PIB;
    int numPontosTuristicos;
    float densidadePop;
};

float obterValor(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.PIB;
        case 4: return c.numPontosTuristicos;
        case 5: return c.densidadePop;
        default: return 0;
    }
}

char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    struct Carta carta1, carta2;
    int attr1, attr2;
    float soma1 = 0, soma2 = 0;

    // ====== ENTRADA DA CARTA 1 ======
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Nome do País: ");
    scanf("%s", carta1.nomePais);

    printf("População: ");
    scanf("%lu", &carta1.populacao);

    printf("Área: ");
    scanf("%f", &carta1.area);

    printf("PIB: ");
    scanf("%f", &carta1.PIB);

    printf("Pontos turísticos: ");
    scanf("%d", &carta1.numPontosTuristicos);

    carta1.densidadePop = carta1.populacao / carta1.area;

    // ====== ENTRADA DA CARTA 2 ======
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Nome do País: ");
    scanf("%s", carta2.nomePais);

    printf("População: ");
    scanf("%lu", &carta2.populacao);

    printf("Área: ");
    scanf("%f", &carta2.area);

    printf("PIB: ");
    scanf("%f", &carta2.PIB);

    printf("Pontos turísticos: ");
    scanf("%d", &carta2.numPontosTuristicos);

    carta2.densidadePop = carta2.populacao / carta2.area;

    // ====== PRIMEIRO MENU ======
    printf("\n=== Escolha o PRIMEIRO atributo ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &attr1);

    // ====== SEGUNDO MENU (DINÂMICO) ======
    printf("\n=== Escolha o SEGUNDO atributo ===\n");
    if (attr1 != 1) printf("1 - População\n");
    if (attr1 != 2) printf("2 - Área\n");
    if (attr1 != 3) printf("3 - PIB\n");
    if (attr1 != 4) printf("4 - Pontos Turísticos\n");
    if (attr1 != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &attr2);

    // ====== CÁLCULO DAS SOMAS ======
    float v1_c1 = obterValor(carta1, attr1);
    float v1_c2 = obterValor(carta2, attr1);
    float v2_c1 = obterValor(carta1, attr2);
    float v2_c2 = obterValor(carta2, attr2);

    // Densidade: menor vence → inverte valor na soma
    soma1 += (attr1 == 5) ? -v1_c1 : v1_c1;
    soma2 += (attr1 == 5) ? -v1_c2 : v1_c2;

    soma1 += (attr2 == 5) ? -v2_c1 : v2_c1;
    soma2 += (attr2 == 5) ? -v2_c2 : v2_c2;

    // ====== RESULTADO ======
    printf("\n=== RESULTADO FINAL ===\n");
    printf("Países: %s x %s\n\n", carta1.nomePais, carta2.nomePais);

    printf("Atributo 1: %s\n", nomeAtributo(attr1));
    printf("%s: %.2f | %s: %.2f\n\n",
           carta1.nomePais, v1_c1,
           carta2.nomePais, v1_c2);

    printf("Atributo 2: %s\n", nomeAtributo(attr2));
    printf("%s: %.2f | %s: %.2f\n\n",
           carta1.nomePais, v2_c1,
           carta2.nomePais, v2_c2);

    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nomePais, soma1);
    printf("%s: %.2f\n", carta2.nomePais, soma2);

    printf("\nVencedor: %s\n",
           soma1 > soma2 ? carta1.nomePais :
           soma2 > soma1 ? carta2.nomePais :
           "Empate!");

    return 0;
}
