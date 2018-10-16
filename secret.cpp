#include <iostream>
#include <random>
#include <string>

int main(void)
{
    std::random_device r;
    std::default_random_engine e1(r());
    // select one between 1 to 25 so as to play the game forever.
    std::uniform_int_distribution<int> uniform_dist(1, 25);
    int secret = uniform_dist(e1);
    int attempts = 0;

    do {
        int n;
        std::cout << "Guess the secret number [1, 24]. Enter to a num to verify: ";
        if (!(std::cin >> n)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        ++attempts;

        if (secret == n) {
            std::cout << "Congrats! It's correct!" << std::endl;
            break;
        } else {
            std::string str = n > secret ? "high" : "small";
            std::cout << "Nope :( Your guess is too " << str << std::endl;
        }
    }while(true);

    std::cout << "You found in " << attempts << " attempts." << std::endl;

}
