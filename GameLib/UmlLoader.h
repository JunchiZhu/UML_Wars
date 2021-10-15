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
#include "UmlNode.h"

/**
 * A loader class that loads the uml data from xml
 */
class UmlLoader {
private:
    std::vector<UmlNode> mNodes;
public:
    void Load();
};

#endif //UML_WARS_UMLLOADER_H
