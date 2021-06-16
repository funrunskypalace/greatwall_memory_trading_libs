
file(GLOB_RECURSE on_time_trading_src
    "*.h"
    "*.hpp"
    "*.cc"
    "*.cpp"
    ${StratRunnerSrcDir}/source/pch/compat.h
	${StratRunnerSrcDir}/source/pch/compat.cc
	${StratRunnerSrcDir}/source/pch/compat_*.*
)

add_library(on_time_trading SHARED ${on_time_trading_src})
cotire(on_time_trading)
set_target_properties(on_time_trading PROPERTIES OUTPUT_NAME "on_time_trading_$ENV{OSVER}$<$<CONFIG:Debug>:d>")
set_property(TARGET on_time_trading PROPERTY FOLDER "strategy_dll")
#add_dependencies(on_time_trading )
target_link_libraries(on_time_trading skypalace_framework_$ENV{OSVER}$<$<CONFIG:Debug>:d> ${OpenOrderLibraryRef} strat_framework_common_$ENV{OSVER}$<$<CONFIG:Debug>:d>)

if(UNIX)
	target_link_libraries(on_time_trading pthread dl)
else()
    add_precompiled_header(on_time_trading pch/compat.h FORCEINCLUDE SOURCE_CXX ${StratRunnerSrcDir}/source/pch/compat.cc)
    set_target_properties(on_time_trading PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE" VS_DEBUGGER_WORKING_DIRECTORY ${OpenOrderDistDir}/app_home/bin)
endif()
add_custom_command(TARGET on_time_trading POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${StratRunnerSrcDir}/config/on_time_trading_config.json.template ${OpenOrderDistDir}/app_home/instance_config)
add_custom_command(TARGET on_time_trading POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${StratRunnerSrcDir}/config/on_time_trading_config.json.template ${OpenOrderDistDir}/target/instance_config)
add_custom_command(TARGET on_time_trading POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:on_time_trading> ${OpenOrderDistDir}/app_home/bin/)
INSTALL(TARGETS on_time_trading RUNTIME)