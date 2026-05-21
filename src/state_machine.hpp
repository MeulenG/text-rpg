#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <cstdint>
#include <stdbool.h>
#include "event_data.hpp"

typedef uint8_t BYTE;

class StateMachine 
{   
public:
    enum { EVENT_IGNORED = 0xFE, CANNOT_HAPPEN };

    StateMachine(BYTE maxStates, BYTE initialState = 0);
    virtual ~StateMachine() {}

    BYTE GetCurrentState() { return m_currentState; }
    
protected:
    void ExternalEvent(BYTE newState, const EventData* pData = nullptr);
    void InternalEvent(BYTE newState, const EventData* pData = nullptr);
    
private:
    const BYTE MAX_STATES;
    BYTE m_currentState;
    BYTE m_newState;
    bool m_eventGenerated;
    const EventData* m_pEventData;

    //virtual const StateMapRow* GetStateMap() = 0;
    //virtual const StateMapRowEx* GetStateMapEx() = 0;
    
    void SetCurrentState(BYTE newState) { m_currentState = newState; }

    void StateEngine(void);     
    //void StateEngine(const StateMapRow* const pStateMap);
    // void StateEngine(const StateMapRowEx* const pStateMapEx);
};

#endif