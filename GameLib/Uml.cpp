/**
 * @file Uml.cpp
 *
 * @author ybw0014
 * @author Matthew Baxter
 */

#include "pch.h"
#include "Uml.h"
#include <random>


const double InitialUmlY = 200.0;


/**
 * Basic constructor
 * @param game the game
 * @param name the uml class name
 * @param attributes the uml class attributes
 * @param operations the uml class operations
 */
Uml::Uml(Game *game, std::wstring name, std::vector<std::wstring> attributes, std::vector<std::wstring> operations)
        : Item(game, L""), mName(name), mAttributes(attributes), mOperations(operations)
{

    mUmlY = InitialUmlY;

    mUmlTY = InitialUmlY;

}

/**
 * Bad uml constructor
 * @param game the game
 * @param name the uml class name
 * @param attributes the uml class attributes
 * @param operations the uml class operations
 * @param badReason the reason why this uml is bad
 */
Uml::Uml(Game *game, std::wstring name, std::vector<std::wstring> attributes, std::vector<std::wstring> operations,
        std::wstring badReason) : Uml(game, name, attributes, operations)
{
    mBadReason = badReason;
}

/**
 * Draw the view on a graphics context
 * @param graphics Graphics context to draw on
 */
void Uml::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
        wxColour backyelColor(255,255,193);
        wxBrush rectBrush(backyelColor);
        wxPen pB(*wxBLACK);
        graphics->SetPen(pB);
        graphics->SetBrush(rectBrush);


        // Set font
        wxFont font(wxSize(0, 20),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
        wxColour fontColor(0, 0, 0);
        graphics->SetFont(font, fontColor);

        double yTracker = mUmlY + 50.0;

        double temp = mUmlTY + 25.0;

        int got = 0;

        int amon = mAttributes.size() + mOperations.size();

        double fin = 0.0;


        for(int i = 0; i < mAttributes.size(); i++)
        {
            temp = temp + 22.50;

            if(mAttributes[i].length() > got)
            {
                got = mAttributes[i].length();
            }
        }

        temp = temp + 25.0;


        for(int i = 0; i< mOperations.size(); i++)
        {

            temp = temp + 22.50;

            if(mOperations[i].length() > got)
            {
                got = mOperations[i].length();
            }

        }


        double con = got;

        graphics->DrawRectangle(0.0,mUmlY,con*10.0, temp/1.75);

        temp = 0.0;

        con = con *10.0;

        if(mAttributes.size()!=0)
        {


            graphics->DrawText(mName,con/2.0 -30.0,mUmlY);
            graphics->StrokeLine(0.0,mUmlY + 50.0,con,mUmlY + 50.0);

            for(int i = 0; i < mAttributes.size(); i++)
            {
                graphics->DrawText(mAttributes[i], 0.0, yTracker);
                yTracker = yTracker + 22.50;

                if(mAttributes[i].length() > got)
                {
                    got = mAttributes[i].length();
                }
            }

            yTracker = yTracker + 25.0;

        }

        if (mOperations.size()!=0)
        {

            graphics->StrokeLine(0.0,yTracker,con,yTracker);

            for(int i = 0; i< mOperations.size(); i++)
            {
                graphics->DrawText(mOperations[i], 0.0, yTracker);

                yTracker = yTracker + 22.50;

                if(mOperations[i].length() > got)
                {
                    got = mOperations[i].length();
                }


            }



        }

}


void Uml::Update(double elapsed)
{


    mUmlY -= mSpeedY * elapsed;

}
