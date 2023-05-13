#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include <string>

using namespace std;


///@file entidades.h
///@brief Definição da entidade Desenvolvedor e seus métodos.


class Desenvolvedor {
private:
    const static int TAMANHO = 6;

    std::string nome;
    std::string matricula;
    std::string telefone;
    std::string senha;

public:
    void setNome(std::string nome);
    void setMatricula(std::string matricula);
    void setTelefone(std::string telefone);
    void setSenha(std::string senha);

    std::string getNome() const;
    std::string getMatricula() const;
    std::string getTelefone() const;
    std::string getSenha() const;

};


#endif // ENTIDADES_H_INCLUDED
