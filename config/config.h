#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <memory>

namespace Config
{
    // Размеры игрового поля
    static constexpr std::size_t BOARD_HEIGHT = 20;
    static constexpr std::size_t BOARD_WIDTH = 10;

    struct Position
    {
        int x;
        int y;
    };

    enum class Rotation
    {
        Up,
        Right,
        Down,
        Left
    };

    enum class TetraminoType { I, O, T, S, Z, J, L, len,};

    // Начальное положение Tetramino
    // I
    constexpr Position I_START_POS_CENTER {BOARD_WIDTH / 2, 1};
    constexpr Position J_START_POS_CENTER {BOARD_WIDTH / 2 - 1, 1};
    constexpr Position L_START_POS_CENTER {BOARD_WIDTH / 2 - 1, 1};
    constexpr Position O_START_POS_CENTER {BOARD_WIDTH / 2 - 1, 1};
    constexpr Position S_START_POS_CENTER {BOARD_WIDTH / 2 - 1, 1};
    constexpr Position T_START_POS_CENTER {BOARD_WIDTH / 2 - 1, 1};
    constexpr Position Z_START_POS_CENTER {BOARD_WIDTH / 2 - 1, 1};

    constexpr int SPEED_LEFT = -1;
    constexpr int SPEED_RIGHT = 1;
    constexpr int SPEED_FAST_DOWN = 2;
    constexpr int SPEED_DOWN = 1;

    // Структура цвета RGBA
    struct Color
    {
        std::uint8_t r;
        std::uint8_t g;
        std::uint8_t b;
        std::uint8_t a;
    };

    // Цвета тетрамино
    constexpr Color EMPTY_CELL_COLOR {0, 0, 0, 255};
    constexpr Color FILLED_CELL_COLOR1 {255, 255, 255, 255};
    constexpr Color WHITE  {255, 255, 255, 255};
    constexpr Color CYAN   {0, 255, 255, 255};
    constexpr Color BLUE   {0, 0, 255, 255};
    constexpr Color ORANGE {255, 165, 0, 255};
    constexpr Color YELLOW {255, 255, 0, 255};
    constexpr Color GREEN  {0, 255, 0, 255};
    constexpr Color PURPLE {128, 0, 128, 255};
    constexpr Color RED    {255, 0, 0, 255};
    constexpr Color Grey   {220, 230, 240, 255};

    struct ViewCell
    {
        Color color;
    };

    constexpr int CELL_SIZE = 40;
    constexpr int WINDOW_PADDING = 40;

    constexpr int WINDOW_WIDTH =
        BOARD_WIDTH * CELL_SIZE + 2 * WINDOW_PADDING + 150;

    constexpr int WINDOW_HEIGHT =
        BOARD_HEIGHT * CELL_SIZE + 2 * WINDOW_PADDING;

    using DisplayBoard = std::array<
        std::array<ViewCell, BOARD_WIDTH>,
        BOARD_HEIGHT
    >;

    constexpr float FALL_INTERVAL_SECONDS = 0.5f;
}
