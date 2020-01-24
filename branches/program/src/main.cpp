#include <iostream>
#include <vector>
#include "Player/Move.h"
#include "Player/Player.h"
#include "Game.h"

int main() {
    std::string input = "a";
    bool load_or_not;
    bool is_ai_player1 = true;
    bool is_ai_player2 = true;
    while (input != "n" && input != "w"){
        std::cout << "czy chcesz rozpocząć nową grę czy wczytać? [n/w]" << "\n";
        std::cin >> input;
        std::cout << "\n";
        while (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "czy chcesz rozpocząć nową grę czy wczytać? [n/w]" << "\n";
            std::cin >> input;
            std::cout << "\n";
        }
    }
    load_or_not = !(input == "n");
    if(!load_or_not){
        while (input != "C" && input != "A") {
            std::cout << "czy chcesz by gracz 1 byl Czlowiekiem czy AI? [C/A]" << "\n";
            std::cin >> input;
            std::cout << "\n";
            while (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "czy chcesz by gracz 1 byl Czlowiekiem czy AI? [C/A]" << "\n";
                std::cin >> input;
                std::cout << "\n";
            }
        }
        is_ai_player1 = !(input == "C");
        input = "n";
        while (input != "C" && input != "A") {
            std::cout << "czy chcesz by gracz 2 byl Czlowiekiem czy AI? [C/A]" << "\n";
            std::cin >> input;
            std::cout << "\n";
            while (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "czy chcesz by gracz 2 byl Czlowiekiem czy AI? [C/A]" << "\n";
                std::cin >> input;
                std::cout << "\n";
            }
        }
        is_ai_player2 = !(input == "C");
    }
    Game game(is_ai_player1, is_ai_player2, load_or_not);

    game.main_game_loop();
}