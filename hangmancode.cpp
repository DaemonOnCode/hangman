#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    //Main program start
    clrscr();
    int wrand, i = 0, lrand1, lrand2, turn = 0, wrong = 0, result = 100, rightcounter;
    //Word Bank
    char go, guess, guessed[27], word[7], display[7], index[51][7] = {"purple", "orange", "family", "twelve", "silver", "thirty", "donate", "people", "future", "heaven", "banana", "africa", "monday", "office", "nature", "eleven", "mumbai", "animal", "twenty", "snitch", "friday", "father", "yellow", "poetry", "august", "broken", "potato", "circle", "school", "breath", "moment", "circus", "person", "scarce", "london", "energy", "sister", "spring", "change", "monkey", "system", "austin", "secret", "pirate", "turtle", "mother", "ginger", "cousin", "couple", "bridge"};
    guessed[0] = '-';
    cout << "\n\n\nWELCOME! PRESS ANY KEY AND ENTER TO PLAY HANGMAN!!";
    cin >> go;
    //Selecting random word from index.
    srand(time(NULL));
    wrand = rand() % 49;
    for (i = 0; i < 7; i++)
    {
        word[i] = index[wrand][i];
    }
    //Deciding which random 2 letters of the word to show initially.
    srand(time(NULL));
    lrand1 = rand() % 5;
randomno2:
    lrand2 = rand() % 5;

    //Making sure they are not same.
    if (lrand1 == lrand2)
    {
        goto randomno2;
    }
    //Game output starts.
    for (wrong = 0; wrong <= 6;)
    {
    loopstart:
        clrscr();
        //Man
        cout << endl;
        cout << "          =============?";
        cout << endl
             << "         ||            |";
        cout << endl
             << "         ||          ";
        if (wrong >= 1)
            cout << "/---\\";
        cout << endl
             << "         ||          ";
        if (wrong >= 1)
            cout << "(   )";
        cout << endl
             << "         ||          ";
        if (wrong >= 1)
            cout << "\\___/";
        cout << endl
             << "         ||           ";
        if (wrong >= 3)
            cout << "/";
        if (wrong == 2)
            cout << " ";
        if (wrong >= 2)
            cout << "|";
        if (wrong >= 4)

            cout << "\\";
        cout << endl
             << "         ||          ";
        if (wrong >= 3)
            cout << "/ ";
        if (wrong == 2)
            cout << "  ";
        if (wrong >= 2)
            cout << "|";
        if (wrong >= 4)
            cout << " \\";
        cout << endl
             << "         ||           ";
        if (wrong >= 5)
            cout << "/^";
        if (wrong >= 6)
            cout << "\\";
        cout << endl
             << "         ||          ";
        if (wrong >= 5)
            cout << "/";
        if (wrong >= 6)
            cout << "   \\";
        cout << endl
             << "         ||                               ";
        cout << endl
             << "        /||\\                                 ";
        //Making display same as the output
        if (turn == 0)
        {
            for (i = 0; i < 7; i++)
            {
                if ((i == lrand1) || (i == lrand2))
                {
                    display[i] = word[i];
                }

                else
                {
                    display[i] = '_';
                }
            }
        }
        //Output
        cout << endl
             << "\t\t";
        for (i = 0; i < 6; i++)
        {
            cout << display[i] << " ";
        }
        if (rightcounter == 6)
        {
            goto win;
        }
        cout << endl
             << "Chances left:" << 6 - wrong;
        cout << endl
             << "Letters already guessed:";
        for (i = 0; i < turn; i++)
        {
            cout << guessed[i] << ",";
        }
        //Turn change comments.
        if (result == 0)
        {
            cout << endl
                 << "You have already guessed this letter before!";
        }
        if (result == 1)
        {
            cout << endl
                 << "Wrong guess!";
        }

        if (result == 2)
        {
            cout << endl
                 << "Good guess!";
        }
        //Asking user for guess if chances left.
        if (wrong < 6)
        {
            cout << endl
                 << "Guess a letter(Use lowercase):";
            cin >> guess;
        }
        guessed[turn] = guess;
        //Checking if letter has been used before.
        for (i = 0; i < turn; i++)
        {
            if (guess == guessed[i])
            {
                result = 0;
                goto checkskip;
            }
        }
        //Checking if letter is present in the word.
        result = 1;
        for (i = 0; i < 6; i++)
        {
            if (guess == word[i])
            {
                display[i] = word[i];
                result = 2;
            }
        }
        if (result == 1)

        {
            wrong++;
        }
    checkskip:
        rightcounter = 0;
        for (i = 0; i < 6; i++)
        {
            if (display[i] == word[i])
            {
                rightcounter++;
            }
        }
        //Checking if user has guessed all letters.
        if (rightcounter == 6)
        {
            goto loopstart;
        }
        turn++;
    }
    //Winning message
win:
    cout << endl
         << "\t\t       YOU WIN!!!";
    //Losing message
    if (wrong == 6)
    {
        clrscr();
        //Man
        cout << endl;
        cout << "          =============?";
        cout << endl
             << "         ||            |";
        cout << endl
             << "         ||          ";

        cout << "/---\\";
        cout << endl
             << "         ||          ";
        cout << "(* *)";
        cout << endl
             << "         ||          ";
        cout << "\\___/";
        cout << endl
             << "         ||           ";
        cout << "/";
        cout << "|";
        cout << "\\";
        cout << endl
             << "         ||          ";
        cout << "/";
        cout << " ";
        cout << "|";
        cout << " \\";
        cout << endl
             << "         ||           ";
        cout << "/^";
        cout << "\\";
        cout << endl
             << "         ||          ";
        cout << "/";
        cout << "   \\";
        cout << endl
             << "         ||                               ";
        cout << endl
             << "        /||\\                                 ";
        cout << endl
             << endl
             << "The correct word is ";
        for (i = 0; i < 6; i++)
        {
            cout << index[wrand][i];
        }
        cout << endl
             << "\t\tGAME OVER! YOU LOST!!";
    }
    //Asking if user wants to quit.

chose:
    cout << endl
         << "\t\tTHANKS FOR PLAYING!!";
    getch();
}
