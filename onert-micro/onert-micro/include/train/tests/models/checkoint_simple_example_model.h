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

#ifndef ONERT_MICRO_TRAIN_TESTS_MODELS_CHECKPOINT_SIMPLE_EXAMPLE_MODEL_H
#define ONERT_MICRO_TRAIN_TESTS_MODELS_CHECKPOINT_SIMPLE_EXAMPLE_MODEL_H

#include <vector>
#include <cstring>

namespace onert_micro
{
namespace train
{
namespace test
{
namespace models
{

unsigned char checkpoint_simple_example_model_data[] = {
  0x18, 0x00, 0x00, 0x00, 0x43, 0x49, 0x52, 0x30, 0x00, 0x00, 0x0e, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x08, 0x00, 0x10, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x94, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 0x0c, 0x02, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
  0x80, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 0x6c, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0xe2, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x53, 0xb4, 0x05, 0x3f, 0x5f, 0x52, 0x80, 0xbe, 0xea, 0xe9, 0xc6, 0x3e, 0xa1, 0x01, 0x96, 0xbf,
  0x00, 0x00, 0x06, 0x00, 0x08, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x30, 0x00, 0x00, 0x00, 0xfa, 0x82, 0xe5, 0xbf, 0xbd, 0xb5, 0x33, 0xbf, 0x48, 0x23, 0x30, 0xbe,
  0xa2, 0x01, 0x35, 0xbe, 0xac, 0x06, 0x1f, 0x3f, 0x29, 0x81, 0x14, 0xc0, 0xa9, 0x0b, 0xd7, 0x3f,
  0xcd, 0x58, 0xd5, 0x3f, 0x5d, 0x9d, 0xb8, 0x3f, 0x3e, 0xe8, 0x1e, 0xbe, 0x2d, 0xaa, 0xe0, 0xbf,
  0x56, 0x65, 0x26, 0xbf, 0xf8, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0x04, 0x00, 0x04, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x18, 0x00, 0x14, 0x00, 0x10, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00,
  0x78, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x16, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x0c, 0x00, 0x07, 0x00, 0x08, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
  0x18, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00,
  0x58, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x8c, 0xff, 0xff, 0xff,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x6f, 0x75, 0x74, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0xb4, 0xff, 0xff, 0xff, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x62, 0x69, 0x61, 0x73, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xd8, 0xff, 0xff, 0xff, 0x0c, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x77, 0x65, 0x69, 0x67,
  0x68, 0x74, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x10, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x08, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x69, 0x6e, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x0c, 0x00,
  0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x09, 0x11, 0x00, 0x00, 0x00, 0x4f, 0x4e, 0x45, 0x2d, 0x74, 0x66, 0x6c, 0x69,
  0x74, 0x65, 0x32, 0x63, 0x69, 0x72, 0x63, 0x6c, 0x65, 0x00, 0x00, 0x00};
unsigned int checkpoint_simple_example_model_size = 588;

} // namespace models
} // namespace test
} // namespace train
} // namespace onert_micro

#endif // ONERT_MICRO_TRAIN_TESTS_MODELS_CHECKPOINT_SIMPLE_EXAMPLE_MODEL_H
