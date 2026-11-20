
#include "IStrategy.h"


std::array<Config::Position, 4>
IStrategy::getRelativePositions(Config::Rotation rotation) const
{
    switch (rotation)
    {
        case Config::Rotation::Up: return {{{ 0, -1}, { 0, 0}, { 0, 1}, { 0, 2}}};
        case Config::Rotation::Right: return {{{-1, 0}, {0,  0}, {1,  0}, {2,  0}}};
        case Config::Rotation::Down: return {{{ 0, 1}, { 0, 0}, { 0, -1}, { 0, -2}}};
        case Config::Rotation::Left: return {{{1, 0}, {0, 0}, {-1, 0}, {-2, 0}}};
    }
    return {{{0, 0}, {0, 0}, {0, 0}, {0, 0}}};;
}

Config::Position IStrategy::getStartCenterPositions() const
{
    return Config::I_START_POS_CENTER;
}
