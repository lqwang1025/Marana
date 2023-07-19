/*
 *        (C) COPYRIGHT Daniel Wang Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : trt_act.cpp
 * Authors    : wangliquan@cc-SYS-7048GR-TR
 * Create Time: 2023-07-19:10:12:42
 * Description:
 * 
 */

#include <structure/funcs/tensorRT/trt_executor.h>
#include <core/utils/logging.h>
#include <structure/funcs/activation.h>
#include <structure/funcs/ops.h>
#include <structure/tensor.h>

namespace mariana { namespace trt {

bool TensorRTEngine::_add_act_node(const Node& node, const ExecContext& context) {
    NodeList inputs = node.inputs();
    MCHECK(inputs.size()==1)<<node.op_type()<<" support 1 input only.";    
    const Shape& ishape = inputs[0]->shapes()[0];
    nvinfer1::ITensor* itensor = _add_tensor(ishape, inputs[0]->name(), nvinfer1::DataType::kFLOAT);
    auto act_type_chose = [&]()->nvinfer1::ActivationType {
        if (node.op_type() == MRELU) {
            return nvinfer1::ActivationType::kRELU;
        } else {
            MLOG(FATAL)<<"Unsupport act type:"<<node.op_type();
        }
    };
    nvinfer1::IActivationLayer* layer = network_->addActivation(*itensor, act_type_chose());
    layer->setName(node.name().c_str());
    return true;
}

}} // namespace mariana::trt
