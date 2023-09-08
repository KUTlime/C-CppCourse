#include <Memory>
#include <string>
#include <format>
#include <iostream>

class DoorState {};

class OpenedState : public DoorState {};
class ClosedState : public DoorState {};
class LockedState : public DoorState {};

class DoorStateEvent 
{
protected:
	DoorState _targetState;
	DoorState _validStartingState;
public:
	virtual DoorState MakeStateTransition(const DoorState& originalState) const noexcept
	{
		if (IsValidStateTransition(originalState))
		{
			return _targetState;
		}
		return originalState;
	};
private:
	virtual bool IsValidStateTransition(const DoorState& originalState) const noexcept
	{
		return typeid(originalState) == typeid(_validStartingState);
	}
};

class OpenEvent : public DoorStateEvent 
{

public:
	OpenEvent()
	{
		_targetState = OpenedState();
		_validStartingState = ClosedState();
	};
};

class CloseEvent : public DoorStateEvent {
public:
	CloseEvent()
	{
		_targetState = ClosedState();
		_validStartingState = OpenedState();
	}
};

class LockEvent : public DoorStateEvent
{
public:
	LockEvent()
	{
		_targetState = LockedState();
		_validStartingState = ClosedState();
	}
};
class UnlockEvent : public DoorStateEvent
{
public:
	UnlockEvent()
	{
		_targetState = ClosedState();
		_validStartingState = LockedState();
	}
};

class DoorStateMachine
{
private:
	DoorState _state;
public:
	DoorStateMachine() {
		_state = ClosedState();
	}

	DoorState GetState()
	{
		return _state;
	}

	void HandleEvent(const DoorStateEvent& incomingEvent)
	{
		_state = incomingEvent.MakeStateTransition(_state);
	}

	operator std::string () const noexcept
	{
		return std::format("Door state: {}", typeid(_state).name());
	}

	friend std::ostream& operator<<(std::ostream& os, const DoorStateMachine& dsm)
	{
		os << (std::string)dsm << std::endl;
		return os;
	}
};

void DemoDoorStateMachine()
{
	DoorStateMachine stateMachine;
	std::cout << stateMachine << std::endl;
	stateMachine.HandleEvent(CloseEvent());
	std::cout << stateMachine << std::endl;
	stateMachine.HandleEvent(LockEvent());
	std::cout << stateMachine << std::endl;
	stateMachine.HandleEvent(OpenEvent());
	std::cout << stateMachine << std::endl;
};