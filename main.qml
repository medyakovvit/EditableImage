import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4

import My.EditableImage 1.0

Window {
    width: 800
    height: 600
    visible: true

    Column{
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        GroupBox{
            title: qsTr("RGB")
            width: 300
            height: 200

            Column{
                anchors.fill: parent
                anchors.margins: 5

                MySlider{
                    id: rSlider
                    label: qsTr("Red:")
                    stepSize: 1.0
                    minimumValue: -15.0
                    maximumValue: 15.0
                    value: 0.0
                    width: parent.width
                    height: 50
                }

                MySlider{
                    id: gSlider
                    label: qsTr("Green:")
                    stepSize: 1.0
                    minimumValue: -15.0
                    maximumValue: 15.0
                    value: 0.0
                    width: parent.width
                    height: 50
                }

                MySlider{
                    id: bSlider
                    label: qsTr("Blue:")
                    stepSize: 1.0
                    minimumValue: -15.0
                    maximumValue: 15.0
                    value: 0.0
                    width: parent.width
                    height: 50
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

            Rectangle{
                border.color: "gray"
                border.width: 2
                color: "transparent"
                anchors.fill: parent

                Text{
                    text: qsTr("Your image\nwill be here")
                    anchors.centerIn: parent
                }
            }
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

