/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Diagram.h"
#include "Style.h"

QUML_BEGIN_NAMESPACE_UD

constexpr static float kFontSize =
#ifdef Q_OS_MAC
        12.0;
#else
        10.0;
#endif

Diagram::Diagram(QString name, double resolution) :
        mName(name),
        mResolution(resolution) {
    auto s = new Style;
    setLocalStyle(s);
    s->setFontName("sans-serif");
    s->setFontSize(kFontSize);
}

Diagram::Diagram(const Diagram& d) :
        Shape(d) {

}

QUML_END_NAMESPACE_UD
