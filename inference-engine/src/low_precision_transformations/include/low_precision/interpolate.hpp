// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "transparent_base_transformation.hpp"

namespace ngraph {
namespace pass {
namespace low_precision {

class TRANSFORMATIONS_API InterpolateTransformation : public LayerTransformation {
public:
    InterpolateTransformation(const Params& params) : LayerTransformation(params) {}
    ~InterpolateTransformation() override {}
    bool transform(TransformationContext &context, ngraph::pattern::Matcher &m) const override;
    void registerMatcherIn(GraphRewrite& pass, TransformationContext& context) const override;
    bool isPrecisionPreserved(std::shared_ptr<Node> layer) const noexcept override;
    bool canBeTransformed(const TransformationContext& context, std::shared_ptr<Node> layer) const override;
};

}  // namespace low_precision
}  // namespace pass
}  // namespace ngraph
