#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
        // Menu interativo yay
        printf("\n=== SUPER TRUNFO ===\n");
        printf("Escolha o atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("6 - PIB per capita\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        // Limpar buffer do teclado
        while(getchar() != '\n');
        
        switch(opcao) {
            case 1: // População
                printf("\nComparação por População:\n");
                printf("%s: %d habitantes\n", carta1.cidade, carta1.populacao);
                printf("%s: %d habitantes\n", carta2.cidade, carta2.populacao);
                
                if(carta1.populacao > carta2.populacao) {
                    printf("Vencedor: %s\n", carta1.cidade);
                } else if(carta2.populacao > carta1.populacao) {
                    printf("Vencedor: %s\n", carta2.cidade);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 2: // Área
                printf("\nComparação por Área:\n");
                printf("%s: %.2f km²\n", carta1.cidade, carta1.area);
                printf("%s: %.2f km²\n", carta2.cidade, carta2.area);
                
                if(carta1.area > carta2.area) {
                    printf("Vencedor: %s\n", carta1.cidade);
                } else if(carta2.area > carta1.area) {
                    printf("Vencedor: %s\n", carta2.cidade);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 3: // PIB
                printf("\nComparação por PIB:\n");
                printf("%s: %.2f bilhões\n", carta1.cidade, carta1.PIB);
                printf("%s: %.2f bilhões\n", carta2.cidade, carta2.PIB);
                
                if(carta1.PIB > carta2.PIB) {
                    printf("Vencedor: %s\n", carta1.cidade);
                } else if(carta2.PIB > carta1.PIB) {
                    printf("Vencedor: %s\n", carta2.cidade);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 4: // Pontos Turísticos
                printf("\nComparação por Pontos Turísticos:\n");
                printf("%s: %d pontos\n", carta1.cidade, carta1.pontos_turisticos);
                printf("%s: %d pontos\n", carta2.cidade, carta2.pontos_turisticos);
                
                if(carta1.pontos_turisticos > carta2.pontos_turisticos) {
                    printf("Vencedor: %s\n", carta1.cidade);
                } else if(carta2.pontos_turisticos > carta1.pontos_turisticos) {
                    printf("Vencedor: %s\n", carta2.cidade);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 5: // Densidade Demográfica
                printf("\nComparação por Densidade Demográfica:\n");
                printf("%s: %.2f hab/km²\n", carta1.cidade, carta1.densidade);
                printf("%s: %.2f hab/km²\n", carta2.cidade, carta2.densidade);
                
                if(carta1.densidade < carta2.densidade) {
                    printf("Vencedor: %s (menor densidade)\n", carta1.cidade);
                } else if(carta2.densidade < carta1.densidade) {
                    printf("Vencedor: %s (menor densidade)\n", carta2.cidade);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 6: // PIB per capita
                printf("\nComparação por PIB per capita:\n");
                printf("%s: %.2f reais\n", carta1.cidade, carta1.pib_per_capita);
                printf("%s: %.2f reais\n", carta2.cidade, carta2.pib_per_capita);
                
                if(carta1.pib_per_capita > carta2.pib_per_capita) {
                    printf("Vencedor: %s\n", carta1.cidade);
                } else if(carta2.pib_per_capita > carta1.pib_per_capita) {
                    printf("Vencedor: %s\n", carta2.cidade);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 0: // Sair
                printf("Saindo do jogo...\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
        
        if(opcao != 0) {
            printf("\nDeseja comparar outro atributo? (S/N): ");
            scanf(" %c", &continuar);
            continuar = toupper(continuar);
            
            // Limpar buffer do teclado
            while(getchar() != '\n');
        }
    } while(opcao != 0 && continuar == 'S');
    
    return 0;
}