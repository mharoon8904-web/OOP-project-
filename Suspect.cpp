#include "Suspect.h"

Suspect::Suspect()
    : Character(), isCulprit(false), motive(nullptr),
      alibi(nullptr), word1(nullptr), word2(nullptr) {}

Suspect::Suspect(const char* name, const char* role, char tile, int pos, WordRow row,
                 const char* mot, const char* ali, const char* w1, const char* w2)
    : Character(name, role, tile, pos, row), isCulprit(false),
      motive(nullptr), alibi(nullptr), word1(nullptr), word2(nullptr) {
    copyStrPtr(motive, mot);
    copyStrPtr(alibi,  ali);
    copyStrPtr(word1,  w1);
    copyStrPtr(word2,  w2);
}

Suspect::Suspect(const Suspect& other)
    : Character(other), isCulprit(other.isCulprit),
      motive(nullptr), alibi(nullptr), word1(nullptr), word2(nullptr) {
    copyStrPtr(motive, other.motive);
    copyStrPtr(alibi,  other.alibi);
    copyStrPtr(word1,  other.word1);
    copyStrPtr(word2,  other.word2);
}

Suspect& Suspect::operator=(const Suspect& other) {
    if (this != &other) {
        Character::operator=(other);
        isCulprit = other.isCulprit;
        copyStrPtr(motive, other.motive);
        copyStrPtr(alibi,  other.alibi);
        copyStrPtr(word1,  other.word1);
        copyStrPtr(word2,  other.word2);
    }
    return *this;
}

Suspect::~Suspect() {
    delete[] motive;
    delete[] alibi;
    delete[] word1;
    delete[] word2;
    motive = nullptr;
    alibi  = nullptr;
    word1  = nullptr;
    word2  = nullptr;
}

void Suspect::display() const {
    std::cout << "  Name   : " << (charName ? charName : "Unknown") << "\n";
    std::cout << "  Role   : " << (charRole ? charRole : "Unknown") << "\n";
    std::cout << "  Motive : " << (motive   ? motive   : "None documented") << "\n";
    std::cout << "  Alibi  : " << (alibi    ? alibi    : "Unverified") << "\n";
}

const char* Suspect::getType()                const { return "SUSPECT"; }
bool        Suspect::getIsCulprit()           const { return isCulprit; }
void        Suspect::setIsCulprit(bool val)         { isCulprit = val; }
const char* Suspect::getMotive()              const { return motive ? motive : "None documented"; }
const char* Suspect::getAlibi()               const { return alibi ? alibi : "Unverified"; }
const char* Suspect::getWord1()               const { return word1 ? word1 : "SCANDAL"; }
const char* Suspect::getWord2()               const { return word2 ? word2 : "EVIDENCE"; }
int         Suspect::getCredibilityRequired() const { return 40; }
