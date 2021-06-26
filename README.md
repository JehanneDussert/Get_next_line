### Welcome to my get_next_line repository 👋

⭐️ The goal of this subject was to code a program which reads content line by line.

## 💡 Usage

- You can change the file to read from the main :
```
fd = open("name_of_your_file", O_RDONLY);
```

- Then, run :
```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c
./a.out
```

✅ If there is another line to read, the program displays __1- the line__, if it is the last line __0- the line__
