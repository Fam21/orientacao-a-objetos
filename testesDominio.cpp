
///@file testesDominio.h
///@brief Arquivo contendo os testes de unidade das classes do domínio


#include "testesDominio.h"
#include "dominios.h"

#include <iostream>
#include <cassert>
using namespace std;



///@brief Classe de teste para validação da Classe


void TesteClasse::rodarTestes(){

    Classe validador;

    ///Teste 1: valor valido.
    try{
        validador.setClasse("UNIDADE");
        std::cout <<"SUCESSO"<<endl;
    }
    catch(std::invalid_argument &ex){
        std::cout <<"FALHA"<<endl;
    }

    ///Teste 2: metodo getClasse.

    if(validador.getClasse()=="UNIDADE"){
        std::cout <<"SUCESSO"<<endl;
    }
    else{
        std::cout <<"FALHA"<<endl;
    }
}


///@brief Classe de teste para validação do Resultado


void TesteResultado::rodarTestes(){

    Resultado validador;

    ///Teste 1: valor valido.

    try {
        validador.setResultado("APROVADO");
        std::cout << "SUCESSO"<<endl;
    } catch (std::invalid_argument &ex) {
        std::cout << "FALHA"<<endl;
    }

    ///Teste 2: Metodo getResultado.

    if(validador.getResultado()=="APROVADO"){
        std::cout << "SUCESSO"<<endl;
    }
    else{
        std::cout << "FALHA"<<endl;
    }

    ///Teste 3: Valor invalido.

    try {
        validador.setResultado("12345");
        std::cout << "FALHA";
    } catch (std::invalid_argument &ex) {
        std::cout << "SUCESSO"<<endl;
    }

}


///@brief Classe de teste para validação da Data


void TesteData::rodarTestes(){

    Data validador;

    ///Teste 1: valor invalido.

    try{
        validador.setData("29/FEV/2001");
        std::cout <<"FALHA"<<endl;
    }
    catch(std::invalid_argument &ex){
        std::cout <<"SUCESSO"<<endl;
    }

    ///Teste 2: valor valido.

    try{
        validador.setData("29/FEV/2024");
        std::cout <<"SUCESSO"<<endl;
    }
    catch(std::invalid_argument &ex){
        std::cout <<"FALHA"<<endl;
    }

    ///Teste 3: teste metodo getData.

    if(validador.getData()== "29/FEV/2024"){
        std::cout <<"SUCESSO"<<endl;
    }
    else{
        std::cout <<"FALHA"<<endl;
    }

}


///@brief Classe de teste para validação do Código


void TesteCodigo::rodarTestes(){

    Codigo validador;

    ///Teste 1: valor invalido.

    try{
        validador.setCodigo("AcJ189");
        std::cout <<"SUCESSO"<<endl;
    }
    catch(std::invalid_argument &ex){
        std::cout <<"FALHA"<<endl;
    }

    ///Teste 2: valor invalido.

    try{
        validador.setCodigo("46D6#f");
        std::cout <<"FALHA"<<endl;
    }
    catch(std::invalid_argument &ex){
        std::cout <<"SUCESSO"<<endl;
    }

    ///Teste 3: Teste metodo getCodigo.

    if(validador.getCodigo()!=""){
        std::cout <<"SUCESSO"<<endl;
    }

    else{
        std::cout <<"FALHA"<<endl;
    }
}


///@brief Classe de teste para validação do Texto


void TesteTexto::rodarTestes(){

    Texto validador;

    ///Teste 1: valor valido.

    try{
        validador.setTexto("HeLLo...,:;?456!");
        std::cout <<"SUCESSO"<<endl;
    }
    catch(std::invalid_argument &ex){
        std::cout <<"FALHA"<<endl;
    }
    if(validador.getTexto() == "HeLLo...,:;?456!"){
        std::cout <<"SUCESSO"<<endl;
    }
    else{
       std::cout <<"FALHA"<<endl;
    }

    ///Teste 2: Valor invalido.

    try{
        validador.setTexto("HeLLo...World456!AKBDADD");
        std::cout <<"FALHA"<<endl;
    }
    catch(std::invalid_argument &ex){
        std::cout <<"SUCESSO"<<endl;
    }
}
