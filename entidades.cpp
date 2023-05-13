
///@file entidades.cpp
///@brief Implementação dos métodos da classe Desenvolvedor.
///@details Os métodos definidos nesta classe são responsáveis por definir e obter os atributos de um Desenvolvedor.


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


///@brief Obtém o nome do Desenvolvedor.
///@return Nome do desenvolvedor.


std::string Desenvolvedor::getNome() const {
    return nome;
}



///@brief Define a matrícula do Desenvolvedor.
///@param valor Matrícula do Desenvolvedor.
///@throw invalid_argument Se a matrícula não tiver 7 caracteres,ou não for composta apenas por dígitos,ou se o dígito verificador estiver incorreto.



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
 @brief Obtém a matrícula do Desenvolvedor.
 @return Matrícula do desenvolvedor.
*/

std::string Desenvolvedor::getMatricula() const {
    return matricula;
}


///@brief Define o telefone do Desenvolvedor.
///@param telefone Telefone do Desenvolvedor.
///@throw invalid_argument Se o número de telefone não tiver entre 8 e 15 caracteres,ou não começar com o caractere '+',ou se não for composto apenas por dígitos.


void Desenvolvedor::setTelefone(std::string telefone) {
    if (telefone.size() < 8 || telefone.size() > 15) {
        this->telefone = "";
        throw std::invalid_argument("Número de telefone inválido.");
    }

    if (telefone[0] != '+') {
        this->telefone = "";
        throw std::invalid_argument("Número de telefone inválido.");
    }

    for (size_t i = 1; i < telefone.size(); i++) {
        if (!isdigit(telefone[i])) {
            this->telefone = "";
            throw std::invalid_argument("Número de telefone inválido.");
        }
    }

    this->telefone = telefone;
}


///@brief Obtém o telefone do Desenvolvedor.
///@return Telefone do desenvolvedor.


std::string Desenvolvedor::getTelefone() const {
    return this->telefone;

}

///@brief Define uma senha para o desenvolvedor.
///@param senha A senha a ser definida.
///@throws std::invalid_argument Se a senha não tiver o tamanho correto ou contiver caracteres inválidos ou duplicados.

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


///@brief Obtém a senha do desenvolvedor.
///@return A senha atual do desenvolvedor.


std::string Desenvolvedor::getSenha() const{
    return this->senha;
}

