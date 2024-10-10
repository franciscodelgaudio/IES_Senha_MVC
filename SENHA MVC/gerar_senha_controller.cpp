#include "gerar_senha_controller.h"
#include <iostream>

// Construtor da classe GerarSenhaController.
// Pré-condição: Model e View devem ser instanciados corretamente.
// Pós-condição: O controlador é inicializado com referências para o model e a view.
GerarSenhaController::GerarSenhaController(GerarSenhaModel& model, GerarSenhaView& view) : model(model), view(view) {}

// Executa o loop principal do programa, gerenciando a navegação entre os menus.
// Pré-condição: Model e View devem estar inicializados corretamente.
// Pós-condição: O menu principal é exibido repetidamente até o usuário optar por sair.
void GerarSenhaController::executar() {
    int escolha;
    do {
        view.exibirMenuPrincipal();
        while (!(cin >> escolha)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            view.exibirMensagem("Entrada inválida. Tente novamente:");
        }

        switch (escolha) {
            case 1:
                menuAdministrador();
                break;
            case 2:
                menuAtendente();
                break;
            case 3:
                menuCliente();
                break;
            case 0:
                view.exibirMensagem("Saindo...");
                break;
            default:
                view.exibirMensagem("Opção inválida!");
        }
    } while (escolha != 0);
}

// Exibe e gerencia o menu do administrador, permitindo a adição e listagem de atendentes.
// Pré-condição: Model e View devem estar inicializados e o administrador deve ter acesso ao menu.
// Pós-condição: O menu administrador é exibido repetidamente até o usuário optar por voltar ao menu principal.
void GerarSenhaController::menuAdministrador() {
    int escolha;
    do {
        view.exibirMenuAdministrador();
        while (!(cin >> escolha)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            view.exibirMensagem("Entrada inválida. Tente novamente:");
        }

        switch (escolha) {
            case 1: {
                string nome = view.obterEntradaTexto("Digite o nome do atendente: ");
                string senha = view.obterEntradaTexto("Digite a senha: ");
                // Adiciona um novo atendente se o nome não estiver em uso.
                if (model.adicionarAtendente(nome, senha)) {
                    view.exibirMensagem("Atendente adicionado com sucesso.");
                } else {
                    view.exibirMensagem("Nome de atendente já existente. Tente outro.");
                }
                break;
            }
            case 2: {
                vector<string> atendentes = model.listarAtendentes();
                view.exibirMensagem("Lista de Atendentes:");
                for (const auto& nome : atendentes) {
                    view.exibirMensagem(nome);
                }
                break;
            }
            case 0:
                view.exibirMensagem("Voltando ao menu principal...");
                break;
            default:
                view.exibirMensagem("Opção inválida!");
        }
    } while (escolha != 0);
}

// Exibe e gerencia o menu do atendente, permitindo chamar senhas.
// Pré-condição: Model e View devem estar inicializados, e o atendente deve autenticar-se com sucesso.
// Pós-condição: O menu atendente é exibido repetidamente até o usuário optar por voltar ao menu principal.
void GerarSenhaController::menuAtendente() {
    string nome = view.obterEntradaTexto("Digite o nome do atendente: ");
    string senha = view.obterEntradaTexto("Digite a senha: ");
    
    // Valida as credenciais do atendente.
    if (model.validarAtendente(nome, senha)) {
        view.exibirMensagem("Login realizado com sucesso.");
        int escolha;
        do {
            view.exibirMenuAtendente();
            while (!(cin >> escolha)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                view.exibirMensagem("Entrada inválida. Tente novamente:");
            }

            switch (escolha) {
                case 1: {
                    // Chama a próxima senha normal.
                    string senhaChamada = model.chamarProxima(true);
                    if (!senhaChamada.empty()) {
                        view.exibirMensagem("Senha chamada: " + senhaChamada);
                    } else {
                        view.exibirMensagem("Nenhuma senha disponível.");
                    }
                    break;
                }
                case 2: {
                    // Chama a próxima senha preferencial.
                    string senhaChamada = model.chamarProxima(true);
                    if (!senhaChamada.empty()) {
                        view.exibirMensagem("Senha chamada: " + senhaChamada);
                    } else {
                        view.exibirMensagem("Nenhuma senha disponível.");
                    }
                    break;
                }
                case 0:
                    view.exibirMensagem("Voltando ao menu principal...");
                    break;
                default:
                    view.exibirMensagem("Opção inválida!");
            }
        } while (escolha != 0);
    } else {
        view.exibirMensagem("Credenciais inválidas. Digite 0 para voltar ao menu principal ou tente novamente.");
        string retry = view.obterEntradaTexto("Nome: ");
        if (retry == "0") return;
        string retrySenha = view.obterEntradaTexto("Senha: ");
        if (model.validarAtendente(retry, retrySenha)) {
            menuAtendente();
        }
    }
}

// Exibe e gerencia o menu do cliente, permitindo gerar senhas e visualizar senhas disponíveis.
// Pré-condição: Model e View devem estar inicializados corretamente.
// Pós-condição: O menu cliente é exibido repetidamente até o usuário optar por voltar ao menu principal.
void GerarSenhaController::menuCliente() {
    int escolha;
    do {
        view.exibirMenuCliente();
        while (!(cin >> escolha)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            view.exibirMensagem("Entrada inválida. Tente novamente:");
        }

        switch (escolha) {
            case 1: {
                // Gera uma senha normal.
                string senha = model.gerarSenha(false);
                model.adicionarSenha(false);
                view.exibirMensagem("Senha normal gerada: " + senha);
                break;
            }
            case 2: {
                // Gera uma senha preferencial.
                string senha = model.gerarSenha(true);
                model.adicionarSenha(true);
                view.exibirMensagem("Senha preferencial gerada: " + senha);
                break;
            }
            case 3: {
                // Lista as senhas disponíveis.
                vector<string> senhas = model.listarSenhas();
                if (!senhas.empty()) {
                    view.exibirMensagem("Senhas disponíveis:");
                    for (const auto& senha : senhas) {
                        view.exibirMensagem(senha);
                    }
                } else {
                    view.exibirMensagem("Nenhuma senha disponível.");
                }
                break;
            }
            case 0:
                view.exibirMensagem("Voltando ao menu principal...");
                break;
            default:
                view.exibirMensagem("Opção inválida!");
        }
    } while (escolha != 0);
}
