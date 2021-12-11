#include "parser.hpp"
#include "run_info.hpp"
#include <gtest/gtest.h>
#include <memory>

TEST(ExecutionTests, NopExecutionDoesNotChangeValue)
{
    RunInfo info { 0, 0 };
    NopCommand command(0);
    auto updatedInfo = command.execute(info);
    ASSERT_EQ(info.value, updatedInfo.value);
}

TEST(ExecutionTests, NopExecutionIncreasesLineByOne)
{
    RunInfo info { 0, 0 };
    NopCommand command { 0 };
    auto updatedInfo = command.execute(info);
    ASSERT_EQ(updatedInfo.line, info.line + 1);
}

TEST(ExecutionTests, JmpExecutionDoesNotChangeValue)
{
    RunInfo info { 0, 0 };
    JmpCommand command { 1 };
    auto updatedInfo = command.execute(info);
    ASSERT_EQ(info.value, updatedInfo.value);
}

class CommandExecutionParametrizedTestFixture : public ::testing::TestWithParam<int> {
};

TEST_P(CommandExecutionParametrizedTestFixture, JmpChangesLineByAppropriateAmount)
{
    RunInfo info { 0, 0 };
    JmpCommand command { GetParam() };
    auto updatedInfo = command.execute(info);
    ASSERT_EQ(updatedInfo.line, GetParam());
}

TEST_P(CommandExecutionParametrizedTestFixture, AccChangesValueByAppropriateAmount)
{
    RunInfo info { 0, 0 };
    AccCommand command { GetParam() };
    auto updatedInfo = command.execute(info);
    ASSERT_EQ(updatedInfo.value, GetParam());
}

INSTANTIATE_TEST_SUITE_P(CommandExecutionTest, CommandExecutionParametrizedTestFixture,
    ::testing::Values(0, 1, -1, 199, -99));

TEST(ExecutionTests, AccExecutionIncreasesLineByOne)
{
    RunInfo info { 0, 0 };
    AccCommand command { 0 };
    auto updatedInfo = command.execute(info);
    ASSERT_EQ(updatedInfo.line, info.line + 1);
}
