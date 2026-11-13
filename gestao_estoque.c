#include <stdio.h>

struct produto {
    int id;
    char nome[50];
    int quantidade;
    float preco;
};

// Função para cadastrar um novo produto
void cadastrar_produto(struct produto *p) {
    printf("Digite o nome do produto: \n");
    scanf("%49s", p->nome); // evita estouro de buffer no array
    printf("Digite a quantidade do produto: \n");
    scanf("%d", &p->quantidade);
    printf("Digite o preco da unidade do produto: \n");
    scanf("%f", &p->preco);
}

// Função para exibir as informações de um produto
void exibir_produto(struct produto p) {
    printf("ID: %d\n", p.id);
    printf("Nome: %s\n", p.nome);
    printf("Quantidade: %d\n", p.quantidade);
    printf("Preco: %.2f\n", p.preco);
}

// Função para atualizar as informações de um produto
void atualizar_produto(struct produto *p) {
    printf("Digite o novo nome do produto: \n");
    scanf("%s", p->nome);
    printf("Digite a nova quantidade do produto: \n");
    scanf("%d", &p->quantidade);
    printf("Digite o novo preco do produto: \n");
    scanf("%f", &p->preco);
}

// Função para excluir um produto
void excluir_produto(struct produto *p) {
    p->id = 0;
    p->nome[0] = '\0';
    p->quantidade = 0;
    p->preco = 0.0;
}

int main() {
    struct produto produtos[100];
    int num_produtos = 0;
    int opcao;
    char continuar;

    // Loop principal do sistema de gestão de estoque
   do { printf("Bem-vindo ao sistema de gestão de estoque!\n");
    printf("O que você gostaria de fazer?\n");
    printf("1. Cadastrar produto\n");
    printf("2. Exibir produtos \n");
    printf("3. Atualizar produto\n");
    printf("4. Excluir produto\n");
    printf("5. Sair\n");

    scanf("%d", &opcao);

    // Executa a opção escolhida pelo usuário
    switch(opcao) {
        case 1:
            if (num_produtos < 100) {
                cadastrar_produto(&produtos[num_produtos]);
            produtos[num_produtos].id = num_produtos + 1;
            num_produtos++;
            printf("Produto cadastrado com sucesso!\n");
            } else {
                printf("Limite de produtos atingido.\n");
            }
            break;
        case 2: 
            if (num_produtos == 0) {
                printf("Nenhum produto cadastrado.\n");
            } else {
                for (int i = 0; i < num_produtos; i++) {
                    if (produtos[i].id != 0) { // Verifica se o produto não foi excluído
                    exibir_produto(produtos[i]);
                    }
                }
            }
            break;
        case 3:
            printf("Digite o ID do produto que deseja atualizar: \n");
            int id_atualizar;
            scanf("%d", &id_atualizar);
            if (id_atualizar > 0 && id_atualizar <= num_produtos) {
                atualizar_produto(&produtos[id_atualizar - 1]);
            } else {
                printf("Produto nao encontrado.\n");
            }
            break;
        case 4:
            printf("Digite o ID do produto que deseja excluir: \n");
            int id_excluir;
            scanf("%d", &id_excluir);
            if (id_excluir > 0 && id_excluir <= num_produtos) {
                excluir_produto(&produtos[id_excluir - 1]);
                printf("Produto excluido com sucesso.\n");
            } else {
                printf("Produto nao encontrado.\n");
            }
            break;
        case 5:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }

    if (opcao == 5) break;

    while (getchar() != '\n'); // Limpa o buffer do teclado
    
    printf("Deseja realizar outra operacao? (s/n)\n");
    scanf(" %c", &continuar);
} while (continuar == 's' || continuar == 'S');

    return 0;
}