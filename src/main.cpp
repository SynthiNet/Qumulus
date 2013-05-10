/*
 * Qumulus UML editor
 *
 * Author: Frank Erens
 */

#include <Gui/Core/QumulusApplication.h>
#include <Gui/Widgets/MainWindow.h>

#include <cstdlib>
#include <ctime>

int main(int argc, char** argv) {
    std::srand(std::time(nullptr));

    QuGC::QumulusApplication app(argc, argv);

    QuGW::MainWindow w;
    w.show();

    return app.exec();
}
