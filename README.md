# 🔓 Hackout - Terminal Hacking Game

A terminal-based password cracking game inspired by the hacking minigame### Manual Compilation

```bash
# Build the project
make

# Or build and run immediately
make game

# Clean object files
make clean

# Clean everything
make fclean

# Rebuild from scratch
make re
```t video game series. Test your pattern recognition skills by finding the correct password hidden among random gibberish in a retro computer terminal interface.

## 🎮 Game Overview

Hackout simulates a ROBCO Industries terminal where you must crack a password by selecting the correct word from a grid of random characters. The game features three difficulty levels with increasing word lengths and complexity.

### Features

- **3 Difficulty Levels**: Choose from 4, 5, or 6-letter words
- **Retro Terminal Aesthetics**: Green monospace text with typewriter effect
- **Password Similarity Feedback**: Get hints about how close your guess was
- **Limited Attempts**: 4 attempts before lockout
- **Random Word Pool**: Hundreds of words across all difficulty levels

## Quick Start

### Prerequisites

- GCC compiler
- Make utility
- Linux/Unix environment with terminal support

### Installation & Running

1. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/Hackerout-0.1.git
   cd Hackerout-0.1
   ```

2. **Compile and run**
   ```bash
   make game
   ```

   Or compile manually:
   ```bash
   make
   ./hackerout play
   ```

3. **Start the game**
   ```bash
   ./hackerout play
   ```

## How to Play

1. **Select Difficulty**: Choose access level 1-3
   - Level 1: 4-letter words
   - Level 2: 5-letter words  
   - Level 3: 6-letter words

2. **Analyze the Terminal**: Look for actual words hidden among random symbols in the hexadecimal dump-style display

3. **Enter Your Guess**: Type the word you think is the password

4. **Use Feedback**: The game shows similarity score (number of correct letters in correct positions)

5. **Win or Lose**: 
   - Success: "PASSWORD ACCEPTED. ACCESS GRANTED."
   - Failure: "TOO MANY FAILED ATTEMPTS. INTRUDER DETECTED."

## Project Structure

```
├── builder.c       # Generates the terminal display grid
├── foh.h          # Main header file with function prototypes
├── getter.c       # Loads word lists from level files
├── injector.c     # Injects real words into the random grid
├── launcher.c     # Main entry point and game initialization
├── manager.c      # Handles user input and game logic
├── printer.c      # Terminal output with retro styling
├── Makefile       # Build configuration
├── levels/        # Word lists for each difficulty
│   ├── level1.txt # 4-letter words
│   ├── level2.txt # 5-letter words
│   └── level3.txt # 6-letter words
└── libft/         # Custom C library functions
```

## Technical Details

### Core Components

- **Builder Module**: Creates randomized terminal display with hex addresses and symbols
- **Injector Module**: Strategically places real words within the gibberish
- **Manager Module**: Handles game state, input validation, and similarity checking
- **Printer Module**: Provides retro terminal aesthetics with green text and typewriter effects

### Word Lists

- **Level 1**: 101 four-letter words (ABLE, ACID, AIDE...)
- **Level 2**: 123 five-letter words (ABOUT, ACORN, ACTOR...)
- **Level 3**: 131 six-letter words (ABANDON, ABDUCT, ABJURE...)

### Display Format

The game generates a hex dump-style display:
```
0x1234  &#@$WORD%^&*  0x5678  !@#$%^&*()
0x9ABC  *()_+PASS=[]  0xDEFG  {}|:"<>?
```

Real words are hidden among the random symbols in designated injection zones.

## Building from Source

### Manual Compilation

```bash
# Compile individual components
cc -Wall -Werror -Wextra -I. -c launcher.c -o launcher.o
cc -Wall -Werror -Wextra -I. -c builder.c -o builder.o
cc -Wall -Werror -Wextra -I. -c printer.c -o printer.o
cc -Wall -Werror -Wextra -I. -c getter.c -o getter.o
cc -Wall -Werror -Wextra -I. -c injector.c -o injector.o
cc -Wall -Werror -Wextra -I. -c manager.c -o manager.o

# Create static library
ar rcs foh.a *.o libft/*.o

# Link and create executable
cc printer.c builder.c launcher.c injector.c manager.c foh.a -o hackout
```

### Make Targets

- `make` or `make all`: Build the executable
- `make game`: Build and run the game immediately
- `make clean`: Remove object files and dependencies
- `make fclean`: Remove all generated files
- `make re`: Clean rebuild

## Screenshots



## Contributing

Contributions are welcome! Here are some areas for improvement:

- Add more difficulty levels
- Implement hint system
- Add sound effects
- Create GUI version
- Add more word categories
- Improve terminal animations

### Development Setup

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## TODO

- [ ] Add configuration file for custom word lists
- [ ] Implement save/load game state
- [ ] Add statistics tracking
- [ ] Create difficulty scaling system
- [ ] Add color customization options
- [ ] Implement multiplayer mode

## Known Issues

- Input buffer size limitation for longer words
- Memory management could be optimized
- No input validation for special characters

## License

This project is open source. Feel free to use, modify, and distribute as needed.

## Inspiration

This game is inspired by the terminal hacking minigames from the *Fallout* series by Bethesda Game Studios. It recreates the tense atmosphere of cracking into abandoned computer terminals in a post-apocalyptic world.

---

*Enjoy cracking those passwords! Remember: In the wasteland, knowledge is power.*⚡
