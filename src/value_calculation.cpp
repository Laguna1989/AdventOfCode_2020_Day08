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
