/**
 * @file UmlLoader.cpp
 *
 * @author ybw0014
 */
#include "pch.h"

#include <memory>
#include <random>

#include "Game.h"
#include "UmlLoader.h"
#include "UmlNode.h"
#include "UmlInheritNode.h"

/// UML data filename
const std::wstring DataFilename = L"data/uml.xml";

/// The maximum number of attributes that can be generated
const int NumAttributesCap = 3;

/// The maximum number of operations that can be generated
const int NumOperationsCap = 4;

/**
 * Constructor
 */
UmlLoader::UmlLoader(Game *game) : mGame(game)
{
}

/**
 * Loads uml data from xml
 */
void UmlLoader::Load()
{
    // Load from xml
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(DataFilename))
    {
        wxMessageBox(L"Unable to load UML data");
        return;
    }

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //
    auto child = root->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        if(name == L"class")
        {
            LoadClasses(child);
        }
        else if(name == L"inheritance")
        {
            LoadInheritances(child);
        }
    }
}

/**
 * Add a node to the nodes collection
 * @param umlNode the node to be added
 */
void UmlLoader::Add(std::shared_ptr<UmlNode> umlNode)
{
    if (umlNode->GetType() == L"name")
    {
        mNames.push_back(umlNode);
    }
    else if (umlNode->GetType() == L"attribute")
    {
        mAttributes.push_back(umlNode);
    }
    else if (umlNode->GetType() == L"operation")
    {
        mOperations.push_back(umlNode);
    }
    else if(umlNode->GetType() == L"inherit")
    {
        mInheritances.push_back(umlNode);
    }
}

/**
 * load nodes under class
 * @param node XML node
 */
void UmlLoader::LoadClasses(wxXmlNode* node)
{
    auto child = node->GetChildren();
    for( ; child; child=child->GetNext())
    {
        // read from xml
        std::wstring type = child->GetName().ToStdWstring();
        std::wstring value = child->GetNodeContent().ToStdWstring();
        std::wstring bad = child->GetAttribute(L"bad").ToStdWstring();

        // init
        std::shared_ptr<UmlNode> umlNode;

        // empty reason
        if (bad.empty())
        {
            umlNode = std::make_shared<UmlNode>(type, value);
        }
        else
        {
            umlNode = std::make_shared<UmlNode>(type, value, bad);
        }

        Add(umlNode);
    }
}

/**
 * Load nodes under inheritance
 * @param node XML node
 */
void UmlLoader::LoadInheritances(wxXmlNode* node)
{
    auto child = node->GetChildren();
    for( ; child; child=child->GetNext())
    {
        // read from xml
        auto type = child->GetName().ToStdWstring();
        auto value = child->GetAttribute("base").ToStdWstring();
        auto derived = child->GetAttribute(L"derived").ToStdWstring();
        auto direction = child->GetAttribute(L"direction").ToStdWstring();
        auto bad = child->GetAttribute(L"bad").ToStdWstring();

        // init
        std::shared_ptr<UmlInheritNode> umlNode;

        // call correct constructors
        if (bad.empty())
        {
            umlNode = std::make_shared<UmlInheritNode>(type, value, derived);
        }
        else if(direction.empty())
        {
            umlNode = std::make_shared<UmlInheritNode>(type, value, derived, bad);
        }
        else
        {
            umlNode = std::make_shared<UmlInheritNode>(type, value, derived, direction, bad);
        }

        Add(umlNode);
    }
}

/**
 * Generate a good uml
 * @return the pointer of a good uml
 */
std::shared_ptr<Uml> UmlLoader::GenerateGoodUml()
{
    int num = 0;

    // name
    std::uniform_int_distribution<> nameIndex(0, GetNumNames() - 1);
    std::shared_ptr<UmlNode> name = mNames[nameIndex(mGame->GetRandom())];
    // make sure name is not a bad one
    while (name->IsBad())
    {
        name = mNames[nameIndex(mGame->GetRandom())];
    }

    // attributes
    std::vector<std::wstring> attrs;
    std::uniform_int_distribution<> attrNum(0, NumAttributesCap);
    std::uniform_int_distribution<> attrIndex(0, GetNumAttributes() - 1);
    num = attrNum(mGame->GetRandom()); // the number of attributes to be generated
    for (int i = 0; i < num; i++)
    {
        std::shared_ptr<UmlNode> attr = mAttributes[attrIndex(mGame->GetRandom())];
        // make sure attr is not a bad one, or added to list already
        while (attr->IsBad() || (!attrs.empty() &&
            std::find(attrs.begin(), attrs.end(), attr->GetValue()) != attrs.end()))
        {
            attr = mAttributes[attrIndex(mGame->GetRandom())];
        }
        attrs.push_back(attr->GetValue());
    }

    // operations
    std::vector<std::wstring> ops;
    std::uniform_int_distribution<> opNum(0, NumOperationsCap);
    std::uniform_int_distribution<> opIndex(0, GetNumOperations() - 1);
    num = opNum(mGame->GetRandom()); // the number of operations to be generated
    for (int i = 0; i < num; i++)
    {
        std::shared_ptr<UmlNode> op = mOperations[opIndex(mGame->GetRandom())];
        // make sure attr is not a bad one, or added to list already
        while (op->IsBad() || (!ops.empty() &&
            std::find(ops.begin(), ops.end(), op->GetValue()) != ops.end()))
        {
            op = mOperations[opIndex(mGame->GetRandom())];
        }
        ops.push_back(op->GetValue());
    }

    // pass values to uml constructor
    return std::make_shared<Uml>(mGame, name->GetValue(), attrs, ops);
}

/**
 * Generate a bad uml
 * @return the pointer of a bad uml
 */
std::shared_ptr<Uml> UmlLoader::GenerateBadUml()
{
    std::wstring badReason;
    int num = 0;

    // attributes
    std::vector<std::wstring> attrs;
    std::uniform_int_distribution<> attrNum(0, NumAttributesCap);
    std::uniform_int_distribution<> attrIndex(0, GetNumAttributes() - 1);
    num = attrNum(mGame->GetRandom()); // the number of attributes to be generated
    for (int i = 0; i < num; i++)
    {
        std::shared_ptr<UmlNode> attr = mAttributes[attrIndex(mGame->GetRandom())];
        // make sure the attributes is not listed
        // or a bad attribute has already been generated
        while ((attr->IsBad() && !badReason.empty()) ||
            std::find(attrs.begin(), attrs.end(), attr->GetValue()) != attrs.end())
        {
            attr = mAttributes[attrIndex(mGame->GetRandom())];
        }
        // put the attr to attrs and set bad reason
        attrs.push_back(attr->GetValue());
        if (attr->IsBad())
        {
            badReason = attr->GetBadReason();
        }
    }

    // operations
    std::vector<std::wstring> ops;
    std::uniform_int_distribution<> opNum(0, NumOperationsCap);
    std::uniform_int_distribution<> opIndex(0, GetNumOperations() - 1);
    num = opNum(mGame->GetRandom()); // the number of operations to be generated
    for (int i = 0; i < num; i++)
    {
        std::shared_ptr<UmlNode> op = mOperations[opIndex(mGame->GetRandom())];
        // make sure attr is not a bad one, or added to list already
        while ((op->IsBad() && !badReason.empty()) ||
            std::find(ops.begin(), ops.end(), op->GetValue()) != ops.end())
        {
            op = mOperations[opIndex(mGame->GetRandom())];
        }
        // put the op to ops and set bad reason
        ops.push_back(op->GetValue());
        if (op->IsBad())
        {
            badReason = op->GetBadReason();
        }
    }

    // if no bad attributes or operations generated, generate a bad name,
    // otherwise generate a good one
    std::uniform_int_distribution<> nameIndex(0, GetNumNames() - 1);
    std::shared_ptr<UmlNode> name = mNames[nameIndex(mGame->GetRandom())];
    // if generated name is good and bad reason is empty, generate new one
    // if generated name is bad and bad reason in not empty, generate new one
    while (name->IsBad() != badReason.empty())
    {
        name = mNames[nameIndex(mGame->GetRandom())];
    }
    if (name->IsBad())
    {
        badReason = name->GetBadReason();
    }

    // pass values to uml constructor
    return std::make_shared<Uml>(mGame, name->GetValue(), attrs, ops, badReason);
}
