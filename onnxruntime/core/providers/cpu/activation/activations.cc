// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "core/providers/cpu/activation/activations.h"

namespace onnxruntime {

#define REGISTER_UNARY_ELEMENTWISE_KERNEL_ALIAS(alias, x, sinceVersion)                              \
  ONNX_CPU_OPERATOR_KERNEL(                                                                          \
      alias,                                                                                         \
      sinceVersion,                                                                                  \
      KernelDefBuilder().MayInplace(0, 0).TypeConstraint("T", DataTypeImpl::GetTensorType<float>()), \
      x<float>);

#define REGISTER_UNARY_ELEMENTWISE_KERNEL(x, sinceVersion) \
  REGISTER_UNARY_ELEMENTWISE_KERNEL_ALIAS(x, x, sinceVersion)

REGISTER_UNARY_ELEMENTWISE_KERNEL(Elu, 6);
REGISTER_UNARY_ELEMENTWISE_KERNEL(HardSigmoid, 6);
REGISTER_UNARY_ELEMENTWISE_KERNEL(LeakyRelu, 6);
REGISTER_UNARY_ELEMENTWISE_KERNEL(ParametricSoftplus, 1);
REGISTER_UNARY_ELEMENTWISE_KERNEL(Relu, 6);
REGISTER_UNARY_ELEMENTWISE_KERNEL(ScaledTanh, 1);
REGISTER_UNARY_ELEMENTWISE_KERNEL(Selu, 6);
REGISTER_UNARY_ELEMENTWISE_KERNEL(Sigmoid, 6);
// SoftPlus is the default case for ParametricSoftPlus
REGISTER_UNARY_ELEMENTWISE_KERNEL_ALIAS(Softplus, ParametricSoftplus, 1);
REGISTER_UNARY_ELEMENTWISE_KERNEL(Softsign, 1);
REGISTER_UNARY_ELEMENTWISE_KERNEL(Tanh, 6);
REGISTER_UNARY_ELEMENTWISE_KERNEL(ThresholdedRelu, 1);

}  // namespace onnxruntime
