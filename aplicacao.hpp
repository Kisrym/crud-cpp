#include <nlohmann/json.hpp>

#include <fstream>
#include <string>
#include <iostream>

using json = nlohmann::json;

class Aplicacao{
private:
    std::fstream file;
    json data;

public:
    Aplicacao();
    ~Aplicacao();

    void mostrar() const;
    void adicionar();
    void deletar();
    void editar();
};