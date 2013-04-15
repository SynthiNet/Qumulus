/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_CORE_QUMULUSAPPLICATION_H_
#define GUI_CORE_QUMULUSAPPLICATION_H_

#include <QtWidgets/QApplication>

class QumulusApplication : public QApplication {
    Q_OBJECT;

public:
    QumulusApplication(int& argc, char** argv);
    
};

#endif /* GUI_CORE_QUMULUSAPPLICATION_H_ */

