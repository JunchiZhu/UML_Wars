project(GameLib)

set(SOURCE_FILES
        pch.h Game.cpp Game.h MainFrame.cpp MainFrame.h GameView.cpp GameView.h ids.h Item.cpp Item.h Kid.cpp Kid.h Pen.h Pen.cpp Vector.h Vector.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)