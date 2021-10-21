/**
 * @file UmlLoader.cpp
 *
 * @author ybw0014
 */

#include "pch.h"
#include <memory>
#include "UmlLoader.h"
#include "UmlNode.h"
#include "UmlInheritNode.h"

/// UML data filename
const std::wstring DataFilename = L"data/uml.xml";

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
        auto type = child->GetName().ToStdWstring();
        auto value = child->GetContent().ToStdWstring();
        auto bad = child->GetAttribute(L"bad").ToStdWstring();

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
    // TODO: generate a good uml
}

/**
 * Generate a bad uml
 * @return the pointer of a bad uml
 */
std::shared_ptr<Uml> UmlLoader::GenerateBadUml()
{
    // TODO: generate a bad uml
}
