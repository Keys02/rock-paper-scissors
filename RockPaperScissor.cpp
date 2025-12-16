// A program which plays the game rock paper scissors

#include <iostream>
#include <vector>
#include <string>

std::string draw_hand(std::string choice) {
    std::string hand = "";
    if (choice == "Rock") {
        hand = R"(
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
        )";
    }
    else if (choice == "Paper") {
        hand = R"(
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
        )";
    }
    else if (choice == "Scissor") {
        hand = R"(
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
        )";
    }
    return hand;
}

std::string shoot_player() {
    std::string choice;
    std::cout << "Player: ";
    std::cin >> choice;
    std::cout << draw_hand(choice) << "\n";
    return choice;
}

std::string shoot_computer() {
    std::vector<std::string> choices = {"Rock", "Paper", "Scissor"};
    srand(time(0));
    int rand_num = (rand() % 3);
    std::string computer_choice = choices.at(rand_num);
    return computer_choice;

}

std::string choose_winner(std::string player_choice, std::string computer_choice) {
    char p_s  = player_choice[0];

    switch (p_s) {
        case 'R':
            if (computer_choice == "Rock")
                return "It's a tie";
            else if (computer_choice == "Paper")
                return "You lost";
            else if (computer_choice == "Scissor")
                return "You won";
            break;
        case 'P':
            if (computer_choice == "Rock")
                return "You won";
            else if (computer_choice == "Paper")
                return "It's a tie";
            else if (computer_choice == "Scissor")
                return "You lost";
            break;
        case 'S':
            if (computer_choice == "Rock")
                return "You lost";
            else if (computer_choice == "Paper")
                return "You won";
            else if (computer_choice == "Scissor")
                return "It's a tie";
            break;
    }
    return "";
}

void start_game() {
    std::string player_shoot;
    std::string computer_shoot;

    do {
        std::cout << "################################################################################################################\n"
                  << "****************************************************************************************************************\n"
                  << "                                                  How to play                                                   \n"
                  << "****************************************************************************************************************\n"
                  << "Shoot either one of Rock, Paper or Scissor"
                  << "\n"
                  << "\n"
                  << "Rock Paper Scissor shoot!!\n"
                  << "################################################################################################################\n";
        player_shoot = shoot_player();
    } while (player_shoot != "Rock" && player_shoot != "Paper" && player_shoot != "Scissor");

    computer_shoot = shoot_computer();
    std::cout << "Computer: " << computer_shoot << '\n';
    std::cout << draw_hand(computer_shoot) << '\n';

    std::cout << "Result: " << choose_winner(player_shoot, computer_shoot) << '\n' ;
}

int main() {
    start_game();
    return 0;
}
