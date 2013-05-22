/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_FEATURELABEL_H_
#define UML_DIAGRAM_FEATURELABEL_H_

#include "internal_base.h"

#include "Label.h"

QUML_BEGIN_NAMESPACE_UD

class FeatureLabel : public Label {
public:
    FeatureLabel(QuUK::Element* e = 0, DiagramElement* p = 0);
    FeatureLabel(const QString& t, QuUK::Element* e = 0, DiagramElement* p = 0);
    FeatureLabel(const FeatureLabel& l);

    void setText(const QString& s) override;
    void resize(double, double) override;

    bool isStatic() const { return mStatic; }
    void setStatic(bool b) { mStatic = b; }

    QUML_CLONABLE(FeatureLabel);
private:
    bool mStatic = false;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_FEATURELABEL_H_ */

