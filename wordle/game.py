import json
import random
from os import system, name
from time import sleep

with open("WordList.json", "r") as f:
    RAW_WORD_LIST = json.load(f)["words"]

WORD = random.choice(RAW_WORD_LIST)
GRID = [[" " for _ in range(5)] for _ in range(6)]
INCORRECT_WORDS = []

TITLE = r"""
     __       __   ______   _______   _______   __        ________         ______   __         ______   __    __  ________
    /  |  _  /  | /      \ /       \ /       \ /  |      /        |       /      \ /  |       /      \ /  \  /  |/        |
    $$ | / \ $$ |/$$$$$$  |$$$$$$$  |$$$$$$$  |$$ |      $$$$$$$$/       /$$$$$$  |$$ |      /$$$$$$  |$$  \ $$ |$$$$$$$$/
    $$ |/$  \$$ |$$ |  $$ |$$ |$$ |$$ |  $$ |$$ |      $$ |__          $$ |  $$/ $$ |      $$ |  $$ |$$$  \$$ |$$ |__
    $$ /$$$  $$ |$$ |  $$ |$$    $$< $$ |  $$ |$$ |      $$    |         $$ |      $$ |      $$ |  $$ |$$$$  $$ |$$    |
    $$ $$/$$ $$ |$$ |  $$ |$$$$$$$  |$$ |  $$ |$$ |      $$$$$/          $$ |   __ $$ |      $$ |  $$ |$$ $$ $$ |$$$$$/
    $$$$/  $$$$ |$$ \$$ |$$ |  $$ |$$ |$$ |$$ |_____ $$ |_____       $$ \/  |$$ |_____ $$ \$$ |$$ |$$$$ |$$ |_____
    $$$/    $$$ |$$    $$/ $$ |  $$ |$$    $$/ $$       |$$       |      $$    $$/ $$       |$$    $$/ $$ | $$$ |$$       |
    $$/      $$/  $$$$$$/  $$/   $$/ $$$$$$$/  $$$$$$$$/ $$$$$$$$/        $$$$$$/  $$$$$$$$/  $$$$$$/  $$/   $$/ $$$$$$$$/
"""

INSTRUCTIONS = """
INSTRUCTIONS:
    1) A random 5-letter word is selected by the computer. The objective of the game is to guess the word within 6 moves.

    2) The user must enter valid 5-letter words every time they wish to make a guess.

    3) Incorrect letters of the guess become visible in the 'Incorrect Letters' list.

    4) Correct letters that are in the correct position are visible as 'UPPERCASE' characters.

    5) Correct letters that are in the wrong position are visible as 'lowercase' characters.
"""


def user_input() -> str:
    inp = input("Enter a 5-letter word that you think may be the answer: ").capitalize()
    # Remove or comment out the following line to prevent revealing the answer
    # print(inp, WORD)
    if len(inp) != 5:
        print(f"The entered word '{inp}' is not of length '5', try again\n")
        return user_input()

    if inp not in RAW_WORD_LIST:
        print(f"The entered word '{inp}' is not recognized by the game dictionary, try again\n")
        return user_input()

    return inp


def print_grid():
    for row in GRID:
        colored_row = []
        for letter in row:
            if letter.isupper():
                colored_row.append(f"\033[92m{letter}\033[0m")  # green for correct letters
            elif letter.islower():
                colored_row.append(f"\033[91m{letter}\033[0m")  # red for incorrect letters
            else:
                colored_row.append(letter)  # default white
        print("|", " | ".join(colored_row), "|")


def clear_screen():
    if name == "nt":
        _ = system("cls")
    else:
        _ = system("clear")


def compare_characters(inp: str, TURNS: int):
    compare = list(zip(inp, WORD))
    for idx, char in enumerate(inp):
        if char.lower() in WORD.lower():
            GRID[TURNS][idx] = char.lower()
        else:
            INCORRECT_WORDS.append(char.lower())

    for idx, tup in enumerate(compare):
        if len(set(tup)) == 1:
            GRID[TURNS][idx] = tup[0].upper()


def game_logic():
    TURNS = 0
    while TURNS < 5:

        print(f"\nTURN NUMBER: {TURNS + 1}\n")

        print("\nINCORRECT_WORDS:")
        print(list(set(INCORRECT_WORDS)))
        print()

        print("\nCURRENT GRID")
        print_grid()

        print()
        inp = user_input()

        compare_characters(inp, TURNS)
        print(f"\nInputted word >>> {inp}")

        print("\nINCORRECT_WORDS:")
        print(list(set(INCORRECT_WORDS)))
        print()

        print("\nCURRENT GRID")
        print_grid()

        if inp == WORD:
            print(f"You guessed the word {WORD} in {TURNS + 1} turns")
            break

        play = input("Enter [y/Y] to continue the game: ").lower()
        if play not in "yes":
            print("Quitting game")
            break

        print("Continuing game")

        TURNS += 1
        sleep(0.5)
        clear_screen()

    else:
        print("You were not able to guess the word")
        print(f"The word was >>> {WORD}")
        print("Your current grid state is\n")
        print_grid()


def main():
    clear_screen()

    print(TITLE)
    print("\n\n\n")

    print("This is your grid")
    print_grid()
    print("\n", INSTRUCTIONS)

    play = input("Enter [y/Y] to play the game: ").lower()
    if play not in "yes":
        print("Quitting game")
        return
    sleep(0.5)
    clear_screen()

    game_logic()


main()