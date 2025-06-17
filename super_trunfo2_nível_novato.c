#include <stdio.h>
#include <string.h>

int main() {
    // Dados da Carta 1 (as pré-definidas)
    char estado1[] = "SP";
    char codigo1[] = "SP01";
    char cidade1[] = "São Paulo";
    int populacao1 = 12300000;
    float area1 = 1521.11;
    float PIB1 = 650.50; // em bilhões
    int pontos_turisticos1 = 300;
    
    // Dados da Carta 2 (pré-definida também)
    char estado2[] = "RJ";
    char codigo2[] = "RJ01";
    char cidade2[] = "Rio de Janeiro";
    int populacao2 = 6748000;
    float area2 = 1200.25;
    float PIB2 = 380.75; // em bilhões
    int pontos_turisticos2 = 250;
    
    // Cálculos para ambas as cartas
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pib_per_capita1 = (PIB1 * 1000000000) / populacao1;
    float pib_per_capita2 = (PIB2 * 1000000000) / populacao2;
    
    // Escolha do atributo para comparação (definido no código)
    // Opções: "populacao, area, PIB, densidade, pib_per_capita"
    char atributo_escolhido[] = "populacao"; 
    
    // Variáveis para armazenar os resultados da comparação
    int carta_vencedora = 0;
    float valor1 = 0, valor2 = 0;
    
    // Lógica de comparação baseada no atributo escolhido
    if (strcmp(atributo_escolhido, "populacao") == 0) {
        valor1 = populacao1;
        valor2 = populacao2;
        carta_vencedora = (populacao1 > populacao2) ? 1 : 2;
    } 
    else if (strcmp(atributo_escolhido, "area") == 0) {
        valor1 = area1;
        valor2 = area2;
        carta_vencedora = (area1 > area2) ? 1 : 2;
    } 
    else if (strcmp(atributo_escolhido, "PIB") == 0) {
        valor1 = PIB1;
        valor2 = PIB2;
        carta_vencedora = (PIB1 > PIB2) ? 1 : 2;
    } 
    else if (strcmp(atributo_escolhido, "densidade") == 0) {
        valor1 = densidade1;
        valor2 = densidade2;
        // Para densidade, o menor valor vence
        carta_vencedora = (densidade1 < densidade2) ? 1 : 2;
    } 
    else if (strcmp(atributo_escolhido, "pib_per_capita") == 0) {
        valor1 = pib_per_capita1;
        valor2 = pib_per_capita2;
        carta_vencedora = (pib_per_capita1 > pib_per_capita2) ? 1 : 2;
    }
    
    // Exibição dos resultados
    printf("\nComparação de cartas (Atributo: %s):\n", atributo_escolhido);
    printf("\nCarta 1 - %s (%s): %.2f", cidade1, estado1, valor1);
    printf("\nCarta 2 - %s (%s): %.2f", cidade2, estado2, valor2);
    
    if (carta_vencedora == 1) {
        printf("\n\nResultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (carta_vencedora == 2) {
        printf("\n\nResultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("\n\nResultado: Empate!\n");
    }
    
    return 0;
}