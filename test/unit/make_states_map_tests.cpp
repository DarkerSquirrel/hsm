#include "hsm/details/make_states_map.h"
#include "hsm/details/state.h"
#include "hsm/details/transition_table.h"
#include "hsm/front/transition_tuple.h"

#include <gtest/gtest.h>

#include <boost/hana/find.hpp>
#include <boost/hana/size.hpp>
#include <boost/hana/type.hpp>

using namespace ::testing;

namespace bh {
using namespace boost::hana;
}

namespace {

class MakeStatesMapTests : public Test {
};

// States
struct S1 {
    std::string data = "";
};
struct S2 {
};
struct S3 {
};
struct S4 {
};

// Events
struct e1 {
};

// Guards
const auto g1 = [](auto) { return true; };

// Actions
const auto a1 = [](auto /*event*/) {};

struct SubState {
    static constexpr auto make_transition_table()
    {
        // clang-format off
        return hsm::transition_table(
            // Region 0    
            hsm::transition(*hsm::state_t<S1> {}, hsm::event_t<e1> {}, g1, a1, hsm::state_t<S2> {})
        );
        // clang-format on
    }
};

struct MainState {
    static constexpr auto make_transition_table()
    {
        // clang-format off
        return hsm::transition_table(
            // Region 0    
            hsm::transition(*hsm::state_t<S1> {}, hsm::event_t<e1> {}, g1, a1, hsm::state_t<S2> {}),
            hsm::transition(hsm::state_t<S2> {}, hsm::event_t<e1> {}, g1, a1, hsm::state_t<SubState> {}),
            // Region 1
            hsm::transition(*hsm::state_t<S3> {}, hsm::event_t<e1> {}, g1, a1, hsm::state_t<S4> {})
        );
        // clang-format on
    }
};

}

TEST_F(MakeStatesMapTests, should_make_states_map)
{
    auto statesMap = hsm::make_states_map(hsm::state_t<MainState> {});

    ASSERT_EQ(bh::size_c<6>, bh::size(statesMap));

    ASSERT_EQ(
        bh::typeid_(std::unique_ptr<S1> {}),
        bh::typeid_(*bh::find(statesMap, bh::typeid_(hsm::state_t<S1> {})).value()));
    ASSERT_EQ(
        bh::typeid_(std::unique_ptr<S2> {}),
        bh::typeid_(*bh::find(statesMap, bh::typeid_(hsm::state_t<S2> {})).value()));
    ASSERT_EQ(
        bh::typeid_(std::unique_ptr<S3> {}),
        bh::typeid_(*bh::find(statesMap, bh::typeid_(hsm::state_t<S3> {})).value()));
    ASSERT_EQ(
        bh::typeid_(std::unique_ptr<S4> {}),
        bh::typeid_(*bh::find(statesMap, bh::typeid_(hsm::state_t<S4> {})).value()));
    ASSERT_EQ(
        bh::typeid_(std::unique_ptr<MainState> {}),
        bh::typeid_(*bh::find(statesMap, bh::typeid_(hsm::state_t<MainState> {})).value()));
    ASSERT_EQ(
        bh::typeid_(std::unique_ptr<SubState> {}),
        bh::typeid_(*bh::find(statesMap, bh::typeid_(hsm::state_t<SubState> {})).value()));
}

TEST_F(MakeStatesMapTests, should_return_same_instance)
{
    auto statesMap = hsm::make_states_map(hsm::state_t<MainState> {});

    auto s1 = bh::find(statesMap, bh::typeid_(hsm::state_t<S1> {})).value();
    (*s1)->data = std::string("42");
    ASSERT_EQ("42", (*bh::find(statesMap, bh::typeid_(hsm::state_t<S1> {})).value())->data);
}