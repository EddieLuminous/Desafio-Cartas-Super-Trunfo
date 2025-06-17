#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Estrutura para representar uma carta de Super Trunfo
typedef struct {
    char estado[3];
    char codigo[5];
    char cidade[40];
    int populacao;
    float area;
    float PIB;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

// Função para calcular densidade e PIB per capita
void calcularAtributos(Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
    carta->pib_per_capita = (carta->PIB * 1000000000) / carta->populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta) {
    printf("\nDados da carta:\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.PIB);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidade);
    printf("PIB per capita: %.2f reais\n", carta.pib_per_capita);
}

// Função para exibir o menu de atributos, ocultando os já selecionados
void exibirMenuAtributos(int atributoExcluido) {
    printf("\nEscolha o atributo para comparar:\n");
    if (atributoExcluido != 1) printf("1 - População\n");
    if (atributoExcluido != 2) printf("2 - Área\n");
    if (atributoExcluido != 3) printf("3 - PIB\n");
    if (atributoExcluido != 4) printf("4 - Pontos Turísticos\n");
    if (atributoExcluido != 5) printf("5 - Densidade Demográfica\n");
    if (atributoExcluido != 6) printf("6 - PIB per capita\n");
    printf("0 - Sair\n");
    printf("Opção: ");
}

// Função para comparar dois valores de atributo (considerando regras especiais)
int compararAtributo(float valor1, float valor2, int atributo) {
    // Para densidade demográfica, o menor valor vence
    if (atributo == 5) {
        return (valor1 < valor2) ? 1 : (valor1 > valor2) ? -1 : 0;
    }
    // Para outros atributos, o maior valor vence
    return (valor1 > valor2) ? 1 : (valor1 < valor2) ? -1 : 0;
}

// Função para obter o valor de um atributo específico de uma carta
float obterValorAtributo(Carta carta, int atributo) {
    switch(atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.PIB;
        case 4: return carta.pontos_turisticos;
        case 5: return carta.densidade;
        case 6: return carta.pib_per_capita;
        default: return 0;
    }
}

// Função para obter o nome de um atributo
const char* obterNomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        case 6: return "PIB per capita";
        default: return "Desconhecido";
    }
}

int main() {
    // Inicialização das cartas (as que são pré-definidas)
    Carta carta1 = {"SP", "SP01", "São Paulo", 12300000, 1521.11, 650.50, 300};
    Carta carta2 = {"RJ", "RJ01", "Rio de Janeiro", 6748000, 1200.25, 380.75, 250};
    
    // Calcular atributos derivados
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);
    
    int opcao;
    char continuar;
    
    do {
        // Exibir informações das cartas
        printf("\n=== SUPER TRUNFO - NÍVEL MESTRE ===\n");
        printf("Cartas em jogo:\n");
        printf("1. %s (%s)\n", carta1.cidade, carta1.estado);
        printf("2. %s (%s)\n", carta2.cidade, carta2.estado);
        
        // Menu para escolher o primeiro atributo
        int atributo1, atributo2;
        printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
        exibirMenuAtributos(0);
        scanf("%d", &atributo1);
        
        // Validar entrada
        while(atributo1 < 0 || atributo1 > 6) {
            printf("Opção inválida! Tente novamente: ");
            scanf("%d", &atributo1);
        }
        
        if(atributo1 == 0) break;
        
        // Menu para escolher o segundo atributo (excluindo o primeiro né)
        printf("\nEscolha o SEGUNDO atributo para comparar (diferente do primeiro):\n");
        exibirMenuAtributos(atributo1);
        scanf("%d", &atributo2);
        
        // Validando entrada
        while(atributo2 < 0 || atributo2 > 6 || atributo2 == atributo1) {
            printf("Opção inválida! Deve ser diferente do primeiro atributo: ");
            scanf("%d", &atributo2);
        }
        
        if(atributo2 == 0) break;
        
        // Obter valores dos atributos para as duas cartas
        float valor1_atr1 = obterValorAtributo(carta1, atributo1);
        float valor2_atr1 = obterValorAtributo(carta2, atributo1);
        float valor1_atr2 = obterValorAtributo(carta1, atributo2);
        float valor2_atr2 = obterValorAtributo(carta2, atributo2);
        
        // Comparar os atributos individualmente
        int resultado_atr1 = compararAtributo(valor1_atr1, valor2_atr1, atributo1);
        int resultado_atr2 = compararAtributo(valor1_atr2, valor2_atr2, atributo2);
        
        // Calculando a soma dos atributos
        float soma_carta1 = valor1_atr1 + valor1_atr2;
        float soma_carta2 = valor2_atr1 + valor2_atr2;
        
        // Exibir resultados
        printf("\n=== RESULTADOS DA COMPARAÇÃO ===\n");
        printf("Atributos comparados: %s e %s\n", 
               obterNomeAtributo(atributo1), obterNomeAtributo(atributo2));
        
        printf("\n%s:\n", carta1.cidade);
        printf("- %s: %.2f\n", obterNomeAtributo(atributo1), valor1_atr1);
        printf("- %s: %.2f\n", obterNomeAtributo(atributo2), valor1_atr2);
        printf("SOMA: %.2f\n", soma_carta1);
        
        printf("\n%s:\n", carta2.cidade);
        printf("- %s: %.2f\n", obterNomeAtributo(atributo1), valor2_atr1);
        printf("- %s: %.2f\n", obterNomeAtributo(atributo2), valor2_atr2);
        printf("SOMA: %.2f\n", soma_carta2);
        
        // Determinar o vencedor
        printf("\nRESULTADO:\n");
        
        // Exibir resultados individuais
        printf("- %s: ", obterNomeAtributo(atributo1));
        if (resultado_atr1 == 1) {
            printf("%s vence\n", carta1.cidade);
        } else if (resultado_atr1 == -1) {
            printf("%s vence\n", carta2.cidade);
        } else {
            printf("Empate!\n");
        }
        
        printf("- %s: ", obterNomeAtributo(atributo2));
        if (resultado_atr2 == 1) {
            printf("%s vence\n", carta1.cidade);
        } else if (resultado_atr2 == -1) {
            printf("%s vence\n", carta2.cidade);
        } else {
            printf("Empate!\n");
        }
        
        // Exibir resultado final baseado na soma
        printf("\nRESULTADO FINAL (soma dos atributos):\n");
        if (soma_carta1 > soma_carta2) {
            printf("%s vence com %.2f pontos!\n", carta1.cidade, soma_carta1);
        } else if (soma_carta2 > soma_carta1) {
            printf("%s vence com %.2f pontos!\n", carta2.cidade, soma_carta2);
        } else {
            printf("Empate! Ambas as cartas têm %.2f pontos.\n", soma_carta1);
        }
        
        // Perguntar se deseja continuar
        printf("\nDeseja comparar novamente? (S/N): ");
        scanf(" %c", &continuar);
        continuar = toupper(continuar);
        
        // Limpar buffer do teclado
        while(getchar() != '\n');
        
    } while(continuar == 'S');
    
    printf("Saindo do jogo...\n");
    return 0;
}

