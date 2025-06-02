#include <iostream>
#include "Empresa.hpp"
#include "Onibus.hpp"
#include <cstring>

Empresa::Empresa(int numeroonibus)
{
    _numeroonibus = numeroonibus; 
    for (int i = 0; i < 20; i++)
    {
        _vetor[i] = nullptr;
    }
}

Onibus* Empresa::adicionar_onibus(std::string placa, int capmax)
{
    for (int i = 0; i < _numeroonibus; i++)
    {
        if ((_vetor[i]->_placa) == placa)
        {
            return nullptr;
        }
    }

    _vetor[_numeroonibus] = new Onibus(placa, capmax);
    _numeroonibus++;
    return _vetor[_numeroonibus - 1];
    

}

Onibus* Empresa::busca_onibus(std::string placa)
{
    for (int i = 0; i < _numeroonibus; i++)
    {
        if ((_vetor[i]->_placa) == placa)
        {
            return _vetor[i];
            break;
        }
        
    }return nullptr;
}
void Empresa::imprimir_estado()
{
    
    for (int i = 0; i < _numeroonibus; i++)
    {
        
        std::cout << _vetor[i]->_placa << " " << "(" << _vetor[i]->_lotatual << "/" << _vetor[i]->_capmax << ")" << std::endl;
    }
    return;
}

