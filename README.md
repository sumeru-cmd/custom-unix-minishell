# Custom Unix MiniShell

A simple Unix shell written in C. It reads commands from the terminal, parses arguments, and executes system binaries using `fork`, `execvp`, and `wait`. It also supports built-in commands like `cd` and `exit`.

## How to Run

Make sure you have GCC and a Unix environment (Linux, macOS, or WSL) installed.

1. Clone the repo and navigate into it:
   bash
   git clone [https://github.com/sumeru-cmd/minishell.git](https://github.com/sumeru-cmd/minishell.git)
   cd minishell
