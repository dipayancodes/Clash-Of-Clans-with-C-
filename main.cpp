#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int TOWNHALL_LEVEL = 1;
const int GOLD = 1000;
const int ELIXIR = 1000;
const int TROOP_CAPACITY = 20;

class Player {
private:
    std::string name;
    int townhall_level;
    int gold;
    int elixir;
    int troop_capacity;
    std::vector<std::string> troops;

public:
    Player(std::string playerName) {
        name = playerName;
        townhall_level = TOWNHALL_LEVEL;
        gold = GOLD;
        elixir = ELIXIR;
        troop_capacity = TROOP_CAPACITY;
        troops = std::vector<std::string>();
    }

    void print_resources() {
        std::cout << "Gold: " << gold << std::endl;
        std::cout << "Elixir: " << elixir << std::endl;
    }

    void print_troops() {
        std::cout << "Troops: " << std::endl;
        for (const auto& troop : troops) {
            std::cout << troop << std::endl;
        }
    }

    void attack() {
        int enemy_townhall_level = rand() % 10 + 1;
        if (townhall_level > enemy_townhall_level) {
            std::cout << "You won the attack!" << std::endl;
        } else {
            std::cout << "You lost the attack!" << std::endl;
        }
    }

    void train_troop(std::string troop_name, int troop_cost) {
        if (troops.size() >= troop_capacity) {
            std::cout << "Troop capacity reached. Upgrade your camps to train more troops." << std::endl;
        } else {
            if (gold >= troop_cost) {
                gold -= troop_cost;
                troops.push_back(troop_name);
            } else {
                std::cout << "Not enough gold to train the troops." << std::endl;
            }
        }
    }
};

void game_loop() {
    std::cout << "Welcome to Clash of Clans (CLI Version)!" << std::endl;
    std::string player_name;
    std::cout << "Enter Your Name: ";
    std::cin >> player_name;
    Player player(player_name);

    while (true) {
        std::cout << "\n[MAIN MENU]" << std::endl;
        std::cout << "1. Print Resources" << std::endl;
        std::cout << "2. Print Troops" << std::endl;
        std::cout << "3. Train Troops" << std::endl;
        std::cout << "4. Attack" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::string choice;
        std::cin >> choice;

        if (choice == "1") {
            player.print_resources();
        } else if (choice == "2") {
            player.print_troops();
        } else if (choice == "3") {
            std::string troop_name;
            int troop_cost;
            std::cout << "Enter the Troop name: ";
            std::cin >> troop_name;
            std::cout << "Enter the troop cost: ";
            std::cin >> troop_cost;
            player.train_troop(troop_name, troop_cost);
        } else if (choice == "4") {
            player.attack();
        } else if (choice == "5") {
            std::cout << "Thanks for Playing Clash of Clans (CLI version)!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

int main() {
    // Set random seed
    srand(static_cast<unsigned>(time(nullptr)));
    game_loop();
    return 0;
}

