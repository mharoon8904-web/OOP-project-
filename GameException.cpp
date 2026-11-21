#include "GameException.h"
#include "Types.h"

GameException::GameException(const char* msg) : message(nullptr) {
    copyStrPtr(message, msg);
}

GameException::GameException(const GameException& other) : message(nullptr) {
    copyStrPtr(message, other.message);
}

GameException::~GameException() {
    delete[] message;
    message = nullptr;
}

const char* GameException::what() const noexcept {
    return message ? message : "GameException";
}

InvalidWordException::InvalidWordException(const char* msg)
    : GameException(msg) {}

RackFullException::RackFullException(const char* msg)
    : GameException(msg) {}

InvalidPositionException::InvalidPositionException(const char* msg)
    : GameException(msg) {}
