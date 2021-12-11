#include "command.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <typeinfo>

using namespace ::testing;

std::shared_ptr<Command> parseSingleCommand(std::string input)
{
    return std::make_shared<NoopCommand>();
}

TEST(ParserTest, ParseSingleLineReturnsCorrectCommand)
{
    std::string input = "nop +0";
    auto command = parseSingleCommand(input);

    //EXPECT_STREQ(typeid(NoopCommand).name(), typeid(*command).name());
    EXPECT_NE(nullptr, dynamic_cast<NoopCommand*>(command.get()));
}
