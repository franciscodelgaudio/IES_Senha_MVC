// gerar_senha_view.h
#ifndef GERAR_SENHA_VIEW_H
#define GERAR_SENHA_VIEW_H

#include <string>
using namespace std;

// Classe responsável por exibir menus e interagir com o usuário através de mensagens e entradas.
// Pré-condição: O sistema deve estar configurado corretamente para entrada e saída de dados.
// Pós-condição: A classe GerarSenhaView permite a exibição de menus e captura de entradas do usuário.
class GerarSenhaView {
public:
    // Exibe o menu principal para o usuário escolher o tipo de acesso.
    // Pré-condição: Nenhuma.
    // Pós-condição: O menu principal é exibido e uma opção é solicitada ao usuário.
    void exibirMenuPrincipal();

    // Exibe o menu do administrador, permitindo adicionar e listar atendentes.
    // Pré-condição: O usuário deve ter permissão de administrador.
    // Pós-condição: O menu do administrador é exibido e uma opção é solicitada ao usuário.
    void exibirMenuAdministrador();

    // Exibe o menu do atendente, permitindo chamar senhas normais ou preferenciais.
    // Pré-condição: O usuário deve ter permissão de atendente.
    // Pós-condição: O menu do atendente é exibido e uma opção é solicitada ao usuário.
    void exibirMenuAtendente();

    // Exibe o menu do cliente, permitindo gerar e consultar senhas.
    // Pré-condição: O usuário deve ser cliente.
    // Pós-condição: O menu do cliente é exibido e uma opção é solicitada ao usuário.
    void exibirMenuCliente();

    // Exibe uma mensagem genérica para o usuário.
    // Pré-condição: A mensagem deve ser passada como string.
    // Pós-condição: A mensagem é exibida na tela.
    void exibirMensagem(const string& mensagem);

    // Obtém a opção numérica escolhida pelo usuário.
    // Pré-condição: O usuário deve digitar um valor numérico válido.
    // Pós-condição: Retorna a opção escolhida pelo usuário.
    int obterOpcao();

    // Exibe uma mensagem e obtém uma entrada de texto do usuário.
    // Pré-condição: O texto informativo deve ser passado como string.
    // Pós-condição: Retorna a entrada de texto digitada pelo usuário.
    string obterEntradaTexto(const string& mensagem);
};

#endif
