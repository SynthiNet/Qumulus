/*
 * Qumulus UML editor
 *
 * Author: Frank Erens
 */

#include <Lib/Core/Nyi.h>
#include <Gui/Core/QumulusApplication.h>
#include <Gui/Widgets/MainWindow.h>

int main(int argc, char** argv) {
    QuGC::QumulusApplication app(argc, argv);

    QuGW::MainWindow w;
    w.show();

    QuGW::MainWindow w2;
    w2.show();

    return app.exec();
}
