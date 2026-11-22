#ifndef VICTIM_AND_DETECTIVE_H
#define VICTIM_AND_DETECTIVE_H

#include "Character.h"

// ============================================================================
// VICTIM CLASS (Lord Edmund Ashton)
// ============================================================================
class Victim : public Character {
private:
    char* causeOfDeath;
    char* lastKnownLocation;
public:
    Victim();
    Victim(const char* name, const char* role, char tile, int pos, WordRow row,
           const char* cod, const char* lkl);
    Victim(const Victim& other);
    Victim& operator=(const Victim& other);
    virtual ~Victim();

    virtual void        display() const override;
    virtual const char* getType() const override;

    const char* getCauseOfDeath()      const;
    const char* getLastKnownLocation() const;
};

// ============================================================================
// DETECTIVE CLASS (Inspector Victor Reid - Player Avatar)
// ============================================================================
class Detective : public Character {
private:
    int   credibility;  // Meter 0-100
    int   turnsLeft;    // Starts at 25
    char* badgeNumber;
public:
    Detective();
    Detective(const char* name, const char* role, const char* badge);
    Detective(const Detective& other);
    Detective& operator=(const Detective& other);
    virtual ~Detective();

    virtual void        display() const override;
    virtual const char* getType() const override;

    int  getCredibility() const;
    int  getTurnsLeft()   const;
    bool isAlive()        const;

    void deductTurn(int amount = 1);
    void deductCredibility(int amount);
    void addCredibility(int amount);
    void reset();
};

#endif // VICTIM_AND_DETECTIVE_H
