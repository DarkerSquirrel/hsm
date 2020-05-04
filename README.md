# Hana State Machine (HSM)
[![CI](https://github.com/erikzenker/hsm/workflows/CI/badge.svg)](https://github.com/erikzenker/hsm/actions?query=workflow%3ACI) [![Build Status](https://travis-ci.org/erikzenker/cmake-project-template.svg?branch=master)](https://travis-ci.org/erikzenker/hsm) [![codecov](https://codecov.io/gh/erikzenker/hsm/branch/master/graph/badge.svg)](https://codecov.io/gh/erikzenker/hsm) [![GitHub license](https://img.shields.io/github/license/erikzenker/hsm.svg)](https://github.com/erikzenker/hsm/blob/master/LICENSE) [![GitHub contributors](https://img.shields.io/github/contributors/erikzenker/hsm.svg)](https://GitHub.com/erikzenker/hsm/graphs/contributors/) [![GitHub release](https://img.shields.io/github/release/erikzenker/hsm.svg)](https://GitHub.com/erikzenker/hsm/releases/) [![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://paypal.me/erikzenker) [![Join the chat at https://gitter.im/hsm-gitter/community](https://badges.gitter.im/hsm-gitter/community.svg)](https://gitter.im/hsm-gitter/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
=

The **hana state machine** (hsm) is a [finite state machine](https://en.wikipedia.org/wiki/Finite-state_machine) library based on the [boost hana](https://www.boost.org/doc/libs/1_61_0/libs/hana/doc/html/index.html) meta programming library. It follows the principles of the [boost msm](https://www.boost.org/doc/libs/1_64_0/libs/msm/doc/HTML/index.html) and [boost sml](https://boost-experimental.github.io/sml/index.html) libraries, but tries to reduce own complex meta programming code to a minimum.

The following table compares features among popular c++ state machine libraries.
A click on a particular feature check mark will forward to the feature documentation.

 <table style="width:100%">
  <tr>
    <th>Feature</th>
    <th><a href="https://github.com/erikzenker/hsm">Hsm</a></th>
    <th><a href="https://boost-experimental.github.io/sml/index.html">Sml</a></th>
    <th><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/index.html">Msm</a></th>
    <th><a href="https://www.boost.org/doc/libs/1_73_0/libs/statechart/doc/index.html">Statechart</a></th>
  </tr>
  <tr>
    <td>External transition</td>
    <td><center><a href="test/integration/basic_transitions.cpp">✓</a></center></td>
    <td><center><a href="https://boost-experimental.github.io/sml/examples.html#transitions">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/ch03s02.html#d0e358">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/statechart/doc/uml_mapping.html#Transition">✓</a></center></td>
  </tr>
  <tr>
    <td>Anonymous transition (Completion)</td>
    <td><center><a href="test/integration/anonymous_transition.cpp">✓</a></center></td>
    <td><center><a href="https://boost-experimental.github.io/sml/examples.html#transitions">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/ch03s02.html#d0e713">✓</a></center></td>
    <td><center>✗</center></td>
  </tr>
  <tr>
    <td>Internal transition</td>
    <td><center><a href="test/integration/internal_transition.cpp">✓</a></center></td>
    <td><center><a href="https://boost-experimental.github.io/sml/examples.html#transitions">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/ch03s02.html#d0e740">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/statechart/doc/uml_mapping.html#InternalTransition">✓</a></center></td>
  </tr>
  <tr>
    <td>Direct transition</td>
    <td><center><a href="test/integration/direct_transition.cpp">✓</a></center></td>
    <td><center>✗</center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/ch03s02.html#d0e875">✓</a></center></td>
    <td><center>✗</center></td>
  </tr>
  <tr>
    <td>Guards / actions</td>
    <td><center><a href="test/integration/guards_actions.cpp">✓</a></center></td>
    <td><center><a href="test/integration/guards_actions.cpp">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/ch03s02.html#d0e358">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/statechart/doc/uml_mapping.html#Reactions">✓</a></center></td>
  </tr>
  <tr>
    <td>Entry / exit actions</td>
    <td><center><a href="test/integration/entry_exit_actions.cpp">✓</a></center></td>
    <td><center><a href="https://boost-experimental.github.io/sml/examples.html#transitions">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/ch03s02.html#d0e406">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/statechart/doc/uml_mapping.html#Actions">✓</a></center></td>
  </tr>  
  <tr>
    <td>Orthogonal regions</td>
    <td><center><a href="test/integration/orthogonal_regions.cpp">✓</a></center></td>
    <td><center><a href="https://boost-experimental.github.io/sml/examples.html#orthogonal-regions">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/ch03s02.html#d0e577">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/statechart/doc/tutorial.html#OrthogonalStates">✓</a></center></td>
  </tr> 
  <tr>
    <td>Hierachies / sub state machines</td>
    <td><center><a href="test/integration/basic_transitions.cpp">✓</a></center></td>
    <td><center><a href="https://boost-experimental.github.io/sml/examples.html#composite">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/ch03s02.html#d0e529">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/statechart/doc/tutorial.html#BasicTopicsAStopWatch">✓</a></center></td>
  </tr>
  <tr>
    <td>Event defering</td>
    <td><center><a href="test/integration/defer_events.cpp">✓</a></center></td>
    <td><center><a href="https://boost-experimental.github.io/sml/examples.html#deferprocess">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/statechart/doc/tutorial.html#DeferringEvents">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/statechart/doc/tutorial.html#DeferringEvents">✓</a></center></td>
  </tr>  
  <tr>
    <td>Transition logging</td>
    <td><center><a href="test/integration/transition_logging.cpp">✓</a></center></td>
    <td><center><a href="https://boost-experimental.github.io/sml/examples.html#logging">✓</a></center></td>
    <td><center>✓</center></td>
    <td><center>?</center></td>
  </tr>
  <tr>
    <td>Initial pseudo state</td>
    <td><center><a href="test/integration/basic_transitions.cpp">✓</a></center></td>
    <td><center><a href="https://boost-experimental.github.io/sml/uml_vs_sml.html">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/ch03s02.html#d0e471">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/statechart/doc/tutorial.html#DefiningStatesAndEvents">✓</a></center></td>
  </tr>
  <tr>
    <td>History pseudo state</td>
    <td><center><a href="test/integration/history_pseudo_state.cpp">✓</a></center></td>
    <td><center><a href="https://boost-experimental.github.io/sml/examples.html#history">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/ch03s02.html#d0e668">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/statechart/doc/tutorial.html#History">✓</a></center></td>
  </tr>
  <tr>
    <td>eUml frontend</td>
    <td><center><a href="test/integration/transition_dsl.cpp">✓</a></center></td>
    <td><center><a href="https://boost-experimental.github.io/sml/uml_vs_sml.html">✓</a></center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/ch03s04.html">✓</a></center></td>
    <td><center>✗</center></td>
  </tr>
  <tr>
    <td>Entry / exit pseudo state</td>
    <td><center><a href="test/integration/entry_exit_pseudo_states.cpp">✓</a></center></td>
    <td><center>✗</center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/ch03s02.html#d0e875">✓</a></center></td>
    <td><center>✗</center></td>
  </tr>
  <tr>
    <td>State data members</td>
    <td><center><a href="test/integration/state_data_members.cpp">✓</a></center></td>
    <td><center>✗</center></td>
    <td><center>✓</center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/statechart/doc/tutorial.html#StateLocalStorage">✓</a></center></td>
  </tr>
  <tr>
    <td>Unexpected event / no transition handler</td>
    <td><center><a href="test/integration/unexpected_transition_handler.cpp">✓</a></center></td>
    <td><center>✗</center></td>
    <td><center><a href="https://www.boost.org/doc/libs/1_73_0/libs/msm/doc/HTML/ch03s02.html#d0e471">✓</a></center></td>
    <td><center>✗</center></td>
  </tr>
  <tr>
    <td>Dependency injection</td>
    <td><center><a href="test/integration/dependency_injection.cpp">✓</a></center></td>
    <td><center><a href="https://boost-experimental.github.io/sml/examples.html#dependency-injection">✓</a></center></td>
    <td><center>✗</center></td>
    <td><center>✗</center></td>
  </tr>
</table> 

## Simple Example ([Turnstile](example/turnstile/main.cpp))
![Turnstile fsm](doc/example/turnstile_example.svg "Turnstile fsm")

```c++
#include "hsm/hsm.h"

#include <cassert>

// States
struct Locked {
};
struct Unlocked {
};

// Events
struct Push {
};
struct Coin {
};

// Guards
const auto noError = [](auto /*event*/, auto /*source*/, auto /*target*/){return true;};

// Actions
const auto beep = [](auto /*event*/, auto /*source*/, auto /*target*/){ std::cout << "beep!" << std::endl;};
const auto blink = [](auto /*event*/, auto /*source*/, auto /*target*/){ std::cout << "blink, blink, blink!" << std::endl;};

struct Turnstile {
    static constexpr auto make_transition_table()
    {
        // clang-format off
        return hsm::transition_table(
            // Source               + Event               [Guard]   / Action = Target
            // +--------------------+---------------------+---------+--------+------------------------+
            hsm::state<Locked> {}   + hsm::event<Push> {}           / beep   = hsm::state<Locked> {}  ,
            hsm::state<Locked> {}   + hsm::event<Coin> {} [noError] / blink  = hsm::state<Unlocked> {},
            // +--------------------+---------------------+---------+--------+------------------------+
            hsm::state<Unlocked> {} + hsm::event<Push> {} [noError]          = hsm::state<Locked> {}  ,
            hsm::state<Unlocked> {} + hsm::event<Coin> {}           / blink  = hsm::state<Unlocked> {}
            // +--------------------+---------------------+---------+--------+------------------------+                        
            );
        // clang-format on
    }

    static constexpr auto initial_state()
    {
        return hsm::initial(hsm::state<Locked> {});
    }
};

int main()
{
    hsm::sm<Turnstile> turnstileSm;

    // The turnstile is initially locked
    assert(turnstileSm.is(hsm::state<Locked> {}));

    // Inserting a coin unlocks it
    turnstileSm.process_event(Coin {});
    assert(turnstileSm.is(hsm::state<Unlocked> {}));

    // Entering the turnstile will lock it again
    turnstileSm.process_event(Push {});
    assert(turnstileSm.is(hsm::state<Locked> {}));

    return 0;
}
```

## Runtime Benchmark Results
### [Simple Benchmark](benchmark/simple/)
| Events | States | Transitions | Process Events |
|--------|--------|-------------|----------------|
|  6     |   5    |      12     |        1000000 |

| Runtime | Compile Time |
|--|--|
|![Simple benchmark results](doc/benchmark/simple_benchmark_results.svg "simple benchmark results")|![Simple benchmark compile timeresults](doc/benchmark/simple_benchmark_compiletime_results.svg "simple benchmark compile time results")|


### [Complex Benchmark](benchmark/complex/)
| Events | States | Transitions | Process Events |
|--------|--------|-------------|----------------|
|  50    |   50   |      50     |        1000000 |

| Runtime | Compile Time |
|--|--|
|![Complex benchmark results](doc/benchmark/complex_benchmark_results.svg "Complex benchmark results")|![Complex benchmark compile time results](doc/benchmark/complex_benchmark_compiletime_results.svg "Complex benchmark compile time results")|

## Dependencies
* Boost 1.72
* C++17
* >= g++-8
* >= clang-8

## Create and Install the Package
``` bash
mkdir src/build
cd src/build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/tmp/
cmake --build . --target install
```

## Create and Install the Package with Conan
``` bash
mkdir src/build
cd src/build
conan install ..
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/tmp/
cmake --build . --target install
```

## Compile and Run the Tests Using the Installed Library
``` bash
mkdir test/build/
cd test/build/
cmake .. -DCMAkE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/tmp/
cmake --build . --target hsmTests
ctest -VV
```

## Author
* erikzenker(at)hotmail.com
