//
// Created by rgrandia on 15.03.20.
//

#include "ocs2_switched_model_interface/logic/Gait.h"
#include "ocs2_switched_model_interface/core/MotionPhaseDefinition.h"

#include <ocs2_core/misc/Display.h>

#include <algorithm>
#include <cassert>
#include <cmath>

namespace switched_model {

bool isValidGait(const Gait& gait) {
  bool validGait = true;
  validGait &= gait.duration > 0;
  validGait &= std::all_of(gait.eventPhases.begin(), gait.eventPhases.end(), [](scalar_t phase) { return 0 < phase && phase < 1; });
  validGait &= std::is_sorted(gait.eventPhases.begin(), gait.eventPhases.end());
  validGait &= gait.eventPhases.size() + 1 == gait.modeSequence.size();
  return validGait;
}

bool isValidPhase(scalar_t phase) {
  return phase >= 0 && phase < 1.0;
}

scalar_t wrapPhase(scalar_t phase) {
  phase = std::fmod(phase, 1.0);
  if (phase < 0) {
    phase += 1.0;
  }
  return phase;
}

int getCurrentModeIndex(scalar_t phase, const Gait& gait) {
  assert(isValidPhase(phase));
  assert(isValidGait(gait));
  auto firstLargerValueIterator = std::upper_bound(gait.eventPhases.begin(), gait.eventPhases.end(), phase);
  return static_cast<int>(firstLargerValueIterator - gait.eventPhases.begin());
}

size_t getModeFromPhase(scalar_t phase, const Gait& gait) {
  assert(isValidPhase(phase));
  assert(isValidGait(gait));
  return gait.modeSequence[getCurrentModeIndex(phase, gait)];
}

scalar_t timeLeftInGait(scalar_t phase, const Gait& gait) {
  assert(isValidPhase(phase));
  assert(isValidGait(gait));
  return (1.0 - phase) * gait.duration;
}

scalar_t timeLeftInMode(scalar_t phase, const Gait& gait) {
  assert(isValidPhase(phase));
  assert(isValidGait(gait));
  int modeIndex = getCurrentModeIndex(phase, gait);
  if (modeIndex < gait.eventPhases.size()) {
    return (gait.eventPhases[modeIndex] - phase) * gait.duration;
  } else {
    return timeLeftInGait(phase, gait);
  }
}

feet_array_t<scalar_t> getCurrentSwingPhasePerLeg(scalar_t phase, const Gait& gait) {
  assert(isValidPhase(phase));
  assert(isValidGait(gait));
  feet_array_t<scalar_t> swingDurationPerLeg;

  int modeIndex = getCurrentModeIndex(phase, gait);
  const auto& stanceLegs = modeNumber2StanceLeg(gait.modeSequence[modeIndex]);

  for (int leg = 0; leg < switched_model::NUM_CONTACT_POINTS; ++leg) {
    if (stanceLegs[leg]) {
      swingDurationPerLeg[leg] = -1.0;
    } else {
      if (modeIndex < gait.eventPhases.size()) {
        swingDurationPerLeg[leg] =
            (phase - gait.eventPhases[modeIndex - 1]) / (gait.eventPhases[modeIndex] - gait.eventPhases[modeIndex - 1]);
      } else {
        swingDurationPerLeg[leg] = (phase - gait.eventPhases.rbegin()[1]) / (gait.eventPhases.rbegin()[0] - gait.eventPhases.rbegin()[1]);
      }
    }
  }
  return swingDurationPerLeg;
}

std::ostream& operator<<(std::ostream& stream, const Gait& gait) {
  stream << "Duration:       " << gait.duration << "\n";
  stream << "Event phases:  {" << ocs2::toDelimitedString(gait.eventPhases) << "}\n";
  stream << "Mode sequence: {" << ocs2::toDelimitedString(gait.modeSequence) << "}\n";
  return stream;
}

}  // namespace switched_model
