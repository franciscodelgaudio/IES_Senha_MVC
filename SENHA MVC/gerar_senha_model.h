#ifndef GERAR_SENHA_MODEL_H
#define GERAR_SENHA_MODEL_H

#include <queue>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

// Classe que gerencia a lógica de geração de senhas e administração de atendentes.
// Pré-condição: O sistema deve estar configurado corretamente com acesso aos arquivos necessários.
// Pós-condição: A classe GerarSenhaModel gerencia as filas de senhas, os atendentes e o arquivo de log.
class GerarSenhaModel {
private:
    queue<string> filaNormal;         // Fila para senhas normais.
    queue<string> filaPreferencial;   // Fila para senhas preferenciais.
    ofstream arquivoLog;              // Arquivo de log para registrar atividades.
    map<string, string> atendentes;   // Mapa para armazenar atendentes e suas senhas.

    // Carrega os atendentes a partir do arquivo "atendentes.txt".
    // Pré-condição: O arquivo deve existir e estar acessível.
    // Pós-condição: O mapa de atendentes é preenchido com os dados lidos do arquivo.
    void carregarAtendentes();

    // Salva os atendentes no arquivo "atendentes.txt".
    // Pré-condição: O mapa de atendentes deve estar preenchido corretamente.
    // Pós-condição: Os dados são gravados no arquivo, atualizando a lista de atendentes.
    void salvarAtendentes();

public:
    // Construtor da classe GerarSenhaModel.
    // Inicializa o sistema e carrega os atendentes do arquivo.
    // Pré-condição: O arquivo "atendentes.txt" e o arquivo de log devem estar disponíveis.
    // Pós-condição: A classe é inicializada e os atendentes são carregados para uso.
    GerarSenhaModel();

    // Destrutor da classe GerarSenhaModel.
    // Salva os atendentes e fecha o arquivo de log ao destruir o objeto.
    // Pré-condição: O arquivo de log deve estar aberto e os atendentes devem estar carregados corretamente.
    // Pós-condição: O arquivo de log é fechado e os atendentes são salvos no arquivo.
    ~GerarSenhaModel();

    // Gera uma senha preferencial ou normal.
    // Pré-condição: O sistema deve estar inicializado com srand para geração de números aleatórios.
    // Pós-condição: Retorna uma senha como string, começando com "P" ou "N" seguido por uma sequência aleatória.
    string gerarSenha(bool preferencial);

    // Adiciona uma senha à fila preferencial ou normal e registra no log.
    // Pré-condição: A fila correspondente deve estar inicializada e o arquivo de log deve estar aberto.
    // Pós-condição: A senha é adicionada à fila e registrada no log com a data e hora atuais.
    void adicionarSenha(bool preferencial);

    // Chama a próxima senha disponível (preferencial ou normal) e remove da fila, se solicitado.
    // Pré-condição: As filas de senhas devem estar inicializadas.
    // Pós-condição: Retorna a próxima senha e, se remover for verdadeiro, ela é removida da fila.
    string chamarProxima(bool remover = true);

    // Adiciona um novo atendente se o nome ainda não existir.
    // Pré-condição: O mapa de atendentes deve estar inicializado.
    // Pós-condição: Retorna verdadeiro se o atendente for adicionado com sucesso, falso se o nome já existir.
    bool adicionarAtendente(const string& nome, const string& senha);

    // Valida as credenciais de um atendente.
    // Pré-condição: O mapa de atendentes deve estar preenchido com os dados.
    // Pós-condição: Retorna verdadeiro se as credenciais forem válidas, falso caso contrário.
    bool validarAtendente(const string& nome, const string& senha);

    // Retorna uma lista de todos os nomes dos atendentes cadastrados.
    // Pré-condição: O mapa de atendentes deve estar preenchido corretamente.
    // Pós-condição: Um vetor contendo os nomes dos atendentes é retornado.
    vector<string> listarAtendentes();

    // Retorna uma lista de todas as senhas disponíveis nas filas (normal e preferencial).
    // Pré-condição: As filas de senhas devem estar inicializadas.
    // Pós-condição: Um vetor contendo todas as senhas disponíveis é retornado.
    vector<string> listarSenhas();
};

#endif
