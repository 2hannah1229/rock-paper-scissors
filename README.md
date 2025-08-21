# RockPaperScissors Game

A simple C++ console-based Rock-Paper-Scissors game supporting two modes:
- Player vs Computer
- Computer vs Computer

## Features

- Choose game mode
- Enter player name (Player vs Computer)
- Specify odd number of rounds
- Play rounds (draws are replayed)
- See round-by-round results and overall winner
- Optionally save results to a timestamped file


## How to Play

1. Choose a game mode:
    - 1: Player vs Computer
    - 2: Computer vs Computer
    - 3: Exit
2. Enter the number of rounds (must be odd and positive).
3. Enter your name (if Player vs Computer).
4. Play each round (choose 1 for rock, 2 for paper, 3 for scissors).
5. View results and choose whether to save them to a file.

## File Output

If you choose to save results, a `.txt` file will be created with a summary of all rounds and the winner.

## Requirements

- C++ compiler (clang++ or g++)
- macOS or Linux recommended

## Notes

- All game logic is encapsulated in the `RockPaperScissors` class.
- Only one `main()` function should exist (in `main.cpp`).
- Results files are timestamped for uniqueness.
