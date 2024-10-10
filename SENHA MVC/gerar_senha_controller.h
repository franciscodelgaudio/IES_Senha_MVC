#ifndef GERAR_SENHA_CONTROLLER_H
#define GERAR_SENHA_CONTROLLER_H

#include "gerar_senha_model.h"
#include "gerar_senha_view.h"
#include <limits>
#include <string>

using namespace std;

// Classe responsável por controlar o fluxo entre a model e a view.
// Pré-condição: Os objetos de GerarSenhaModel e GerarSenhaView devem ser instanciados corretamente.
// Pós-condição: A classe GerarSenhaController fornece a funcionalidade de gerenciar e exibir menus,
// manipulando as interações do usuário para geração e controle de senhas.
class GerarSenhaController {
private:
    GerarSenhaModel& model; // Referência ao model que gerencia a lógica de senhas.
    GerarSenhaView& view;   // Referência à view que gerencia a interface com o usuário.

public:
    // Construtor da classe GerarSenhaController.
    // Pré-condição: Model e View devem ser passados por referência e estar instanciados corretamente.
    // Pós-condição: O controlador é inicializado com as referências ao model e à view.
    GerarSenhaController(GerarSenhaModel& model, GerarSenhaView& view);

    // Método que executa o loop principal do programa, gerenciando a navegação entre os menus.
    // Pré-condição: A model e a view devem estar inicializadas corretamente.
    // Pós-condição: O programa apresenta o menu principal e interage com o usuário até que ele opte por sair.
    void executar();

    // Método que exibe e gerencia o menu do administrador.
    // Pré-condição: Model e View devem estar inicializados, e o administrador deve ter acesso.
    // Pós-condição: Permite ao administrador adicionar e listar atendentes até optar por voltar ao menu principal.
    void menuAdministrador();

    // Método que exibe e gerencia o menu do atendente, permitindo o login e a chamada de senhas.
    // Pré-condição: Model e View devem estar inicializados, e o atendente deve autenticar-se corretamente.
    // Pós-condição: Permite ao atendente chamar senhas disponíveis até optar por voltar ao menu principal.
    void menuAtendente();

    // Método que exibe e gerencia o menu do cliente, permitindo gerar e visualizar senhas.
    // Pré-condição: Model e View devem estar inicializados corretamente.
    // Pós-condição: Permite ao cliente gerar senhas e visualizar as disponíveis até optar por voltar ao menu principal.
    void menuCliente();
};

#endif
