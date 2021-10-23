/**
 * @file UmlLoader.h
 *
 * @author ybw0014
 *
 * A loader class that loads the uml data from xml,
 * also capable to generate a uml node
 */

#ifndef UML_WARS_UMLLOADER_H
#define UML_WARS_UMLLOADER_H

#include <vector>
#include <memory>
#include <string>
#include <wx/xml/xml.h>
#include "Uml.h"
#include "UmlNode.h"
#include "UmlInheritNode.h"

class Game;

/**
 * A loader class that loads the uml data from xml
 */
class UmlLoader {
private:
    /// The game
    Game* mGame;

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
    /// Default constructor (disabled)
    UmlLoader() = delete;

    /// Copy constructor (disabled)
    UmlLoader(const UmlLoader &) = delete;

    /// Assignment operator
    void operator=(const UmlLoader &) = delete;

    /// Constructor
    UmlLoader(Game *game);

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

    std::shared_ptr<Uml> GenerateGoodUml();
    std::shared_ptr<Uml> GenerateBadUml();
};

#endif //UML_WARS_UMLLOADER_H
