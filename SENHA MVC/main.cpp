#include "gerar_senha_model.h"
#include "gerar_senha_view.h"
#include "gerar_senha_controller.h"

int main() {
    GerarSenhaModel model;
    GerarSenhaView view;
    GerarSenhaController controller(model, view);

    controller.executar();

    return 0;
}
