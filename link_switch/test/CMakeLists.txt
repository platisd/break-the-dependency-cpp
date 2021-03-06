set(mocks ${CMAKE_CURRENT_SOURCE_DIR}/mocks)

# MockAsioSerialPortManager
add_library(mock_asio_serial_port_manager mocks/AsioSerialPortManager.cpp)
target_include_directories(mock_asio_serial_port_manager PUBLIC ${mocks})
target_link_libraries(mock_asio_serial_port_manager
        PUBLIC
        asio_serial_port_manager_interface
        gmock)
# Gmock doesn't play nice with CLang so we need to disable a warning
target_compile_options(mock_asio_serial_port_manager PRIVATE -Wno-gnu-zero-variadic-macro-arguments)

# LinkSwitchCameraPowerControllerTest
add_executable(link_switch_camera_power_controller_test LinkSwitchCameraPowerControllerTest.cpp)
target_link_libraries(link_switch_camera_power_controller_test
        link_switch_camera_power_controller
        mock_asio_serial_port_manager)
configure_test(link_switch_camera_power_controller_test)
