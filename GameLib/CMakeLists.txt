project(GameLib)

set(SOURCE_FILES
        pch.h
        Game.cpp Game.h
        MainFrame.cpp MainFrame.h
        GameView.cpp GameView.h
        ids.h
        Item.cpp Item.h
        Kid.cpp Kid.h
        pen.cpp pen.h
        vector.cpp vector.h
        Scoreboard.cpp Scoreboard.h
        Uml.cpp Uml.h
        Pen.cpp Pen.h
        Vector.cpp Vector.h
        UmlLoader.cpp UmlLoader.h
        UmlNode.cpp UmlNode.h)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)