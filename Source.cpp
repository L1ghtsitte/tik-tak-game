#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;
char square[9] = { '0','1','2','3','4','5','6','7','8' };

int checkwin()
{
    if (square[0] == square[1] && square[1] == square[2])
    {
        if (square[0] == 'X') return 1;
        else return 2;
    }
    else
    if (square[3] == square[4] && square[4] == square[5])
    {
       if (square[3] == 'X') return 1;
       else return 2;
   }
   else
   if (square[6] == square[7] && square[7] == square[8])
   {
       if (square[6] == 'X') return 1;
       else return 2;
   }
   else
   if (square[0] == square[3] && square[3] == square[6])
   {
       if (square[0] == 'X') return 1;
       else return 2;
   }
   else
   if (square[1] == square[4] && square[4] == square[7])
   {
       if (square[1] == 'X') return 1;
       else return 2;
   }
   else
   if (square[2] == square[5] && square[5] == square[8])
   {
       if (square[2] == 'X') return 1;
       else return 2;
   }
   else
   if (square[0] == square[4] && square[4] == square[8])
   {
       if (square[0] == 'X') return 1;
       else return 2;
   }
   else
   if (square[2] == square[4] && square[4] == square[6])
   {
       if (square[2] == 'X') return 1;
       else return 2;
   }
   else
   if (square[0] == square[3] && square[3] == square[6])
   {
       if (square[0] == 'X') return 1;
       else return 2;
   }
   else return 0;
}

void mark(int player, int box)
{
    if (player == 1 ) square[box] = 'X';
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

void setConsoleColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

void statsPlayer(string player1Name, string player2Name, int match1, int match2, double winrate1, double loserate1, double drawrate1, double winrate2, double loserate2, double drawrate2, int setColor)
{
    double winperpr1;
    double lossperpr1;
    double drawperpr1;
    double winperpr2;
    double lossperpr2;
    double drawperpr2;

    string name1 = player1Name;
    string name2 = player1Name;
    string color;

    winperpr1 = winrate1 / match1 * 100;
    lossperpr1 = loserate1 / match1 * 100;
    drawperpr1 = drawrate1 / match1 * 100;
    winperpr2 = winrate2 / match2 * 100;
    lossperpr2 = loserate2 / match2 * 100;
    drawperpr2 = drawrate2 / match2 * 100;

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
    std::ofstream out;    
    out.open("stats.txt");
    if (out.is_open())
    {
        out << "-----------------------------" << endl;
        out << "| Color : "<< color << "   | " << endl;
        out << "-----------------------------" << endl;
        out << "| Name : " << player1Name << "   | " << endl;
        out << "-----------------------------" << endl;
        out << "| Matches : " << match1 << " | " << endl;
        out << "| Win : " << winrate1 << "  | " << winperpr1 << "%|" << endl;
        out << "| Loss : " << loserate1 << " | " << lossperpr1 << "%|" << endl;
        out << "| Draw : " << drawrate1 << " | " << drawperpr1 << "%|" << endl;
        out << "-----------------------------" << endl;
        out << "| Name : " << player2Name << "   | " << endl;
        out << "-----------------------------" << endl;
        out << "| Matches : " << match2 << " | " << endl;
        out << "| Win : " << winrate2 << "  | " << winperpr2 << "%|" << endl;
        out << "| Loss : " << loserate2 << " | " << lossperpr2 << "%|" << endl;
        out << "| Draw : " << drawrate2 << " | " << drawperpr2 << "%|" << endl;
        out << "-----------------------------" << endl;
    }                
    out.close();
}
void vivod(string player1Name, string player2Name, int match1, int match2, double winrate1, double loserate1, double drawrate1, double winrate2, double loserate2, double drawrate2, int setColor)
{
    double winperpr1;
    double lossperpr1;
    double drawperpr1;
    double winperpr2;
    double lossperpr2;
    double drawperpr2;

    string name1 = player1Name;
    string name2 = player1Name;
    string color;

    winperpr1 = winrate1 / match1 * 100;
    lossperpr1 = loserate1 / match1 * 100;
    drawperpr1 = drawrate1 / match1 * 100;
    winperpr2 = winrate2 / match2 * 100;
    lossperpr2 = loserate2 / match2 * 100;
    drawperpr2 = drawrate2 / match2 * 100;

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
    cout << "| Name : " << player1Name << "   | " << endl;
    cout << "-----------------------------" << endl;
    cout << "| Matches : " << match1 << " | " << endl;
    cout << "| Win : " << winrate1 << "  | " << winperpr1 << "%|" << endl;
    cout << "| Loss : " << loserate1 << " | " << lossperpr1 << "%|" << endl;
    cout << "| Draw : " << drawrate1 << " | " << drawperpr1 << "%|" << endl;
    cout << "-----------------------------" << endl;
    cout << "| Name : " << player2Name << "   | " << endl;
    cout << "-----------------------------" << endl;
    cout << "| Matches : " << match2 << " | " << endl;
    cout << "| Win : " << winrate2 << "  | " << winperpr2 << "%|" << endl;
    cout << "| Loss : " << loserate2 << " | " << lossperpr2 << "%|" << endl;
    cout << "| Draw : " << drawrate2 << " | " << drawperpr2 << "%|" << endl;
    cout << "-----------------------------" << endl;
}


int main()
{
    int player1 = 1;
    int player2 = 2;
    int setColor = 7;
    int match1 = 0;
    int match2 = 0;
    double loserate1 = 0;
    double drawrate1 = 0;
    double winrate1 = 0;
    double drawrate2 = 0;
    double loserate2 = 0;
    double winrate2 = 0;

    int box;
    int result = 0;
    int flag = 0;
    int choise = 0;

    string player1Name;
    string player2Name;

    ofstream oFile("stats.txt");

    while (true)
    {
        cout << "ver 0.1 - By L1ghtsitte" << endl;
        cout << "Play - 1" << endl;
        cout << "Info - 2" << endl;
        cout << "Change color - 3" << endl;
        cout << "Your choise - ";
        cin >> choise;
        system("cls");

        switch (choise)
        {
        case 1:
        {
            cout << "Player 1 enter name : ";
            cin >> player1Name;
            match1 += 1;
            cout << "Player 2 enter name : ";
            cin >> player2Name;
            match2 += 1;
            system("cls");

            for (int i = 1; i < 5; i++)
            {   
                system("cls");
                display();
                cout << player1Name << endl << "Enter the Box : ";
                cin >> box;
                if (box >= 9 || box < 0)
                {
                    cout << "Eter again : ";
                    cin >> box;
                }
                for (int i = 0; i < 9; i++)
                {
                    if (square[box] == 'O')
                    {
                        cout << "Eter again : ";
                        cin >> box;
                    }
                }
                mark(player1, box);
                display();

                result = checkwin();
                if (result == 1)
                {
                    system("cls");
                    display();
                    cout << "Congratualtions! player " << player1Name << " has Won " << endl;
                    flag = 1;
                    winrate1 += 1;
                    loserate2 += 1;
                    statsPlayer(player1Name, player2Name, match1, match2, winrate1, loserate1, drawrate1, winrate2, loserate2, drawrate2, setColor);
                    break;
                }
                else
                    if (result == 2)
                    {
                        system("cls");
                        display();
                        cout << "Congratualtions! player " << player2Name << " has Won " << endl;
                        flag = 1;
                        winrate2 += 1;
                        loserate1 += 1;
                        statsPlayer(player1Name, player2Name, match1, match2, winrate1, loserate1, drawrate1, winrate2, loserate2, drawrate2, setColor);
                        break;
                    }
                system("cls");
                display();
                cout << player2Name << endl << "Enter the Box : ";
                cin >> box;
                if (box >= 9 || box < 0)
                {
                    cout << "Eter again : ";
                    cin >> box;
                }
                for (int i = 0; i < 9; i++)
                {
                    if (square[box] == 'X')
                    {
                        cout << "Eter again : ";
                        cin >> box;
                    }
                }
                mark(player2, box);
                display();

                result = checkwin();
                if (result == 1)
                {
                    system("cls");
                    display();
                    cout << "Congratualtions! player " << player1Name << " has Won " << endl;
                    flag = 1;
                    winrate1 += 1;
                    loserate2 += 1;
                    statsPlayer(player1Name, player2Name, match1, match2, winrate1, loserate1, drawrate1, winrate2, loserate2, drawrate2, setColor);
                    break;
                }
                else
                    if (result == 2)
                    {
                        system("cls");
                        display();
                        cout << "Congratualtions! player " << player2Name << " has Won " << endl;
                        flag = 1;
                        winrate2 += 1;
                        loserate1 += 1;
                        statsPlayer(player1Name, player2Name, match1, match2, winrate1, loserate1, drawrate1, winrate2, loserate2, drawrate2, setColor);
                        break;
                    }
            }
            if (flag == 0)
            {
                system("cls");
                display();
                cout << "The game is a draw " << endl;
                drawrate1 += 1;
                drawrate2 += 1;
                statsPlayer(player1Name, player2Name, match1, match2, winrate1, loserate1, drawrate1, winrate2, loserate2, drawrate2, setColor);
            }
            cout << "For new game : " << endl;
            clear();
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            vivod(player1Name, player2Name, match1, match2, winrate1, loserate1, drawrate1, winrate2, loserate2, drawrate2, setColor);
            break;
        }
        case 3:
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
            break;
        }
        }
    }
}