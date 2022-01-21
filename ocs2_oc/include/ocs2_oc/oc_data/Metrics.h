/******************************************************************************
Copyright (c) 2017, Farbod Farshidian. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#pragma once

#include <ocs2_core/Types.h>
#include <ocs2_oc/oc_problem/OptimalControlProblem.h>

namespace ocs2 {

struct Metrics {
  using value_t = std::pair<vector_t, scalar_t>;

  // Cost
  scalar_t cost;

  // Equality constraints
  vector_t stateEqConstraint;
  vector_t stateInputEqConstraint;

  // Lagrangians
  std::vector<value_t> stateEqLagrangian;
  std::vector<value_t> stateIneqLagrangian;
  std::vector<value_t> stateInputEqLagrangian;
  std::vector<value_t> stateInputIneqLagrangian;
};

struct MetricsCollection {
  Metrics final;
  std::vector<Metrics> preJumps;
  std::vector<Metrics> intermediates;
};

/** Exchanges the given values of Metrics */
void swap(Metrics& lhs, Metrics& rhs);

/** Clears the value of the given Metrics */
void clear(Metrics& m);

/** Sums the penalty part of Metrics::value_t */
scalar_t sum(const std::vector<Metrics::value_t>& termsValue);

/** Exchanges the given values of MetricsCollection */
void swap(MetricsCollection& lhs, MetricsCollection& rhs);

/** Clears the value of the given MetricsCollection */
void clear(MetricsCollection& m);

}  // namespace ocs2
