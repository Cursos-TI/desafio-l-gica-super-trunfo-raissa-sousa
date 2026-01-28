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

int main() {
    struct Carta carta1, carta2;
    int opcao;

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

    // ====== MENU ======
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha o atributo: ");
    scanf("%d", &opcao);

    printf("\nComparação entre as cartas %s e %s:\n", carta1.nomePais, carta2.nomePais);

    switch (opcao) {

        case 1:
            printf("Atributo: População\n");
            printf("%s: %lu\n", carta1.nomePais, carta1.populacao);
            printf("%s: %lu\n", carta2.nomePais, carta2.populacao);

            if (carta1.populacao > carta2.populacao)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.populacao > carta1.populacao)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f\n", carta1.nomePais, carta1.area);
            printf("%s: %.2f\n", carta2.nomePais, carta2.area);

            if (carta1.area > carta2.area)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.area > carta1.area)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f\n", carta1.nomePais, carta1.PIB);
            printf("%s: %.2f\n", carta2.nomePais, carta2.PIB);

            if (carta1.PIB > carta2.PIB)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.PIB > carta1.PIB)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", carta1.nomePais, carta1.numPontosTuristicos);
            printf("%s: %d\n", carta2.nomePais, carta2.numPontosTuristicos);

            if (carta1.numPontosTuristicos > carta2.numPontosTuristicos)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.numPontosTuristicos > carta1.numPontosTuristicos)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Atributo: Densidade Demográfica (MENOR vence)\n");
            printf("%s: %.2f\n", carta1.nomePais, carta1.densidadePop);
            printf("%s: %.2f\n", carta2.nomePais, carta2.densidadePop);

            if (carta1.densidadePop < carta2.densidadePop)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.densidadePop < carta1.densidadePop)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
