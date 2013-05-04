/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "MultiplicityElement.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UK

bool MultiplicityElement::isMultivalued() const { 
    NYI(); 
    return false; 
}

bool MultiplicityElement::includesCardinatity(unsigned i) const { 
    NYI(); 
    return false; 
}

bool MultiplicityElement::includedMultiplicity(MultiplicityElement* m) const {
    NYI();
    return false;
}

QUML_END_NAMESPACE_UK
