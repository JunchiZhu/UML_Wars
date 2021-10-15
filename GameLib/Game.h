/**
 * @file Game.h
 *
 * @author ybw0014
 * @author Melody Buado
 *@author Matthew Baxter
 * The class that implements our game
 */



#ifndef UML_WARS_GAME_H
#define UML_WARS_GAME_H

#include <wx/xml/xml.h>

class Item;

class Game {
private:

    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    /// All of the items to populate our game
    std::vector<std::shared_ptr<Item>> mItems;

    void Game::XmlItem(wxXmlNode *node){};

public:

    double mXOffset = 0.0;
    double mYOffset = 0.0;
    double mScale = 0.0;

    /// Game area in virtual pixels
    const static int Width = 1250;

    /// Game area height in virtual pixels
    const static int Height = 1000;
    Game(){}; ///< Constructor
    ~Game(){}; ///< Destructor

    void Add(std::shared_ptr<Item> item);

    void OnDraw(wxGraphicsContext *graphics, int width, int height);

    void OnMouseMove(int x, int y, wxMouseEvent& event);
};

#endif //UML_WARS_GAME_H
