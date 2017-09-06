#pragma once

#include <memory>
#include <stack>

#include "State.h"

namespace Tas
{
    typedef std::unique_ptr<State> StateRef;

    class StateMachine
    {
    public:
        void addState(StateRef newState, bool isReplacing);
        void removeState();

        void proceedStateChanges();

        inline StateRef& getActiveState() {return _states.top();}
    private:
        std::stack<StateRef> _states;
        StateRef _newState;

        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
    };
}
