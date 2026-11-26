#pragma once
#include "../DrawingStrategy.h"

class BoardStrategy final : public BaseDrawingStrategy
{
public:
    void draw(sf::RenderWindow& window, const DrawingContext& context) const override;
};
