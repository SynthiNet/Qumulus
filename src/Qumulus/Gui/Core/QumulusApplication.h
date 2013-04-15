/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_CORE_QUMULUSAPPLICATION_H_
#define GUI_CORE_QUMULUSAPPLICATION_H_

#include "internal_base.h"
#include <QtWidgets/QApplication>

QUML_BEGIN_NAMESPACE_GC

class QumulusApplication : public QApplication {
    Q_OBJECT;

public:
    QumulusApplication(int& argc, char** argv);
};

QUML_END_NAMESPACE_GC

#endif /* GUI_CORE_QUMULUSAPPLICATION_H_ */

