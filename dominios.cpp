
 ///@file dominios.cpp
 ///@brief Implementação dos metodos de dominios.h.


#include "dominios.h"

#include <iostream>

using namespace std;



///@brief Método para definir a classe.
///@param classe classe a ser definida.



void Classe::setClasse(std::string classe){
    if(classe=="UNIDADE"||classe=="INTEGRACAO"||classe=="FUMACA"||classe=="SISTEMA"||classe=="REGRESSAO"||classe=="ACEITACAO"){
        this->classe=classe;
    }
    else{
        this->classe="";
        throw std::invalid_argument("resultado inválido.");
    }
}

std::string Classe::getClasse() const {
    return this->classe;

}


///@brief Método para definir o resultado.

void Resultado::setResultado(std::string resultado){
    if(resultado=="APROVADO"||resultado=="REPROVADO"){
        this->resultado=resultado;
    }
    else{
         this->resultado="";
        throw std::invalid_argument("resultado inválido.");
    }
}

std::string Resultado::getResultado() const {
    return this->resultado;
}


///@brief Verifica se um determinado ano é bissexto.
///@param ano O ano a ser verificado.

bool Data::ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

///@brief Método para definir a data.
///@param data A data a ser definida.


void Data::setData(std::string data) {
    int pos1 = data.find("/");
    int pos2 = data.rfind("/");
    string dia_str = data.substr(0, pos1);
    string mes_str = data.substr(pos1 + 1, pos2 - pos1 - 1);
    string ano_str = data.substr(pos2 + 1);

    int dia = stoi(dia_str);
    int ano = stoi(ano_str);

    if (ano < 2000 || ano > 2999) {
        this->dia = NULL;
        this->mes = "";
        this->ano = NULL;
        throw invalid_argument("Data invalida.");
    }

    if (!(mes_str == "JAN" || mes_str == "FEV" || mes_str == "MAR" || mes_str == "ABR" || mes_str == "MAI" || mes_str == "JUN" || mes_str == "JUL" || mes_str == "AGO" || mes_str == "SET" || mes_str == "OUT" || mes_str == "NOV" || mes_str == "DEZ")) {
        this->dia = NULL;
        this->mes = "";
        this->ano = NULL;
        throw invalid_argument("Mes invalido.");;
    }

    int dia_max = 31;
    if (mes_str == "ABR" || mes_str == "JUN" || mes_str == "SET" || mes_str == "NOV") {
        dia_max = 30;
    } else if (mes_str == "FEV") {
        if (ehBissexto(ano)) {
            dia_max = 29;
        } else {
            dia_max = 28;
        }
    }
    if (dia < 1 || dia > dia_max) {
        this->dia = NULL;
        this->mes = "";
        this->ano = NULL;
        throw invalid_argument("Data invalida.");
    }

    this->data=data;
}
std::string Data::getData() const {
    return this->data;
}


///@brief Verifica se a letra é válida para o código
///@param letra letra a ser validada


bool Codigo::validarLetra(char letra) {
    if (letra >= 'a' && letra <= 'z')
        return true;
    if (letra >= 'A' && letra <= 'Z')
        return true;
    return false;
}


///@brief Verifica se o dígito é válido para o código
///@param digito dígito a ser validado


bool Codigo::validarDigito(char digito) {
    if (digito >= '0' && digito <= '9')
        return true;
    return false;
}

///@brief Construtor padrão da classe Codigo.


Codigo::Codigo() {
    codigo = "AAA000";
}


///@brief Construtor da classe Codigo


Codigo::Codigo(std::string codigo) {
    setCodigo(codigo);
}


///@brief Seta o valor do código
///@param codigo string que representa o código


void Codigo::setCodigo(std::string codigo) {
    if (codigo.length() != TAMANHO)
        throw invalid_argument("Codigo invalido!");

    for (int i = 0; i < LETRAS; i++) {
        if (!validarLetra(codigo[i]))
            throw invalid_argument("Codigo invalido!");
    }

    for (int i = LETRAS; i < TAMANHO; i++) {
        if (!validarDigito(codigo[i]))
            throw invalid_argument("Codigo invalido!");
    }

    this->codigo = codigo;
}

void Codigo::validar() {
    setCodigo(codigo);
}
std::string Codigo::getCodigo() const {
    return codigo;
}


///@brief Verifica se o caractere é válido para o texto.
///@param texto texto a ser validado.


void Texto:: setTexto(std::string texto){
    if(texto.length() > TAMANHO_MAXIMO || texto.length() < TAMANHO_MINIMO){
        throw invalid_argument("Tamanho invalido");
    }
    for (char c : texto) {
        if (!isalnum(c) && c != '.' && c != ',' && c != ';' && c != '?' && c != '!' && c != ':' && c != '-' && c != '@' && c != '#' && c != '$' && c != '%' && c != '&') {
            throw invalid_argument("O valor do texto deve conter apenas letras, números e os caracteres . , ; ? ! : - @ # $ % &");
        }
        if (isalpha(c) && !isascii(c)) {
            throw invalid_argument("O valor do texto deve conter apenas letras sem acento");
        }
    }
    this->texto = texto;
}

std::string Texto::getTexto() const {
    return texto;
}
