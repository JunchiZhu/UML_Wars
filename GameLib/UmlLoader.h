/**
 * @file UmlLoader.h
 *
 * @author ybw0014
 *
 * A loader class that loads the uml data from xml
 */

#ifndef UML_WARS_UMLLOADER_H
#define UML_WARS_UMLLOADER_H

#include <vector>
#include <memory>
#include <string>
#include "UmlNode.h"
#include "UmlInheritNode.h"

/**
 * A loader class that loads the uml data from xml
 */
class UmlLoader {
private:
    /// the collection of class names
    std::vector<std::shared_ptr<UmlNode>> mNames;
    /// the collection of class attributes
    std::vector<std::shared_ptr<UmlNode>> mAttributes;
    /// the collection of class operations
    std::vector<std::shared_ptr<UmlNode>> mOperations;
    /// the collection of inheritances
    std::vector<std::shared_ptr<UmlNode>> mInheritances;

    void Add(std::shared_ptr<UmlNode> umlNode);

    void LoadClasses(wxXmlNode *node);
    void LoadInheritances(wxXmlNode *node);
public:
    void Load();
};

#endif //UML_WARS_UMLLOADER_H
