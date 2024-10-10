// gerar_senha_view.cpp
#include "gerar_senha_view.h"
#include <iostream>

// Exibe o menu principal para o usuário escolher o tipo de acesso.
// Pré-condição: Nenhuma.
// Pós-condição: O menu principal é exibido e uma opção é solicitada ao usuário.
void GerarSenhaView::exibirMenuPrincipal() {
    cout << "Selecione o tipo de usuário:\n";
    cout << "1. Administrador\n";
    cout << "2. Atendente\n";
    cout << "3. Cliente\n";
    cout << "0. Sair\n";
    cout << "Opção: ";
}

// Exibe o menu para o administrador, permitindo adicionar e listar atendentes.
// Pré-condição: O usuário deve ter permissão de administrador.
// Pós-condição: O menu do administrador é exibido e uma opção é solicitada ao usuário.
void GerarSenhaView::exibirMenuAdministrador() {
    cout << "Menu Administrador:\n";
    cout << "1. Adicionar Atendente\n";
    cout << "2. Listar Atendentes\n";
    cout << "0. Voltar ao menu principal\n";
    cout << "Opção: ";
}

// Exibe o menu para o atendente, permitindo chamar senhas normais ou preferenciais.
// Pré-condição: O usuário deve ter permissão de atendente.
// Pós-condição: O menu do atendente é exibido e uma opção é solicitada ao usuário.
void GerarSenhaView::exibirMenuAtendente() {
    cout << "Menu Atendente:\n";
    cout << "1. Chamar Senha Normal\n";
    cout << "2. Chamar Senha Preferencial\n";
    cout << "0. Voltar ao menu principal\n";
    cout << "Opção: ";
}

// Exibe o menu para o cliente, permitindo gerar e consultar senhas.
// Pré-condição: O usuário deve ser cliente.
// Pós-condição: O menu do cliente é exibido e uma opção é solicitada ao usuário.
void GerarSenhaView::exibirMenuCliente() {
    cout << "Menu Cliente:\n";
    cout << "1. Gerar Senha Normal\n";
    cout << "2. Gerar Senha Preferencial\n";
    cout << "3. Consultar Fila de Senhas\n";
    cout << "0. Voltar ao menu principal\n";
    cout << "Opção: ";
}

// Exibe uma mensagem genérica para o usuário.
// Pré-condição: A mensagem deve ser passada como string.
// Pós-condição: A mensagem é exibida na tela.
void GerarSenhaView::exibirMensagem(const string& mensagem) {
    cout << mensagem << endl;
}

// Obtém a opção numérica escolhida pelo usuário.
// Pré-condição: O usuário deve ter digitado um valor numérico válido.
// Pós-condição: Retorna a opção escolhida pelo usuário.
int GerarSenhaView::obterOpcao() {
    int opcao;
    cin >> opcao;
    return opcao;
}

// Exibe uma mensagem e obtém uma entrada de texto do usuário.
// Pré-condição: O texto informativo deve ser passado como string.
// Pós-condição: Retorna a entrada de texto digitada pelo usuário.
string GerarSenhaView::obterEntradaTexto(const string& mensagem) {
    string entrada;
    cout << mensagem;
    cin >> entrada;
    return entrada;
}
