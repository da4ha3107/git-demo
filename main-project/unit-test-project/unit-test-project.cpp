#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    TEST_CLASS(unittestproject)
    {
    public:
        TEST_METHOD(TestLongestTalk)
        {
            std::vector<Talk> talks = {
                {"AI Ethics", 25},
                {"Cybersecurity Trends", 30},
                {"Robotics Future", 40}
            };

            Assert::AreEqual(std::string("00:40"), process(talks)); // Должно вернуть 40 минут
        }

        TEST_METHOD(TestSingleTalk)
        {
            std::vector<Talk> talks = { {"Quantum Computing", 15} };
            Assert::AreEqual(std::string("00:15"), process(talks)); // Один доклад, 15 мин
        }

        TEST_METHOD(TestNoTalks)
        {
            std::vector<Talk> talks = {};
            Assert::AreEqual(std::string("00:00"), process(talks)); // Нет докладов
        }
    };
}
