#include "StateMachine.hpp"
#include "State.h"
namespace Tas
{
    void StateMachine::addState(Tas::StateRef newState, bool isReplacing = true)
    {
        this->_isAdding = true;
        this->_isReplacing = isReplacing;
        this->_newState = std::move(newState);
    }
    void StateMachine::removeState()
    {
        this->_isRemoving = true;
    }
    void StateMachine::proceedStateChanges()
    {
        if(this->_isRemoving && !this->_states.empty())
        {
            this->_states.pop();
            if(!this->_states.empty())
            {
                this->_states.top()->resume();
            }
            this->_isRemoving = false;
        }
        if(this->_isAdding)
        {
            if(!this->_states.empty())
            {
                if(this->_isReplacing)
                {
                    this->_states.pop();
                }
                else
                {
                    this->_states.top()->pause();
                }
            }
            this->_states.push(std::move(this->_newState));
            this->_states.top()->initState();
            this->_isAdding = false;
        }
    }
}
