/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_CLASSIFIER_H_
#define UML_KERNEL_CLASSIFIER_H_

#include "internal_base.h"

#include "Namespace.h"
#include "Type.h"
#include "RedefinableElement.h"

QUML_BEGIN_NAMESPACE_UK

class Property;
class Feature;

class Classifier : public Type, public Namespace, public RedefinableElement {
public:
    Classifier();
    Classifier(QString name, Package* p = 0);

    bool abstract() const { return mAbstract; }
    void setAbstract(bool a) { mAbstract = a; }

    bool final() const { return mFinal; }
    void setFinal(bool f) { mFinal = f; }

    const QList<Property*>& attributes() const {
        return mAttributes;
    }

    /**
     * This function takes over ownership.
     */
    void addAttribute(Property* p);
    void removeAttribute(Property* p);

    const QSet<Feature*>& features() const {
        return mFeatures;
    }

    /**
     * This function takes over ownership.
     */
    void addFeature(Feature* p);
    void removeFeature(Feature* f);

    virtual QSet<Classifier*> general() const = 0;

    QUML_CLONABLE_ABSTRACT(Classifier);

private:
    bool mAbstract = false;
    bool mFinal = false;
    QList<Property*> mAttributes;
    QSet<Feature*> mFeatures;

};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_CLASSIFIER_H_ */

