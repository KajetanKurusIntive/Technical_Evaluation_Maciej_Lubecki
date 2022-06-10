#pragma once

#include <Animal.h>
#include <Utils.h>

//3. Derive from the Animal class to create a Duck. Use cout in Speak to say "Quack".

namespace mlubecki{

    class Duck : public Animal{

    public:
    
        Duck(std::uint8_t age = getRandomAge());

        virtual ~Duck() = default;

        virtual void Speak() const override;

    };
}
