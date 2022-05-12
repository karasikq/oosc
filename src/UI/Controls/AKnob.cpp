#include "AKnob.h"

AKnob::AKnob(QQuickItem *parent) : QQuickPaintedItem(parent) {
  automationConnected = false;
  interpolation = KnobInterpolation::KnobInterpolationMethod::Linear;
  direction = KnobDirection::KnobDirectionMethod::Horizontal;

  connect(this, &AKnob::mousePositionChanged, this, &AKnob::mouseMove);
  connect(this, &AKnob::mouseTrackChanged, this, &AKnob::trackMouseState);
  connect(this, &AKnob::mouseStartPositionChanged, this, &QQuickItem::update);

  automationRangeLeft = {0.0f, 1.0f, 0.5f};
  automationRangeRight = {0.0f, 1.0f, 0.5f};
  automatedParameter.setParameter(
      this, &AKnob::changeAutomatedCurrent, {0.0f, 1.0f, 0.5f});
  connect(&automatedParameter,
          &IChangeableParameter::valueChanged,
          this,
          &QQuickItem::update);

  valueRange = {0.f, 1.f, 0.f};
}

AKnob::~AKnob() {}

void AKnob::connectValueSender(AValueSender *sender) {
  sender->addAutomatedParameter(&automatedParameter);
  automationConnected = true;
}

void AKnob::disconnectSender() {
  automatedParameter.setAutomated(false);
  automationConnected = false;
  this->update();
}

void AKnob::updateAutomation(float value) {
  automatedParameter.setValue(value);
}

void AKnob::mouseMove() {
  float startProgress = valueRange.percentToMax(valueRange.getCurrent());
  float progress = 0.f;
  float value = 0.f;

  if (trackMouse) {
    float difference = 0.0f;
    switch (direction) {
    case KnobDirection::KnobDirectionMethod::Vertical:
      difference =
          (float)(startMousePosition.y() - mousePosition.y()) / (height() * 4);
      break;
    case KnobDirection::KnobDirectionMethod::Horizontal:
      difference =
          (float)(mousePosition.x() - startMousePosition.x()) / (width() * 4);
      break;
    default:
      break;
    };
    switch (interpolation) {
    case KnobInterpolation::KnobInterpolationMethod::Linear:
      progress = startProgress + difference;
      break;
    case KnobInterpolation::KnobInterpolationMethod::Exponential:
      progress =
          startProgress +
          exponentialGrowth(difference, coefRange.value(1.0f - startProgress));
      break;
    default:
      progress = startProgress + difference;
      break;
    }
    value = progress * valueRange.difference();
    startMousePosition = mousePosition;
    changeCurrent(valueRange.min + value);
  }
}

void AKnob::updateValues() { this->update(); }

void AKnob::trackMouseState(bool state) { trackMouse = state; }

void AKnob::setChangeableParametr(IChangeableParameter *parametr) {
  if (changeableParameter != nullptr) {
    disconnect(changeableParameter,
               &IChangeableParameter::parameterChanged,
               this,
               &AKnob::updateChangeableParameter);
  }
  this->changeableParameter = parametr;
  updateChangeableParameter();
  connect(parametr,
          &IChangeableParameter::parameterChanged,
          this,
          &AKnob::updateChangeableParameter);
}

void AKnob::updateChangeableParameter() {
  valueRange.min = changeableParameter->getMin().toFloat();
  valueRange.max = changeableParameter->getMax().toFloat();
  valueRange.setCurrent(changeableParameter->getCurrent().toFloat());
  changeCurrent(valueRange.getCurrent());
  updateValues();
}

void AKnob::changeAutomatedCurrent(float value) {
  endRange.setCurrent(endRange.value(value));
  if (changeableParameter != nullptr)
    changeableParameter->setValue(endRange.getCurrent());
}

void AKnob::changeCurrent(float value) {
  valueRange.setCurrent(value);
  MinMax<float> bufferRange(valueRange.min, valueRange.getCurrent(), .0f);
  endRange.min = bufferRange.value(1.0f - automationRangeLeft.getCurrent());
  bufferRange.min = valueRange.getCurrent();
  bufferRange.max = valueRange.max;
  endRange.max = bufferRange.value(automationRangeRight.getCurrent());

  postChangedAction();
}

void AKnob::postChangedAction() {
  changeableParameter->setValue(valueRange.getCurrent());
  emit valueChanged(valueRange.getCurrent());
  updateValues();
}
