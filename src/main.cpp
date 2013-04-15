/*
 * Qumulus UML editor
 *
 * Author: Frank Erens
 */

#include <QtWidgets/QWidget>

#include <Lib/Core/Nyi.h>
#include <Gui/Core/QumulusApplication.h>

int main(int argc, char** argv) {
    QumulusApplication app(argc, argv);

    QWidget w;
    w.show();

    NYI();

    return app.exec();
}
