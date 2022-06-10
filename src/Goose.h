#pragma once

#include <Animal.h>
#include <Utils.h>

namespace mlubecki{

    //8. Create a Goose class derived from the Animal class. Use cout in Speak to say "HONK".
    class Goose : public Animal {

    public:

        Goose(std::uint8_t age = getRandomAge());

        virtual ~Goose() = default;

        virtual void Speak() const override;

    };
}