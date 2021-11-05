project(GameLib)

set(SOURCE_FILES
        pch.h
        Game.cpp Game.h
        MainFrame.cpp MainFrame.h
        GameView.cpp GameView.h
        ids.h
        Item.cpp Item.h
        Kid.cpp Kid.h
        Scoreboard.cpp Scoreboard.h
        Uml.cpp Uml.h
        Pen.cpp Pen.h
        Vector.cpp Vector.h
        UmlLoader.cpp UmlLoader.h
        UmlNode.cpp UmlNode.h
        ItemVisitor.cpp ItemVisitor.h
        UmlInheritNode.cpp UmlInheritNode.h
        SoundStuff.cpp SoundStuff.h
        UmlVisitor.cpp UmlVisitor.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml  media REQUIRED)

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})


add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})