#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "Types.h"

class GameEngine;

// ============================================================================
// ABSTRACT CHARACTER BASE CLASS
// ============================================================================
class Character {
protected:
    char*   charName;
    char*   charRole;
    char    clueTile;
    int     cluePosition;
    WordRow clueRow;
    bool    interviewed;

    friend class GameEngine;

public:
    Character();
    Character(const char* name, const char* role, char tile, int pos, WordRow row);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();

    // Pure virtual functions enforcing polymorphism
    virtual void        display() const = 0;
    virtual const char* getType() const = 0;

    const char* getName()         const;
    const char* getRole()         const;
    char        getClueTile()     const;
    int         getCluePosition() const;
    WordRow     getClueRow()      const;
    bool        isInterviewed()   const;

    void setInterviewed(bool val);
    void setClueData(char tile, int pos, WordRow row);

    friend std::ostream& operator<<(std::ostream& os, const Character& c);
    friend std::istream& operator>>(std::istream& is, Character& c);
};

#endif // CHARACTER_H
