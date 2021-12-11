#include "command.hpp"
#include "strutils.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <typeinfo>
#include <stdexcept>

using namespace ::testing;

std::shared_ptr<Command> parseSingleCommand(std::string input)
{
    if(strutil::starts_with(input, "nop"))
    {
        return std::make_shared<NopCommand>();
    }
    else  if(strutil::starts_with(input, "jmp"))
    {
        return std::make_shared<JmpCommand>();
    }
    else  if(strutil::starts_with(input, "acc"))
    {
        return std::make_shared<AccCommand>();
    }
    else
    {
        throw std::invalid_argument{"invalid input"};
    }

}


TEST(ParserTest, ParseSingleLineNopReturnsCorrectCommand)
{
    std::string input = "nop +0";
    auto command = parseSingleCommand(input);
    EXPECT_NE(nullptr, dynamic_cast<NopCommand*>(command.get()));
}

class ParserParameterizedTestFixture : public ::testing::TestWithParam<std::pair<std::string, int>>
{

};

TEST_P(ParserParameterizedTestFixture, ParseSingleLineNopReturnsCorrectCommandArgumentParameterized)
{
    std::string input = GetParam().first;
    auto command = parseSingleCommand(input);
    EXPECT_EQ(command->value(), GetParam().second);
}

INSTANTIATE_TEST_SUITE_P(ParserParameterizedTest, ParserParameterizedTestFixture,
    ::testing::Values(std::make_pair("nop +0", 0)));

TEST(ParserTest, ParseSingleLineNopReturnsCorrectCommandArgument)
{
    std::string input = "nop +0";
    auto command = parseSingleCommand(input);
    EXPECT_EQ(command->value(), 0);
}


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
