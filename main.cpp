#include "aplicacao.hpp"
using namespace std;

int main(){
    Aplicacao aplicacao;
    short int escolha = 0;

    while (true){
        system("clear");
        cout << "[ 1 ] Mostrar\n[ 2 ] Adicionar\n[ 3 ] Editar\n[ 4 ] Deletar\n[ 5 ] Sair" << endl;
        cin >> escolha;

        switch (escolha){
            case 1:
                aplicacao.mostrar();
                system("read -p \"Pressione enter para sair\" saindo");
                break;
            case 2:
                aplicacao.adicionar();
                break;
            case 3:
                aplicacao.editar();
                break;
            case 4:
                aplicacao.deletar();
                break;
            case 5:
                aplicacao.~Aplicacao();
                exit(0);
        }
    }
    return 0;
}