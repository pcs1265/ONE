/*
 * Copyright (c) 2018 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __ONERT_BACKEND_ICONFIG_H__
#define __ONERT_BACKEND_ICONFIG_H__

#include "ir/Layout.h"
#include "ir/Operation.h"
#include "util/ITimer.h"

#include <memory>
#include <string>

namespace onert
{
namespace backend
{

struct IConfig
{
  virtual ~IConfig() = default;

  virtual std::string id() = 0;
  virtual bool initialize() = 0;
  // Support permute kernel
  virtual bool SupportPermutation() = 0;
  virtual ir::Layout SupportLayout(const ir::Operation &node, ir::Layout frontend_layout) = 0;

  // Timer is used for backend profiling. In case of default (nullptr) timer profiler won't work.
  virtual std::unique_ptr<util::ITimer> timer() { return nullptr; }
};

} // namespace backend
} // namespace onert

#endif // __ONERT_BACKEND_ICONFIG_H__
