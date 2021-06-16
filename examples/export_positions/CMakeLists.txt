
file(GLOB_RECURSE export_positions_src
    "*.h"
    "*.hpp"
    "*.cc"
    "*.cpp"
    ${StratRunnerSrcDir}/source/pch/compat.h
	${StratRunnerSrcDir}/source/pch/compat.cc
	${StratRunnerSrcDir}/source/pch/compat_*.*
)

add_library(export_positions SHARED ${export_positions_src})
cotire(export_positions)
set_target_properties(export_positions PROPERTIES OUTPUT_NAME "export_positions_$ENV{OSVER}$<$<CONFIG:Debug>:d>")
set_property(TARGET export_positions PROPERTY FOLDER "strategy_dll")
#add_dependencies(export_positions )
target_link_libraries(export_positions skypalace_framework_$ENV{OSVER}$<$<CONFIG:Debug>:d> ${OpenOrderLibraryRef} strat_framework_common_$ENV{OSVER}$<$<CONFIG:Debug>:d>)

if(UNIX)
	target_link_libraries(export_positions pthread dl)
else()
    add_precompiled_header(export_positions pch/compat.h FORCEINCLUDE SOURCE_CXX ${StratRunnerSrcDir}/source/pch/compat.cc)
    set_target_properties(export_positions PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE" VS_DEBUGGER_WORKING_DIRECTORY ${OpenOrderDistDir}/app_home/bin)
    set_target_properties(export_positions PROPERTIES VS_DEBUGGER_COMMAND "./../app_home/bin/greatwall_host_win64$<$<CONFIG:Debug>:d>.exe")
endif()
add_custom_command(TARGET export_positions POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${StratRunnerSrcDir}/config/export_positions_config.json.template ${OpenOrderDistDir}/app_home/instance_config)
add_custom_command(TARGET export_positions POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${StratRunnerSrcDir}/config/export_positions_config.json.template ${OpenOrderDistDir}/target/instance_config)
add_custom_command(TARGET export_positions POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:export_positions> ${OpenOrderDistDir}/app_home/bin/)
INSTALL(TARGETS export_positions RUNTIME)