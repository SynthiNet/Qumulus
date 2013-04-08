/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef QUMULUS_GUI_CORE_NYI_H_
#define QUMULUS_GUI_CORE_NYI_H_

#include "internal_base.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_GC

class GuiNyiHandler : public QuLC::NyiHandler {
public:
    void handleNyi(const char* file, unsigned line, 
            const char* func) const override;
};

QUML_END_NAMESPACE_GC

#endif /* QUMULUS_GUI_CORE_NYI_H_ */

