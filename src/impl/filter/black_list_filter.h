
// Copyright 2024-present the vsag project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <functional>

#include "typing.h"
#include "vsag/bitset.h"
#include "vsag/filter.h"

namespace vsag {

class BlackListFilter : public Filter {
public:
    explicit BlackListFilter(const IdFilterFuncType& fallback_func)
        : fallback_func_(fallback_func), is_bitset_filter_(false), bitset_(nullptr){};

    explicit BlackListFilter(const BitsetPtr& bitset) : bitset_(bitset), is_bitset_filter_(true){};

    bool
    CheckValid(int64_t id) const override;

private:
    IdFilterFuncType fallback_func_{nullptr};
    const BitsetPtr bitset_{nullptr};
    const bool is_bitset_filter_;
};
}  // namespace vsag
