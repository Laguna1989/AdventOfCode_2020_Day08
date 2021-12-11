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
    NopCommand command(0);
    auto updatedInfo = command.execute(info);
    ASSERT_EQ(updatedInfo.line, info.line + 1);
}

TEST(ExecutionTests, JmpExecutionDoesNotChangeValue)
{
    RunInfo info { 0, 0 };
    JmpCommand command(1);
    auto updatedInfo = command.execute(info);
    ASSERT_EQ(info.value, updatedInfo.value);
}

TEST(ExecutionTests, JmpExecutionChangesLineByAppropriateAmount)
{
    RunInfo info { 0, 0 };
    JmpCommand command(0);
    auto updatedInfo = command.execute(info);
    ASSERT_EQ(updatedInfo.line, info.line );
}
