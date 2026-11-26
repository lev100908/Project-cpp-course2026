#pragma once

#include <SFML/Graphics.hpp>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>


// Рисует строку внешним TrueType-шрифтом.
// Параметр scale сохранён для совместимости со старыми вызовами:
// размер символов SFML равен scale * 7 пикселям.
inline void drawPixelText(sf::RenderWindow& window,
                          const std::string& text,
                          float center_x,
                          float y,
                          float scale,
                          sf::Color color)
{
    // sf::Text хранит ссылку на sf::Font, поэтому шрифт должен жить
    // дольше текста. Статический объект загружается только один раз.
    static sf::Font font;
    static const bool font_loaded = []() {
        const char* paths[] = {
            "assets/fonts/PIXY.ttf",
            "../../assets/fonts/PIXY.ttf",               // запуск из build/bin
        };

        for (const char* path : paths)
        {
            if (font.openFromFile(path))
                return true;
        }

        std::cerr << "Failed to load font: assets/fonts/PIXY.ttf\n";
        return false;
    }();

    if (!font_loaded || text.empty())
        return;

    sf::Text drawable(font);
    drawable.setString(text);
    drawable.setCharacterSize(static_cast<unsigned int>(
        std::max(1.f, std::round(scale * 7.f))));
    drawable.setFillColor(color);

    // Центрируем строку по горизонтали и выравниваем верхнюю границу по y.
    const sf::FloatRect bounds = drawable.getLocalBounds();
    drawable.setOrigin({bounds.position.x + bounds.size.x / 2.f, bounds.position.y});
    drawable.setPosition({center_x, y});

    window.draw(drawable);
}
inline sf::Color toSfColor(const Config::Color& color)
{
    return {color.r, color.g, color.b, color.a};
}
