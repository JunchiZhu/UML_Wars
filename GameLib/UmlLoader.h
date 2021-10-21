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

    /**
     * Get the number of class names
     * @return the number of class names
     */
    int GetNumNames() const { return mNames.size(); }

    /**
     * Get the number of class attributes
     * @return the number of class attributes
     */
    int GetNumAttributes() const { return mAttributes.size(); }

    /**
     * Get the number of class operations
     * @return the number of class operations
     */
    int GetNumOperations() const { return mOperations.size(); }

    /**
     * Get the number of inheritances
     * @return the number of inheritances
     */
    int GetNumInheritances() const { return mInheritances.size(); }
};

#endif //UML_WARS_UMLLOADER_H
