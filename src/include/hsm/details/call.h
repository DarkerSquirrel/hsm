
#pragma once

#include <boost/hana.hpp>

namespace hsm
{
    
namespace bh {
using namespace boost::hana;
};

/**
 * Calls the nth callable of a list of callables
 * 
 * callables:   a boost hana tuple of callables
 * index:       the index of the callabled to be called
 * args:        args for the nth callable
 */
template <class TCallables, class... TArgs>
auto call(std::size_t index, const TCallables& callables, TArgs&... args)
{
    bh::fold_left(callables, callables, [&callables, &index, &args...](const auto& remainingCallables, const auto& callable){
            auto currentIndex = bh::minus(bh::size(callables), bh::size(remainingCallables));

            if (index == currentIndex) {
                callable(args...);
            }

            return bh::drop_front(remainingCallables);
        });
};
}