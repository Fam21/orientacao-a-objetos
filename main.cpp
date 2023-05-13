
///@file main.cpp
///@brief Programa principal para execução dos testes das entidades e dos domínios.

#include <iostream>

#include "dominios.h"
#include "entidades.h"
#include "testes.h"
#include "testesDominio.h"

using namespace std;


///@brief Função principal para execução dos testes das entidades e dos domínios.


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
