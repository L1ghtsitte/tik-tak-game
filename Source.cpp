
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <windows.h>
#include <limits>

using namespace std;


struct Player {
    string name;
    int matches;
    int wins;
    int losses;
    int draws;
    int moves;
};

char square[9] = { '0','1','2','3','4','5','6','7','8' };
int currentPlayer = 1;
int setColor = 7;
Player player1, player2;

int checkwin();
void mark(int player, int box);
void display();
void clear();
void setConsoleColor(int colorCode);
void saveStats();
void loadStats();
void displayStats();
void resetStats();
int getValidBoxInput(int currentPlayer);
int getComputerMove();

int checkwin()
{
    if (square[0] == square[1] && square[1] == square[2]) {
        if (square[0] == 'X') return 1;
        else return 2;
    }
    else if (square[3] == square[4] && square[4] == square[5]) {
        if (square[3] == 'X') return 1;
        else return 2;
    }
    else if (square[6] == square[7] && square[7] == square[8]) {
        if (square[6] == 'X') return 1;
        else return 2;
    }
    else if (square[0] == square[3] && square[3] == square[6]) {
        if (square[0] == 'X') return 1;
        else return 2;
    }
    else if (square[1] == square[4] && square[4] == square[7]) {
        if (square[1] == 'X') return 1;
        else return 2;
    }
    else if (square[2] == square[5] && square[5] == square[8]) {
        if (square[2] == 'X') return 1;
        else return 2;
    }
    else if (square[0] == square[4] && square[4] == square[8]) {
        if (square[0] == 'X') return 1;
        else return 2;
    }
    else if (square[2] == square[4] && square[4] == square[6]) {
        if (square[2] == 'X') return 1;
        else return 2;
    }
    else return 0;
}


void mark(int player, int box)
{
    if (player == 1) square[box] = 'X';
    else square[box] = 'O';
}


void display()
{
    for (int i = 0; i < 9; i++)
    {
        cout << square[i] << "      ";
        if (i == 2 || i == 5 || i == 8) cout << "\n";
    }
}

void clear()
{
    for (int i = 0; i < 9; i++)
    {
        square[0] = '0';
        square[1] = '1';
        square[2] = '2';
        square[3] = '3';
        square[4] = '4';
        square[5] = '5';
        square[6] = '6';
        square[7] = '7';
        square[8] = '8';
    }
}


void setConsoleColor(int colorCode) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

void saveStats() 
{
    double winperpr1, lossperpr1, drawperpr1, winperpr2, lossperpr2, drawperpr2;

    if (player1.matches > 0) {
        winperpr1 = (double)player1.wins / player1.matches * 100;
        lossperpr1 = (double)player1.losses / player1.matches * 100;
        drawperpr1 = (double)player1.draws / player1.matches * 100;
    }
    else {
        winperpr1 = 0;
        lossperpr1 = 0;
        drawperpr1 = 0;
    }
    if (player2.matches > 0) {
        winperpr2 = (double)player2.wins / player2.matches * 100;
        lossperpr2 = (double)player2.losses / player2.matches * 100;
        drawperpr2 = (double)player2.draws / player2.matches * 100;
    }
    else {
        winperpr2 = 0;
        lossperpr2 = 0;
        drawperpr2 = 0;
    }
    ofstream out("stats.txt");
    if (out.is_open()) 
    {
        out << "-----------------------------" << endl;
        out << "Color : " << setColor << endl;
        out << "-----------------------------" << endl;
        out << "Player 1 : " << player1.name << endl;
        out << "Moves : " << player1.moves << endl;
        out << "Matches : " << player1.matches << endl;
        out << "Wins : " << player1.wins << " | " << winperpr1 << " %" << endl;
        out << "Losses : " << player1.losses << " | " << lossperpr1 << " %" << endl;
        out << "Draws : " << player1.draws << " | " << drawperpr1 << " %" << endl;
        out << "-----------------------------" << endl;
        out << "Player 2 : " << player2.name << endl;
        out << "Moves : " << player2.moves << endl;
        out << "Matches : " << player2.matches << endl;
        out << "Wins : " << player2.wins << " | " << winperpr2 << " %" << endl;
        out << "Losses : " << player2.losses << " | " << lossperpr2 << " %" << endl;
        out << "Draws : " << player2.draws << " | " << drawperpr1 << " %" << endl;
        out.close();
    }
    else {
        cerr << "Error opening stats.txt for saving!" << endl;
    }
}

void loadStats() {
    ifstream in("stats.txt");
    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            size_t pos = line.find(":");
            if (pos != string::npos) {
                string key = line.substr(0, pos);
                string value = line.substr(pos + 1);

                if (key == "Player1Name") player1.name = value;
                else if (key == "Player1Matches") player1.matches = stoi(value);
                else if (key == "Player1Wins") player1.wins = stoi(value);
                else if (key == "Player1Losses") player1.losses = stoi(value);
                else if (key == "Player1Draws") player1.draws = stoi(value);
                else if (key == "Player1Moves") player1.moves = stoi(value);
                else if (key == "Player2Name") player2.name = value;
                else if (key == "Player2Matches") player2.matches = stoi(value);
                else if (key == "Player2Wins") player2.wins = stoi(value);
                else if (key == "Player2Losses") player2.losses = stoi(value);
                else if (key == "Player2Draws") player2.draws = stoi(value);
                else if (key == "Player2Moves") player2.moves = stoi(value);
                else if (key == "Color") setColor = stoi(value);

            }
        }
        in.close();
    }
    else {
        cerr << "No stats file found, starting with new stats." << endl;
        player1.name = "Player 1";
        player1.matches = 0;
        player1.wins = 0;
        player1.losses = 0;
        player1.draws = 0;
        player1.moves = 0;

        player2.name = "Player 2";
        player2.matches = 0;
        player2.wins = 0;
        player2.losses = 0;
        player2.draws = 0;
        player2.moves = 0;
    }
}
void displayStats()
{
    double winperpr1, lossperpr1, drawperpr1, winperpr2, lossperpr2, drawperpr2;

    if (player1.matches > 0) {
        winperpr1 = (double)player1.wins / player1.matches * 100;
        lossperpr1 = (double)player1.losses / player1.matches * 100;
        drawperpr1 = (double)player1.draws / player1.matches * 100;
    }
    else {
        winperpr1 = 0;
        lossperpr1 = 0;
        drawperpr1 = 0;
    }
    if (player2.matches > 0) {
        winperpr2 = (double)player2.wins / player2.matches * 100;
        lossperpr2 = (double)player2.losses / player2.matches * 100;
        drawperpr2 = (double)player2.draws / player2.matches * 100;
    }
    else {
        winperpr2 = 0;
        lossperpr2 = 0;
        drawperpr2 = 0;
    }
    string color;

    if (setColor == 0) color = "Black";
    if (setColor == 1) color = "Blue";
    if (setColor == 2) color = "Green";
    if (setColor == 3) color = "Cyan";
    if (setColor == 4) color = "Red";
    if (setColor == 5) color = "Purple";
    if (setColor == 6) color = "Yellow(Brown)";
    if (setColor == 7) color = "White";
    if (setColor == 8) color = "Gray";
    if (setColor == 9) color = "L1ght Blue 1";
    if (setColor == 10) color = "L1ght Green";
    if (setColor == 11) color = "L1ght Blue 2";
    if (setColor == 12) color = "L1ght Red";
    if (setColor == 13) color = "L1ght Purple";
    if (setColor == 14) color = "L1ght Yellow";
    if (setColor == 15) color = "L1ght White";

    cout << "-----------------------------" << endl;
    cout << "| Color : " << color << "   | " << endl;
    cout << "-----------------------------" << endl;
    cout << "| Name : " << player1.name << "   | " << endl;
    cout << "-----------------------------" << endl;
    cout << "| Matches : " << player1.matches << " | " << endl;
    cout << "| Move : " << player1.moves << " | " << endl;
    cout << "| Win : " << player1.wins << "  | " << winperpr1 << "%|" << endl;
    cout << "| Loss : " << player1.losses << " | " << lossperpr1 << "%|" << endl;
    cout << "| Draw : " << player1.draws << " | " << drawperpr1 << "%|" << endl;
    cout << "-----------------------------" << endl;
    cout << "| Name : " << player2.name << "   | " << endl;
    cout << "-----------------------------" << endl;
    cout << "| Matches : " << player2.matches << " | " << endl;
    cout << "| Move : " << player2.moves << " | " << endl;
    cout << "| Win : " << player2.wins << "  | " << winperpr2 << "%|" << endl;
    cout << "| Loss : " << player2.losses << " | " << lossperpr2 << "%|" << endl;
    cout << "| Draw : " << player2.draws << " | " << drawperpr2 << "%|" << endl;
    cout << "-----------------------------" << endl;
}

void resetStats()
{
    player1.name = "Player 1";
    player1.matches = 0;
    player1.wins = 0;
    player1.losses = 0;
    player1.draws = 0;
    player1.moves = 0;

    player2.name = "Player 2";
    player2.matches = 0;
    player2.wins = 0;
    player2.losses = 0;
    player2.draws = 0;
    player2.moves = 0;
    saveStats();
}


int getValidBoxInput(int currentPlayer) {
    int box;
    bool validInput = false;
    string playerName;

    if (currentPlayer == 1)
    {
        playerName = player1.name;
    }
    else {
        playerName = player2.name;
    }

    while (!validInput) {
        cout << playerName << ", enter the Box: ";
        cin >> box;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
        }
        else if (box >= 0 && box <= 8 && square[box] != 'X' && square[box] != 'O')
        {
            validInput = true;
        }
        else
        {
            cout << "Invalid input. Please enter an available number." << endl;
        }
    }
    return box;
}

int getComputerMove() 
{
    vector<int> availableMoves;
    for (int i = 0; i < 9; ++i) 
    {
        if (square[i] != 'X' && square[i] != 'O') 
        {
            availableMoves.push_back(i);
        }
    }

    if (availableMoves.empty()) 
    {
        return -1;
    }

    for (int move : availableMoves) 
    {
        char originalValue = square[move];
        square[move] = 'O';
        if (checkwin() == 2) 
        {
            square[move] = originalValue;
            return move;
        }
        square[move] = originalValue;
    }

    for (int move : availableMoves) 
    {
        char originalValue = square[move];
        square[move] = 'X';
        if (checkwin() == 1) 
        {
            square[move] = originalValue;
            return move;
        }
        square[move] = originalValue;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, availableMoves.size() - 1);
    return availableMoves[distrib(gen)];
}

int main()
{
    int result = 0;
    int flag = 0;
    int choise = 0;
    bool playWithComputer = false;

    loadStats();

    while (true)
    {
        cout << "ver 0.2 - By L1ghtsitte" << endl;
        cout << "Play - 1" << endl;
        cout << "Play with computer - 2" << endl;
        cout << "Info - 3" << endl;
        cout << "Change color - 4" << endl;
        cout << "Reset stats - 5" << endl;
        cout << "Your choise - ";
        cin >> choise;
        system("cls");

        switch (choise)
        {
        case 1:
        case 2:
        {
            if (choise == 1)
            {
                playWithComputer = false;
            }
            else if (choise == 2)
            {
                playWithComputer = true;
            }

            cout << "Player 1 enter name : ";
            cin >> player1.name;
            player1.matches += 1;

            if (!playWithComputer)
            {
                cout << "Player 2 enter name : ";
                cin >> player2.name;
                player2.matches += 1;
            }
            else {
                player2.name = "Computer";
                player2.matches += 1;
            }
            
            system("cls");

            for (int i = 1; i < 5; i++)
            {
                system("cls");
                display();
                int box;

                box = getValidBoxInput(1);

                player1.moves += 1;
                mark(1, box);
                display();

                result = checkwin();
                if (result == 1)
                {
                    system("cls");
                    display();
                    cout << "Congratualtions! player " << player1.name << " has Won " << endl;
                    flag = 1;
                    player1.wins += 1;
                    player2.losses += 1;
                    saveStats();
                    break;
                }
                else if (result == 2)
                {
                    system("cls");
                    display();
                    cout << "Congratualtions! player " << player2.name << " has Won " << endl;
                    flag = 1;
                    player2.wins += 1;
                    player1.losses += 1;
                    saveStats();
                    break;
                }
                if (playWithComputer)
                {
                    system("cls");
                    display();
                    box = getComputerMove();
                    if (box != -1)
                    {
                        player2.moves += 1;
                        mark(2, box);
                        display();
                        result = checkwin();
                        if (result == 1)
                        {
                            system("cls");
                            display();
                            cout << "Congratualtions! player " << player1.name << " has Won " << endl;
                            flag = 1;
                            player1.wins += 1;
                            player2.losses += 1;
                            saveStats();
                            break;
                        }
                        else if (result == 2)
                        {
                            system("cls");
                            display();
                            cout << "Congratualtions! player " << player2.name << " has Won " << endl;
                            flag = 1;
                            player2.wins += 1;
                            player1.losses += 1;
                            saveStats();
                            break;
                        }
                    }
                    else
                    {
                        result = 3;
                        break;
                    }
                }
                else
                {
                    system("cls");
                    display();

                    box = getValidBoxInput(2);

                    player2.moves += 1;
                    mark(2, box);
                    display();

                    result = checkwin();
                    if (result == 1)
                    {
                        system("cls");
                        display();
                        cout << "Congratualtions! player " << player1.name << " has Won " << endl;
                        flag = 1;
                        player1.wins += 1;
                        player2.losses += 1;
                        saveStats();
                        break;
                    }
                    else if (result == 2)
                    {
                        system("cls");
                        display();
                        cout << "Congratualtions! player " << player2.name << " has Won " << endl;
                        flag = 1;
                        player2.wins += 1;
                        player1.losses += 1;
                        saveStats();
                        break;
                    }
                }
            }
            if (flag == 0 && result != 3)
            {
                system("cls");
                display();
                cout << "The game is a draw " << endl;
                player1.draws += 1;
                player2.draws += 1;
                saveStats();
            }
            if (result == 3)
            {
                system("cls");
                display();
                cout << "The game is a draw " << endl;
                player1.draws += 1;
                player2.draws += 1;
                saveStats();
            }
            cout << "For new game : " << endl;
            clear();
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            displayStats();
            break;
        }
        case 4:
        {
            cout << "List of color codes : " << endl;
            setConsoleColor(0);
            cout << "| 0 | - | Black |" << endl;
            setConsoleColor(1);
            cout << "| 1 | - | Blue |" << endl;
            setConsoleColor(2);
            cout << "| 2 | - | Green |" << endl;
            setConsoleColor(3);
            cout << "| 3 | - | Cyan |" << endl;
            setConsoleColor(4);
            cout << "| 4 | - | Red |" << endl;
            setConsoleColor(5);
            cout << "| 5 | - | Purple |" << endl;
            setConsoleColor(6);
            cout << "| 6 | - | Yellow (Brown) |" << endl;
            setConsoleColor(7);
            cout << "| 7 | - | White |" << endl;
            setConsoleColor(8);
            cout << "| 8 | - | Gray |" << endl;
            setConsoleColor(9);
            cout << "| 9 | - | Light Blue |" << endl;
            setConsoleColor(10);
            cout << "| 10 | - | Light Green |" << endl;
            setConsoleColor(11);
            cout << "| 11 | - | Light Blue |" << endl;
            setConsoleColor(12);
            cout << "| 12 | - | Light Red |" << endl;
            setConsoleColor(13);
            cout << "| 13 | - | Light Purple |" << endl;
            setConsoleColor(14);
            cout << "| 14 | - | Light yellow |" << endl;
            setConsoleColor(15);
            cout << "| 15 | - | Bright white |" << endl;
            setConsoleColor(7);
            cout << "Enter your favorite collor : ";
            cin >> setColor;
            setConsoleColor(setColor);
            system("cls");
            saveStats();
            break;
        }
        case 5:
        {
            cout << "Are you sure you want to reset stats? (y/n): ";
            char confirm;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                resetStats();
                cout << "Stats have been reset." << endl;
            }
            else {
                cout << "Stats reset canceled." << endl;
            }
            break;
        }
        }
    }
    return 0;
}
