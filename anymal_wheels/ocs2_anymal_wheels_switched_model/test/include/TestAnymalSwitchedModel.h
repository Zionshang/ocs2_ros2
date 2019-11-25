/*!
* @file    TestAnymalSwitchedModel.h
* @author  Jan Carius
* @date    Nov, 2017
*/

#pragma once

// model
#include <ocs2_anymal_bear_switched_model/core/AnymalKinematics.h>
#include <ocs2_anymal_bear_switched_model/core/AnymalCom.h>

namespace anymal {

class TestAnymalSwitchedModel {

public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  TestAnymalSwitchedModel() :
    stanceLegs_({{true,true,true,true}})
    {
  }

  void init() {
    // nothing to do yet
  }

public:
  AnymalKinematics kinematics_;
  AnymalCom comDynamics_;

  std::array<bool,4> stanceLegs_;

};

} // namespace anymal
