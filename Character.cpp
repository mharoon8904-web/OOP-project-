#include "Character.h"

Character::Character()
    : charName(nullptr), charRole(nullptr), clueTile('\0'),
      cluePosition(0), clueRow(ROW_ONE), interviewed(false) {}

Character::Character(const char* name, const char* role, char tile, int pos, WordRow row)
    : charName(nullptr), charRole(nullptr), clueTile(tile),
      cluePosition(pos), clueRow(row), interviewed(false) {
    copyStrPtr(charName, name);
    copyStrPtr(charRole, role);
}

Character::Character(const Character& other)
    : charName(nullptr), charRole(nullptr), clueTile(other.clueTile),
      cluePosition(other.cluePosition), clueRow(other.clueRow),
      interviewed(other.interviewed) {
    copyStrPtr(charName, other.charName);
    copyStrPtr(charRole, other.charRole);
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        copyStrPtr(charName, other.charName);
        copyStrPtr(charRole, other.charRole);
        clueTile     = other.clueTile;
        cluePosition = other.cluePosition;
        clueRow      = other.clueRow;
        interviewed  = other.interviewed;
    }
    return *this;
}

Character::~Character() {
    delete[] charName;
    delete[] charRole;
    charName = nullptr;
    charRole = nullptr;
}

const char* Character::getName()         const { return charName ? charName : "Unknown"; }
const char* Character::getRole()         const { return charRole ? charRole : "Unknown"; }
char        Character::getClueTile()     const { return clueTile; }
int         Character::getCluePosition() const { return cluePosition; }
WordRow     Character::getClueRow()      const { return clueRow; }
bool        Character::isInterviewed()   const { return interviewed; }

void Character::setInterviewed(bool val) { interviewed = val; }
void Character::setClueData(char tile, int pos, WordRow row) {
    clueTile     = tile;
    cluePosition = pos;
    clueRow      = row;
}

std::ostream& operator<<(std::ostream& os, const Character& c) {
    os << "[" << c.getType() << "] "
       << (c.charName ? c.charName : "Unknown")
       << " (" << (c.charRole ? c.charRole : "Unknown") << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Character& c) {
    char buf[256];
    is.getline(buf, 256);
    copyStrPtr(c.charName, buf);
    return is;
}
