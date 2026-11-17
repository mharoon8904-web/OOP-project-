#ifndef TYPES_H
#define TYPES_H

#include <iostream>

// ============================================================================
// ENUMERATIONS
// ============================================================================
enum GameState {
    MAIN_MENU,
    GAME_RUNNING,
    GAME_WON,
    GAME_LOST
};

enum MenuChoice {
    NEW_GAME    = 1,
    LEADERBOARD = 2,
    ABOUT       = 3,
    RULES       = 4,
    EXIT_GAME   = 5
};

enum WordRow {
    ROW_ONE,    // Row 1: 7-letter word (gathered from 7 locations)
    ROW_TWO     // Row 2: 8-letter word (gathered from 8 characters)
};

// ============================================================================
// STRING UTILITIES (POINTER ARITHMETIC ONLY, ZERO CRT SECURE MACROS)
// ============================================================================
int  strLenPtr(const char* str);
void copyStrPtr(char*& dest, const char* src);
void copyToBufPtr(char* dest, int maxLen, const char* src);
bool strEqualPtr(const char* s1, const char* s2);

// ============================================================================
// FOUNDATIONAL STRUCTS
// ============================================================================
struct Tile {
    char    tileLetter;
    bool    filled;
    int     boardPos;
    WordRow tileRow;

    Tile();
    Tile(char letter, int pos, WordRow row);

    bool operator==(const Tile& other) const;
    bool operator==(char ch) const;

    friend std::ostream& operator<<(std::ostream& os, const Tile& t);
    friend std::istream& operator>>(std::istream& is, Tile& t);
};

struct Clue {
    char    clueLetter;
    int     cluePosition;
    WordRow clueRow;

    Clue();
    Clue(char letter, int pos, WordRow row);
};

struct Location {
    char*   locName;        // Dynamically allocated room name
    char    letterClueLoc;
    int     boardPosLoc;
    WordRow locRow;
    bool    locSearchFlag;

    Location();
    Location(const char* name, char letter, int pos, WordRow row);
    Location(const Location& other);
    Location& operator=(const Location& other);
    ~Location();

    friend std::ostream& operator<<(std::ostream& os, const Location& l);
    friend std::istream& operator>>(std::istream& is, Location& l);
};

#endif // TYPES_H
