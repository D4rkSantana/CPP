#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 20

int main(int, char**)
{
    // Declaração com construtor recebendo o tamanho
    Array<int> numbers(MAX_VAL);
    // vetor padrão
    int* mirror = new int[MAX_VAL];

    // preenchendo com valores aleatorios
    std::srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // Teste sobrecarga de copia
    Array<int> tmp = numbers;

    // Teste construtor de copia
    Array<int> test(tmp);

    // Teste comparando o Array com o vetor
    std::cout << std::endl << "===== Teste comparando o Array com o vetor" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cout << "KO | Os valores não são iguais" << std::endl;
            return (1);
        }
        else
        {
            std::cout << "OK | index: " << i;
            std::cout << " mirror: " << mirror[i];
            std::cout << " numbers: " << numbers[i] << std::endl;
        }
    }

    // Teste index negativo
    std::cout << std::endl << "===== Teste index negativo" << std::endl;
    try
    {
        numbers[-2] = 0;
        std::cout << " ERROR!!! INDEX NEGATIVO ACEITO "<< std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << " - index negativo interceptado\n";
    }

    // Teste index fora do range
    std::cout << std::endl << "===== Teste index fora do range" << std::endl;
    try
    {
        numbers[MAX_VAL + 1] = 0;
        std::cout << " ERROR!!! INDEX FORA DO RANGE ACEITO "<< std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << " - index fora do range interceptado\n";
    }

    // Reescrevendo o Array
    std::cout << std::endl << "===== Reescrevendo o Array" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();
        std::cout << "index [" << i << "]: " << numbers[i] << std::endl;
    }

    delete [] mirror;
    return 0;
}