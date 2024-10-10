# Sistema de Gerenciamento de Senhas

Este é um sistema simples de gerenciamento de senhas utilizando o padrão MVC (Model-View-Controller). O sistema permite que diferentes tipos de usuários (administradores, atendentes e clientes) interajam com o sistema para gerar e chamar senhas, bem como para gerenciar atendentes.

## Estrutura do Projeto

O projeto está dividido em três componentes principais, seguindo o padrão MVC:

- **Model**: Gerencia a lógica de negócios e armazenamento de dados, como filas de senhas e atendentes.
- **View**: Gerencia a interface com o usuário, exibindo menus e capturando entradas.
- **Controller**: Faz a ponte entre o Model e a View, gerenciando as interações e a lógica de fluxo do sistema.

## Como Compilar e Executar

1. Certifique-se de que você tem o **g++** instalado no seu sistema.
2. No terminal, navegue até a pasta principal do projeto e execute o seguinte comando para compilar o projeto:

   ```bash
   g++ *.cpp -o main.exe
