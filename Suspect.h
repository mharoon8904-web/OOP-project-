#ifndef SUSPECT_H
#define SUSPECT_H

#include "Character.h"

// ============================================================================
// SUSPECT BASE CLASS
// ============================================================================
class Suspect : public Character {
protected:
    bool  isCulprit;
    char* motive;
    char* alibi;
    char* word1;
    char* word2;
public:
    Suspect();
    Suspect(const char* name, const char* role, char tile, int pos, WordRow row,
            const char* mot, const char* ali, const char* w1, const char* w2);
    Suspect(const Suspect& other);
    Suspect& operator=(const Suspect& other);
    virtual ~Suspect();

    virtual void        display() const override;
    virtual const char* getType() const override;

    bool        getIsCulprit()  const;
    void        setIsCulprit(bool val);
    const char* getMotive()     const;
    const char* getAlibi()      const;
    const char* getWord1()      const;
    const char* getWord2()      const;

    virtual int getCredibilityRequired() const;
};

#endif // SUSPECT_H
