#include "boss_monster_input.hpp"
#include "parser.hpp"
#include "value_calculation.hpp"
#include <gtest/gtest.h>

TEST(BossMonsterTest, BossMonsterPreparation)
{
    auto input = R"(nop +0
acc +1
jmp +4
acc +3
jmp -3
acc -99
acc +1
jmp -4
acc +6)";

    auto commands = parseCommands(input);
    auto expectedValue = 5;

    ASSERT_EQ(calculateValueAfterFirstLoop(commands), expectedValue);
}

TEST(BossMonsterTest, BossMonsterTestOne)
{
    auto commands = parseCommands(bossMonsterInput);
    auto expectedValue = 2051;

    ASSERT_EQ(calculateValueAfterFirstLoop(commands), expectedValue);
}

TEST(BossMonsterTest, BossMonsterPartTwoPreparation)
{
    auto input = R"(nop +0
acc +1
jmp +4
acc +3
jmp -3
acc -99
acc +1
jmp -4
acc +6)";

    auto commands = parseCommands(input);
    auto expectedValue = 8;

    ASSERT_EQ(bruteForceSwap(commands), expectedValue);
}

TEST(BossMonsterTest, BossMonsterTestTwo)
{
    auto commands = parseCommands(bossMonsterInput);
    auto expectedValue = 2304;

    ASSERT_EQ(bruteForceSwap(commands), expectedValue);
}
