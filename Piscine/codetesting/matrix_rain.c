/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:01:50 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/08 18:06:03 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DELAY 30000   // Speed of the matrix rain (reduce for faster effect)
#define WIDTH  1900    // Width of the matrix effect (increase for bigger screens)
#define HEIGHT 1080   // Height of the terminal
#define DENSITY 100     // Number of falling characters per column

// List of possible symbols to enhance the Matrix effect
const char matrix_symbols[] = "vwxyz@#$%^&*()[]{}<>/|\\~";

int symbols_length;

// Function to initialize the column positions randomly
void initialize_columns(int columns[], int width) {
    for (int i = 0; i < width; i++) {
        columns[i] = rand() % HEIGHT;  // Random starting position
    }
}

// Function to generate random characters from the symbol list
char random_char() {
    return matrix_symbols[rand() % symbols_length];
}

int main() {
    int columns[WIDTH];  // Array to store column positions
    symbols_length = sizeof(matrix_symbols) - 1;
    
    srand(time(0));      // Seed random generator
    initscr();           // Start ncurses mode
    noecho();            // Don't echo user input
    curs_set(0);         // Hide cursor
    nodelay(stdscr, TRUE); // Make getch non-blocking
    start_color();       // Enable color
    init_pair(1, COLOR_GREEN, COLOR_BLACK); // Green on black

    initialize_columns(columns, WIDTH); // Initialize starting points

    while (1) {
        clear();  // Clear the screen
        attron(COLOR_PAIR(1)); // Apply green color

        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < DENSITY; j++) { // Increase density per column
                int y = (columns[i] + j) % HEIGHT;  // Generate multiple drops per column
                mvaddch(y, i, random_char()); // Print a random character at (y, i)
            }
            columns[i] = (columns[i] + 1) % HEIGHT; // Move down, reset at bottom
        }

        attroff(COLOR_PAIR(1)); // Turn off color
        refresh();  // Update the screen
        usleep(DELAY);  // Delay to control speed

        if (getch() == 'q') break; // Exit if user presses 'q'
    }

    endwin(); // End ncurses mode
    return 0;
}

