#include <Animal.h>

namespace mlubecki{

    Animal::Animal(std::uint8_t age, std::string&& name)
        : m_age(age)
        , m_name(std::move(name))
    {}

    std::uint8_t Animal::GetAge() const {
        return m_age;
    }

    std::string Animal::GetName() const {
        return m_name;
    }

}