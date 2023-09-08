export module DoorStateMachine;

import <Memory>;
import <string>;
import <format>;
import <iostream>;
import <typeinfo>;

export class DoorState
{
public:
	virtual std::string GetName() const noexcept
	{
		return typeid(*this).name(); // not really great solution, compiler implementation dependant
	}

	virtual ~DoorState() = default;
};

export class OpenedState : public DoorState {};
export class ClosedState : public DoorState {};
export class LockedState : public DoorState {};

export class DoorStateEvent
{
protected:
	std::shared_ptr<DoorState> _targetState;
	std::unique_ptr<DoorState> _validStartingState;
public:
	DoorStateEvent(std::shared_ptr<DoorState> targetState, std::unique_ptr<DoorState> validStartingState) : _targetState(targetState), _validStartingState(std::move(validStartingState))
	{
	}

	virtual std::shared_ptr<DoorState> MakeStateTransition(std::shared_ptr<DoorState> originalState) const noexcept
	{
		if (IsValidStateTransition(originalState))
		{
			return _targetState;
		}
		return originalState;
	};

	virtual ~DoorStateEvent() = default;

private:
	virtual bool IsValidStateTransition(std::shared_ptr<DoorState> originalState) const noexcept
	{
		return typeid(*originalState) == typeid(*_validStartingState);
	}
};

export class OpenEvent : public DoorStateEvent
{

public:
	OpenEvent() : DoorStateEvent(std::make_shared<OpenedState>(), std::make_unique<ClosedState>())
	{
	};
};

export class CloseEvent : public DoorStateEvent {
public:
	CloseEvent() : DoorStateEvent(std::make_shared<ClosedState>(), std::make_unique<OpenedState>())
	{
	}
};

export class LockEvent : public DoorStateEvent
{
public:
	LockEvent() : DoorStateEvent(std::make_shared<LockedState>(), std::make_unique<ClosedState>())
	{
	}
};

export class UnlockEvent : public DoorStateEvent
{
public:
	UnlockEvent() : DoorStateEvent(std::make_shared<ClosedState>(), std::make_unique<LockedState>())
	{
	}
};

export class DoorStateMachine
{
private:
	std::shared_ptr<DoorState> _state;
public:
	DoorStateMachine(std::shared_ptr<DoorState> state) : _state(state)
	{
	}

	const DoorState & GetState()
	{
		return *_state;
	}

	void HandleEvent(const DoorStateEvent& incomingEvent)
	{
		_state = incomingEvent.MakeStateTransition(_state);
	}

	operator std::string() const noexcept
	{
		return std::format("Door state: {}", _state->GetName());
	}

	friend std::ostream& operator<<(std::ostream& os, const DoorStateMachine& dsm)
	{
		os << (std::string)dsm << std::endl;
		return os;
	}
};

export void DemoDoorStateMachine()
{
	DoorStateMachine stateMachine(std::make_shared<ClosedState>());
	std::cout << stateMachine << std::endl;
	stateMachine.HandleEvent(CloseEvent());
	std::cout << stateMachine << std::endl;
	stateMachine.HandleEvent(LockEvent());
	std::cout << stateMachine << std::endl;
	stateMachine.HandleEvent(OpenEvent());
	std::cout << stateMachine << std::endl;
};