/*
 * Copyright (c) 2024 Samsung Electronics Co., Ltd. All Rights Reserved
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

#include <cker/eigen/Utils.h>
#include <cker/operation/AveragePool.h>
#include <cker/train/operation/AveragePool.h>
#include <cker/Shape.h>

#include <gtest/gtest.h>
#include <vector>

namespace
{
using namespace nnfw::cker;

template <typename T> class AvgPoolOpVerifier
{
private:
  const PoolParams _op_params;
  const Shape _in_shape;
  const Shape _out_shape;

public:
  AvgPoolOpVerifier(const nnfw::cker::PoolParams &op_params, const Shape &in_shape,
                    const Shape &out_shape)
    : _op_params(op_params), _in_shape(in_shape), _out_shape(out_shape)
  {
  }

public:
  void verifyForward(const std::vector<T> input, const std::vector<T> expected_output,
                     bool expect_eq = true)
  {
    assert(input.size() == _in_shape.FlatSize());
    assert(expected_output.size() == _out_shape.FlatSize());

    std::vector<T> cacluated_output(_out_shape.FlatSize());
    nnfw::cker::AveragePool<float>(_op_params, _in_shape, input.data(), _out_shape,
                                   cacluated_output.data());

    if (expect_eq)
      EXPECT_EQ(expected_output, cacluated_output);
    else
      EXPECT_NE(expected_output, cacluated_output);
  }

  void verifyBackward(const std::vector<T> incoming_data, const std::vector<T> expected_grad_data,
                      bool expect_eq = true)
  {
    assert(incoming_data.size() == _out_shape.FlatSize());
    assert(expected_grad_data.size() == _in_shape.FlatSize());

    std::vector<T> calcuated_grad(_in_shape.FlatSize());
    nnfw::cker::train::AveragePool2DGrad(_op_params, _out_shape, incoming_data.data(), _in_shape,
                                         calcuated_grad.data());

    if (expect_eq)
    {
      for (size_t i = 0; i < expected_grad_data.size(); i++)
      {
        EXPECT_FLOAT_EQ(expected_grad_data[i], calcuated_grad[i]);
      }
    }

    else
      EXPECT_NE(expected_grad_data, calcuated_grad);
  }
};

} // namespace

TEST(CKer_Operation, AveragePool2D)
{
  // Depth 1 case
  {
    nnfw::cker::PoolParams op_param;
    {
      op_param.stride_height = 1;
      op_param.stride_width = 1;
      op_param.filter_height = 2;
      op_param.filter_width = 2;
      op_param.padding_values.height = 0;
      op_param.padding_values.width = 0;
      op_param.float_activation_max = std::numeric_limits<float>::max();
      op_param.float_activation_min = std::numeric_limits<float>::lowest();
    }
    nnfw::cker::Shape in = {1, 3, 3, 1};
    nnfw::cker::Shape out = {1, 2, 2, 1};

    AvgPoolOpVerifier<float> verifier(op_param, in, out);

    /**
     *  input :                                   output:
     *
     *  10(0)  15(1)   2(2)
     *   7(3)   8(4)   9(5)   - (forward) ->    10(4)   8.5(4)
     *  10(6)   1(7)   0(8)                    6.5(4)   4.5(4)
     */

    std::vector<float> input = {10, 15, 2, 7, 8, 9, 10, 1, 0};
    std::vector<float> expected_output = {10, 8.5, 6.5, 4.5};
    verifier.verifyForward(input, expected_output);

    /**
     *  output_deriv:                     input_deriv:
     *
     *
     *   0.4   0.4                        0.1   0.2   0.1
     *   0.4   0.4     - (backward) ->    0.2   0.4   0.2
     *                                    0.1   0.2   0.1
     */

    std::vector<float> output_deriv = {0.4, 0.4, 0.4, 0.4};
    std::vector<float> expected_input_deriv = {0.1, 0.2, 0.1, 0.2, 0.4, 0.2, 0.1, 0.2, 0.1};
    verifier.verifyBackward(output_deriv, expected_input_deriv);
  }

  // Depth 2 case
  {
    nnfw::cker::PoolParams op_param;
    {
      op_param.stride_height = 1;
      op_param.stride_width = 1;
      op_param.filter_height = 3;
      op_param.filter_width = 3;
      op_param.padding_values.height = 0;
      op_param.padding_values.width = 0;
      op_param.float_activation_max = std::numeric_limits<float>::max();
      op_param.float_activation_min = std::numeric_limits<float>::lowest();
    }
    nnfw::cker::Shape in = {1, 3, 3, 2};
    nnfw::cker::Shape out = {1, 1, 1, 2};

    AvgPoolOpVerifier<float> verifier(op_param, in, out);

    /**
     *  depth[0]
     *  input :                               output:
     *
     *  10(0)  15(1)  2(2)
     *  10(3)  12(4)  17(5)   -(forward)->     16(0)
     *  50(6)  30(7)  -2(8)
     *
     *
     *  depth[1]
     *  input:                                 output:
     *
     *  -1(0)  2(1)  3(2)
     *  8(3)   9(4)  2(5)    -(forward)->       4(0)
     *  4(6)   2(7)  7(8)
     */

    std::vector<float> input(in.FlatSize());
    auto input_mat = MapAsMatrixWithLastDimAsRows(input.data(), in);
    input_mat << /* depth0 */ 10, 15, 2, 10, 12, 17, 50, 30, -2,
      /* depth1 */ -1, 2, 3, 8, 9, 2, 4, 2, 7;
    std::vector<float> expected_output = {16, 4};
    verifier.verifyForward(input, expected_output);

    /**
     * depth[0]
     * ouput_deriv:                 input_deriv:
     *
     *                             0.02  0.02  0.02
     *    0.18     -(backward)->   0.02  0.02  0.02
     *                             0.02  0.02  0.02
     *
     *
     * depth[1]
     * output_deriv:                input_deriv:
     *                              0.04  0.04  0.04
     *    0.36     -(backward)->    0.04  0.04  0.04
     *                              0.04  0.04  0.04
     */

    std::vector<float> output_deriv = {0.18, 0.36};
    std::vector<float> expected_input_deriv(in.FlatSize());
    auto input_deriv_mat = MapAsMatrixWithLastDimAsRows(expected_input_deriv.data(), in);
    input_deriv_mat << /* depth0 */ 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02,
      /* depth1 */ 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04;
    verifier.verifyBackward(output_deriv, expected_input_deriv);
  }
}

TEST(CKer_Operation, neg_AveragePoolInvalidExpectedValue)
{
  // Invalid expected value
  {
    nnfw::cker::PoolParams op_param;
    {
      op_param.stride_height = 1;
      op_param.stride_width = 1;
      op_param.filter_height = 2;
      op_param.filter_width = 2;
      op_param.padding_values.height = 0;
      op_param.padding_values.width = 0;
      op_param.float_activation_max = std::numeric_limits<float>::max();
      op_param.float_activation_min = std::numeric_limits<float>::lowest();
    }
    nnfw::cker::Shape in = {1, 2, 2, 1};
    nnfw::cker::Shape out = {1, 1, 1, 1};

    AvgPoolOpVerifier<float> verifier(op_param, in, out);

    std::vector<float> input = {0, 0, 0, 0};
    std::vector<float> expected_output = {-1};

    verifier.verifyForward(input, expected_output, false);
  }

  // Invalid expected value
  {
    nnfw::cker::PoolParams op_param;
    {
      op_param.stride_height = 2;
      op_param.stride_width = 2;
      op_param.filter_height = 2;
      op_param.filter_width = 2;
      op_param.padding_values.height = 1;
      op_param.padding_values.width = 1;
      op_param.float_activation_max = std::numeric_limits<float>::max();
      op_param.float_activation_min = std::numeric_limits<float>::lowest();
    }

    nnfw::cker::Shape in = {1, 2, 2, 1};
    nnfw::cker::Shape out = {1, 2, 2, 1};

    AvgPoolOpVerifier<float> verifier(op_param, in, out);

    std::vector<float> input = {0, 0, 0, 0};
    std::vector<float> expected_output = {0, 0, 0, 0};
    verifier.verifyForward(input, expected_output);

    std::vector<float> output_deriv = {0.1, 0.1, 0.1, 0.2};
    std::vector<float> expected_input_deriv = {0.1, 0.1, 0.1, 0.1};
    verifier.verifyBackward(output_deriv, expected_input_deriv, false);
  }
}
