#pragma once

#include <string>

//1. Create a base Animal class with an age, a name, and a function only invocable in derived classes called Speak.
//2. The Animal will take an age and name upon creation to set its member variables.

namespace mlubecki{

    class Animal{

        protected:
        std::uint8_t m_age;
        std::string m_name;

        public:
        Animal(std::uint8_t age, std::string&& name);

        virtual ~Animal() = default;

        std::uint8_t GetAge() const;

        std::string GetName() const;

        virtual void Speak() const = 0;

    };

}
