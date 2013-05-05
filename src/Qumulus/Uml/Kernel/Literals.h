/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_LITERALS_H_
#define UML_KERNEL_LITERALS_H_

#include "internal_base.h"

#include "LiteralSpecification.h"

QUML_BEGIN_NAMESPACE_UK

class LiteralBoolean : public LiteralSpecification {
public:
    LiteralBoolean(bool v) : mValue(v) {}

    QuLC::Optional<bool> boolValue() const override {
        return mValue;
    }

    void setValue(QuLC::Optional<bool> v) { mValue = v; }
private:
    bool mValue;
};

class LiteralInteger : public LiteralSpecification {
public:
    LiteralInteger(int v) : mValue(v) {}

    QuLC::Optional<int> intValue() const override {
        return mValue;
    }

    void setValue(QuLC::Optional<int> v) { mValue = v; }
private:
    int mValue;
};

class LiteralNull : public LiteralSpecification {
public:
    LiteralNull() {}

    bool isNull() const override {
        return false;
    }

private:
    bool mValue;
};

class LiteralReal : public LiteralSpecification {
public:
    LiteralReal(double v) : mValue(v) {}

    QuLC::Optional<double> doubleValue() const {
        return mValue;
    }

    void setValue(QuLC::Optional<double> v) { mValue = v; }
private:
    double mValue;
};

class LiteralString : public LiteralSpecification {
public:
    LiteralString(const QString& v) : mValue(v) {}

    QuLC::Optional<QString> stringValue() const override {
        return mValue;
    }

    void setValue(QuLC::Optional<QString> v) { mValue = v; }
private:
    QString mValue;
};

class LiteralUnlimited : public LiteralSpecification {
public:
    LiteralUnlimited(QuLC::Unlimited v) : mValue(v) {}

    QuLC::Optional<QuLC::Unlimited> unlimitedValue() const override {
        return mValue;
    }

    void setValue(QuLC::Optional<QuLC::Unlimited> v) { mValue = v; }
private:
    QuLC::Unlimited mValue;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_LITERALS_H_ */

