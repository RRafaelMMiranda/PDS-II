#include "Empresa.hpp"
#include "Onibus.hpp"
#include <iostream>
#include <string>
#include <sstream>

int main (void)
{
    Empresa empresa(0);
    std::string comando;
    while (std::getline(std::cin, comando))
    {
        std::istringstream calma(comando);
        char calabreso;
        calma >> calabreso;
        if (calabreso == 'C')
        {
            //std::cout << "entrei aqui" << std::endl;
            std::string placaaux;
            int capmaxaux;
            calma >> placaaux >> capmaxaux;
           // std::cout << "entrei aqui" << placaaux << capmaxaux << std::endl;
            if (empresa.adicionar_onibus(placaaux, capmaxaux) != nullptr)
            {
                empresa.adicionar_onibus(placaaux, capmaxaux);
                std::cout << "novo onibus cadastrado" << std::endl;
                
            }
            else{
                std::cout << "ERRO : onibus repetido" << std::endl;
            }
            continue;
        }
        else if (calabreso == 'S')
        {
            std::string placaaux;
            int npessoas;
            calma >> placaaux >> npessoas;

            Onibus* aux;
            if (empresa.busca_onibus(placaaux) != nullptr)
            {
                aux = empresa.busca_onibus(placaaux);
                if (aux->_lotatual + npessoas > aux->_capmax)
                {
                    std::cout << "ERRO : onibus lotado" << std::endl;
                    continue;
                }
                else {
                    aux->_lotatual = aux->subir_passageiros(aux->_lotatual, npessoas);
                    std::cout << "passageiros subiram com sucesso" << std::endl;
                    continue;
                }
                
            }
            else{
                std::cout << "ERRO : onibus inexistente" << std::endl;
                continue;
            }

        }
        else if (calabreso == 'D')
        {
            std::string placaaux;
            int npessoas;
            calma >> placaaux;
            calma >> npessoas;

            Onibus* aux;
            if (empresa.busca_onibus(placaaux) != nullptr)
            {
                aux = empresa.busca_onibus(placaaux);
                if (aux->_lotatual - npessoas < 0)
                {
                    std::cout << "ERRO : faltam passageiros" << std::endl;
                    continue;
                }
                else {
                    aux->_lotatual = aux->descer_passageiros(aux->_lotatual, npessoas);
                    std::cout << "passageiros desceram com sucesso" << std::endl;
                    continue;
                }
                
            }
            else{
                std::cout << "ERRO : onibus inexistente" << std::endl;
                continue;
            }

        }
        else if (calabreso == 'T')
        {
            std::string placa1;
            std::string placa2;
            int npessoas;
            calma >> placa1;
            calma >> placa2;
            calma >> npessoas;

            Onibus* aux;
            Onibus* aux2;
            if (empresa.busca_onibus(placa1) != nullptr)
            {
                aux = empresa.busca_onibus(placa1);
                if (empresa.busca_onibus(placa2) != nullptr)
                {
                    aux2 = empresa.busca_onibus(placa2);
                    if (aux2->_lotatual + npessoas > aux2->_capmax) 
                    {
                        std::cout << "ERRO : transferencia cancelada" << std::endl;
                        continue;
                    }
                    else{
                        aux->transfere_passageiros(aux2, npessoas);
                        std::cout << "transferencia de passageiros efetuada" << std::endl;
                        continue;
                    }
                }
                else{
                    std::cout << "ERRO : onibus inexistente" << std::endl;
                    continue;
                }

            }
            else{
                std::cout << "ERRO : onibus inexistente" << std::endl;
                continue;
            }


        }
        else if (calabreso == 'I')
        {
            empresa.imprimir_estado();
            continue;
        }
        else if (calabreso == 'F')
        {
            return 0;    
        }
        continue;
    }
}