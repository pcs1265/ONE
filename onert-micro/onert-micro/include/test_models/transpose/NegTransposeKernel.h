/*
 * Copyright (c) 2024 Samsung Electronics Co., Ltd. All Rights Reserved
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

#ifndef ONERT_MICRO_TEST_MODELS_NEG_TRANSPOSE_KERNEL_H
#define ONERT_MICRO_TEST_MODELS_NEG_TRANSPOSE_KERNEL_H

#include "test_models/TestDataBase.h"

namespace onert_micro
{
namespace test_model
{
namespace neg_transpose_wrong_perm_type
{

/*
 * Transpose Kernel:
 *
 *  Input(3, 8, 1) FLOAT32   Perm([1, 2, 0]) UINT8
 *               \                /
 *                   Transpose
 *                      |
 *                Output(8, 1, 3) FLOAT32
 */
const unsigned char test_kernel_model_circle[] = {
  0x18, 0x00, 0x00, 0x00, 0x43, 0x49, 0x52, 0x30, 0x00, 0x00, 0x0e, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x08, 0x00, 0x10, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x44, 0x00, 0x00, 0x00, 0x74, 0x01, 0x00, 0x00, 0x90, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x30, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x06, 0x00, 0x08, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x8c, 0xff, 0xff, 0xff, 0x90, 0xff, 0xff, 0xff,
  0x94, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x18, 0x00, 0x14, 0x00, 0x10, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00,
  0x68, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x0c, 0x00, 0x07, 0x00, 0x08, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1a,
  0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00,
  0x3c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xa4, 0xff, 0xff, 0xff, 0x0c, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x6f, 0x66, 0x6d, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x14, 0x00, 0x10, 0x00, 0x0f, 0x00, 0x08, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x10, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x70, 0x65, 0x72, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x10, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x08, 0x00, 0x04, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x69, 0x66, 0x6d, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x0c, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x11, 0x00, 0x00, 0x00, 0x4f, 0x4e, 0x45, 0x2d,
  0x74, 0x66, 0x6c, 0x69, 0x74, 0x65, 0x32, 0x63, 0x69, 0x72, 0x63, 0x6c, 0x65, 0x00, 0x00, 0x00};
} // namespace neg_transpose_wrong_perm_type

class NegTestDataWrongPermTypeTransposeKernel : public NegTestDataBase
{
public:
  NegTestDataWrongPermTypeTransposeKernel()
  {
    _test_kernel_model_circle = neg_transpose_wrong_perm_type::test_kernel_model_circle;
  }

  ~NegTestDataWrongPermTypeTransposeKernel() override = default;

  const unsigned char *get_model_ptr() override final { return _test_kernel_model_circle; }

protected:
  const unsigned char *_test_kernel_model_circle;
};

} // namespace test_model
} // namespace onert_micro

#endif // ONERT_MICRO_TEST_MODELS_NEG_TRANSPOSE_KERNEL_H
