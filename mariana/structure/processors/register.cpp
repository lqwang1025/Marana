/*
 *        (C) COPYRIGHT Daniel Wang Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : structure/processors/register.cpp
 * Authors    : wangliquan@cc-SYS-7048GR-TR
 * Create Time: 2023-08-02:13:41:36
 * Description:
 * 
 */

#include <structure/processors/register.h>
#include <structure/processors/yolov8_post.h>

namespace mariana {

#define ADD_PROCESSOR(identity, type)                                   \
    static auto __##identity##_make = [](const ConvertContext& context)->Processor* \
    { return new type{context}; };                                      \
    ProcessorHolder::add_func(ProcessorCategory::identity, __##identity##_make)

void register_processors() {
    ADD_PROCESSOR(YOLOV8_POST_ONE_OUTPUT, Yolov8OnePostProcessor);
    ADD_PROCESSOR(YOLOV8_POST_THREE_OUTPUT, Yolov8ThreePostProcessor);
}

#undef ADD_FUNC

void unregister_processors() {
    ProcessorHolder::release();
}

} // namespace mariana {
