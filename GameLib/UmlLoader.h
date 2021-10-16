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
#include <wx/xml/xml.h>


/**
 * A loader class that loads the uml data from xml
 */
class UmlNode;
class UmlLoader {
private:
    /// the collection of node data read from xml
    std::vector<std::shared_ptr<UmlNode>> mNodes;

    void Add(std::shared_ptr<UmlNode> umlNode);
public:
    void Load();

    void LoadClasses(wxXmlNode *node);
    void LoadInheritances(wxXmlNode *node);
};

#endif //UML_WARS_UMLLOADER_H
