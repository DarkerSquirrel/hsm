#pragma once

#include <type_traits>

namespace hsm {
namespace details {
template <class Source, class Event, class Guard, class Action, class Target> struct Transition {
    constexpr Transition(Source source, Event event, Guard guard, Action action, Target target)
        : m_guard(guard)
        , m_action(action)
    {
    }

    [[nodiscard]] constexpr auto source() const -> Source
    {
        return Source {};
    }

    [[nodiscard]] constexpr auto event() const -> Event
    {
        return Event {};
    }

    [[nodiscard]] constexpr auto action() const -> Action
    {
        return m_action;
    }

    [[nodiscard]] constexpr auto guard() const -> Guard
    {
        return m_guard;
    }

    [[nodiscard]] constexpr auto target() const -> Target
    {
        return Target {};
    }

  private:
    const Guard m_guard;
    const Action m_action;
};

template <class Event, class Guard, class Action> struct InternalTransition {
    constexpr InternalTransition(Event event, Guard guard, Action action)
        : m_guard(guard)
        , m_action(action)
    {
    }

    constexpr auto event() const -> Event
    {
        return Event {};
    }

    constexpr auto action() const -> Action
    {
        return m_action;
    }

    constexpr auto guard() const -> Guard
    {
        return m_guard;
    }

  private:
    const Guard m_guard;
    const Action m_action;
};

template <class Parent, class Source, class Event, class Guard, class Action, class Target>
struct ExtendedTransition {
    constexpr ExtendedTransition(
        Parent parent, Source source, Event event, Guard guard, Action action, Target target)
        : m_guard(guard)
        , m_action(action)
    {
    }

    [[nodiscard]] constexpr auto parent() const -> Parent
    {
        return Parent {};
    }

    [[nodiscard]] constexpr auto source() const -> Source
    {
        return Source {};
    }

    [[nodiscard]] constexpr auto event() const -> Event
    {
        return Event {};
    }

    [[nodiscard]] constexpr auto action() const -> Action
    {
        return m_action;
    }

    [[nodiscard]] constexpr auto guard() const -> Guard
    {
        return m_guard;
    }

    [[nodiscard]] constexpr auto target() const -> Target
    {
        return Target {};
    }

  private:
    const Action m_action;
    const Guard m_guard;
};

constexpr auto transition
    = [](auto&&... xs) { return Transition<std::decay_t<decltype(xs)>...> { xs... }; };

constexpr auto internal_transition
    = [](auto&&... xs) { return InternalTransition<std::decay_t<decltype(xs)>...> { xs... }; };

constexpr auto extended_transition = [](auto&& parent, auto&& transition) {
    return ExtendedTransition<
        std::decay_t<decltype(parent)>,
        std::decay_t<decltype(transition.source())>,
        std::decay_t<decltype(transition.event())>,
        std::decay_t<decltype(transition.guard())>,
        std::decay_t<decltype(transition.action())>,
        std::decay_t<decltype(transition.target())>> { parent,
                                                       transition.source(),
                                                       transition.event(),
                                                       transition.guard(),
                                                       transition.action(),
                                                       transition.target() };
};
}
}