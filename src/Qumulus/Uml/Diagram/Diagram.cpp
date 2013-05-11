/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Diagram.h"
#include "Style.h"

QUML_BEGIN_NAMESPACE_UD

Diagram::Diagram(QString name, double resolution) :
        mName(name),
        mResolution(resolution) {
    auto s = new Style;
    setLocalStyle(s);
    s->setFontName("sans-serif");
    s->setFontSize(12.0);
}

Diagram::Diagram(const Diagram& d) :
        Shape(d) {

}

QUML_END_NAMESPACE_UD
