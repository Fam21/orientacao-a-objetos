
///@file main.cpp
///@brief Programa principal para execu��o dos testes das entidades e dos dom�nios.

#include <iostream>

#include "dominios.h"
#include "entidades.h"
#include "testes.h"
#include "testesDominio.h"

using namespace std;


///@brief Fun��o principal para execu��o dos testes das entidades e dos dom�nios.


int main()
{
    TesteNome().rodarTestes();
    TesteTelefone().rodarTestes();
    TesteSenha().rodarTestes();
    TesteMatricula().rodarTestes();

    TesteClasse().rodarTestes();
    TesteResultado().rodarTestes();
    TesteData().rodarTestes();
    TesteCodigo().rodarTestes();
    TesteTexto().rodarTestes();
};
