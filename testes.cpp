
///@file testes.cpp
///@brief Implementação dos métodos referentes aos testes das entidades e métodos da classe Desenvolvedor.


#include <iostream>
#include <cassert>

#include "testes.h"
#include "entidades.h"

using namespace std;


///@brief Método para testar o nome do desenvolvedor.


void TesteNome::rodarTestes(){
    Desenvolvedor validador;

    ///Teste 1: valor valido e metodo getNome.

    validador.setNome("Joao");
    if(validador.getNome()== "Joao"){
        std::cout<<"SUCESSO"<<endl;
    }
    else{
        std::cout<<"FALHA"<<endl;
    }
}


///@brief Método para testar o telefone do desenvolvedor.


void TesteTelefone::rodarTestes() {

    Desenvolvedor validador;

    ///Teste 1: valor valido.

    try {
        validador.setTelefone("+1234567");
        std::cout << "SUCESSO"<<endl;
    } catch (std::invalid_argument &ex) {
        std::cout << "FALHA"<<endl;
    }

    ///Teste 2: Metodo getTelefone.

    if(validador.getTelefone()=="+1234567"){
        std::cout << "SUCESSO"<<endl;
    }
    else{
        std::cout << "FALHA"<<endl;
    }

    ///Teste 3: valor invalido.

    try {
        validador.setTelefone("12345678");
        std::cout << "FALHA";
    }
    catch (std::invalid_argument &ex) {
        std::cout << "SUCESSO"<<endl;
    }
    ///Teste 4: valor invalido.
    try {
        validador.setTelefone("+2358642365478956");
        std::cout << "FALHA"<<endl;
    }
    catch (std::invalid_argument &ex) {
        std::cout << "SUCESSO"<<endl;
    }

}


///@brief Método para testar a senha do desenvolvedor.


void TesteSenha::rodarTestes(){

    Desenvolvedor validador;


    ///Teste 1: valor invalido.

    try {
        validador.setSenha("abc12");
        std::cout << "FALHA" <<endl;
    }
    catch (std::invalid_argument &ex) {
        std::cout <<"SUCESSO"<<endl;
    }

    ///Teste 2:valor valido.

    try {
        validador.setSenha("A#$%&@");
        std::cout << "SUCESSO" <<endl;

    }
    catch (std::invalid_argument &ex) {
        std::cout <<"FALHA"<<endl;
    }

    ///Teste 3: metodo getSenha.

    if(validador.getSenha()=="A#$%&@"){
        std::cout << "SUCESSO" <<endl;
    }
    else{
        std::cout <<"FALHA"<<endl;
    }


}


///@brief Método para testar a matricula do desenvolvedor.


void TesteMatricula::rodarTestes(){

    Desenvolvedor validador;

    ///Teste 1: valor invalido.

    try{
        validador.setMatricula("123456b");
        std::cout <<"FALHA"<<endl;
    }
    catch(std::invalid_argument &ex){
        std::cout <<"SUCESSO"<<endl;
    }

    ///Teste 2: valor valido.

    try{
        validador.setMatricula("1234567");
        std::cout <<"SUCESSO"<<endl;
    }
    catch(std::invalid_argument &ex){
        std::cout <<"fALHA"<<endl;
    }

    ///Teste 3: metodo getMatricula.
    if(validador.getMatricula()=="1234567"){
        std::cout <<"SUCESSO"<<endl;
    }
    else{
        std::cout <<"fALHA"<<endl;
    }

}
