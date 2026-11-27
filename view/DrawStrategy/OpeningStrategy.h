#pragma once
#include "../DrawingStrategy.h"

class OpeningStrategy final : public BaseDrawingStrategy
{
public:
    void draw(sf::RenderWindow& window, const DrawingContext& context) const override;
};
