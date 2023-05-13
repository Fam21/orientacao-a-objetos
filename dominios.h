
///@file dominios.h
///@brief Definição das classes que representam as entidades do domínio.


#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

class Classe{
private:
    std::string classe;
public:
    void setClasse(std::string classe);
    std::string getClasse() const;

};


///@brief Classe que representa um resultado que pode ser "APROVADO" ou "REPROVADO".


class Resultado{

private:
    std::string resultado;

public:
    void setResultado(std::string resultado);
    std::string getResultado() const;
};


class Data {
    private:
        std::string data;
        int dia;
        std::string mes;
        int ano;
        bool ehBissexto(int ano);

    public:

        void setData(std::string data);
        std::string getData() const;
};


class Codigo {
private:
    std::string codigo;
    const static int TAMANHO = 6;
    const static int LETRAS = 3;
    const static int DIGITOS = 3;

    bool validarLetra(char letra);
    bool validarDigito(char digito);

public:

///@brief Construtor padrão da classe Codigo.

    Codigo();
    Codigo(std::string codigo);

    void setCodigo(std::string codigo);

    std::string getCodigo() const;

    void validar();

};

class Texto{
private:
    std::string texto;
    const int TAMANHO_MAXIMO = 20;
    const int TAMANHO_MINIMO = 10;
public:
    void setTexto(std::string texto);
    std::string getTexto() const;
};

#endif // DOMINIOS_H_INCLUDED
