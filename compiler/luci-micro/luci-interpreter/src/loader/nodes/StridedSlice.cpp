/*
 * Copyright (c) 2021 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Builders.h"

#include "kernels/StridedSlice.h"

namespace luci_interpreter
{

std::unique_ptr<Kernel> build_kernel_CircleStridedSlice(std::vector<const Tensor *> &&inputs,
                                                        std::vector<Tensor *> &&outputs,
                                                        const uint32_t op_index,
                                                        KernelBuilder &builder)
{
  assert(inputs.size() == 4);

  const Tensor *input = inputs.at(0);
  const Tensor *begin = inputs.at(1);
  const Tensor *end = inputs.at(2);
  const Tensor *strides = inputs.at(3);
  Tensor *output = outputs.at(0);

  circle::OperatorT oper_t;
  builder.get_circle_reader()->operators()[op_index]->UnPackTo(&oper_t);
  const auto *options = oper_t.builtin_options.AsStridedSliceOptions();

  StridedSliceParams params{};
  params.begin_mask = options->begin_mask;
  params.ellipsis_mask = options->ellipsis_mask;
  params.end_mask = options->end_mask;
  params.new_axis_mask = options->new_axis_mask;
  params.shrink_axis_mask = options->shrink_axis_mask;

  return std::make_unique<kernels::StridedSlice>(input, begin, end, strides, output, params);
}

} // namespace luci_interpreter
