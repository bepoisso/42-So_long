<div align="center">
  <img height="200" src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/so_long.png" />
</div>

# So Long - A 2D Escape Game

**So Long** is a project where you will develop a 2D game using the **MiniLibX**, with textures, sprites, and basic gameplay mechanics. This project introduces you to graphical programming and event handling in C.

## Status
<div align="center">
  <img height="200" src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/so_long_success.png" />
</div>

<div align="center">
  <img src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/solong_exp.png" />
</div>
<div align="center">
  <img src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/solong_exp2.png" />
</div>
<div align="center">
  <img src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/solong_exp3.png" />
</div>

## How to run my so_long ?
Just clone the repo

```Make``` inside the repo

to execute : ```./so_long your_42_login map_you_would_use.ber```

(the 42login is used for add your score in scoreboard)
You can send me your score and i'm gonna add it inside the scorboard file (With the default map).


## Objectives

The main goal is to program a game where the player must collect all items on the map and escape through the exit while adhering to the following constraints:

- Use **MiniLibX** for graphical rendering.
- Write the program in **C**, following strict coding standards (Norm).
- Properly manage memory (no **memory leaks**).
- Validate and parse maps in the `.ber` format.

## Useful Resources

<li><a href="https://harm-smits.github.io/42docs/libs/minilibx">MiniLibX Doc</a></li>
<li><a href="https://suspectedoceano.notion.site/So_long-bccdb29d879049a0981404886e097230">So_Long Tester</a></li>

## Key Features

<table>
  <tr>
    <th>Program Name</th>
    <td>so_long</td>
  </tr>
  <tr>
    <th>Submission Files</th>
    <td>Makefile, *.h, *.c, maps, textures</td>
  </tr>
  <tr>
    <th>Arguments</th>
    <td>A map in the *.ber format</td>
  </tr>
  <tr>
    <th>Allowed External Functions</th>
    <td>open, close, read, write, malloc, free, perror, strerror, exit, MiniLibX functions</td>
  </tr>
  <tr>
    <th>Libft Allowed</th>
    <td>Yes</td>
  </tr>
  <tr>
    <th>Description</th>
    <td>A game where the player collects items and escapes a labyrinth.</td>
  </tr>
</table>

### Rules

1. The map must:
   - Be rectangular and surrounded by walls.
   - Contain at least one exit, one collectible item, and one starting position.
   - Follow a valid structure (`0, 1, C, E, P`).
2. The **W, A, S, D** keys are used to move the player.
3. Each movement is counted and displayed in the terminal.
4. The window must close properly via `ESC` or clicking the window close button.

### Bonus Features

- Add patrolling enemies that can defeat the player.
- Display the move count directly on the game window.
- Animate sprites to enhance aesthetics.

## Example Map


## Compilation and Execution

Compile the program with the provided **Makefile**:
make
./so_long maps/example.ber
The program should display a window containing the map and allow user interaction.

Good luck and enjoy working on this project!

---
Feel free to add a issue if you find it and i will fix it.
(Leak, Error, Missing feature, etc...)
