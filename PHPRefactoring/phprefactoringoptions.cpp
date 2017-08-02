#include "phprefactoringoptions.h"
#include "cl_standard_paths.h"

PHPRefactoringOptions::PHPRefactoringOptions()
    : clConfigItem("phprefactoring")
    , m_phprefactoringPhar("")
    , m_skipPreview(false)
{
}

PHPRefactoringOptions::~PHPRefactoringOptions() {}

void PHPRefactoringOptions::FromJSON(const JSONElement& json)
{
    m_phprefactoringPhar = json.namedObject("phprefactoringPhar").toString(m_phprefactoringPhar);
    m_skipPreview = json.namedObject("skipPreview").toBool(m_skipPreview);
}

JSONElement PHPRefactoringOptions::ToJSON() const
{
    JSONElement element = JSONElement::createObject(GetName());
    element.addProperty("phprefactoringPhar", m_phprefactoringPhar);
    element.addProperty("skipPreview", m_skipPreview);
    return element;
}

PHPRefactoringOptions& PHPRefactoringOptions::Load()
{
    clConfig config("phprefactoring.conf");
    config.ReadItem(this);
    return *this;
}

PHPRefactoringOptions& PHPRefactoringOptions::Save()
{
    clConfig config("phprefactoring.conf");
    config.WriteItem(this);
    return *this;
}
