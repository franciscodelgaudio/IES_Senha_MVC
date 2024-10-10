#include "gerar_senha_model.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>

// Construtor da classe GerarSenhaModel.
// Inicializa o arquivo de log e carrega os atendentes do arquivo.
// Pré-condição: Os arquivos "log_senhas.txt" e "atendentes.txt" devem estar disponíveis para leitura/escrita.
// Pós-condição: O arquivo de log é aberto e os atendentes são carregados na estrutura interna.
GerarSenhaModel::GerarSenhaModel() {
    arquivoLog.open("log_senhas.txt", ios::app);
    if (!arquivoLog.is_open()) {
        cerr << "Erro ao abrir o arquivo de log." << endl;
    }
    carregarAtendentes();
}

// Destrutor da classe GerarSenhaModel.
// Salva os atendentes e fecha o arquivo de log ao destruir o objeto.
// Pré-condição: O arquivo de log deve estar aberto e os dados de atendentes devem ser válidos.
// Pós-condição: O arquivo de log é fechado e os atendentes são salvos no arquivo.
GerarSenhaModel::~GerarSenhaModel() {
    salvarAtendentes();
    arquivoLog.close();
}

// Carrega os atendentes do arquivo "atendentes.txt" e os armazena no map atendentes.
// Pré-condição: O arquivo "atendentes.txt" deve existir e estar acessível.
// Pós-condição: Os atendentes são armazenados no map para uso posterior.
void GerarSenhaModel::carregarAtendentes() {
    ifstream infile("atendentes.txt");
    string nome, senha;
    while (infile >> nome >> senha) {
        atendentes[nome] = senha;
    }
    infile.close();
}

// Salva os atendentes no arquivo "atendentes.txt".
// Pré-condição: O map atendentes deve estar preenchido com os dados dos atendentes.
// Pós-condição: Os dados dos atendentes são escritos no arquivo.
void GerarSenhaModel::salvarAtendentes() {
    ofstream outfile("atendentes.txt");
    for (const auto& pair : atendentes) {
        outfile << pair.first << " " << pair.second << "\n";
    }
    outfile.close();
}

// Gera uma senha com prefixo "P" (preferencial) ou "N" (normal) seguido de três letras e três números aleatórios.
// Pré-condição: O sistema deve estar inicializado com srand para geração de números aleatórios.
// Pós-condição: Uma string representando a senha é retornada.
string GerarSenhaModel::gerarSenha(bool preferencial) {
    return (preferencial ? "P" : "N") + string(3, 'A' + rand() % 26) + to_string(rand() % 900 + 100);
}

// Adiciona uma senha à fila preferencial ou normal, dependendo do parâmetro.
// Também registra a senha no arquivo de log, se disponível.
// Pré-condição: O arquivo de log deve estar aberto e pronto para escrita.
// Pós-condição: A senha é adicionada à fila correspondente e registrada no log com a data e hora atuais.
void GerarSenhaModel::adicionarSenha(bool preferencial) {
    string senha = gerarSenha(preferencial);
    if (preferencial) {
        filaPreferencial.push(senha);
    } else {
        filaNormal.push(senha);
    }

    // Registrar no log após adicionar à fila
    if (arquivoLog.is_open()) {
        time_t agora = time(0);
        char* dt = ctime(&agora);
        arquivoLog << "Gerada: " << senha << " em " << dt;
    } else {
        cerr << "Arquivo de log não está aberto." << endl;
    }
}

// Chama a próxima senha disponível (preferencial, se existir; caso contrário, normal).
// Se remover for verdadeiro, a senha é removida da fila após ser chamada.
// Pré-condição: As filas de senhas devem estar inicializadas.
// Pós-condição: A próxima senha disponível é retornada e, se solicitado, removida da fila.
string GerarSenhaModel::chamarProxima(bool remover) {
    string proxima;
    if (!filaPreferencial.empty()) {
        proxima = filaPreferencial.front();
        if (remover) filaPreferencial.pop();
    } else if (!filaNormal.empty()) {
        proxima = filaNormal.front();
        if (remover) filaNormal.pop();
    }

    // Atualizar o log se uma senha for chamada
    if (!proxima.empty() && remover) {
        if (arquivoLog.is_open()) {
            time_t agora = time(0);
            char* dt = ctime(&agora);
            arquivoLog << "Chamada: " << proxima << " em " << dt;
        } else {
            cerr << "Arquivo de log não está aberto." << endl;
        }
    }

    return proxima;
}

// Adiciona um atendente ao map de atendentes se o nome não existir ainda.
// Pré-condição: O map atendentes deve estar inicializado.
// Pós-condição: Retorna verdadeiro se o atendente foi adicionado com sucesso; falso caso o nome já exista.
bool GerarSenhaModel::adicionarAtendente(const string& nome, const string& senha) {
    if (atendentes.find(nome) != atendentes.end()) {
        return false; // Usuário já existe
    }
    atendentes[nome] = senha;
    return true;
}

// Valida se as credenciais do atendente estão corretas.
// Pré-condição: O map atendentes deve estar carregado com os dados.
// Pós-condição: Retorna verdadeiro se as credenciais forem válidas, falso caso contrário.
bool GerarSenhaModel::validarAtendente(const string& nome, const string& senha) {
    auto it = atendentes.find(nome);
    if (it != atendentes.end() && it->second == senha) {
        return true;
    }
    return false;
}

// Retorna uma lista contendo todos os nomes dos atendentes cadastrados.
// Pré-condição: O map atendentes deve estar carregado com os dados.
// Pós-condição: Um vetor com os nomes dos atendentes é retornado.
vector<string> GerarSenhaModel::listarAtendentes() {
    vector<string> lista;
    for (const auto& pair : atendentes) {
        lista.push_back(pair.first);
    }
    return lista;
}

// Retorna uma lista contendo todas as senhas disponíveis nas filas preferencial e normal.
// Pré-condição: As filas de senhas devem estar inicializadas.
// Pós-condição: Um vetor contendo todas as senhas é retornado.
vector<string> GerarSenhaModel::listarSenhas() {
    vector<string> todasSenhas;

    // Copiar as senhas da fila preferencial
    queue<string> filaTempPreferencial = filaPreferencial;
    while (!filaTempPreferencial.empty()) {
        todasSenhas.push_back(filaTempPreferencial.front());
        filaTempPreferencial.pop();
    }

    // Copiar as senhas da fila normal
    queue<string> filaTempNormal = filaNormal;
    while (!filaTempNormal.empty()) {
        todasSenhas.push_back(filaTempNormal.front());
        filaTempNormal.pop();
    }

    return todasSenhas;
}
