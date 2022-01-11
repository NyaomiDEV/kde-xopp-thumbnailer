project(xoppthumbnailer)

cmake_minimum_required(VERSION 3.16.0)
set(QT_MIN_VERSION "5.2.0")

find_package(ECM 1.0.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(FeatureSummary)
include(WriteBasicConfigVersionFile)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS Gui)
find_package(KF5 REQUIRED COMPONENTS KIO)

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

set(
  xoppthumbnailer_PART_SRCS
  xoppthumbnailer.cpp
)

add_library(xoppthumbnailer MODULE ${xoppthumbnailer_PART_SRCS})

target_link_libraries(xoppthumbnailer Qt5::Gui KF5::KIOWidgets)

install(TARGETS xoppthumbnailer DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES xoppthumbnailer.desktop DESTINATION ${SERVICES_INSTALL_DIR})
