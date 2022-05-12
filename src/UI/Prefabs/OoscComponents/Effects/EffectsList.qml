import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import OOSC 1.0
import "../../"

Item {
    id: control
    width: 250
    height: 250

    property SynthesizerControl synthesizer

    DelayEffectBlock {
        id: delayEffect
        width: control.width
        height: control.height
        visible: false

        onBackButtonClicked: {
            visible = false
            effectsList.visible = true
        }
    }

    ChorusEffectBlock {
        id: chorusEffect
        width: control.width
        height: control.height
        visible: false

        onBackButtonClicked: {
            visible = false
            effectsList.visible = true
        }
    }

    ReverbEffectBlock {
        id: reverbEffect
        width: control.width
        height: control.height
        visible: false

        onBackButtonClicked: {
            visible = false
            effectsList.visible = true
        }
    }

    FlangerEffectBlock {
        id: flangerEffect
        width: control.width
        height: control.height
        visible: false

        onBackButtonClicked: {
            visible = false
            effectsList.visible = true
        }
    }

    VibratoEffectBlock {
        id: vibratoEffect
        width: control.width
        height: control.height
        visible: false

        onBackButtonClicked: {
            visible = false
            effectsList.visible = true
        }
    }

    PhaserEffectBlock {
        id: phaserEffect
        width: control.width
        height: control.height
        visible: false

        onBackButtonClicked: {
            visible = false
            effectsList.visible = true
        }
    }

    CompressorEffectBlock {
        id: compressorEffect
        width: control.width
        height: control.height
        visible: false

        onBackButtonClicked: {
            visible = false
            effectsList.visible = true
        }
    }

    DistortionEffectBlock {
        id: distortionEffect
        width: control.width
        height: control.height
        visible: false

        onBackButtonClicked: {
            visible = false
            effectsList.visible = true
        }
    }

    EqEffectBlock {
        id: eqEffect
        width: control.width
        height: control.height
        visible: false

        onBackButtonClicked: {
            visible = false
            effectsList.visible = true
        }
    }

    ListView {
        id: effectsList
        width: parent.width
        height: parent.height

        model: [{
                "effect": delayEffect
            }, {
                "effect": chorusEffect
            }, {
                "effect": reverbEffect
            }, {
                "effect": flangerEffect
            }, {
                "effect": vibratoEffect
            }, {
                "effect": phaserEffect
            }, {
                "effect": compressorEffect
            }, {
                "effect": distortionEffect
            }, {
                "effect": eqEffect
            }]
        delegate: Text {
            id: effectTitle
            color: effectsList.model[index].effect.active ? "#98c379" : "#993939"
            text: effectsList.model[index].effect.title
            anchors.left: parent.left
            anchors.right: parent.right
            height: ScaleControl.scaleY(40)
            font.pixelSize: ScaleControl.scaleY(20) 
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.italic: true
            font.family: "Golos UI VF"

            MouseArea {
                anchors.fill: enableImage
                z: 1000
                preventStealing: true
                hoverEnabled: true
                onPressed: {
                    synthesizer.attachEffect(
                                effectsList.model[index].effect.effect)
                    effectsList.model[index].effect.active = true
                }
            }

            Image {
                id: enableImage
                width: ScaleControl.scaleY(20)
                height: width
                anchors.left: parent.left
                anchors.leftMargin: ScaleControl.scaleX(10)
                anchors.verticalCenter: parent.verticalCenter
                source: effectsList.model[index].effect.active ? "qrc:/resources/images/effects/active.png" : "qrc:/resources/images/effects/deactive.png"
                mipmap: true
                visible: effectsList.currentIndex === index ? true : false

                ScaleAnimator {
                    id: appearAnimation
                    target: enableImage
                    from: 0.2
                    to: 1
                    duration: 70
                    running: true
                }
                onVisibleChanged: {
                    appearAnimation.start()
                }
            }
            MouseArea {
                anchors.fill: goImage
                z: 1000
                preventStealing: true
                hoverEnabled: true
                onPressed: {
                    effectsList.visible = false
                    effectsList.model[index].effect.visible = true
                }
            }
            Image {
                id: goImage
                width: ScaleControl.scaleX(20)
                height: width
                anchors.right: parent.right
                anchors.rightMargin: ScaleControl.scaleX(5)
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/resources/images/effects/rightArrow.png"
                mipmap: true
                visible: (effectsList.currentIndex === index
                          && effectsList.model[index].effect.active) ? true : false

                ScaleAnimator {
                    id: appearAnimation2
                    target: goImage
                    from: 0.2
                    to: 1
                    duration: 70
                    running: true
                }
                onVisibleChanged: {
                    appearAnimation2.start()
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: effectsList.currentIndex = index
            }
        }
        highlight: Item {
            id: effectsListHighlight
            Rectangle {
                id: rect
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: ScaleControl.scaleX(10)
                anchors.rightMargin: ScaleControl.scaleX(10)
                height: 1
                color: effectsList.model[effectsList.currentIndex].effect.active ? "#98c379" : "#993939"
            }
            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: ScaleControl.scaleX(10)
                anchors.rightMargin: ScaleControl.scaleX(10)
                height: 1
                y: ScaleControl.scaleY(39)
                color: effectsList.model[effectsList.currentIndex].effect.active ? "#98c379" : "#993939"
            }
            PropertyAnimation { id: animation;
                        target: effectsListHighlight;
                        property: "width";
                        from: 30;
                        to: effectsList.width
                        duration: 250 
            }
            onVisibleChanged: {
                animation.running = true
            }
        }
        clip: true
        highlightFollowsCurrentItem: true
    }
}
