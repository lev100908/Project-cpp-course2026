#include "BoardStrategy.h"

namespace
{
constexpr float BOARD_X = static_cast<float>(Config::WINDOW_PADDING);
constexpr float BOARD_Y = static_cast<float>(Config::WINDOW_PADDING);
}

void BoardStrategy::draw(sf::RenderWindow& window, const DrawingContext& context) const
{
    sf::RectangleShape cell({static_cast<float>(Config::CELL_SIZE - 1),
                             static_cast<float>(Config::CELL_SIZE - 1)});

    for (std::size_t row = 0; row < Config::BOARD_HEIGHT; ++row)
    {
        for (std::size_t column = 0; column < Config::BOARD_WIDTH; ++column)
        {
            cell.setPosition({BOARD_X + static_cast<float>(column * Config::CELL_SIZE),
                             BOARD_Y + static_cast<float>(row * Config::CELL_SIZE)});
            cell.setFillColor(toSfColor(context.board[row][column].color));
            window.draw(cell);
        }
    }

    sf::RectangleShape border({static_cast<float>(Config::BOARD_WIDTH * Config::CELL_SIZE),
                               static_cast<float>(Config::BOARD_HEIGHT * Config::CELL_SIZE)});
    border.setPosition({BOARD_X, BOARD_Y});
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineThickness(2.f);
    border.setOutlineColor(toSfColor(Config::Grey));
    window.draw(border);
}
