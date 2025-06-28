#include <stdio.h>

int main() {
    // Carta 1
    char estado1, codigo_da_carta1[4], cidade1[40];
    int pontos_turisticos1;
    unsigned long int populacao1;
    float area1, PIB1, superpoder1;
    float densidade_populacional1, PIBcapita1;

    // Carta 2
    char estado2, codigo_da_carta2[4], cidade2[40];
    int pontos_turisticos2;
    unsigned long int populacao2;
    float area2, PIB2, superpoder2;
    float densidade_populacional2, PIBcapita2;

    // Aqui estão os Dados da Carta 1
    printf("\nDados da Carta 1 \n");
    printf("Digite o estado (Uma letra de 'A' a 'H'): ");
    scanf(" %c", &estado1);

    printf("Digite o código da carta (A letra do estado seguida de um número de 01 a 04): ");
    scanf("%3s", codigo_da_carta1);

    printf("Digite o nome da cidade:");
    scanf("%39s", cidade1);

    printf("Digite o numero de habitantes da cidade:");
    scanf("%lu", &populacao1);

    printf("A área da cidade em quilômetros quadrados:");
    scanf("%f", &area1);

    printf("Produto Interno Bruto da cidade:");
    scanf("%f", &PIB1);

    printf("A quantidade de pontos turísticos na cidade:");
    scanf("%d", &pontos_turisticos1);

    //Calculo da Densidade Populacional da Carta 1
    densidade_populacional1 = (float) populacao1 / area1;
    //Calculo do PIB per Capita da Carta1
    PIBcapita1 = (PIB1 * 1000000000) / populacao1; //eu decidi adicionar essa linha multiplicando por bilhão para deixar o codigo coeso

    //Super Poder da Carta1
    superpoder1 = (populacao1 + area1 + PIB1 + pontos_turisticos1 + PIBcapita1) + (1/densidade_populacional1);

    // Aqui estão os Dados da Carta 2
    printf("\nDados da Carta 2 \n");
    printf("Digite o estado (Uma letra de 'A' a 'H'): ");
    scanf(" %c", &estado2);

    printf("Digite o código da carta (A letra do estado seguida de um número de 01 a 04): ");
    scanf("%3s", codigo_da_carta2);

    printf("Digite o nome da cidade:");
    scanf("%39s", cidade2);

    printf("Digite o numero de habitantes da cidade:");
    scanf("%lu", &populacao2);

    printf("A área da cidade em quilômetros quadrados:");
    scanf("%f", &area2);

    printf("Produto Interno Bruto da cidade:");
    scanf("%f", &PIB2);

    printf("A quantidade de pontos turísticos na cidade:");
    scanf("%d", &pontos_turisticos2);

    //Calculo da Densidade Populacional da Carta 2
    densidade_populacional2 = (float) populacao2 / area2;
    //Calculo do PIB per Capita da Carta 2
    PIBcapita2 = (PIB2 * 1000000000) / populacao2; //eu decidi adicionar essa linha multiplicando por bilhão para deixar o codigo coeso
    //Super Poder da Carta2
    superpoder2 = (populacao2 + area2 + PIB2 + pontos_turisticos2 + PIBcapita2) + (1/densidade_populacional2);

    // Exibição da Carta 1
    printf("\nCarta 1: \n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo_da_carta1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais \n", PIB1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km² \n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais \n", PIBcapita1);
    
    // Exibição da Carta 2
    printf("\nCarta 2: \n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo_da_carta2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais \n", PIB2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km² \n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais \n", PIBcapita2);

    //Titulo!!!
    printf("\n Comparação de Cartas \n 1 = verdadeiro  0 = falso \n");

    //Comparando as cartas em si
    printf("População: Carta 1 venceu? (%d)\n", (populacao1 > populacao2));
    printf("Área: Carta 1 venceu? (%d)\n", (area1 > area2));
    printf("PIB: Carta 1 venceu? (%d)\n", (PIB1 > PIB2));
    printf("Pontos Turísticos: Carta 1 venceu? (%d)\n", (pontos_turisticos1 > pontos_turisticos2));
    printf("Densidade Populacional: Carta 2 venceu? (%d)\n", (densidade_populacional2 < densidade_populacional1));
    printf("PIB per Capita: Carta 1 venceu? (%d)\n", (PIBcapita1 > PIBcapita2));
    printf("Super Poder: Carta 1 venceu? (%d)\n", (superpoder1 > superpoder2));

    return 0;
}