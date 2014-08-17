import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Window 2.0
import QtWebKit 3.0
//ApplicationWindow {
//    title: qsTr("Hello World")
//    width: 640
//    height: 480

//    menuBar: MenuBar {
//        Menu {
//            title: qsTr("File")
//            MenuItem {
//                text: qsTr("Exit")
//                onTriggered: Qt.quit();
//            }
//        }
//    }

//    Button {
//        text: qsTr("Hello World")
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.verticalCenter: parent.verticalCenter
//    }
//}

ScrollView {
    width: 1280
    height: 720
    WebView {
        id: webview
        url: "http://www.baidu.com"
        anchors.fill: parent
        onNavigationRequested: {
            // detect URL scheme prefix, most likely an external link
            var schemaRE = /^\w+:/;
            if (schemaRE.test(request.url)) {
                request.action = WebView.AcceptRequest;
            } else {
                request.action = WebView.IgnoreRequest;
                // delegate request.url here
            }
        }
    }
}
