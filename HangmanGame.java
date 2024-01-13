import java.util.Scanner;
import java.util.Random;

public class HangmanGame {
    public static void main(String[] args) {
        // Main program start
        Scanner scanner = new Scanner(System.in);

        char guess = 0;
        final int wordLength = 7;
        final int maxAttempts = 6;

        // Word Bank
        String[] index = {"purple", "orange", /*...*/ "couple", "bridge"};
        int wordBankSize = index.length;

        // Selecting a random word from the index.
        Random random = new Random();
        int rand = random.nextInt(wordBankSize);
        String word = index[rand];

        // Deciding which random 2 letters of the word to show initially.
        Random letterRandom = new Random();
        int rand1 = letterRandom.nextInt(wordLength);
        int rand2;

        do {
            rand2 = letterRandom.nextInt(wordLength);
        } while (rand1 == rand2);

        // Game output starts.
        int wrong = 0;
        char[] guessed = new char[26];
        guessed[0] = '-';

        while (wrong <= maxAttempts) {
            // Your code for displaying the hangman figure and word status
            displayHangman(wrong);

            // Making display same as the output
            char[] display = new char[wordLength];
            for (int i = 0; i < wordLength; i++) {
                if (i == rand1 || i == rand2) display[i] = word.charAt(i);
                else {
                    display[i] = '_';
                }
            }

            // Output
            System.out.print("\t\t");
            for (int i = 0; i < wordLength; i++) {
                System.out.print(display[i] + " ");
            }
            System.out.println("\nChances left: " + (maxAttempts - wrong));
            System.out.print("Letters already guessed: ");
            for (int i = 0; i < wrong; i++) {
                System.out.print(guessed[i] + ",");
            }

            // Asking user for guess if chances left.
            if (wrong < maxAttempts) {
                System.out.print("\nGuess a letter (Use lowercase): ");
                guess = scanner.next().charAt(0);
            }

            // Checking if letter has been used before.
            boolean letterUsed = false;
            for (int i = 0; i < wrong; i++) {
                if (guess == guessed[i]) {
                    letterUsed = true;
                    System.out.println("\nYou have already guessed this letter before!");
                    break;
                }
            }

            if (!letterUsed) {
                // Checking if letter is present in the word.
                boolean correctGuess = false;
                for (int i = 0; i < wordLength; i++) {
                    if (guess == word.charAt(i)) {
                        display[i] = guess;
                        correctGuess = true;
                    }
                }

                if (correctGuess) {
                    System.out.println("\nGood guess!");
                } else {
                    System.out.println("\nWrong guess!");
                    wrong++;
                }

                guessed[wrong] = guess;
            }

            // Checking if user has guessed all letters.
            int rightCounter = 0;
            for (int i = 0; i < wordLength; i++) {
                if (display[i] == word.charAt(i)) {
                    rightCounter++;
                }
            }

            if (rightCounter == wordLength) {
                System.out.println("YOU WIN!!!");

                // You may choose to break out of the loop or handle further logic here.
                break;
            }
        }

        // Losing message
        if (wrong == maxAttempts) {
            displayHangman(wrong);
            System.out.println("\nThe correct word is " + word);
            System.out.println("GAME OVER! YOU LOST!!");
        }

        System.out.println("THANKS FOR PLAYING!!");
        scanner.close();
    }

    private static void displayHangman(int wrongAttempts) {
        System.out.println();

        switch (wrongAttempts) {
            case 0:
                System.out.println("  =============?");
                System.out.println(" ||            |");
                System.out.println(" ||");
                System.out.println(" ||");
                System.out.println(" ||");
                System.out.println(" ||");
                break;

            case 1:
                System.out.println("  =============?");
                System.out.println(" ||            |");
                System.out.println(" ||          /---\\");
                System.out.println(" ||          (   )");
                System.out.println(" ||          \\___/");
                System.out.println(" ||");
                break;

            case 2:
                System.out.println("  =============?");
                System.out.println(" ||            |");
                System.out.println(" ||          /---\\");
                System.out.println(" ||          (   )");
                System.out.println(" ||          \\___/");
                System.out.println(" ||           / | \\");
                System.out.println(" ||          /  |  \\");
                break;

            case 3:
                System.out.println("  =============?");
                System.out.println(" ||            |");
                System.out.println(" ||          /---\\");
                System.out.println(" ||          (   )");
                System.out.println(" ||          \\___/");
                System.out.println(" ||           / | \\");
                System.out.println(" ||          /  |  \\");
                System.out.println(" ||           /^\\");
                break;

            case 4:
                System.out.println("  =============?");
                System.out.println(" ||            |");
                System.out.println(" ||          /---\\");
                System.out.println(" ||          (   )");
                System.out.println(" ||          \\___/");
                System.out.println(" ||           / | \\");
                System.out.println(" ||          /  |  \\");
                System.out.println(" ||           /^\\");
                System.out.println(" ||          /   \\");
                break;

            case 5:
                System.out.println("  =============?");
                System.out.println(" ||            |");
                System.out.println(" ||          /---\\");
                System.out.println(" ||          (   )");
                System.out.println(" ||          \\___/");
                System.out.println(" ||           / | \\");
                System.out.println(" ||          /  |  \\");
                System.out.println(" ||           /^\\");
                System.out.println(" ||          /   \\");
                System.out.println(" ||         /     \\");
                break;

            case 6:
                System.out.println("  =============?");
                System.out.println(" ||            |");
                System.out.println(" ||          /---\\");
                System.out.println(" ||          (   )");
                System.out.println(" ||          \\___/");
                System.out.println(" ||           / | \\");
                System.out.println(" ||          /  |  \\");
                System.out.println(" ||           /^\\");
                System.out.println(" ||          /   \\");
                System.out.println(" ||         /     \\");
                System.out.println(" ||        /       \\");
                break;
        }
        System.out.println();
    }
}
