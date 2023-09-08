#include <variant>

struct DoorState
{
    struct DoorOpened {};
    struct DoorClosed {};
    struct DoorLocked {};

    using State = std::variant<DoorOpened, DoorClosed, DoorLocked>;

    void open()
    {
        m_state = std::visit(OpenEvent{}, m_state);
    }

    void close()
    {
        m_state = std::visit(CloseEvent{}, m_state);
    }

    void lock()
    {
        m_state = std::visit(LockEvent{}, m_state);
    }

    void unlock()
    {
        m_state = std::visit(UnlockEvent{}, m_state);
    }

    State m_state;
};

using DoorOpened = DoorState::DoorOpened;
using DoorClosed = DoorState::DoorClosed;
using DoorLocked = DoorState::DoorLocked;
using State = DoorState::State;

struct OpenEvent
{
    State operator()(const DoorOpened&) { return DoorOpened(); }
    State operator()(const DoorClosed&) { return DoorOpened(); }
    // cannot open locked doors
    State operator()(const DoorLocked&) { return DoorLocked(); }
};

struct CloseEvent
{
    State operator()(const DoorOpened&) { return DoorClosed(); }
    State operator()(const DoorClosed&) { return DoorClosed(); }
    State operator()(const DoorLocked&) { return DoorLocked(); }
};

struct LockEvent
{
    // cannot lock opened doors
    State operator()(const DoorOpened&) { return DoorOpened(); }
    State operator()(const DoorClosed&) { return DoorLocked(); }
    State operator()(const DoorLocked&) { return DoorLocked(); }
};

struct UnlockEvent
{
    // cannot unlock opened doors
    State operator()(const DoorOpened&) { return DoorOpened(); }
    State operator()(const DoorClosed&) { return DoorClosed(); }
    // unlock
    State operator()(const DoorLocked&) { return DoorClosed(); }
};
