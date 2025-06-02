#ifndef ONIBUS_H
#define ONIBUS_H
#include <string>
struct Onibus
{
    std::string _placa;
    int _capmax;
    int _lotatual;

    Onibus(std::string, int);
    int subir_passageiros(int, int);
    int descer_passageiros(int, int);
    void transfere_passageiros(Onibus *, int);
    void imprimir_estado();

};

#endif
