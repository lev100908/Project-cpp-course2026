#include "OpeningStrategy.h"

void OpeningStrategy::draw(sf::RenderWindow& window, const DrawingContext&) const
{
    const float cx = static_cast<float>(Config::WINDOW_WIDTH) / 2.f;
    const float cy = static_cast<float>(Config::WINDOW_HEIGHT) / 2.f;
    drawPixelText(window, "TETRIS", cx, cy - 105.f, 10.f, toSfColor(Config::CYAN));
    drawPixelText(window, "PRESS ENTER", cx, cy + 25.f, 5.f, toSfColor(Config::WHITE));
    drawPixelText(window, "ESC TO QUIT", cx, cy + 65.f, 4.f, toSfColor(Config::Grey));
}
