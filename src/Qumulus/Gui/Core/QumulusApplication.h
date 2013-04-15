/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_CORE_QUMULUSAPPLICATION_H_
#define GUI_CORE_QUMULUSAPPLICATION_H_

#include "internal_base.h"
#include <QtWidgets/QApplication>
#include <Gui/Widgets/MainWindow.h>

#ifdef qApp
#undef qApp
#endif
#define qApp static_cast<QumulusApplication*>(QCoreApplication::instance())

QUML_BEGIN_NAMESPACE_GC

class QumulusApplication : public QApplication {
    Q_OBJECT;

public:
    QumulusApplication(int& argc, char** argv);
    void setMainWindow(QuGW::MainWindow* m);
    QuGW::MainWindow* mainWindow();

public slots:
    void onFocusChanged(QWidget* old, QWidget* now);

private:
    QuGW::MainWindow* mMainWindow;
};

QUML_END_NAMESPACE_GC

#endif /* GUI_CORE_QUMULUSAPPLICATION_H_ */

