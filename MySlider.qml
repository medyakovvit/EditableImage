import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    property alias label: lblValueName.text
    property alias stepSize: aSlider.stepSize
    property alias minimumValue: aSlider.minimumValue
    property alias maximumValue: aSlider.maximumValue
    property alias value: aSlider.value

        Text{
            id: lblValueName
            anchors.left: parent.left
            anchors.top: parent.top
        }
        Text{
            id: lblValue
            text: value
            anchors.right: parent.right
            anchors.top: parent.top
        }

        Slider{
            id: aSlider
            anchors.left: parent.left
            anchors.top: lblValueName.bottom
            anchors.right: parent.right
            stepSize: 1.0
            minimumValue: -15.0
            maximumValue: 15.0
            value: 0.0
            tickmarksEnabled: true
        }

        Text{
            text: aSlider.minimumValue
            anchors.left: parent.left
            anchors.top: aSlider.bottom
            anchors.topMargin: 5
        }

        Text{
            text: Math.abs(aSlider.minimumValue+aSlider.maximumValue)/2
            anchors.horizontalCenter: aSlider.horizontalCenter
            anchors.top: aSlider.bottom
            anchors.topMargin: 5
        }

        Text{
            text: aSlider.maximumValue
            anchors.topMargin: 5
            anchors.right: parent.right
            anchors.top: aSlider.bottom
        }
}

