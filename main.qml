import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4

import My.EditableImage 1.0

Window {
    width: 640
    height: 480
    visible: true

    Column{
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        GroupBox{
            title: qsTr("RGB")

            Column{
                anchors.fill: parent

                Slider{
                    id: rSlider
                    stepSize: 1.0
                    minimumValue: -15.0
                    maximumValue: 15.0
                    value: 0.0
                }

                Slider{
                    id: gSlider
                    stepSize: 1.0
                    minimumValue: -15.0
                    maximumValue: 15.0
                    value: 0.0
                }

                Slider{
                    id: bSlider
                    stepSize: 1.0
                    minimumValue: -15.0
                    maximumValue: 15.0
                    value: 0.0
                }
            }
        }

        EditableImage{
            id: editableImage
            r: rSlider.value
            g: gSlider.value
            b: bSlider.value
            onRChanged: rSlider.value = r
            onGChanged: gSlider.value = g
            onBChanged: bSlider.value = b
            width: 400
            height: 300
        }

        Button{
            text: qsTr("Load")
            onClicked: fileDialog.open()
        }
    }

    FileDialog{
        id: fileDialog
        selectExisting: true
        selectMultiple: false
        nameFilters: [ "Image files (*.jpg *.jpeg)"]

        onAccepted: {
            var urlStr = fileUrl.toString();
            editableImage.load(urlStr.substring(8, urlStr.length));
        }
    }
}

