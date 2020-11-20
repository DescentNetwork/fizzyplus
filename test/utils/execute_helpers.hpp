// Fizzy: A fast WebAssembly interpreter
// Copyright 2020 The Fizzy Authors.
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "execute.hpp"
#include <test/utils/instantiate_helpers.hpp>
#include <initializer_list>

namespace fizzy::test
{
inline ExecutionResult execute(
    Instance& instance, FuncIdx func_idx, std::initializer_list<Value> args)
{
    assert(args.size() == instance.module->get_function_type(func_idx).inputs.size());
    return fizzy::execute(instance, func_idx, args.begin());
}

inline ExecutionResult execute(const std::unique_ptr<const Module>& module, FuncIdx func_idx,
    std::initializer_list<Value> args)
{
    auto instance = instantiate(*module);
    return test::execute(*instance, func_idx, args);
}
}  // namespace fizzy::test
