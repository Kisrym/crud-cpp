#include <iostream>

#include "headers/adicionarData.hpp"
#include "headers/mostrarData.hpp"
#include "headers/read.hpp"
#include "headers/editarData.hpp"
#include "headers/deletarData.hpp"

using namespace std;

int main(){
    int escolha;
    char tmp;
    while (true){
        static Json::Value jsonFinal = read();
        cout << "1 - Ver Dados" << endl << "2 - Adicionar Dados" << endl << "3 - Editar Dados" << endl << "4 - Deletar Dado" << endl << "5 - Sair" << endl;
        cin >> escolha;

        switch (escolha){
            case 1:
                mostrarData();
                cout << "Digite qualquer coisa para continuar ";
                cin >> tmp;
                system("clear");
                break;

            case 2:
                adicionarData(jsonFinal);
                cout << "Digite qualquer coisa para continuar ";
                cin >> tmp;
                system("clear");
                break;
            
            case 3:
                editarData(jsonFinal);
                cout << "Digite qualquer coisa para continuar ";
                cin >> tmp;
                system("clear");
                break;
            
            case 4:
                deletarData(jsonFinal);
                cout << "Digite qualquer coisa para continuar ";
                cin >> tmp;
                system("clear");
                break;

            case 5:
                cout << "Saindo..." << endl;
                exit(0);
        }
    }
    return 0;
}