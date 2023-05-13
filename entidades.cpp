
///@file entidades.cpp
///@brief Implementa��o dos m�todos da classe Desenvolvedor.
///@details Os m�todos definidos nesta classe s�o respons�veis por definir e obter os atributos de um Desenvolvedor.


#include <stdexcept>
#include <iostream>
#include <unordered_set>

#include "entidades.h"

using namespace std;


///@brief Define o nome do Desenvolvedor.
///@param nome Nome do desenvolvedor.


void Desenvolvedor::setNome(std::string nome) {
    this->nome = nome;
}


///@brief Obt�m o nome do Desenvolvedor.
///@return Nome do desenvolvedor.


std::string Desenvolvedor::getNome() const {
    return nome;
}



///@brief Define a matr�cula do Desenvolvedor.
///@param valor Matr�cula do Desenvolvedor.
///@throw invalid_argument Se a matr�cula n�o tiver 7 caracteres,ou n�o for composta apenas por d�gitos,ou se o d�gito verificador estiver incorreto.



void Desenvolvedor::setMatricula(string valor) {
    int digitos[7];
    int soma = 0;

    if (valor.length() != 7) {
        throw invalid_argument("A matricula deve ter 7 caracteres.");
    }
    int j=1;
    for (int i = 0; i < 6; i++) {
        if (!isdigit(valor[i])) {
            throw invalid_argument("A matricula deve conter apenas digitos.");
        }
        digitos[i] = valor[i] - '0';
        if(j%2==0){
            soma += digitos[i] * 2;
        }
        else{
            soma+=digitos[i];
        }
        j+=1;
    }

    if (!isdigit(valor[6])) {
        throw invalid_argument("O digito verificador deve ser um digito.");
    }
    digitos[6] = valor[6] - '0';

    int resto = soma % 10;
    int verificador = resto == 0 ? 0 : 10 - resto;

    if (verificador != digitos[6]) {
        throw invalid_argument("Matricula invalida.");
    }
    this-> matricula = valor;
}

/**
 @brief Obt�m a matr�cula do Desenvolvedor.
 @return Matr�cula do desenvolvedor.
*/

std::string Desenvolvedor::getMatricula() const {
    return matricula;
}


///@brief Define o telefone do Desenvolvedor.
///@param telefone Telefone do Desenvolvedor.
///@throw invalid_argument Se o n�mero de telefone n�o tiver entre 8 e 15 caracteres,ou n�o come�ar com o caractere '+',ou se n�o for composto apenas por d�gitos.


void Desenvolvedor::setTelefone(std::string telefone) {
    if (telefone.size() < 8 || telefone.size() > 15) {
        this->telefone = "";
        throw std::invalid_argument("N�mero de telefone inv�lido.");
    }

    if (telefone[0] != '+') {
        this->telefone = "";
        throw std::invalid_argument("N�mero de telefone inv�lido.");
    }

    for (size_t i = 1; i < telefone.size(); i++) {
        if (!isdigit(telefone[i])) {
            this->telefone = "";
            throw std::invalid_argument("N�mero de telefone inv�lido.");
        }
    }

    this->telefone = telefone;
}


///@brief Obt�m o telefone do Desenvolvedor.
///@return Telefone do desenvolvedor.


std::string Desenvolvedor::getTelefone() const {
    return this->telefone;

}

///@brief Define uma senha para o desenvolvedor.
///@param senha A senha a ser definida.
///@throws std::invalid_argument Se a senha n�o tiver o tamanho correto ou contiver caracteres inv�lidos ou duplicados.

void Desenvolvedor::setSenha(string senha) {

    if (senha.size() != TAMANHO) {
        this->senha = "";
        throw invalid_argument("Senha: tamanho invalido");
    }

    for (char c : senha) {
        if (!isalnum(c) && c != '@' && c != '#' && c != '$' && c != '%' && c != '&') {
            this->senha = "";
            throw invalid_argument("Senha: caracteres invalidos");
        }

    }
    unordered_set<char> set;
    for (char c : senha) {
        if (set.find(c) != set.end()) {
            this->senha="";
            throw invalid_argument("Senha: caracteres duplicados");
        }
        set.insert(c);
    }
    this->senha = senha;
}


///@brief Obt�m a senha do desenvolvedor.
///@return A senha atual do desenvolvedor.


std::string Desenvolvedor::getSenha() const{
    return this->senha;
}

