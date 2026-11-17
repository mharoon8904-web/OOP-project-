#include "Types.h"

// ============================================================================
// STRING UTILITIES VIA PURE POINTER ARITHMETIC
// ============================================================================
int strLenPtr(const char* str) {
    if (!str) return 0;
    int len = 0;
    const char* p = str;
    while (*p != '\0') {
        ++len;
        ++p;
    }
    return len;
}

void copyStrPtr(char*& dest, const char* src) {
    delete[] dest;
    dest = nullptr;
    if (!src) return;

    int len = strLenPtr(src);
    dest = new char[len + 1];

    char* d = dest;
    const char* s = src;
    while (*s != '\0') {
        *d = *s;
        ++d;
        ++s;
    }
    *d = '\0';
}

void copyToBufPtr(char* dest, int maxLen, const char* src) {
    if (!dest || maxLen <= 0) return;
    char* d = dest;
    const char* s = src;
    int count = 0;
    if (s) {
        while (*s != '\0' && count < maxLen - 1) {
            *d = *s;
            ++d;
            ++s;
            ++count;
        }
    }
    *d = '\0';
}

bool strEqualPtr(const char* s1, const char* s2) {
    if (!s1 || !s2) return false;
    const char* p1 = s1;
    const char* p2 = s2;
    while (*p1 != '\0' && *p2 != '\0') {
        if (*p1 != *p2) return false;
        ++p1;
        ++p2;
    }
    return (*p1 == '\0' && *p2 == '\0');
}

// ============================================================================
// Tile Implementation
// ============================================================================
Tile::Tile() : tileLetter('\0'), filled(false), boardPos(-1), tileRow(ROW_ONE) {}

Tile::Tile(char letter, int pos, WordRow row)
    : tileLetter(letter), filled(false), boardPos(pos), tileRow(row) {}

bool Tile::operator==(const Tile& other) const {
    return tileLetter == other.tileLetter;
}

bool Tile::operator==(char ch) const {
    return tileLetter == ch;
}

std::ostream& operator<<(std::ostream& os, const Tile& t) {
    os << (t.tileLetter != '\0' ? t.tileLetter : '_');
    return os;
}

std::istream& operator>>(std::istream& is, Tile& t) {
    int r = 0;
    is >> t.tileLetter >> t.filled >> t.boardPos >> r;
    t.tileRow = static_cast<WordRow>(r);
    return is;
}

// ============================================================================
// Clue Implementation
// ============================================================================
Clue::Clue() : clueLetter('\0'), cluePosition(0), clueRow(ROW_ONE) {}

Clue::Clue(char letter, int pos, WordRow row)
    : clueLetter(letter), cluePosition(pos), clueRow(row) {}

// ============================================================================
// Location Implementation (Rule of Three)
// ============================================================================
Location::Location()
    : locName(nullptr), letterClueLoc('\0'), boardPosLoc(0),
      locRow(ROW_ONE), locSearchFlag(false) {}

Location::Location(const char* name, char letter, int pos, WordRow row)
    : locName(nullptr), letterClueLoc(letter), boardPosLoc(pos),
      locRow(row), locSearchFlag(false) {
    copyStrPtr(locName, name);
}

Location::Location(const Location& other)
    : locName(nullptr), letterClueLoc(other.letterClueLoc),
      boardPosLoc(other.boardPosLoc), locRow(other.locRow),
      locSearchFlag(other.locSearchFlag) {
    copyStrPtr(locName, other.locName);
}

Location& Location::operator=(const Location& other) {
    if (this != &other) {
        copyStrPtr(locName, other.locName);
        letterClueLoc = other.letterClueLoc;
        boardPosLoc   = other.boardPosLoc;
        locRow        = other.locRow;
        locSearchFlag = other.locSearchFlag;
    }
    return *this;
}

Location::~Location() {
    delete[] locName;
    locName = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Location& l) {
    os << (l.locName ? l.locName : "Unknown Room")
       << (l.locSearchFlag ? " [SEARCHED]" : " [Unsearched]");
    return os;
}

std::istream& operator>>(std::istream& is, Location& l) {
    char buffer[256];
    is.getline(buffer, 256);
    copyStrPtr(l.locName, buffer);
    return is;
}
