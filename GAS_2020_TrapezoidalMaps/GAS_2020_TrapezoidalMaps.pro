# Debug configuration
CONFIG(debug, debug|release){
    DEFINES += DEBUG
}

# Release configuration
CONFIG(release, debug|release){
    DEFINES -= DEBUG

    # Uncomment next line if you want to ignore asserts and got a more optimized binary
    CONFIG += FINAL_RELEASE
}

# Final release optimization
FINAL_RELEASE {
    unix:!macx{
        QMAKE_CXXFLAGS_RELEASE -= -g -O2
        QMAKE_CXXFLAGS += -Os -DNDEBUG
    }
}

# cg3lib works with c++11
CONFIG += c++11

# Cg3lib configuration. Available options:
#
#   CG3_ALL                 -- All the modules
#
#   CG3_CORE                -- Core of the library. Geometry primitives and utilities
#   CG3_VIEWER              -- Module containing utilities for creating viewers (Qt and OpenGL)
#
# Example:  CONFIG += CG3_CORE CG3_VIEWER CG3_DATA_STRUCTURES CG3_DCEL
CONFIG += CG3_CORE CG3_VIEWER

# Include the chosen modules
include (cg3lib/cg3.pri)
message($$MODULES)

DISTFILES += \
    LICENSE

SOURCES +=  \
    algorithms/trapezoidalmap_builder.cpp \
    algorithms/trapezoidalmap_query.cpp \
    data_structures/segment_intersection_checker.cpp \
    data_structures/trapezoidalmap_dataset.cpp \
    drawables/drawable_trapezoidalmap_dataset.cpp \
    main.cpp \
    managers/trapezoidalmap_manager.cpp \
    utils/consistence_checker.cpp \
    utils/fileutils.cpp \
    drawables/drawable_vertical_segment.cpp \
    drawables/drawable_trapezoid.cpp \
    data_structures/trapezoidalmap.cpp \
    utils/fill_color.cpp \
    data_structures/trapezoid.cpp \
    utils/point_utils.cpp \
    data_structures/dag.cpp \
    data_structures/node.cpp

FORMS += \
    managers/trapezoidalmapmanager.ui

HEADERS += \
    algorithms/trapezoidalmap_builder.h \
    algorithms/trapezoidalmap_query.h \
    data_structures/segment_intersection_checker.h \
    data_structures/trapezoidalmap_dataset.h \
    drawables/drawable_trapezoidalmap_dataset.h \
    managers/trapezoidalmap_manager.h \
    utils/consistence_checker.h \
    utils/fileutils.h \
    drawables/drawable_vertical_segment.h \
    drawables/drawable_trapezoid.h \
    data_structures/trapezoidalmap.h \
    utils/fill_color.h \
    data_structures/trapezoid.h \
    utils/point_utils.h \
    data_structures/dag.h \
    data_structures/node.h





