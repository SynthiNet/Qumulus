/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_GENERALIZATION_H_
#define UML_KERNEL_GENERALIZATION_H_

#include "internal_base.h"

#include "DirectedRelationship.h"

QUML_BEGIN_NAMESPACE_UK
class Classifier;

class Generalization : public DirectedRelationship {
public:
    Generalization();
    Generalization(Classifier* general, Classifier* specific);

    Classifier* general() const;
    void setGeneral(Classifier*);

    Classifier* specific() const;
    void setSpecific(Classifier*);

    void writeXml(QXmlStreamWriter& writer) const override;
    void readXml(QDomElement node, QuLC::XmlModelReader& reader) override;

    QUML_CLONABLE(Generalization);
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_GENERALIZATION_H_ */

