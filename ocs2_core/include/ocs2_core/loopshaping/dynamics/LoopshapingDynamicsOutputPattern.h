//
// Created by rgrandia on 30.04.19.
//

#ifndef OCS2_LOOPSHAPINGDYNAMICSOUTPUTPATTERN_H
#define OCS2_LOOPSHAPINGDYNAMICSOUTPUTPATTERN_H

namespace ocs2 {
template <size_t FULL_STATE_DIM, size_t FULL_INPUT_DIM, size_t SYSTEM_STATE_DIM, size_t SYSTEM_INPUT_DIM, size_t FILTER_STATE_DIM,
          size_t FILTER_INPUT_DIM>
class LoopshapingDynamicsOutputPattern final
    : public LoopshapingDynamics<FULL_STATE_DIM, FULL_INPUT_DIM, SYSTEM_STATE_DIM, SYSTEM_INPUT_DIM, FILTER_STATE_DIM, FILTER_INPUT_DIM> {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  using BASE = LoopshapingDynamics<FULL_STATE_DIM, FULL_INPUT_DIM, SYSTEM_STATE_DIM, SYSTEM_INPUT_DIM, FILTER_STATE_DIM, FILTER_INPUT_DIM>;
  using typename BASE::filter_input_vector_t;
  using typename BASE::filter_state_vector_t;
  using typename BASE::SYSTEM;
  using typename BASE::system_input_vector_t;

  LoopshapingDynamicsOutputPattern(const SYSTEM& controlledSystem, std::shared_ptr<LoopshapingDefinition> loopshapingDefinition)
      : BASE(controlledSystem, std::move(loopshapingDefinition)) {}

  ~LoopshapingDynamicsOutputPattern() override = default;

  LoopshapingDynamicsOutputPattern(const LoopshapingDynamicsOutputPattern& obj) = default;

  LoopshapingDynamicsOutputPattern* clone() const override { return new LoopshapingDynamicsOutputPattern(*this); };

 protected:
  using BASE::loopshapingDefinition_;

 private:
  void filterFlowmap(const filter_state_vector_t& x_filter, const filter_input_vector_t& u_filter, const system_input_vector_t& u_system,
                     filter_state_vector_t& filterStateDerivative) override {
    const auto& r_filter = loopshapingDefinition_->getInputFilter();
    filterStateDerivative = r_filter.getA() * x_filter + r_filter.getB() * u_system;
  }
};
}  // namespace ocs2

#endif  // OCS2_LOOPSHAPINGDYNAMICSOUTPUTPATTERN_H
