/*
 * Qumulus UML editor
 *
 * Author: Frank Erens
 */

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

#include <Lib/Core/Nyi.h>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QWidget w;
    w.show();

    NYI();

    return app.exec();
}
