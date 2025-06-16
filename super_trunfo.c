#include <stdio.h>

int main() {
    // Carta 1
    char estado1, codigo_da_carta1[4], cidade1[40];
    int populacao1, pontos_turisticos1;
    float area1, PIB1;

    // Carta 2
    char estado2, codigo_da_carta2[4], cidade2[40];
    int populacao2, pontos_turisticos2;
    float area2, PIB2;

    // Aqui estão os Dados da Carta 1
    printf("\nDados da Carta 1 \n");
    printf("Digite o estado (Uma letra de 'A' a 'H'): ");
    scanf(" %c", &estado1);

    printf("Digite o código da carta (A letra do estado seguida de um número de 01 a 04): ");
    scanf("%3s", codigo_da_carta1);

    printf("Digite o nome da cidade:");
    scanf("%39s", cidade1);

    printf("Digite o numero de habitantes da cidade:");
    scanf("%d", &populacao1);

    printf("A área da cidade em quilômetros quadrados:");
    scanf("%f", &area1);

    printf("Produto Interno Bruto da cidade:");
    scanf("%f", &PIB1);

    printf("A quantidade de pontos turísticos na cidade:");
    scanf("%d", &pontos_turisticos1);

    // Aqui estão os Dados da Carta 2
    printf("\nDados da Carta 2 \n");
    printf("Digite o estado (Uma letra de 'A' a 'H'): ");
    scanf(" %c", &estado2);

    printf("Digite o código da carta (A letra do estado seguida de um número de 01 a 04): ");
    scanf("%3s", codigo_da_carta2);

    printf("Digite o nome da cidade:");
    scanf("%39s", cidade2);

    printf("Digite o numero de habitantes da cidade:");
    scanf("%d", &populacao2);

    printf("A área da cidade em quilômetros quadrados:");
    scanf("%f", &area2);

    printf("Produto Interno Bruto da cidade:");
    scanf("%f", &PIB2);

    printf("A quantidade de pontos turísticos na cidade:");
    scanf("%d", &pontos_turisticos2);

    // Exibição da Carta 1
    printf("\nCarta 1: \n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo_da_carta1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f\n", PIB1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    
    // Exibição da Carta 2
    printf("\nCarta 2: \n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo_da_carta2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f\n", PIB2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);

    return 0;
}