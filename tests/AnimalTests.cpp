#include <gtest/gtest.h>

#include <Constants.h>
#include <Duck.h>
#include <Functionality.h>
#include <Goose.h>

#include <numeric>

namespace mlubecki::tests{

    struct TestDuck : public Duck{
        TestDuck(std::uint8_t age) 
            : Duck(age) 
        {}

        virtual ~TestDuck() = default;

        virtual void Speak() const override {}
    };

    struct TestGoose : public Goose{
        TestGoose(std::uint8_t age) 
            : Goose(age) 
        {}

        virtual ~TestGoose() = default;

        virtual void Speak() const override {}
    };

    void verifyDuckPtr(Animal* animal, std::uint8_t expected_age){
        ASSERT_NE(animal, nullptr);
        auto testduck = dynamic_cast<TestDuck*>(animal);
        ASSERT_NE(testduck, nullptr);
        ASSERT_EQ(testduck->GetAge(), expected_age);
        ASSERT_EQ(testduck->GetName(), determineDuckName(expected_age));
    }

    //////

    TEST(AnimalTests, DucksAreNamedProperly){
        const std::uint8_t earl_age = 5;
        TestDuck named_earl(earl_age);
        ASSERT_EQ(named_earl.GetName(), animal_names::DUCK_ODD);
        ASSERT_EQ(determineDuckName(earl_age), animal_names::DUCK_ODD);

        const std::uint8_t lady_age = 2;        
        TestDuck named_lady(lady_age);
        ASSERT_EQ(named_lady.GetName(), animal_names::DUCK_EVEN);
        ASSERT_EQ(determineDuckName(lady_age), animal_names::DUCK_EVEN);
    }    

    TEST(AnimalTests, RemoveOldestDuck_EmptyCollection){
        AnimalCollectionT collection;
        ASSERT_NO_THROW(removeOldestDuck(collection));
        ASSERT_EQ(removeOldestDuck(collection), nullptr);
    }

    TEST(AnimalTests, RemoveOldestDuck_SingleDuck){
        const std::uint8_t duck_age = 0;

        AnimalCollectionT collection;
        collection.emplace_back(std::make_unique<TestDuck>(duck_age));
        auto result = removeOldestDuck(collection);        
        
        verifyDuckPtr(result.get(), duck_age);
    }

    TEST(AnimalTests, RemoveOldestDuck_MultipleDucksOfSameAge){
        std::array<std::uint8_t, 3> duck_ages = {0, 0, 0};

        AnimalCollectionT collection;
        collection.reserve(5);
        for(auto age : duck_ages){
            collection.emplace_back(std::make_unique<TestDuck>(age));
        }        

        for(auto it = duck_ages.cbegin(); it != duck_ages.end(); ++it){
            auto result = removeOldestDuck(collection);
            verifyDuckPtr(result.get(), *it);
        }
    }

    TEST(AnimalTests, RemoveOldestDuck_MultipleRemovals){
        constexpr std::size_t size = 5;
        std::array<std::uint8_t, size> duck_ages = {0, 8, 1, 2, 3};

        AnimalCollectionT collection;
        collection.reserve(size);
        for(auto age : duck_ages){
            collection.emplace_back(std::make_unique<TestDuck>(age));
        }        

        std::sort(duck_ages.begin(), duck_ages.end(), std::greater<>());
        for(auto it = duck_ages.cbegin(); it != duck_ages.end(); ++it){
            auto result = removeOldestDuck(collection);
            verifyDuckPtr(result.get(), *it);
        }
    }

    TEST(AnimalTests, GeeseAreNamedProperly){
        const std::uint8_t mom_age = 4;
        TestGoose named_mom(mom_age);
        ASSERT_EQ(named_mom.GetName(), animal_names::GOOSE_EVEN);
        ASSERT_EQ(determineGooseName(mom_age), animal_names::GOOSE_EVEN);

        const std::uint8_t bert_age = 7;        
        TestGoose named_bert(bert_age);
        ASSERT_EQ(named_bert.GetName(), animal_names::GOOSE_ODD);
        ASSERT_EQ(determineGooseName(bert_age), animal_names::GOOSE_ODD);
    }

    TEST(AnimalTests, SumAges_EmptyCollection){
        AnimalCollectionT c;
        ASSERT_EQ(sumAges(c), 0);
    }

    TEST(AnimalTests, SumAges_OneAnimal){
        std::uint8_t age = 3;
        AnimalCollectionT c;
        c.emplace_back(std::make_unique<TestDuck>(age));
        ASSERT_EQ(sumAges(c), age);
    }

    TEST(AnimalTests, SumAges_OneNewbornAnimal){
        std::uint8_t age = 0;
        AnimalCollectionT c;
        c.emplace_back(std::make_unique<TestDuck>(age));
        ASSERT_EQ(sumAges(c), age);
    }

    TEST(AnimalTests, SumAges_ManyAnimals){
        std::array<std::uint8_t, 5> ages = {10, 8, 3, 2, 1};
        auto expected_sum = std::accumulate(ages.cbegin(), ages.cend(), 0);
        AnimalCollectionT c;
        for(auto age : ages) {
            c.emplace_back(std::make_unique<TestDuck>(age));
        };
        ASSERT_EQ(sumAges(c), expected_sum);
    }

}