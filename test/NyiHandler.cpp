/*
 * Qumulus UML Editor 
 * Author: Frank Erens
 *
 */

#include <gtest/gtest.h>

#include <Lib/Core/Nyi.h>

class TestNyiHandler : public QuLC::NyiHandler {
public:
    void handleNyi(const char* file, unsigned line, 
            const char* func) const override;
};

QuLC::NyiHandler* QuLC::NyiHandler::gDefaultNyiHandler = 
        new TestNyiHandler;

void TestNyiHandler::handleNyi(const char* file, unsigned line, 
        const char* func) const {
    FAIL() << "NYI @" << file << ":" << line << " in " << func;
}
