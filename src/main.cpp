/*
 * Qumulus UML editor
 *
 * Author: Frank Erens
 */

#include <Gui/Core/QumulusApplication.h>
#include <Gui/Widgets/MainWindow.h>

int main(int argc, char** argv) {
    QuGC::QumulusApplication app(argc, argv);

    QuGW::MainWindow w;
    w.show();

    return app.exec();
}
