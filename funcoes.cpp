#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>
#include <iostream>

void dump(const Json::Value valor){
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "   ";

    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    std::ofstream outputFileStream("data.json");
    writer -> write(valor, &outputFileStream);
}

Json::Value read(){
    using namespace std;

    ifstream arquivo("data.json");
    Json::Value jsonAtual;
    Json::Reader reader;

    reader.parse(arquivo, jsonAtual);
    return jsonAtual;
}

void mostrarData(){
    using namespace std;

    ifstream arquivo("data.json");

    Json::Value json;
    Json::Reader reader;

    reader.parse(arquivo, json);

    for (int i = 0; i < json.size(); i++){
        cout << "----------------" << endl;
        cout << "Nome: " << json[i]["NOME"] << endl << "Idade: " <<  json[i]["IDADE"] << endl << "Cor Favorita: " << json[i]["COR"] << endl;
    }
}

void adicionarData(Json::Value& jsonFinal){
    using namespace std;

    string nome;
    int idade;
    string cor;

    cout << "Nome: ";
    cin >> nome;
    cout << "Idade: ";
    cin >> idade;
    cout << "Cor Favorita: ";
    cin >> cor;

    Json::Value json;

    json["NOME"] = nome;
    json["IDADE"] = idade;
    json["COR"] = cor;

    jsonFinal.append(json);
    dump(jsonFinal);
}

void editarData(Json::Value& jsonFinal){
    using namespace std;

    string nome;
    bool existe = false;
    cout << "Nome do usuário: ";
    cin >> nome;

    for (int i = 0; i < jsonFinal.size(); i++){
        if (jsonFinal[i]["NOME"] == nome){
            int idade;
            string cor;

            cout << "Nova idade do usuário: ";
            cin >> idade;
            cout << "Nova cor favorita do usuário: ";
            cin >> cor;

            jsonFinal[i]["IDADE"] = idade;
            jsonFinal[i]["COR"] = cor;
            existe = true;
            break;
        }
    }

    if (existe){dump(jsonFinal);}
    if (!existe){cout << "Não foi possível encontrar o usuário" << endl;}
}

void deletarData(Json::Value& jsonFinal){
    using namespace std;

    int selected_item;
    bool encontrou = false;
    Json::Value new_item;
    string nome;

    cout << "Nome do usuário: ";
    cin >> nome;

    for (int i = 0; i < jsonFinal.size(); i++){
        if (jsonFinal[i]["NOME"] == nome){
            selected_item = i;
            encontrou = true;
        }
    }

    for (int i = 0; i < jsonFinal.size(); i++){
        if (i != selected_item){
            new_item.append(jsonFinal[i]);
        }
    }

    if (encontrou){
        jsonFinal = new_item;
        dump(jsonFinal);
    }
    else {cout << "Não foi possível encontrar o usuário." << endl;}
}