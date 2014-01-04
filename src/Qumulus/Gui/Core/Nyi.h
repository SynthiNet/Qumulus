/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
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

