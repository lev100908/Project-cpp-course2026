#include "OStrategy.h"

std::array<Config::Position, 4>
OStrategy::getRelativePositions(Config::Rotation rotation) const
{
    switch (rotation)
    {
        case Config::Rotation::Up: return {{{-1, -1}, {0, -1}, {-1, 0}, {0, 0}}};
        case Config::Rotation::Right: return {{{-1, -1}, {0, -1}, {-1, 0}, {0, 0}}};
        case Config::Rotation::Down: return {{{-1, -1}, {0, -1}, {-1, 0}, {0, 0}}};
        case Config::Rotation::Left: return {{{-1, -1}, {0, -1}, {-1, 0}, {0, 0}}};
    }
    return {{{0, 0}, {0, 0}, {0, 0}, {0, 0}}};
}

Config::Position OStrategy::getStartCenterPositions() const
{
    return Config::O_START_POS_CENTER;
}
