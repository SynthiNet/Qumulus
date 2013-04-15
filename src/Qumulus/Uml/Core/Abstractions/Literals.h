/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_ABSTRACTIONS_LITERALS_H_
#define UML_CORE_ABSTRACTIONS_LITERALS_H_

#include "internal_base.h"

#include "LiteralSpecification.h"

QUML_BEGIN_NAMESPACE_UCA

class LiteralBoolean : public LiteralSpecification {
public:
    LiteralBoolean(bool v) : mValue(v) {}

    QuLC::Optional<bool> boolValue() const override {
        return mValue;
    }
private:
    bool mValue;
};

class LiteralInteger : public LiteralSpecification {
public:
    LiteralInteger(int v) : mValue(v) {}

    QuLC::Optional<int> intValue() const override {
        return mValue;
    }
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
private:
    double mValue;
};

class LiteralString : public LiteralSpecification {
public:
    LiteralString(const QString& v) : mValue(v) {}

    QuLC::Optional<QString> stringValue() const override {
        return mValue;
    }
private:
    QString mValue;
};

class LiteralUnlimited : public LiteralSpecification {
public:
    LiteralUnlimited(QuLC::Unlimited v) : mValue(v) {}

    QuLC::Optional<QuLC::Unlimited> unlimitedValue() const override {
        return mValue;
    }
private:
    QuLC::Unlimited mValue;
};

QUML_END_NAMESPACE_UCA

#endif /* UML_CORE_ABSTRACTIONS_LITERALS_H_ */

