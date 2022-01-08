#include "value_calculation.hpp"
#include <set>

bool testForInfiniteLoop(std::vector<Command> vector1);
int calculateValueAfterFirstLoop(std::vector<std::shared_ptr<Command>> const& commands)
{
    RunInfo state { 0, 0 };
    std::set<int> visitedLines;

    while (true) {
        visitedLines.insert(state.line);
        auto currentCommand = commands.at(state.line);
        state = currentCommand->execute(state);

        if (visitedLines.count(state.line)) {
            break;
        }
    }

    return state.value;
}

bool isInfiniteLoop(std::vector<std::shared_ptr<Command>> const& commands) { return false; }

int bruteForceSwap(std::vector<std::shared_ptr<Command>> const& commands)
{
    RunInfo state { 0, 0 };

    auto commandsWithChange = commands;
    commandsWithChange.at(0) = std::make_shared<JmpCommand>(commandsWithChange.at(0)->value());

    if (!isInfiniteLoop(commandsWithChange)) {
        return state.value;
    }

    return state.value;
}
