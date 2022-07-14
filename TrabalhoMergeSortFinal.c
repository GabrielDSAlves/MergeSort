#include<stdio.h>
#include <stdlib.h>

/*Quando você iniciar o codigo, ele terá um menu com duas opções, entrar com numeros aleatórios e entrada de numero em um vetor de 10 posições
após a sua esscolha, será impresso na sua tela, duas lista de numeros, a lista original, ou seja, o vetor que você entrou, (entrada de dados no vetor e numeros aleatórios)
umas das duas listas será seu vetor de entrada e a outra será seu vetor de forma ordenada crescente. */

/*Inicialmente, o vetor será dividido em 2 partes, aproximadamente na metade, de forma consecutiva.
Posteriormente, será realizada a comapração e a ordernação dos valores utilizando um vetor auxiliar.*/

void merge(int *vetor, int tamanho){

    int metade = tamanho / 2, i = 0, j = metade, k = 0, auxiliar[tamanho];

    while(i < metade && j < tamanho){
        
        if(vetor[i] <= vetor[j])
            auxiliar[k] = vetor[i++];
        else
            auxiliar[k] = vetor[j++];

        k++;
    }
    if(i == metade)
        while(j < tamanho)
            auxiliar[k++] = vetor[j++];
    else
        while(i < metade)
            auxiliar[k++] = vetor[i++];
    for(i = 0;i < tamanho;i++)
        vetor[i] = auxiliar[i];
}


void mergeSort(int *vetor, int tamanho){

    int metade = tamanho / 2;

    if(tamanho > 1){
    
        mergeSort(vetor, metade);//Caso a variável do tamanho do vetor seja maior do que 1, será feita a chamada da função MergeSort com as variaveis vetor e metade.
        mergeSort(vetor + metade, tamanho - metade);//Será realizada a junção do vetor e da metade, e do tamanho menos a metade.
        merge(vetor, tamanho);//Será feita a chamada da função acima, junto com as variaveis vetor e tamanho.
    }
}

/*Faça a entrada dos valores do vetor, e escolha entre numeros aleatórios ou através da entrada de dados.
Ao final da operação, você conseguirá ver o vetor desordenado e o vetor após a ordernação.*/

int main(){

    system("cls||clear");
    printf("\nGrupo Nubank: Gabriel, Jeferson, Mariana e Victor Ruan\n");
    printf("\n\n========================================\n");
    printf("        Trabalho Final: MergeSort         \n");
    printf("========================================\n");


    int vetor[10],i=0, opcao;

    printf("\n1 - Numeros aleatorios\n2 - Digite numeros inteiros da\nsua escolha: ");//Escolha o tipo de entrada de dados que desejar.
    scanf("%d", &opcao);

    system("cls||clear");

    if(opcao == 2){
    
        printf("\n\nDigite 10 numeros inteiros de forma desordenada\n\n");//Caso escolha a opção 2, você deve digitar 10 valores desordenados correspondentes ao tamanho do vetor.

        for (int i = 0; i < 10; i++){
        
            printf("Valor referente a posicao %d: ", i+1);
            scanf("%d", &vetor[i]);//Será realizada a leitura dos valores.
        }
    }

    printf("\n\n========================================\n");
    printf("        Vetor antes da ordenacao         \n");
    printf("========================================\n");

    for(int i = 0; i < 10; i++){//Será realizada a impressão dos valores desordenados.
    
        if(opcao == 1)
            vetor[i] = rand()%100;//Caso escolha a opção 1, o vetor será preenchido com numeros aleatórios.

        printf("[%d] ",vetor[i]);//Será realizada a impressão do vetor desordenado (com os valores digitados, ou com o preenchimento autamático aleatório).
    }

    mergeSort(vetor, 10);//Chamada da função mergeSort.

    printf("\n\n========================================\n");
    printf("             vetor ordenado           \n");
    printf("========================================\n");

    for (int i = 0; i < 10; i++)//Será realizada a impressão do vetor com os valores ordenados.
        printf("[%d] ",vetor[i]);

    printf("\n\nPressione Enter para continuar.... \n");
    while( (getchar()) != '\n');//Limpeza do buffer de memória e confirmação do enter para continuar.
    getchar();

   
    return 0;
}
