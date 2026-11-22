#include "VictimAndDetective.h"

// ============================================================================
// Victim Implementation
// ============================================================================
Victim::Victim()
    : Character(), causeOfDeath(nullptr), lastKnownLocation(nullptr) {}

Victim::Victim(const char* name, const char* role, char tile, int pos, WordRow row,
               const char* cod, const char* lkl)
    : Character(name, role, tile, pos, row),
      causeOfDeath(nullptr), lastKnownLocation(nullptr) {
    copyStrPtr(causeOfDeath, cod);
    copyStrPtr(lastKnownLocation, lkl);
}

Victim::Victim(const Victim& other)
    : Character(other), causeOfDeath(nullptr), lastKnownLocation(nullptr) {
    copyStrPtr(causeOfDeath, other.causeOfDeath);
    copyStrPtr(lastKnownLocation, other.lastKnownLocation);
}

Victim& Victim::operator=(const Victim& other) {
    if (this != &other) {
        Character::operator=(other);
        copyStrPtr(causeOfDeath, other.causeOfDeath);
        copyStrPtr(lastKnownLocation, other.lastKnownLocation);
    }
    return *this;
}

Victim::~Victim() {
    delete[] causeOfDeath;
    delete[] lastKnownLocation;
    causeOfDeath = nullptr;
    lastKnownLocation = nullptr;
}

void Victim::display() const {
    std::cout << "\n  +---------------- VICTIM DOSSIER ----------------+\n";
    std::cout << "  Name           : " << (charName ? charName : "Unknown") << "\n";
    std::cout << "  Status         : DECEASED\n";
    std::cout << "  Title          : " << (charRole ? charRole : "Unknown") << "\n";
    std::cout << "  Cause of Death : " << (causeOfDeath ? causeOfDeath : "Unknown") << "\n";
    std::cout << "  Last Seen At   : " << (lastKnownLocation ? lastKnownLocation : "Unknown") << "\n";
    std::cout << "  +------------------------------------------------+\n";
}

const char* Victim::getType()              const { return "VICTIM"; }
const char* Victim::getCauseOfDeath()      const { return causeOfDeath; }
const char* Victim::getLastKnownLocation() const { return lastKnownLocation; }

// ============================================================================
// Detective Implementation
// ============================================================================
Detective::Detective()
    : Character("Inspector Victor Reid", "Scotland Yard Chief Inspector", '\0', -1, ROW_ONE),
      credibility(100), turnsLeft(25), badgeNumber(nullptr) {
    copyStrPtr(badgeNumber, "SY-1923-VR");
}

Detective::Detective(const char* name, const char* role, const char* badge)
    : Character(name, role, '\0', -1, ROW_ONE),
      credibility(100), turnsLeft(25), badgeNumber(nullptr) {
    copyStrPtr(badgeNumber, badge);
}

Detective::Detective(const Detective& other)
    : Character(other), credibility(other.credibility),
      turnsLeft(other.turnsLeft), badgeNumber(nullptr) {
    copyStrPtr(badgeNumber, other.badgeNumber);
}

Detective& Detective::operator=(const Detective& other) {
    if (this != &other) {
        Character::operator=(other);
        credibility = other.credibility;
        turnsLeft   = other.turnsLeft;
        copyStrPtr(badgeNumber, other.badgeNumber);
    }
    return *this;
}

Detective::~Detective() {
    delete[] badgeNumber;
    badgeNumber = nullptr;
}

void Detective::display() const {
    std::cout << "\n  +-------------- DETECTIVE PROFILE ---------------+\n";
    std::cout << "  Name        : " << (charName ? charName : "Unknown") << "\n";
    std::cout << "  Badge       : " << (badgeNumber ? badgeNumber : "None") << "\n";
    std::cout << "  Credibility : " << credibility << " / 100\n";
    std::cout << "  Turns Left  : " << turnsLeft   << " / 25\n";
    std::cout << "  +------------------------------------------------+\n";
}

const char* Detective::getType()        const { return "DETECTIVE"; }
int         Detective::getCredibility() const { return credibility; }
int         Detective::getTurnsLeft()   const { return turnsLeft; }
bool        Detective::isAlive()        const { return (turnsLeft > 0 && credibility > 0); }

void Detective::deductTurn(int amount) {
    turnsLeft -= amount;
    if (turnsLeft < 0) turnsLeft = 0;
}

void Detective::deductCredibility(int amount) {
    credibility -= amount;
    if (credibility < 0) credibility = 0;
}

void Detective::addCredibility(int amount) {
    credibility += amount;
    if (credibility > 100) credibility = 100;
}

void Detective::reset() {
    credibility = 100;
    turnsLeft   = 25;
}
