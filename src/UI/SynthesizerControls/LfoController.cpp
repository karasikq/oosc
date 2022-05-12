#include "LfoController.h"

LfoController::LfoController() {
  phaseParameter.setParameter(
      this, &LfoController::setPhase, {0.0f, M_PI_2M, 0.0f});
  frequencyParameter.setParameter(
      this, &LfoController::setFrequency, {0.0f, 6.0f, 1.0f});
  waveshapeParameter.setParameter(
      this, &LfoController::setWaveshape, {0, 3, 0});
}

void LfoController::UpdateTime(float time) { processValue(time); }

void LfoController::processValue(float value) {
  float lfoValue = lfo.Value(M_PI_2M * value * frequency + phase, waveshape);
  emit lfoValueChanged(lfoValue);
  AValueSender::processValue(lfoValue);
}

void LfoController::setPhase(float value) { phase = value; }

void LfoController::setFrequency(float value) { frequency = value; }

void LfoController::setWaveshape(int value) {
  waveshape = (WaveShape::Shape)value;
  wavetable.SetTable(waveshape);
  emit lfoShapeChanged(*wavetable.getData(),
                       wavetable.getStartPosition(),
                       wavetable.getEndPosition());
}

void LfoController::setDrawer(ADataReceiver *drawer) {
  connect(this,
          &LfoController::lfoShapeChanged,
          drawer->receiver.get(),
          &ADataReceiverSlots::dataUpdate);
  emit lfoShapeChanged(*wavetable.getData(),
                       wavetable.getStartPosition(),
                       wavetable.getEndPosition());
}
