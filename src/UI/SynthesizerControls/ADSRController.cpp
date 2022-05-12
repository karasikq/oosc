#include "ADSRController.h"

ADSRController::ADSRController() {
  receiver = std::make_unique<ADSRSlots>(this);
  envelope = std::shared_ptr<ADSREnvelope>(new ADSREnvelope());
  envelope->setParametrs(0.017f, 1.17f, 0.2f, 0.f, 1.f, 0.6f);

  attackParameter.setParameter(
      this, &ADSRController::setAttack, {0.0f, 2.0f, 0.01f});
  decayParameter.setParameter(
      this, &ADSRController::setDecay, {0.0f, 6.0f, 1.17f});
  sustainParameter.setParameter(
      this, &ADSRController::setSustain, {0.0f, 1.0f, 0.6f});
  releaseParameter.setParameter(
      this, &ADSRController::setRelease, {0.0f, 5.0f, 0.2f});
}

void ADSRController::notePlayed(const Note<3> &note) {
  float envelopeValue = 0.0f;
  ADSREnvelope::State st;
  if (note.freezeState != ADSREnvelope::OFF) {
    if (note.envelopeTime[0] > envelope->AbsoluteDecayTime()) {
      envelopeValue = envelope->PeakValue(note.freezeState);
    } else {
      envelopeValue = envelope->Envelope(note.envelopeTime[0], st);
    }
  } else {
    envelopeValue = envelope->Envelope(note.envelopeTime[0], st);
  }
  processValue(envelopeValue);
}

void ADSRController::setAttack(float value) {
  envelope->setAttack(value);
  emit envelopeChanged();
}

void ADSRController::setDecay(float value) {
  envelope->setDecay(value);
  emit envelopeChanged();
}

void ADSRController::setSustain(float value) {
  envelope->setSustain(value);
  emit envelopeChanged();
}

void ADSRController::setRelease(float value) {
  envelope->setRelease(value);
  emit envelopeChanged();
}

void ADSRController::setDrawer(ADSRDrawer *drawer) {
  this->drawer = drawer;
  drawer->setEnvelope(envelope.get());
  QObject::connect(this,
                   &ADSRController::envelopeChanged,
                   drawer,
                   &ADSRDrawer::envelopeChanges);
  emit drawerChanged(drawer);
}

void ADSRSlots::lastNoteReceived(const Note<3> &note) {
  static_cast<ADSRController *>(object)->notePlayed(note);
}
