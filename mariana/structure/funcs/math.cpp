/*
 *        (C) COPYRIGHT Daniel Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : math.cpp
 * Authors    : wangliquan@zkln
 * Create Time: 2022-12-29:11:28:42
 * Description:
 * 
 */

#include <core/utils/logging.h>
#include <structure/funcs/math.h>

namespace mariana {

tensor_list MathFunction::compute(tensor_list&& inputs) {
    
}

ShapeList MathFunction::infer_shape(ShapeList shapes) {
    MCHECK(shapes.size() == 2)<<"Now math only support 2 input:"<<shapes.size();
    const Shape& ashape = shapes[0];
    const Shape& bshape = shapes[1];
    if (ashape.size() > bshape.size()) {
        return {ashape};
    } else {
        return {bshape};
    }
}

} // namespace mariana
