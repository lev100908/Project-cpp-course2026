#pragma once

#include "../config/config.h"
#include "DrawStrategy/ExtraFunctions.h"
#include <SFML/Graphics.hpp>

// Данные, необходимые стратегиям отрисовки.
struct DrawingContext
{
    const Config::DisplayBoard& board;
    int score;
};

class BaseDrawingStrategy
{
public:
    virtual ~BaseDrawingStrategy() = default;
    virtual void draw(sf::RenderWindow& window, const DrawingContext& context) const = 0;
};
