#include "Onibus.hpp"
#include <iostream>

Onibus::Onibus(std::string placa, int capmax)
{
    _capmax = capmax;
    _placa = placa;
}
    int Onibus::subir_passageiros(int lotatual, int a)
    {
        lotatual += a;
        return lotatual;
    }
    int Onibus::descer_passageiros(int lotatual, int a)
    {
        lotatual -= a;
        return lotatual;
    }
    void Onibus::transfere_passageiros(Onibus *p, int a)
    {
        this->_lotatual -= a;
        p->_lotatual += a;
    }
    void Onibus::imprimir_estado()
    {
        std::cout << _placa << " " << "(" << _lotatual << "/" << _capmax << ")" << std::endl;
    };
