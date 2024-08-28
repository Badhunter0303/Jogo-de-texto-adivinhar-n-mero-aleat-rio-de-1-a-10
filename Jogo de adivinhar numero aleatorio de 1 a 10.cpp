
#include <iostream>
#include <vector>
#include <string>
#include <random>

bool isPrime(int number)    // Eu peguei da internet || Para saber se o número é primo
{

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;
}

int main()
{

    int pontuacao_jogador {0};

    int pontuacao_computador {0};

    std::string nome_do_jogador;

    bool nao_perguntar_nome_de_novo = false; // Inicializada aqui para que o programa não pergunte o nome do jogador + de uma vez

    while (1)   // Se o jogador quiser jogar novamente
    {
        std::vector<std::string> perguntas_lista = {""};

        std::vector<int> perguntas_disponibilidade = {0};

        {   // Perguntas

            perguntas_lista.push_back("\n 1. O número é par? \n");

            perguntas_lista.push_back("\n 2. O número é maior que 5? \n");

            perguntas_lista.push_back("\n 3. O número é primo? \n");

            perguntas_lista.push_back("\n 4. O número é divisível por 3? \n");

            perguntas_lista.push_back("\n 5. O número é divisível por 5? \n");

            perguntas_lista.push_back("\n 6. O número é quadrado perfeito? \n");

            perguntas_lista.push_back("\n 7. O número é menor que 6? \n");
        }

        for (int n {0}; n < perguntas_lista.size() - 1; ++n)
        {
            perguntas_disponibilidade.push_back(1);
        }

        std::cout << "\n\n\n Jogo de Matemática/Lógica: o computador vai pensar em um número natural aleatório de 1 a 10, você terá \n" << " que adivinhar o número podendo fazer até 3 perguntas. \n";

        if (nao_perguntar_nome_de_novo == false)
        {
            nao_perguntar_nome_de_novo = true;

            std::cout << "\n Por favor, digite seu nome: ";

            while (1)
            {
                std::cin >> nome_do_jogador;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();
                }

                std::cout << "\n Seu nome é " << nome_do_jogador << "? Correto? Digite 'Sim' ou 'Não' ";

                std::string confirmacao;

                while (1)
                {
                    std::cin >> confirmacao;

                    if (confirmacao == "Sim" || confirmacao == "SIM" || confirmacao == "sim" || confirmacao == "sIM")
                        break;

                    if (confirmacao == "Não" || confirmacao == "Nao" || confirmacao == "não" || confirmacao == "nao" || confirmacao == "NAO" || confirmacao == "nAO")
                        break;

                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore();
                    }
                }

                if (confirmacao == "Sim" || confirmacao == "SIM" || confirmacao == "sim" || confirmacao == "sIM")
                    break;

                if (confirmacao == "Não" || confirmacao == "Nao" || confirmacao == "não" || confirmacao == "nao" || confirmacao == "NAO" || confirmacao == "nAO")
                    std::cout << "\n Por favor, digite seu nome novamente: ";
            }

            std::cout << "\n Olá " << nome_do_jogador << "!\n\n";

        }

        std::random_device rd;

        std::uniform_int_distribution<int> distribution_1(1, 10);

        int numero_computador = distribution_1(rd); // número (aleatório de 1 a 10) que o computador "pensou".

        bool numero_par;

        bool numero_maior_que_5;

        bool numero_primo;

        bool numero_divisivel_por_3;

        bool numero_divisivel_por_5;

        bool numero_quadrado_perfeito;

        bool numero_menor_que_6;

        {   // Descobrindo propriedades sobre o número que o computador "pensou"

            if (numero_computador % 2 == 0)
                numero_par = true;
            else numero_par = false;

            if (numero_computador > 5)
                numero_maior_que_5 = true;
            else numero_maior_que_5 = false;

            if (isPrime(numero_computador) == true)
                numero_primo = true;
            else numero_primo = false;

            if (numero_computador % 3 == 0)
                numero_divisivel_por_3 = true;
            else numero_divisivel_por_3 = false;

            if (numero_computador % 5 == 0)
                numero_divisivel_por_5 = true;
            else numero_divisivel_por_5 = false;

            std::vector<int> quadrados_perfeitos_de_1_a_10 = {1, 4, 9};

            for (int n {0}; n < quadrados_perfeitos_de_1_a_10.size(); ++n)
            {
                if (numero_computador == quadrados_perfeitos_de_1_a_10[n])
                {
                    numero_quadrado_perfeito = true;
                    break;
                }
                else numero_quadrado_perfeito = false;
            }

            if (numero_computador < 6)
                numero_menor_que_6 = true;
            else numero_menor_que_6 = false;
        }

        std::cout << "\n Computador: Eu já pensei em um número, agora é sua vez de adivinhá-lo! \n";

        std::cout << "\n 1ª Pergunta: \n";

        std::uniform_int_distribution<int> distribution_2(0, perguntas_disponibilidade.size() - 1);

        int pergunta_aleatoria_1;

        int pergunta_1_resposta;

        for (int n {1}; n < 3; ++n) // 1ª Pergunta, duas perguntas disponíveis a escolher
        {
            while (1)

            // É preciso ver se o número da pergunta está disponível
            // Se estiver --> break
            // Vai loopar até achar um número disponível

            {
                pergunta_aleatoria_1 = distribution_2(rd);

                // std::cout << "\n |" << pergunta_aleatoria_1 << "|";      For debugging purposes

                // std::cout << "|" << perguntas_disponibilidade[pergunta_aleatoria_1] << "| \n";       For debugging purposes

                if (perguntas_disponibilidade[pergunta_aleatoria_1] == 1)
                {
                    perguntas_disponibilidade[pergunta_aleatoria_1] = 0; // Já deixa a pergunta indisponível
                    break;
                }

            }

            std::cout << perguntas_lista[pergunta_aleatoria_1];

            if (n == 2)
            {
                std::cout << "\n Escolha o número da pergunta: ";

                while (1)
                {
                    std::cin >> pergunta_1_resposta;

                    bool apenas_pergunta_ja_feita;

                    for (int n {0}; n < perguntas_lista.size(); ++n)
                    {
                        if (pergunta_1_resposta != 0 && pergunta_1_resposta == n && perguntas_disponibilidade[n] == 0) // Usei todos os meus neurônios
                        {
                            apenas_pergunta_ja_feita = true;
                            break;
                        }
                    }

                    if (apenas_pergunta_ja_feita == true)
                        break;

                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore();
                    }
                }

                switch (pergunta_1_resposta)
                {
                    case 1:
                        if (numero_par == true)
                            std::cout << "\n\n Resposta da 1ª Pergunta: Sim, o número é par. \n";
                            else std::cout << "\n\n Resposta da 1ª Pergunta: Não, o número não é par. \n";
                            break;

                    case 2:
                        if (numero_maior_que_5 == true)
                            std::cout << "\n\n Resposta da 1ª Pergunta: Sim, o número é maior que 5. \n";
                            else std::cout << "\n\n Resposta da 1ª Pergunta: Não, o número não é maior que 5. \n";
                            break;

                    case 3:
                        if (numero_primo == true)
                            std::cout << "\n\n Resposta da 1ª Pergunta: Sim, o número é primo. \n";
                            else std::cout << "\n\n Resposta da 1ª Pergunta: Não, o número não é primo. \n";
                            break;

                    case 4:
                        if (numero_divisivel_por_3 == true)
                            std::cout << "\n\n Resposta da 1ª Pergunta: Sim, o número é divisível por 3. \n";
                            else std::cout << "\n\n Resposta da 1ª Pergunta: Não, o número não é divisível por 3. \n";
                            break;

                    case 5:
                        if (numero_divisivel_por_5 == true)
                            std::cout << "\n\n Resposta da 1ª Pergunta: Sim, o número é divisível por 5. \n";
                            else std::cout << "\n\n Resposta da 1ª Pergunta: Não, o número não é divisível por 5. \n";
                            break;

                    case 6:
                        if (numero_quadrado_perfeito == true)
                            std::cout << "\n\n Resposta da 1ª Pergunta: Sim, o número é quadrado perfeito. \n";
                            else std::cout << "\n\n Resposta da 1ª Pergunta: Não, o número não é quadrado perfeito. \n";
                            break;

                    case 7:
                        if (numero_menor_que_6 == true)
                            std::cout << "\n\n Resposta da 1ª Pergunta: Sim, o número é menor que seis. \n";
                            else std::cout << "\n\n Resposta da 1ª Pergunta: Não, o número não é menor que seis. \n";
                            break;
                }
            }

        }
        // Fim da 1ª Pergunta


        std::cout << "\n\n 2ª Pergunta: \n";

        int pergunta_aleatoria_2;

        int pergunta_2_resposta;

        for (int n {1}; n < 3; ++n) // 2ª Pergunta, duas perguntas disponíveis a escolher
        {

            while (1)

            // É preciso ver se o número da pergunta está disponível
            // Se estiver --> break
            // Vai loopar até achar um número disponível

            {
                pergunta_aleatoria_2 = distribution_2(rd);  // Um número natural de 0 até 4

                // std::cout << "\n |" << pergunta_aleatoria_1 << "|";      For debugging purposes

                // std::cout << "|" << perguntas_disponibilidade[pergunta_aleatoria_1] << "| \n";       For debugging purposes

                if (perguntas_disponibilidade[pergunta_aleatoria_2] == 1)
                {
                    perguntas_disponibilidade[pergunta_aleatoria_2] = 0; // Já deixa a pergunta indisponível
                    break;
                }

            }

            std::cout << perguntas_lista[pergunta_aleatoria_2];

            if (n == 2)
            {
                std::cout << "\n Escolha o número da pergunta: ";

                while (1)
                {
                    std::cin >> pergunta_2_resposta;

                    bool apenas_pergunta_ja_feita;

                    for (int n {0}; n < perguntas_lista.size(); ++n)
                    {
                        if (pergunta_2_resposta != 0 && pergunta_2_resposta == n && perguntas_disponibilidade[n] == 0) // Usei todos os meus neurônios
                        {
                            apenas_pergunta_ja_feita = true;
                            break;
                        }
                    }

                    if (apenas_pergunta_ja_feita == true)
                        break;

                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore();
                    }
                }

                switch (pergunta_2_resposta)
                {
                    case 1:
                        if (numero_par == true)
                            std::cout << "\n\n Resposta da 2ª Pergunta: Sim, o número é par. \n";
                            else std::cout << "\n\n Resposta da 2ª Pergunta: Não, o número não é par. \n";
                            break;

                    case 2:
                        if (numero_maior_que_5 == true)
                            std::cout << "\n\n Resposta da 2ª Pergunta: Sim, o número é maior que 5. \n";
                            else std::cout << "\n\n Resposta da 2ª Pergunta: Não, o número não é maior que 5. \n";
                            break;

                    case 3:
                        if (numero_primo == true)
                            std::cout << "\n\n Resposta da 2ª Pergunta: Sim, o número é primo. \n";
                            else std::cout << "\n\n Resposta da 2ª Pergunta: Não, o número não é primo. \n";
                            break;

                    case 4:
                        if (numero_divisivel_por_3 == true)
                            std::cout << "\n\n Resposta da 2ª Pergunta: Sim, o número é divisível por 3. \n";
                            else std::cout << "\n\n Resposta da 2ª Pergunta: Não, o número não é divisível por 3. \n";
                            break;

                    case 5:
                        if (numero_divisivel_por_5 == true)
                            std::cout << "\n\n Resposta da 2ª Pergunta: Sim, o número é divisível por 5. \n";
                            else std::cout << "\n\n Resposta da 2ª Pergunta: Não, o número não é divisível por 5. \n";
                            break;

                    case 6:
                        if (numero_quadrado_perfeito == true)
                            std::cout << "\n\n Resposta da 2ª Pergunta: Sim, o número é quadrado perfeito. \n";
                            else std::cout << "\n\n Resposta da 2ª Pergunta: Não, o número não é quadrado perfeito. \n";
                            break;

                    case 7:
                        if (numero_menor_que_6 == true)
                            std::cout << "\n\n Resposta da 2ª Pergunta: Sim, o número é menor que seis. \n";
                            else std::cout << "\n\n Resposta da 2ª Pergunta: Não, o número não é menor que seis. \n";
                            break;
                }
            }
        }
        // Fim da 2ª Pergunta

        std::cout << "\n 3ª Pergunta: \n";

        int pergunta_aleatoria_3;

        int pergunta_3_resposta;

        for (int n {1}; n < 3; ++n) // 3ª Pergunta, duas perguntas disponíveis a escolher
        {

            while (1)

            // É preciso ver se o número da pergunta está disponível
            // Se estiver --> break
            // Vai loopar até achar um número disponível

            {
                pergunta_aleatoria_3 = distribution_2(rd);  // Um número natural de 0 até 4

                // std::cout << "\n |" << pergunta_aleatoria_1 << "|";      For debugging purposes

                // std::cout << "|" << perguntas_disponibilidade[pergunta_aleatoria_1] << "| \n";       For debugging purposes

                if (perguntas_disponibilidade[pergunta_aleatoria_3] == 1)
                {
                    perguntas_disponibilidade[pergunta_aleatoria_3] = 0; // Já deixa a pergunta indisponível
                    break;
                }
            }

            std::cout << perguntas_lista[pergunta_aleatoria_3];

            if (n == 2)
            {
                std::cout << "\n Escolha o número da pergunta: ";

                while (1)
                {
                    std::cin >> pergunta_3_resposta;

                    bool apenas_pergunta_ja_feita;

                    for (int n {0}; n < perguntas_lista.size(); ++n)
                    {
                        if (pergunta_3_resposta != 0 && pergunta_3_resposta == n && perguntas_disponibilidade[n] == 0) // Usei todos os meus neurônios
                        {
                            apenas_pergunta_ja_feita = true;
                            break;
                        }
                    }

                    if (apenas_pergunta_ja_feita == true)
                        break;

                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore();
                    }
                }

                switch (pergunta_3_resposta)
                {
                    case 1:
                        if (numero_par == true)
                            std::cout << "\n\n Resposta da 3ª Pergunta: Sim, o número é par. \n";
                            else std::cout << "\n\n Resposta da 3ª Pergunta: Não, o número não é par. \n";
                            break;

                    case 2:
                        if (numero_maior_que_5 == true)
                            std::cout << "\n\n Resposta da 3ª Pergunta: Sim, o número é maior que 5. \n";
                            else std::cout << "\n\n Resposta da 3ª Pergunta: Não, o número não é maior que 5. \n";
                            break;

                    case 3:
                        if (numero_primo == true)
                            std::cout << "\n\n Resposta da 3ª Pergunta: Sim, o número é primo. \n";
                            else std::cout << "\n\n Resposta da 3ª Pergunta: Não, o número não é primo. \n";
                            break;

                    case 4:
                        if (numero_divisivel_por_3 == true)
                            std::cout << "\n\n Resposta da 3ª Pergunta: Sim, o número é divisível por 3. \n";
                            else std::cout << "\n\n Resposta da 3ª Pergunta: Não, o número não é divisível por 3. \n";
                            break;

                    case 5:
                        if (numero_divisivel_por_5 == true)
                            std::cout << "\n\n Resposta da 3ª Pergunta: Sim, o número é divisível por 5. \n";
                            else std::cout << "\n\n Resposta da 3ª Pergunta: Não, o número não é divisível por 5. \n";
                            break;

                    case 6:
                        if (numero_quadrado_perfeito == true)
                            std::cout << "\n\n Resposta da 3ª Pergunta: Sim, o número é quadrado perfeito. \n";
                            else std::cout << "\n\n Resposta da 3ª Pergunta: Não, o número não é quadrado perfeito. \n";
                            break;

                    case 7:
                        if (numero_menor_que_6 == true)
                            std::cout << "\n\n Resposta da 3ª Pergunta: Sim, o número é menor que seis. \n";
                            else std::cout << "\n\n Resposta da 3ª Pergunta: Não, o número não é menor que seis. \n";
                            break;
                }
            }
        }
        // Fim da 3ª Pergunta

        std::cout << "\n\n Computador: Qual foi o número que eu pensei? ";

        int resposta_final;

        while (1)
        {
            std::cin >> resposta_final;

            if (resposta_final == numero_computador)
            {
                std::cout << "\n Computador: Você acertou! O número que eu pensei é de fato " << numero_computador << " ! \n";
                ++pontuacao_jogador;
                break;
            }

            if (resposta_final != numero_computador)
            {
                std::cout << "\n Computador: Você errou! Eu pensei no número " << numero_computador << " !\n";
                ++pontuacao_computador;
                break;
            }

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
            }
        }

        std::cout << "\n Pontuação do " << nome_do_jogador << ": " << pontuacao_jogador << "\n";

        std::cout << "\n Pontuação do Computador: " << pontuacao_computador << "\n";

        std::cout << "\n Quer jogar novamente? Digite 'Sim' ou 'Não'. ";

        std::string jogar_novamente;

        while (1)
        {
            std::cin >> jogar_novamente;

            if (jogar_novamente == "Sim")
                break;

            if (jogar_novamente == "Não")
                break;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
            }
        }

        if (jogar_novamente == "Não")
            break;

    }

    std::cout << "\n\n Fim do jogo. Obrigado por jogar " << nome_do_jogador << "! \n";

    std::cout << "\n Jogo criado por Vinicius (Badhunter)."
              << "\n\n Versão 2, 27/08/2024"
              << "\n\n Última atualização: 27/08/2024 \n";

    return 0;
}




