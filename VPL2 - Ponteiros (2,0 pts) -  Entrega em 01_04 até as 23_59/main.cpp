#include <iostream>



// 0) Crie uma função que receba três variveis inteiras como parâmetro, da seguinte forma:

void somarum(int &primeira, int *segunda, int terceira)
{
    primeira++;
    (*segunda)++;
    terceira++;
    return;
};


int main(){

    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int primeira = 0;
    std::cin >> primeira;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *segunda = nullptr;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int tamanho = 0;
    std::cin >> tamanho;
    int* terceira = new int [tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        std::cin >> terceira[i];
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    // 5) Imprima o VALOR da variável declarada em (1)

    std::cout << &primeira << std::endl;
    std::cout << primeira << std::endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    // 7) Imprima o VALOR da variável declarada em (2)

    std::cout << &segunda << std::endl;
    std::cout << segunda << std::endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)

    std::cout << &terceira << std::endl;
    std::cout << &terceira[0] << std::endl;
    std::cout << terceira[0] << std::endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)

    segunda = &primeira;

    // 12) Imprima o VALOR da variável declarada em (2)
    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)

    std::cout << segunda << std::endl;
    std::cout << *segunda << std::endl;

    // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    // 15) Imprima o VALOR da variável declarada em (1)

    *segunda = 5;
    std::cout << primeira << std::endl;

    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    // 17) Imprima o VALOR da variável declarada em (2)
    // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)

    segunda = terceira;
    std::cout << segunda << std::endl;
    std::cout << *segunda << std::endl;

    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)

    segunda = &terceira[0];

    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes

    if (segunda == terceira)
    {
        std::cout << 'S' << std::endl;
    }
    else
        std::cout << 'N' << std::endl;

    // 21) Imprima o VALOR da variável declarada em (2)
    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)

    std::cout << segunda << std::endl;
    std::cout << *segunda << std::endl;


    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)

    for (int i = 0; i < tamanho; i++)
    {
        segunda[i] *= 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)

    for (int i = 0; i < tamanho; i++)
    {
        if (i == tamanho - 1)
        {
            std::cout << terceira[i];
            break;
        }
        std::cout << terceira[i] << " ";
    }
    std::cout << std::endl;

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)

    for (int i = 0; i < tamanho; i++)
    {
        if (i == tamanho - 1)
        {
            std::cout << *(terceira + i);
            break;
        }
        std::cout << *(terceira + i) << " ";
    }
    std::cout << std::endl;


    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
    for (int i = 0; i < tamanho; i++)
    {
        if (i == tamanho - 1)
        {
            std::cout << *(segunda + i);
            break;
        }
        std::cout << *(segunda + i) << " ";
    }
    std::cout << std::endl;

    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)

    segunda = &terceira[tamanho - 1];


    // 28) Imprima o VALOR da variável declarada em (2)

    std::cout << segunda << std::endl;


    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)

    std::cout << *segunda << std::endl;


    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **ponteiro = nullptr;
    ponteiro = &segunda;


    // 31) Imprima o VALOR da variável declarada em (30)

    std::cout << ponteiro << std::endl;


    // 32) Imprima o ENDEREÇO da variável declarada em (30)

    std::cout << &ponteiro << std::endl;


    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)

    std::cout << *ponteiro << std::endl;


    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)

    std::cout << **ponteiro << std::endl;


    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada

    int uma = 0;
    int duas = 0;
    int tres = 0;

    std::cin >> uma >> duas >> tres;


    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    somarum(uma, &duas, tres);


    // 37) Imprima o valor das 3 variáveis criadas em 35, uma por linha
    std::cout << uma << std::endl << duas << std::endl << tres << std::endl;

    return 0;
}
