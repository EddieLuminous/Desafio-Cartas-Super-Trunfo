#include <stdio.h>

int main() {
    // Carta 1
    char estado1, codigo_da_carta1[4], cidade1[40];
    unsigned long int populacao1;
    int pontos_turisticos1;
    float area1, PIB1;
    float densidade_populacional1, PIBcapita1, super_poder1;

    // Carta 2
    char estado2, codigo_da_carta2[4], cidade2[40];
    unsigned long int populacao2;
    int pontos_turisticos2;
    float area2, PIB2;
    float densidade_populacional2, PIBcapita2, super_poder2;

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
    PIBcapita1 = (PIB1 * 1000000000) / populacao1;
    //Calculo do Super Poder da Carta1
    super_poder1 = populacao1 + area1 + PIB1 + pontos_turisticos1 + PIBcapita1 + (1/densidade_populacional1);

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
    PIBcapita2 = (PIB2 * 1000000000) / populacao2;
    //Calculo do Super Poder da Carta2
    super_poder2 = populacao2 + area2 + PIB2 + pontos_turisticos2 + PIBcapita2 + (1/densidade_populacional2);

    // Exibição da Carta 1
    printf("\nCarta 1: \n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo_da_carta1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais \n", PIB1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km² \n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais \n", PIBcapita1);
    printf("Super Poder: %.2f\n", super_poder1);
    
    // Exibição da Carta 2
    printf("\nCarta 2: \n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo_da_carta2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais \n", PIB2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km² \n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais \n", PIBcapita2);
    printf("Super Poder: %.2f\n", super_poder2);

    // Comparação das Cartas
    printf("\nComparação de Cartas:\n");
    
    // População
    printf("População: Carta %d venceu (%d)\n", 
           (populacao1 > populacao2) ? 1 : 2, 
           (populacao1 > populacao2) ? 1 : 0);
    
    // Área
    printf("Área: Carta %d venceu (%d)\n", 
           (area1 > area2) ? 1 : 2, 
           (area1 > area2) ? 1 : 0);
    
    // PIB
    printf("PIB: Carta %d venceu (%d)\n", 
           (PIB1 > PIB2) ? 1 : 2, 
           (PIB1 > PIB2) ? 1 : 0);
    
    // Pontos Turísticos
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", 
           (pontos_turisticos1 > pontos_turisticos2) ? 1 : 2, 
           (pontos_turisticos1 > pontos_turisticos2) ? 1 : 0);
    
    // Densidade Populacional (quanto menor, melhor nesse caso)
    printf("Densidade Populacional: Carta %d venceu (%d)\n", 
           (densidade_populacional1 < densidade_populacional2) ? 1 : 2, 
           (densidade_populacional1 < densidade_populacional2) ? 1 : 0);
    
    // PIB per Capita
    printf("PIB per Capita: Carta %d venceu (%d)\n", 
           (PIBcapita1 > PIBcapita2) ? 1 : 2, 
           (PIBcapita1 > PIBcapita2) ? 1 : 0);
    
    // Super Poder legal
    printf("Super Poder: Carta %d venceu (%d)\n", 
           (super_poder1 > super_poder2) ? 1 : 2, 
           (super_poder1 > super_poder2) ? 1 : 0);

    return 0;
}