#include "parser.hpp"
#include "run_info.hpp"
#include "value_calculation.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ::testing;

TEST(ParserTest, ParseMultipleLinesReturnsCorrectCommands)
{
    std::string input = R"(nop +0
acc +99
jmp -6)";
    auto commands = parseCommands(input);

    EXPECT_EQ(commands.size(), 3);
}

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

class InfiniteLoopParameterizedTestFixture
    : public ::testing::TestWithParam<std::pair<std::string, bool>> {
};

TEST_P(InfiniteLoopParameterizedTestFixture, IsInfiniteLoopDetectedCorrectly)
{
    std::string input = GetParam().first;
    auto commands = parseCommands(input);
    auto result = isInfiniteLoop(commands);
    EXPECT_EQ(result, GetParam().second);
}

INSTANTIATE_TEST_SUITE_P(InfiniteLoopDetectionParameterizedTestFixture,
    InfiniteLoopParameterizedTestFixture,
    ::testing::Values(std::make_pair("jmp +0", true), std::make_pair("nop +0\njmp -1", true),
        std::make_pair("nop +0\nacc +1\njmp -2", true), std::make_pair("nop +0", false),
        std::make_pair("jmp +2\nnop +1\nacc +1", false)));
