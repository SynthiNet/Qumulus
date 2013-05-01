/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_DIAGRAMELEMENT_H_
#define UML_DIAGRAM_DIAGRAMELEMENT_H_

#include "internal_base.h"

#include <QtCore/QString>

#include <unordered_map>

#include <Lib/Core/Hash.h>

QUML_BEGIN_NAMESPACE_UD

class GraphElement;

class DiagramElement {
public:
    DiagramElement();
    
    const QString& property(const QString& key) const;
    QString& property(const QString& key);

    bool visible() const { return mVisible; }
    void setVisible(bool v) { mVisible = v; }

    GraphElement* container() const { return mContainer; }
    void setContainer(GraphElement* e) { mContainer = e; }

private:
    bool mVisible;
    std::unordered_map<QString, QString> mProperties;
    GraphElement* mContainer;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_DIAGRAMELEMENT_H_ */

