/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_CLASSIFIER_H_
#define UML_KERNEL_CLASSIFIER_H_

#include "internal_base.h"

#include "Type.h"
#include "RedefinableElement.h"
#include "Generalization.h"

QUML_BEGIN_NAMESPACE_UK

class Property;
class Feature;

class Classifier : public Type, public RedefinableElement {
    Q_OBJECT
public:
    Classifier();
    Classifier(QString name, Package* p = 0);

    bool abstract() const { return mAbstract; }
    void setAbstract(bool a) { mAbstract = a; }

    bool final() const { return mFinal; }
    void setFinal(bool f) { mFinal = f; }

    const QSet<Classifier*> general() const;

    QSet<Generalization*> generalizations() const { return mGeneralizations; }

    void addGeneralization(Generalization* g);
    void removeGeneralization(Generalization* g);

    QString sidebarText() const override { return name(); }

    QUML_CLONABLE_ABSTRACT(Classifier);

private:
    bool mAbstract = false;
    bool mFinal = false;
    QSet<Generalization*> mGeneralizations;

};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_CLASSIFIER_H_ */

