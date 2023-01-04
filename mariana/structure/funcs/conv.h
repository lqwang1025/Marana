/*
 *        (C) COPYRIGHT LeiNao Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : structure/funcs/conv.h
 * Authors    : wangliquan@zkln
 * Create Time: 2022-12-29:09:39:43
 * Description:
 *
 */

#ifndef __STRUCTURE_FUNCS_CONV_H__
#define __STRUCTURE_FUNCS_CONV_H__

#include <vector>
#include <cstdint>

#include <structure/function.h>
#include <structure/func_option.h>
#include <structure/tensor.h>

namespace mariana {

struct ConvOption : public BaseOption {
    ConvOption() {
        kernel_shape.clear();
        pads.clear();
        strides.clear();
        weights.clear();
    }
    ~ConvOption() {}
    std::vector<int32_t> dilations;
    int32_t group = 1;
    std::vector<int32_t> kernel_shape;
    std::vector<int32_t> pads;
    std::vector<int32_t> strides;
    std::vector<Tensor> weights;
};

struct ConvFunction : public Function {
    ConvFunction() {}
    ~ConvFunction() {}
    ConvOption option;
    tensor_list compute(tensor_list&& inputs) override;
    ShapeList infer_shape(ShapeList shapes) override;
};

} // namespace mariana

#endif /* __STRUCTURE_FUNCS_CONV_H__ */

