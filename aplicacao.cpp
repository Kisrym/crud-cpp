#include "aplicacao.hpp"

Aplicacao::Aplicacao(){
    file.open("data.json", std::ios::out | std::ios::in);
    try {
        data = json::parse(file);
    }
    catch (nlohmann::json_abi_v3_11_2::detail::parse_error){}
}

Aplicacao::~Aplicacao(){
    file.close();
    
    // Limpar o arquivo
    std::ofstream f("data.json");
    f.close();

    file.open("data.json");
    file << data.dump(4);
    file.close();
}

// Funções

void Aplicacao::adicionar(){
    using namespace std;

    string nome;
    string cor;

    cout << "Nome: ";
    cin >> nome;
    cout << "Idade: ";
    cin >> data[nome]["Idade"];
    cout << "Cor favorita: ";
    cin >> cor;
    data[nome]["Cor"] = cor;
}

void Aplicacao::mostrar() const{
    std::cout << "----------------------" << std::endl;
    for (auto i : data.items()){
        std::cout << "Nome: " << i.key() << std::endl;
        for (auto it : data[i.key()].items()){
            std::cout << it.key() << ": " << it.value() << std::endl;
        }
        std::cout << "----------------------" << std::endl;
    }
}

void Aplicacao::deletar(){
    std::string nome;
    this->mostrar();

    std::cout << std::endl << "Quem queres deletar?";
    std::cin >> nome;

    data.erase(nome);
}

void Aplicacao::editar(){
    std::string nome;

    std::string novo_nome;
    std::string nova_cor;

    this->mostrar();

    std::cout << std::endl << "Quem queres editar?";
    std::cin >> nome;

    data.erase(nome);

    std::cout << "Novo nome: ";
    std::cin >> novo_nome;

    std::cout << "Nova idade: ";
    std::cin >> data[novo_nome]["Idade"];

    std::cout << "Nova cor favorita: ";
    std::cin >> nova_cor;
    data[novo_nome]["Cor"] = nova_cor;
}