#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <array>

class InputManager {
private:
    static constexpr size_t KeyCount = sf::Keyboard::KeyCount;

    /* Два списка, хранящие в себе состояния клавиш текущего и предыдущего
    кадров. В 'InputManager.cpp' логика проверки состояния клавиш будет
    сделана через сравнение состояний в текущем и предыдущем кадрах.
    
    Прошлый кадр | Текущий кадр | Что произошло | Какой метод врнёт 'true'
    -------------+--------------+---------------+------------------------------
        false    |    false     |  Ничего       |  Никакой
        false    |    true      |  Нажали       |  isKeyPressed() / isKeyHeld()
        true     |    true      |  Держат       |  isKeyHeld()
        true     |    false     |  Отпустили    |  isKeyReleased()

    */
    std::array<bool, KeyCount> currentKeys;
    std::array<bool, KeyCount> previousKeys;
protected:
    /* ... */
public:
    InputManager(); // Конструктор

    // Обновление кадра. Вызывать один раз до обработки логики (в начале кадра)
    void update();

    // Проверка на удержание клавиши
    bool isKeyHeld(sf::Keyboard::Key key) const;

    // Клавиша была нажата (в течении одного кадра)
    bool isKeyPressed(sf::Keyboard::Key key) const;

    // Клавиша была отпущена (в течении этого кадра)
    bool isKeyReleased(sf::Keyboard::Key key) const;
};
