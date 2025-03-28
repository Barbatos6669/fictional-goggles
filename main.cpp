#include <iostream>
#include <string>
#include <vector>
#include <map>

enum class GameMode
{
    MAIN_MENU,
    GAME,
    EXIT
};

class GameTick
{
    public:
    int tick;

    // Constructor
    GameTick()
    {
        tick = 0;
    }

    // Destructor
    ~GameTick()
    {
        std::cout << "Destructor called" << std::endl;
    }

    // getter
    int getTick();

    // setter
    void setTick(int tick);
    void tickIncrease();

};

// clear screen
void clearScreen();

class Money
{
    public:
        double balance;
        double nationalRevenue;
        double nationalExpenditure;

        // Constructor
        Money()
        {
            balance = 0.0;
            nationalRevenue = 0.0;
            nationalExpenditure = 0.0;
        }

        // Destructor
        ~Money()
        {
            std::cout << "Destructor called" << std::endl;
        }

        // getter
        double getBalance();

        // setter
        void setBalance(double balance);
};

class Population
{
    public:
        int population;

        // Constructor
        Population()
        {
            population = 0;
        }

        // Destructor
        ~Population()
        {
            std::cout << "Destructor called" << std::endl;
        }

        // getter
        int getPopulation()
        {
            return population;
        }

        // setter
        void setPopulation(int population)
        {
            this->population = population;
        }
};

class Player
{
    public:
        std::string playerName;
        Money money;
        Population population;
};

class Gameflow
{
    public:
        GameTick gameTick;
        Player player;
        
        int choice;

        void mainMenu(int choice);
        void gameMenu(int choice);
        void exit();
};

int main()
{        
    Gameflow gameflow;
    GameMode mode = GameMode::MAIN_MENU; 


    while (mode != GameMode::EXIT)
    {
        switch (mode)
        {
            case GameMode::MAIN_MENU:
                clearScreen();        
                gameflow.mainMenu(gameflow.choice);    
                break;
            case GameMode::GAME:
                clearScreen();
                gameflow.gameMenu(gameflow.choice);
                break;
            case GameMode::EXIT:
                clearScreen();
                gameflow.exit();
                break;
        }
    }
        
    return 0;
}

void clearScreen()
{
    std::cout << std::string(100, '\n');
}

int GameTick::getTick()
{
    return tick;
}

void GameTick::setTick(int tick)
{
    this->tick = tick;
}

void GameTick::tickIncrease()
{
    tick++;
}

void Gameflow::mainMenu(int choice)
{
    std::cout << "Main Menu" << std::endl;
    std::cout << std::endl;

    std::cout << "1. play" << std::endl;
    std::cout << "2. exit" << std::endl;
}

void Gameflow::gameMenu(int choice)
{
    std::cout << "Game" << std::endl;
    std::cout << std::endl;

    std::cout << "1. Overview" << std::endl;
    std::cout << "2. Building" << std::endl;
    std::cout << "3. Population" << std::endl;
    std::cout << "4. Local Prices" << std::endl;
    std::cout << "5. Information" << std::endl;
}

void Gameflow::exit()
{
    std::cout << "Exit" << std::endl;
}
