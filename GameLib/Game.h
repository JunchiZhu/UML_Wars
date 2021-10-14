/**
 * @file Game.h
 *
 * @author ybw0014
 *
 * The class that implements our game
 */

#include <wx/xml/xml.h>

#ifndef UML_WARS_GAME_H
#define UML_WARS_GAME_H

class Item;

class Game {
private:

    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    /// All of the items to populate our game
    std::vector<std::shared_ptr<Item>> mItems;

    void Game::XmlItem(wxXmlNode *node){};

public:
    Game(){}; ///< Constructor
    ~Game(){}; ///< Destructor

    void Add(std::shared_ptr<Item> item);
};

#endif //UML_WARS_GAME_H
