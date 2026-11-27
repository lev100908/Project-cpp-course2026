#include "InputManager.h"

InputManager::InputManager() {
    currentKeys.fill(false);
    previousKeys.fill(false);
}

void InputManager::update() {
    previousKeys = currentKeys;
    for (int i = 0; i < static_cast<int>(KeyCount); ++i) {
        currentKeys[i] = sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i));
    }
}

bool InputManager::isKeyHeld(sf::Keyboard::Key key) const {
    if (key == sf::Keyboard::Key::Unknown) return false;
    return currentKeys[static_cast<size_t>(key)];
}

bool InputManager::isKeyPressed(sf::Keyboard::Key key) const {
    if (key == sf::Keyboard::Key::Unknown) return false;
    size_t k = static_cast<size_t>(key);
    return currentKeys[k] && !previousKeys[k];
}

bool InputManager::isKeyReleased(sf::Keyboard::Key key) const {
    if (key == sf::Keyboard::Key::Unknown) return false;
    size_t k = static_cast<size_t>(key);
    return !currentKeys[k] && previousKeys[k];
}
