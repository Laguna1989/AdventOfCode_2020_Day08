#include "value_calculation.hpp"
#include <set>

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

bool isInfiniteLoop(std::vector<std::shared_ptr<Command>> const& commands)
{
    RunInfo state { 0, 0 };
    std::set<int> visitedLines;

    while (true) {
        visitedLines.insert(state.line);
        auto currentCommand = commands.at(state.line);
        state = currentCommand->execute(state);

        if (visitedLines.count(state.line)) {
            return true;
        }
        if (state.line >= commands.size()) {
            return false;
        }
    }

    return false;
}

int bruteForceSwap(std::vector<std::shared_ptr<Command>> const& commands)
{
    for (auto index = 0U; index != commands.size(); ++index) {
        auto commandsWithChange = commands;
        commandsWithChange.at(index) = commandsWithChange.at(index)->switchCommand();

        if (isInfiniteLoop(commandsWithChange)) {
            continue;
        }

        RunInfo state { 0, 0 };
        while (true) {
            auto currentCommand = commandsWithChange.at(state.line);
            state = currentCommand->execute(state);

            if(state.line == commandsWithChange.size())
            {
                return state.value;
            }

            if(state.line > commandsWithChange.size())
            {
                break;
            }
        }
    }

    return 0;
}
