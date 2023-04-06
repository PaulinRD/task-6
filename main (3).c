#include <stdio.h>

// Definindo a estrutura de um projeto
struct Projeto {
  int numero;
  float saldo;
};

// Função que retorna a estrutura de um projeto inicializada
struct Projeto criarProjeto(int numero) {
  struct Projeto projeto;
  projeto.numero = numero;
  projeto.saldo = 0;
  return projeto;
}

int main() {
  int n; // Número de projetos
  printf("Digite o número de projetos: ");
  scanf("%d", &n);

  struct Projeto projetos[n]; // Array com os projetos
  for (int i = 0; i < n; i++) {
    projetos[i] = criarProjeto(i+1); // Inicializando cada projeto com um número
  }

  int numProjeto; // Número do projeto a ser modificado
  float valor; // Valor da operação (receita ou despesa)
  char tipo; // Tipo da operação (R para Receita ou D para Despesa)

  printf("\nOperações:\n");
  printf("Digite o número do projeto, valor e tipo de operação (R ou D)\n");
  printf("Exemplo: 1 500 R (para adicionar R$ 500,00 no projeto 1)\n");

  // Loop para realizar as operações nos projetos
  while (1) {
    scanf("%d %f %c", &numProjeto, &valor, &tipo);

    // Verificando se o número do projeto é válido
    if (numProjeto < 1 || numProjeto > n) {
      printf("Número do projeto inválido!\n");
      continue;
    }

    // Realizando a operação correspondente (receita ou despesa)
    if (tipo == 'R') {
      projetos[numProjeto-1].saldo += valor;
    } else if (tipo == 'D') {
      projetos[numProjeto-1].saldo -= valor;
    } else {
      printf("Tipo de operação inválido!\n");
      continue;
    }

    printf("Operação realizada com sucesso!\n");
  }

  // Mostrando o saldo final de cada projeto
  printf("\nSaldo final dos projetos:\n");
  for (int i = 0; i < n; i++) {
    printf("Projeto %d: R$ %.2f\n", projetos[i].numero, projetos[i].saldo);
  }

  return 0;
}
