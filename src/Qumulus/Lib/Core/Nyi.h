/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef QUMULUS_LIB_CORE_NYI_H_
#define QUMULUS_LIB_CORE_NYI_H_

#include "internal_base.h"

QUML_BEGIN_NAMESPACE_LC

class NyiHandler {
public:
    virtual void handleNyi(const char* file, unsigned, 
            const char* func) const = 0;

    static void nyi(const char* file, unsigned line, const char* func) {
        gDefaultNyiHandler->handleNyi(file, line, func);
    }

public:
    static NyiHandler* gDefaultNyiHandler;
};

QUML_END_NAMESPACE_LC

#define NYI() Qumulus::Lib::Core::NyiHandler::nyi(__FILE__, \
        __LINE__, __PRETTY_FUNCTION__)

#endif /* QUMULUS_LIB_CORE_NYI_H_ */

