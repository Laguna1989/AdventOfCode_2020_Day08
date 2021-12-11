#include "parser.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ::testing;

TEST(ParserTest, ParseSingleLineNopReturnsCorrectCommand)
{
    std::string input = "nop +0";
    auto command = parseSingleCommand(input);
    EXPECT_NE(nullptr, dynamic_cast<NopCommand*>(command.get()));
}

class ParserParameterizedTestFixture
    : public ::testing::TestWithParam<std::pair<std::string, int>> {
};

TEST_P(ParserParameterizedTestFixture, ParseSingleLineNopReturnsCorrectCommandArgumentParameterized)
{
    std::string input = GetParam().first;
    auto command = parseSingleCommand(input);
    EXPECT_EQ(command->value(), GetParam().second);
}

INSTANTIATE_TEST_SUITE_P(ParserParameterizedTest, ParserParameterizedTestFixture,
    ::testing::Values(
        std::make_pair("nop +0", 0), std::make_pair("acc +3", 3), std::make_pair("jmp -4", -4)));

TEST(ParserTest, ParseSingleLineAccReturnsCorrectCommand)
{
    std::string input = "acc +1";
    auto command = parseSingleCommand(input);

    EXPECT_NE(nullptr, dynamic_cast<AccCommand*>(command.get()));
}

TEST(ParserTest, ParseSingleLineJmpReturnsCorrectCommand)
{
    std::string input = "jmp +4";
    auto command = parseSingleCommand(input);

    EXPECT_NE(nullptr, dynamic_cast<JmpCommand*>(command.get()));
}
