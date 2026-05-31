#pragma once

class Klostercode{
private:
    static const int TAM = 7; ///tamaño del codigo

    char _codigo[TAM];
    int _pasoActual;
    bool _activado;

public:
    Klostercode();

    void ProcesarLetra(char letra);

    bool EstaActivado();

    void Reiniciar();
};
