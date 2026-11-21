#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H

#include <exception>

// ============================================================================
// CUSTOM GAME EXCEPTION HIERARCHY
// ============================================================================
class GameException : public std::exception {
protected:
    char* message;
public:
    explicit GameException(const char* msg);
    GameException(const GameException& other);
    virtual ~GameException();
    virtual const char* what() const noexcept override;
};

class InvalidWordException : public GameException {
public:
    explicit InvalidWordException(const char* msg);
};

class RackFullException : public GameException {
public:
    explicit RackFullException(const char* msg);
};

class InvalidPositionException : public GameException {
public:
    explicit InvalidPositionException(const char* msg);
};

#endif // GAME_EXCEPTION_H
