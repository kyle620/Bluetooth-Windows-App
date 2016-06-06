#ifndef BLED112_H
#define BLED112_H
#include "stdafx.h"
#include "cmd_def.h"
#include <QSerialPort>				/* used for serial connection */
#include <QSerialPortInfo>			/* used for listing available serial ports */
#include <QObject>
#include <QtCore>
#include <QThread>

class BLED112 : public QObject
{
	Q_OBJECT

public:
	BLED112();
	~BLED112();
	void doSetup(QThread* cThread, const QSerialPortInfo& serial_port);
	bool openCOM();
	void closeSerial();
	void stopThread();
	int parsePacket(unsigned char);															/* Parses the BLE packet */
	void ble_rsp_system_reset(const void *nul);

	//Hello - command for testing
	void ble_rsp_system_hello(const void *nul);

	//Get device bluetooth address
	void ble_rsp_system_address_get(const struct ble_msg_system_address_get_rsp_t *msg);

	//write register
	void ble_rsp_system_reg_write(const struct ble_msg_system_reg_write_rsp_t *msg);

	//read register
	void ble_rsp_system_reg_read(const struct ble_msg_system_reg_read_rsp_t *msg);

	//get and reset packet counters
	void ble_rsp_system_get_counters(const struct ble_msg_system_get_counters_rsp_t *msg);

	// Get status from all connections
	void ble_rsp_system_get_connections(const struct ble_msg_system_get_connections_rsp_t *msg);

	// Read Memory
	void ble_rsp_system_read_memory(const struct ble_msg_system_read_memory_rsp_t *msg);

	// Get Device info 
	void ble_rsp_system_get_info(const struct ble_msg_system_get_info_rsp_t *msg);

	//Send data to endpoint, error is returned if endpoint does not have enough space
	void ble_rsp_system_endpoint_tx(const struct ble_msg_system_endpoint_tx_rsp_t *msg);

	//Add entry to whitelist
	void ble_rsp_system_whitelist_append(const struct ble_msg_system_whitelist_append_rsp_t *msg);

	//Remove entry from whitelist
	void ble_rsp_system_whitelist_remove(const struct ble_msg_system_whitelist_remove_rsp_t *msg);

	//Add entry to whitelist
	void ble_rsp_system_whitelist_clear(const void *nul);

	//Read data from endpoint, error is returned if endpoint does not have enough data.
	void ble_rsp_system_endpoint_rx(const struct ble_msg_system_endpoint_rx_rsp_t *msg);

	//Set watermarks on both input and output side
	void ble_rsp_system_endpoint_set_watermarks(const struct ble_msg_system_endpoint_set_watermarks_rsp_t *msg);

	//Set encryption key that will be used with aes_encrypt and aes_decrypt commands.
	void ble_rsp_system_aes_setkey(const void *nul);

	//Encrypt one block of data
	void ble_rsp_system_aes_encrypt(const struct ble_msg_system_aes_encrypt_rsp_t *msg);

	//Decrypt one block of data
	void ble_rsp_system_aes_decrypt(const struct ble_msg_system_aes_decrypt_rsp_t *msg);

	//Defragment persistent store
	void ble_rsp_flash_ps_defrag(const void *nul);

	//Dump all ps keys
	void ble_rsp_flash_ps_dump(const void *nul);

	//erase all ps keys
	void ble_rsp_flash_ps_erase_all(const void *nul);

	//save ps key
	void ble_rsp_flash_ps_save(const struct ble_msg_flash_ps_save_rsp_t *msg);

	//load ps key
	void ble_rsp_flash_ps_load(const struct ble_msg_flash_ps_load_rsp_t *msg);

	//erase ps key
	void ble_rsp_flash_ps_erase(const void *nul);

	//erase flash page
	void ble_rsp_flash_erase_page(const struct ble_msg_flash_erase_page_rsp_t *msg);

	//write data to user data area
	void ble_rsp_flash_write_data(const struct ble_msg_flash_write_data_rsp_t *msg);

	//read data from user data area.
	void ble_rsp_flash_read_data(const struct ble_msg_flash_read_data_rsp_t *msg);

	//Write to attribute database
	void ble_rsp_attributes_write(const struct ble_msg_attributes_write_rsp_t *msg);

	//Read from attribute database
	void ble_rsp_attributes_read(const struct ble_msg_attributes_read_rsp_t *msg);

	//Read attribute type from database
	void ble_rsp_attributes_read_type(const struct ble_msg_attributes_read_type_rsp_t *msg);

	//Respond to user attribute read request
	void ble_rsp_attributes_user_read_response(const void *nul);

	//Response to attribute_changed event where reason is user-attribute write.
	void ble_rsp_attributes_user_write_response(const void *nul);

	//Send notification or indication to remote device.
	void ble_rsp_attributes_send(const struct ble_msg_attributes_send_rsp_t *msg);

	//Disconnect connection, starts a disconnection procedure on connection
	void ble_rsp_connection_disconnect(const struct ble_msg_connection_disconnect_rsp_t *msg);

	//Get Link RSSI
	void ble_rsp_connection_get_rssi(const struct ble_msg_connection_get_rssi_rsp_t *msg);

	//Update connection parameters
	void ble_rsp_connection_update(const struct ble_msg_connection_update_rsp_t *msg);

	//Request version exchange
	void ble_rsp_connection_version_update(const struct ble_msg_connection_version_update_rsp_t *msg);

	//Get Current channel map
	void ble_rsp_connection_channel_map_get(const struct ble_msg_connection_channel_map_get_rsp_t *msg);

	//Set Channel map
	void ble_rsp_connection_channel_map_set(const struct ble_msg_connection_channel_map_set_rsp_t *msg);

	//Remote feature request
	void ble_rsp_connection_features_get(const struct ble_msg_connection_features_get_rsp_t *msg);

	//Get Connection Status Parameters
	void ble_rsp_connection_get_status(const struct ble_msg_connection_get_status_rsp_t *msg);

	//Raw TX
	void ble_rsp_connection_raw_tx(const struct ble_msg_connection_raw_tx_rsp_t *msg);

	//Discover attributes by type and value
	void ble_rsp_attclient_find_by_type_value(const struct ble_msg_attclient_find_by_type_value_rsp_t *msg);

	//Discover attributes by type and value
	void ble_rsp_attclient_read_by_group_type(const struct ble_msg_attclient_read_by_group_type_rsp_t *msg);

	//Read all attributes where type matches
	void ble_rsp_attclient_read_by_type(const struct ble_msg_attclient_read_by_type_rsp_t *msg);

	//Discover Attribute handle and type mappings
	void ble_rsp_attclient_find_information(const struct ble_msg_attclient_find_information_rsp_t *msg);

	//Read Characteristic value using handle
	void ble_rsp_attclient_read_by_handle(const struct ble_msg_attclient_read_by_handle_rsp_t *msg);

	//write data to attribute
	void ble_rsp_attclient_attribute_write(const struct ble_msg_attclient_attribute_write_rsp_t *msg);

	//write data to attribute using ATT write command
	void ble_rsp_attclient_write_command(const struct ble_msg_attclient_write_command_rsp_t *msg);

	//Send confirmation for received indication, use only if manual indications are enabled
	void ble_rsp_attclient_indicate_confirm(const struct ble_msg_attclient_indicate_confirm_rsp_t *msg);

	//Read Long Characteristic value
	void ble_rsp_attclient_read_long(const struct ble_msg_attclient_read_long_rsp_t *msg);

	//Send prepare write request to remote host
	void ble_rsp_attclient_prepare_write(const struct ble_msg_attclient_prepare_write_rsp_t *msg);

	//Send prepare write request to remote host
	void ble_rsp_attclient_execute_write(const struct ble_msg_attclient_execute_write_rsp_t *msg);

	//Read multiple attributes from server
	void ble_rsp_attclient_read_multiple(const struct ble_msg_attclient_read_multiple_rsp_t *msg);

	//Enable encryption on link
	void ble_rsp_sm_encrypt_start(const struct ble_msg_sm_encrypt_start_rsp_t *msg);

	//Set device to bondable mode
	void ble_rsp_sm_set_bondable_mode(const void *nul);

	//delete bonding information from ps store
	void ble_rsp_sm_delete_bonding(const struct ble_msg_sm_delete_bonding_rsp_t *msg);

	//set pairing requirements
	void ble_rsp_sm_set_parameters(const void *nul);

	//Passkey entered
	void ble_rsp_sm_passkey_entry(const struct ble_msg_sm_passkey_entry_rsp_t *msg);

	//List all bonded devices
	void ble_rsp_sm_get_bonds(const struct ble_msg_sm_get_bonds_rsp_t *msg);

	/* Set out-of-band encryption data for device
	Device does not allow any other kind of pairing except oob if oob data is set. */

	void ble_rsp_sm_set_oob_data(const void *nul);

	/*
	Add all bonded devices with a known public or static address to
	the whitelist. Previous entries in the whitelist are first
	cleared. This command can't be used while advertising, scanning
	or being connected.
	*/
	void ble_rsp_sm_whitelist_bonds(const struct ble_msg_sm_whitelist_bonds_rsp_t *msg);

	//Set GAP central/peripheral privacy flags

	void ble_rsp_gap_set_privacy_flags(const void *nul);

	//Set discoverable and connectable mode
	void ble_rsp_gap_set_mode(const struct ble_msg_gap_set_mode_rsp_t *msg);

	//start or stop discover procedure
	void ble_rsp_gap_discover(const struct ble_msg_gap_discover_rsp_t *msg);

	//Direct connection
	void ble_rsp_gap_connect_direct(const struct ble_msg_gap_connect_direct_rsp_t *msg);

	//End current GAP procedure
	void ble_rsp_gap_end_procedure(const struct ble_msg_gap_end_procedure_rsp_t *msg);

	//Connect to any device on whitelist
	void ble_rsp_gap_connect_selective(const struct ble_msg_gap_connect_selective_rsp_t *msg);

	//Set scan and advertising filtering parameters
	void ble_rsp_gap_set_filtering(const struct ble_msg_gap_set_filtering_rsp_t *msg);

	//Set scan parameters
	void ble_rsp_gap_set_scan_parameters(const struct ble_msg_gap_set_scan_parameters_rsp_t *msg);

	//Set advertising parameters
	void ble_rsp_gap_set_adv_parameters(const struct ble_msg_gap_set_adv_parameters_rsp_t *msg);

	//Set advertisement or scan response data. Use broadcast mode to advertise data
	void ble_rsp_gap_set_adv_data(const struct ble_msg_gap_set_adv_data_rsp_t *msg);

	/*Sets device to Directed Connectable Mode
	Uses fast advertisement procedure for 1.28s after which device enters nonconnectable mode.
	If device has valid reconnection characteristic value, it is used for connection
	otherwise passed address and address type are used */

	void ble_rsp_gap_set_directed_connectable_mode(const struct ble_msg_gap_set_directed_connectable_mode_rsp_t *msg);

	//Configure I/O-port interrupts
	void ble_rsp_hardware_io_port_config_irq(const struct ble_msg_hardware_io_port_config_irq_rsp_t *msg);

	//Set soft timer to send events
	void ble_rsp_hardware_set_soft_timer(const struct ble_msg_hardware_set_soft_timer_rsp_t *msg);

	//Read A/D conversion
	void ble_rsp_hardware_adc_read(const struct ble_msg_hardware_adc_read_rsp_t *msg);

	//Configure I/O-port direction
	void ble_rsp_hardware_io_port_config_direction(const struct ble_msg_hardware_io_port_config_direction_rsp_t *msg);

	//Configure I/O-port function
	void ble_rsp_hardware_io_port_config_function(const struct ble_msg_hardware_io_port_config_function_rsp_t *msg);

	//Configure I/O-port pull-up/pull-down
	void ble_rsp_hardware_io_port_config_pull(const struct ble_msg_hardware_io_port_config_pull_rsp_t *msg);

	//Write I/O-port
	void ble_rsp_hardware_io_port_write(const struct ble_msg_hardware_io_port_write_rsp_t *msg);

	//Read I/O-port
	void ble_rsp_hardware_io_port_read(const struct ble_msg_hardware_io_port_read_rsp_t *msg);

	//Configure SPI
	void ble_rsp_hardware_spi_config(const struct ble_msg_hardware_spi_config_rsp_t *msg);

	//Transfer SPI data
	void ble_rsp_hardware_spi_transfer(const struct ble_msg_hardware_spi_transfer_rsp_t *msg);

	//Read data from I2C bus using bit-bang in cc2540. I2C clk is in P1.7 data in P1.6. Pull-up must be enabled on pins
	void ble_rsp_hardware_i2c_read(const struct ble_msg_hardware_i2c_read_rsp_t *msg);

	//Write data to I2C bus using bit-bang in cc2540. I2C clk is in P1.7 data in P1.6. Pull-up must be enabled on pins
	void ble_rsp_hardware_i2c_write(const struct ble_msg_hardware_i2c_write_rsp_t *msg);

	//Set TX Power
	void ble_rsp_hardware_set_txpower(const void *nul);

	//Set comparator for timer channel
	void ble_rsp_hardware_timer_comparator(const struct ble_msg_hardware_timer_comparator_rsp_t *msg);

	//Enable I/O-port interrupts
	void ble_rsp_hardware_io_port_irq_enable(const struct ble_msg_hardware_io_port_irq_enable_rsp_t *msg);

	//Set I/O-port interrupt direction
	void ble_rsp_hardware_io_port_irq_direction(const struct ble_msg_hardware_io_port_irq_direction_rsp_t *msg);

	//Enable or disable analog comparator
	void ble_rsp_hardware_analog_comparator_enable(const void *nul);

	//Read analog comparator output
	void ble_rsp_hardware_analog_comparator_read(const struct ble_msg_hardware_analog_comparator_read_rsp_t *msg);

	//Configure analog comparator interrupt
	void ble_rsp_hardware_analog_comparator_config_irq(const struct ble_msg_hardware_analog_comparator_config_irq_rsp_t *msg);

	//Set RX Sensitivity
	void ble_rsp_hardware_set_rxgain(const void *nul);

	//Enable or disable USB
	void ble_rsp_hardware_usb_enable(const struct ble_msg_hardware_usb_enable_rsp_t *msg);

	//Start packet transmission, send one packet at every 625us
	void ble_rsp_test_phy_tx(const void *nul);

	//Start receive test
	void ble_rsp_test_phy_rx(const void *nul);

	//End test, and report received packets
	void ble_rsp_test_phy_end(const struct ble_msg_test_phy_end_rsp_t *msg);

	//Reset test
	void ble_rsp_test_phy_reset(const void *nul);

	//Get current channel quality map
	void ble_rsp_test_get_channel_map(const struct ble_msg_test_get_channel_map_rsp_t *msg);

	//Debug command
	void ble_rsp_test_debug(const struct ble_msg_test_debug_rsp_t *msg);

	//Set channel quality measurement mode
	void ble_rsp_test_channel_mode(const void *nul);

	//Reset system
	void ble_rsp_dfu_reset(const void *nul);

	//set address for flashing
	void ble_rsp_dfu_flash_set_address(const struct ble_msg_dfu_flash_set_address_rsp_t *msg);

	//Upload binary for flashing. Address will be updated automatically.
	void ble_rsp_dfu_flash_upload(const struct ble_msg_dfu_flash_upload_rsp_t *msg);

	//Uploading is finished.
	void ble_rsp_dfu_flash_upload_finish(const struct ble_msg_dfu_flash_upload_finish_rsp_t *msg);

	//Device booted up, and is ready to receive commands
	void ble_evt_system_boot(const struct ble_msg_system_boot_evt_t *msg);

	//Debug data output
	void ble_evt_system_debug(const struct ble_msg_system_debug_evt_t *msg);

	//Endpoint receive size crossed watermark
	void ble_evt_system_endpoint_watermark_rx(const struct ble_msg_system_endpoint_watermark_rx_evt_t *msg);

	//Endpoint transmit size crossed watermark
	void ble_evt_system_endpoint_watermark_tx(const struct ble_msg_system_endpoint_watermark_tx_evt_t *msg);

	//Script failure detected
	void ble_evt_system_script_failure(const struct ble_msg_system_script_failure_evt_t *msg);

	//No valid license key found
	void ble_evt_system_no_license_key(const void *nul);

	//Protocol error in command parser
	void ble_evt_system_protocol_error(const struct ble_msg_system_protocol_error_evt_t *msg);

	//Dump key result
	void ble_evt_flash_ps_key(const struct ble_msg_flash_ps_key_evt_t *msg);

	//Attribute value has changed
	void ble_evt_attributes_value(const struct ble_msg_attributes_value_evt_t *msg);

	//User-backed attribute data requested
	void ble_evt_attributes_user_read_request(const struct ble_msg_attributes_user_read_request_evt_t *msg);

	//attribute status flags has changed
	void ble_evt_attributes_status(const struct ble_msg_attributes_status_evt_t *msg);

	//Connection opened
	void ble_evt_connection_status(const struct ble_msg_connection_status_evt_t *msg);

	//Remote version information
	void ble_evt_connection_version_ind(const struct ble_msg_connection_version_ind_evt_t *msg);

	//Remote feature information
	void ble_evt_connection_feature_ind(const struct ble_msg_connection_feature_ind_evt_t *msg);

	//Raw RX
	void ble_evt_connection_raw_rx(const struct ble_msg_connection_raw_rx_evt_t *msg);

	//Link Disconnected
	void ble_evt_connection_disconnected(const struct ble_msg_connection_disconnected_evt_t *msg);

	//Attribute indication has been acknowledged
	void ble_evt_attclient_indicated(const struct ble_msg_attclient_indicated_evt_t *msg);

	//GATT procedure completed
	void ble_evt_attclient_procedure_completed(const struct ble_msg_attclient_procedure_completed_evt_t *msg);

	//group discovery return
	void ble_evt_attclient_group_found(const struct ble_msg_attclient_group_found_evt_t *msg);

	//characteristics found
	void ble_evt_attclient_attribute_found(const struct ble_msg_attclient_attribute_found_evt_t *msg);

	//Handle type mapping found
	void ble_evt_attclient_find_information_found(const struct ble_msg_attclient_find_information_found_evt_t *msg);

	//attribute value returned
	void ble_evt_attclient_attribute_value(const struct ble_msg_attclient_attribute_value_evt_t *msg);

	//Response to read multiple request
	void ble_evt_attclient_read_multiple_response(const struct ble_msg_attclient_read_multiple_response_evt_t *msg);

	//SMP data output
	void ble_evt_sm_smp_data(const struct ble_msg_sm_smp_data_evt_t *msg);

	//Link bonding has failed
	void ble_evt_sm_bonding_fail(const struct ble_msg_sm_bonding_fail_evt_t *msg);

	//Passkey to be entered to remote device
	void ble_evt_sm_passkey_display(const struct ble_msg_sm_passkey_display_evt_t *msg);

	//Passkey Requested
	void ble_evt_sm_passkey_request(const struct ble_msg_sm_passkey_request_evt_t *msg);

	//Bond status information
	void ble_evt_sm_bond_status(const struct ble_msg_sm_bond_status_evt_t *msg);

	//Scan Response
	void ble_evt_gap_scan_response(const struct ble_msg_gap_scan_response_evt_t *msg);

	//Not used
	void ble_evt_gap_mode_changed(const struct ble_msg_gap_mode_changed_evt_t *msg);

	//I/O-port state
	void ble_evt_hardware_io_port_status(const struct ble_msg_hardware_io_port_status_evt_t *msg);

	//soft timer event
	void ble_evt_hardware_soft_timer(const struct ble_msg_hardware_soft_timer_evt_t *msg);

	//adc result
	void ble_evt_hardware_adc_result(const struct ble_msg_hardware_adc_result_evt_t *msg);

	//This event is produced when analog comparator output changes
	void ble_evt_hardware_analog_comparator_status(const struct ble_msg_hardware_analog_comparator_status_evt_t *msg);

	//Device booted up in dfu, and is ready to receive commands
	void ble_evt_dfu_boot(const struct ble_msg_dfu_boot_evt_t *msg);

	/* //These are apart of BGLIB and will be used to interface with BLED112 
	unsigned char ble_cmd_system_reset(uint8 boot_in_dfu);
	unsigned char ble_cmd_system_hello();
	unsigned char ble_cmd_system_address_get();
	unsigned char ble_cmd_system_reg_write(uint16 address, uint8 value);
	unsigned char ble_cmd_system_reg_read(uint16 address);
	unsigned char ble_cmd_system_get_counters();
	unsigned char ble_cmd_system_get_connections();
	unsigned char ble_cmd_system_read_memory(uint32 address, uint8 length);
	unsigned char ble_cmd_system_get_info();
	unsigned char ble_cmd_system_endpoint_tx(uint8 endpoint, uint8 data_len, const uint8 *data_data);
	unsigned char ble_cmd_system_whitelist_append(bd_addr address, uint8 address_type);
	unsigned char ble_cmd_system_whitelist_remove(bd_addr address, uint8 address_type);
	unsigned char ble_cmd_system_whitelist_clear();
	unsigned char ble_cmd_system_endpoint_rx(uint8 endpoint, uint8 size);
	unsigned char ble_cmd_system_endpoint_set_watermarks(uint8 endpoint, uint8 rx, uint8 tx);
	unsigned char ble_cmd_flash_ps_defrag();
	unsigned char ble_cmd_flash_ps_dump();
	unsigned char ble_cmd_flash_ps_erase_all();
	unsigned char ble_cmd_flash_ps_save(uint16 key, uint8 value_len, const uint8 *value_data);
	unsigned char ble_cmd_flash_ps_load(uint16 key);
	unsigned char ble_cmd_flash_ps_erase(uint16 key);
	unsigned char ble_cmd_flash_erase_page(uint8 page);
	unsigned char ble_cmd_flash_write_data(uint32 address, uint8 data_len, const uint8 *data_data);
	unsigned char ble_cmd_flash_read_data(uint32 address, uint8 length);
	unsigned char ble_cmd_attributes_write(uint16 handle, uint8 offset, uint8 value_len, const uint8 *value_data);
	unsigned char ble_cmd_attributes_read(uint16 handle, uint16 offset);
	unsigned char ble_cmd_attributes_read_type(uint16 handle);
	unsigned char ble_cmd_attributes_user_read_response(uint8 connection, uint8 att_error, uint8 value_len, const uint8 *value_data);
	unsigned char ble_cmd_attributes_user_write_response(uint8 connection, uint8 att_error);
	unsigned char ble_cmd_connection_disconnect(uint8 connection);
	unsigned char ble_cmd_connection_get_rssi(uint8 connection);
	unsigned char ble_cmd_connection_update(uint8 connection, uint16 interval_min, uint16 interval_max, uint16 latency, uint16 timeout);
	unsigned char ble_cmd_connection_version_update(uint8 connection);
	unsigned char ble_cmd_connection_channel_map_get(uint8 connection);
	unsigned char ble_cmd_connection_channel_map_set(uint8 connection, uint8 map_len, const uint8 *map_data);
	unsigned char ble_cmd_connection_features_get(uint8 connection);
	unsigned char ble_cmd_connection_get_status(uint8 connection);
	unsigned char ble_cmd_connection_raw_tx(uint8 connection, uint8 data_len, const uint8 *data_data);
	unsigned char ble_cmd_attclient_find_by_type_value(uint8 connection, uint16 start, uint16 end, uint16 uuid, uint8 value_len, const uint8 *value_data);
	unsigned char ble_cmd_attclient_read_by_group_type(uint8 connection, uint16 start, uint16 end, uint8 uuid_len, const uint8 *uuid_data);
	unsigned char ble_cmd_attclient_read_by_type(uint8 connection, uint16 start, uint16 end, uint8 uuid_len, const uint8 *uuid_data);
	unsigned char ble_cmd_attclient_find_information(uint8 connection, uint16 start, uint16 end);
	unsigned char ble_cmd_attclient_read_by_handle(uint8 connection, uint16 chrhandle);
	unsigned char ble_cmd_attclient_attribute_write(uint8 connection, uint16 atthandle, uint8 data_len, const uint8 *data_data);
	unsigned char ble_cmd_attclient_write_command(uint8 connection, uint16 atthandle, uint8 data_len, const uint8 *data_data);
	unsigned char ble_cmd_attclient_indicate_confirm(uint8 connection);
	unsigned char ble_cmd_attclient_read_long(uint8 connection, uint16 chrhandle);
	unsigned char ble_cmd_attclient_prepare_write(uint8 connection, uint16 atthandle, uint16 offset, uint8 data_len, const uint8 *data_data);
	unsigned char ble_cmd_attclient_execute_write(uint8 connection, uint8 commit);
	unsigned char ble_cmd_attclient_read_multiple(uint8 connection, uint8 handles_len, const uint8 *handles_data);
	unsigned char ble_cmd_sm_encrypt_start(uint8 handle, uint8 bonding);
	unsigned char ble_cmd_sm_set_bondable_mode(uint8 bondable);
	unsigned char ble_cmd_sm_delete_bonding(uint8 handle);
	unsigned char ble_cmd_sm_set_parameters(uint8 mitm, uint8 min_key_size, uint8 io_capabilities);
	unsigned char ble_cmd_sm_passkey_entry(uint8 handle, uint32 passkey);
	unsigned char ble_cmd_sm_get_bonds();
	unsigned char ble_cmd_sm_set_oob_data(uint8 oob_len, const uint8 *oob_data);
	unsigned char ble_cmd_gap_set_privacy_flags(uint8 peripheral_privacy, uint8 central_privacy);
	unsigned char ble_cmd_gap_set_mode(uint8 discover, uint8 connect);
	unsigned char ble_cmd_gap_discover(uint8 mode);
	unsigned char ble_cmd_gap_connect_direct(bd_addr address, uint8 addr_type, uint16 conn_interval_min, uint16 conn_interval_max, uint16 timeout, uint16 latency);
	unsigned char ble_cmd_gap_end_procedure();
	unsigned char ble_cmd_gap_connect_selective(uint16 conn_interval_min, uint16 conn_interval_max, uint16 timeout, uint16 latency);
	unsigned char ble_cmd_gap_set_filtering(uint8 scan_policy, uint8 adv_policy, uint8 scan_duplicate_filtering);
	unsigned char ble_cmd_gap_set_scan_parameters(uint16 scan_interval, uint16 scan_window, uint8 active);
	unsigned char ble_cmd_gap_set_adv_parameters(uint16 adv_interval_min, uint16 adv_interval_max, uint8 adv_channels);
	unsigned char ble_cmd_gap_set_adv_data(uint8 set_scanrsp, uint8 adv_data_len, const uint8 *adv_data_data);
	unsigned char ble_cmd_gap_set_directed_connectable_mode(bd_addr address, uint8 addr_type);
	unsigned char ble_cmd_hardware_io_port_config_irq(uint8 port, uint8 enable_bits, uint8 falling_edge);
	unsigned char ble_cmd_hardware_set_soft_timer(uint32 time, uint8 handle, uint8 single_shot);
	unsigned char ble_cmd_hardware_adc_read(uint8 input, uint8 decimation, uint8 reference_selection);
	unsigned char ble_cmd_hardware_io_port_config_direction(uint8 port, uint8 direction);
	unsigned char ble_cmd_hardware_io_port_config_function(uint8 port, uint8 function);
	unsigned char ble_cmd_hardware_io_port_config_pull(uint8 port, uint8 tristate_mask, uint8 pull_up);
	unsigned char ble_cmd_hardware_io_port_write(uint8 port, uint8 mask, uint8 data);
	unsigned char ble_cmd_hardware_io_port_read(uint8 port, uint8 mask);
	unsigned char ble_cmd_hardware_spi_config(uint8 channel, uint8 polarity, uint8 phase, uint8 bit_order, uint8 baud_e, uint8 baud_m);
	unsigned char ble_cmd_hardware_spi_transfer(uint8 channel, uint8 data_len, const uint8 *data_data);
	unsigned char ble_cmd_hardware_i2c_read(uint8 address, uint8 stop, uint8 length);
	unsigned char ble_cmd_hardware_i2c_write(uint8 address, uint8 stop, uint8 data_len, const uint8 *data_data);
	unsigned char ble_cmd_hardware_set_txpower(uint8 power);
	unsigned char ble_cmd_hardware_timer_comparator(uint8 timer, uint8 channel, uint8 mode, uint16 comparator_value);
	unsigned char ble_cmd_hardware_io_port_irq_enable(uint8 port, uint8 enable_bits);
	unsigned char ble_cmd_hardware_io_port_irq_direction(uint8 port, uint8 falling_edge);
	unsigned char ble_cmd_test_phy_tx(uint8 channel, uint8 length, uint8 type);
	unsigned char ble_cmd_test_phy_rx(uint8 channel);
	unsigned char ble_cmd_test_phy_end();
	unsigned char ble_cmd_test_phy_reset();
	unsigned char ble_cmd_test_get_channel_map();
	unsigned char ble_cmd_test_debug(uint8 input_len, const uint8 *input_data);
	unsigned char ble_cmd_test_channel_mode(uint8 mode);
	unsigned char ble_cmd_dfu_reset(uint8 dfu);
	unsigned char ble_cmd_dfu_flash_set_address(uint32 address);
	unsigned char ble_cmd_dfu_flash_upload(uint8 data_len, const uint8 *data_data);
	unsigned char ble_cmd_dfu_flash_upload_finish();
	
	void(*ble_rsp_system_reset)(const struct ble_msg_system_reset_rsp_t *msg);
	void(*ble_rsp_system_hello)(const struct ble_msg_system_hello_rsp_t *msg);
	void(*ble_rsp_system_address_get)(const struct ble_msg_system_address_get_rsp_t *msg);
	void(*ble_rsp_system_reg_write)(const struct ble_msg_system_reg_write_rsp_t *msg);
	void(*ble_rsp_system_reg_read)(const struct ble_msg_system_reg_read_rsp_t *msg);
	void(*ble_rsp_system_get_counters)(const struct ble_msg_system_get_counters_rsp_t *msg);
	void(*ble_rsp_system_get_connections)(const struct ble_msg_system_get_connections_rsp_t *msg);
	void(*ble_rsp_system_read_memory)(const struct ble_msg_system_read_memory_rsp_t *msg);
	void(*ble_rsp_system_get_info)(const struct ble_msg_system_get_info_rsp_t *msg);
	void(*ble_rsp_system_endpoint_tx)(const struct ble_msg_system_endpoint_tx_rsp_t *msg);
	void(*ble_rsp_system_whitelist_append)(const struct ble_msg_system_whitelist_append_rsp_t *msg);
	void(*ble_rsp_system_whitelist_remove)(const struct ble_msg_system_whitelist_remove_rsp_t *msg);
	void(*ble_rsp_system_whitelist_clear)(const struct ble_msg_system_whitelist_clear_rsp_t *msg);
	void(*ble_rsp_system_endpoint_rx)(const struct ble_msg_system_endpoint_rx_rsp_t *msg);
	void(*ble_rsp_system_endpoint_set_watermarks)(const struct ble_msg_system_endpoint_set_watermarks_rsp_t *msg);
	void(*ble_rsp_flash_ps_defrag)(const struct ble_msg_flash_ps_defrag_rsp_t *msg);
	void(*ble_rsp_flash_ps_dump)(const struct ble_msg_flash_ps_dump_rsp_t *msg);
	void(*ble_rsp_flash_ps_erase_all)(const struct ble_msg_flash_ps_erase_all_rsp_t *msg);
	void(*ble_rsp_flash_ps_save)(const struct ble_msg_flash_ps_save_rsp_t *msg);
	void(*ble_rsp_flash_ps_load)(const struct ble_msg_flash_ps_load_rsp_t *msg);
	void(*ble_rsp_flash_ps_erase)(const struct ble_msg_flash_ps_erase_rsp_t *msg);
	void(*ble_rsp_flash_erase_page)(const struct ble_msg_flash_erase_page_rsp_t *msg);
	void(*ble_rsp_flash_write_data)(const struct ble_msg_flash_write_data_rsp_t *msg);
	void(*ble_rsp_flash_read_data)(const struct ble_msg_flash_read_data_rsp_t *msg);
	void(*ble_rsp_attributes_write)(const struct ble_msg_attributes_write_rsp_t *msg);
	void(*ble_rsp_attributes_read)(const struct ble_msg_attributes_read_rsp_t *msg);
	void(*ble_rsp_attributes_read_type)(const struct ble_msg_attributes_read_type_rsp_t *msg);
	void(*ble_rsp_attributes_user_read_response)(const struct ble_msg_attributes_user_read_response_rsp_t *msg);
	void(*ble_rsp_attributes_user_write_response)(const struct ble_msg_attributes_user_write_response_rsp_t *msg);
	void(*ble_rsp_connection_disconnect)(const struct ble_msg_connection_disconnect_rsp_t *msg);
	void(*ble_rsp_connection_get_rssi)(const struct ble_msg_connection_get_rssi_rsp_t *msg);
	void(*ble_rsp_connection_update)(const struct ble_msg_connection_update_rsp_t *msg);
	void(*ble_rsp_connection_version_update)(const struct ble_msg_connection_version_update_rsp_t *msg);
	void(*ble_rsp_connection_channel_map_get)(const struct ble_msg_connection_channel_map_get_rsp_t *msg);
	void(*ble_rsp_connection_channel_map_set)(const struct ble_msg_connection_channel_map_set_rsp_t *msg);
	void(*ble_rsp_connection_features_get)(const struct ble_msg_connection_features_get_rsp_t *msg);
	void(*ble_rsp_connection_get_status)(const struct ble_msg_connection_get_status_rsp_t *msg);
	void(*ble_rsp_connection_raw_tx)(const struct ble_msg_connection_raw_tx_rsp_t *msg);
	void(*ble_rsp_attclient_find_by_type_value)(const struct ble_msg_attclient_find_by_type_value_rsp_t *msg);
	void(*ble_rsp_attclient_read_by_group_type)(const struct ble_msg_attclient_read_by_group_type_rsp_t *msg);
	void(*ble_rsp_attclient_read_by_type)(const struct ble_msg_attclient_read_by_type_rsp_t *msg);
	void(*ble_rsp_attclient_find_information)(const struct ble_msg_attclient_find_information_rsp_t *msg);
	void(*ble_rsp_attclient_read_by_handle)(const struct ble_msg_attclient_read_by_handle_rsp_t *msg);
	void(*ble_rsp_attclient_attribute_write)(const struct ble_msg_attclient_attribute_write_rsp_t *msg);
	void(*ble_rsp_attclient_write_command)(const struct ble_msg_attclient_write_command_rsp_t *msg);
	void(*ble_rsp_attclient_indicate_confirm)(const struct ble_msg_attclient_indicate_confirm_rsp_t *msg);
	void(*ble_rsp_attclient_read_long)(const struct ble_msg_attclient_read_long_rsp_t *msg);
	void(*ble_rsp_attclient_prepare_write)(const struct ble_msg_attclient_prepare_write_rsp_t *msg);
	void(*ble_rsp_attclient_execute_write)(const struct ble_msg_attclient_execute_write_rsp_t *msg);
	void(*ble_rsp_attclient_read_multiple)(const struct ble_msg_attclient_read_multiple_rsp_t *msg);
	void(*ble_rsp_sm_encrypt_start)(const struct ble_msg_sm_encrypt_start_rsp_t *msg);
	void(*ble_rsp_sm_set_bondable_mode)(const struct ble_msg_sm_set_bondable_mode_rsp_t *msg);
	void(*ble_rsp_sm_delete_bonding)(const struct ble_msg_sm_delete_bonding_rsp_t *msg);
	void(*ble_rsp_sm_set_parameters)(const struct ble_msg_sm_set_parameters_rsp_t *msg);
	void(*ble_rsp_sm_passkey_entry)(const struct ble_msg_sm_passkey_entry_rsp_t *msg);
	void(*ble_rsp_sm_get_bonds)(const struct ble_msg_sm_get_bonds_rsp_t *msg);
	void(*ble_rsp_sm_set_oob_data)(const struct ble_msg_sm_set_oob_data_rsp_t *msg);
	void(*ble_rsp_gap_set_privacy_flags)(const struct ble_msg_gap_set_privacy_flags_rsp_t *msg);
	void(*ble_rsp_gap_set_mode)(const struct ble_msg_gap_set_mode_rsp_t *msg);
	void(*ble_rsp_gap_discover)(const struct ble_msg_gap_discover_rsp_t *msg);
	void(*ble_rsp_gap_connect_direct)(const struct ble_msg_gap_connect_direct_rsp_t *msg);
	void(*ble_rsp_gap_end_procedure)(const struct ble_msg_gap_end_procedure_rsp_t *msg);
	void(*ble_rsp_gap_connect_selective)(const struct ble_msg_gap_connect_selective_rsp_t *msg);
	void(*ble_rsp_gap_set_filtering)(const struct ble_msg_gap_set_filtering_rsp_t *msg);
	void(*ble_rsp_gap_set_scan_parameters)(const struct ble_msg_gap_set_scan_parameters_rsp_t *msg);
	void(*ble_rsp_gap_set_adv_parameters)(const struct ble_msg_gap_set_adv_parameters_rsp_t *msg);
	void(*ble_rsp_gap_set_adv_data)(const struct ble_msg_gap_set_adv_data_rsp_t *msg);
	void(*ble_rsp_gap_set_directed_connectable_mode)(const struct ble_msg_gap_set_directed_connectable_mode_rsp_t *msg);
	void(*ble_rsp_hardware_io_port_config_irq)(const struct ble_msg_hardware_io_port_config_irq_rsp_t *msg);
	void(*ble_rsp_hardware_set_soft_timer)(const struct ble_msg_hardware_set_soft_timer_rsp_t *msg);
	void(*ble_rsp_hardware_adc_read)(const struct ble_msg_hardware_adc_read_rsp_t *msg);
	void(*ble_rsp_hardware_io_port_config_direction)(const struct ble_msg_hardware_io_port_config_direction_rsp_t *msg);
	void(*ble_rsp_hardware_io_port_config_function)(const struct ble_msg_hardware_io_port_config_function_rsp_t *msg);
	void(*ble_rsp_hardware_io_port_config_pull)(const struct ble_msg_hardware_io_port_config_pull_rsp_t *msg);
	void(*ble_rsp_hardware_io_port_write)(const struct ble_msg_hardware_io_port_write_rsp_t *msg);
	void(*ble_rsp_hardware_io_port_read)(const struct ble_msg_hardware_io_port_read_rsp_t *msg);
	void(*ble_rsp_hardware_spi_config)(const struct ble_msg_hardware_spi_config_rsp_t *msg);
	void(*ble_rsp_hardware_spi_transfer)(const struct ble_msg_hardware_spi_transfer_rsp_t *msg);
	void(*ble_rsp_hardware_i2c_read)(const struct ble_msg_hardware_i2c_read_rsp_t *msg);
	void(*ble_rsp_hardware_i2c_write)(const struct ble_msg_hardware_i2c_write_rsp_t *msg);
	void(*ble_rsp_hardware_set_txpower)(const struct ble_msg_hardware_set_txpower_rsp_t *msg);
	void(*ble_rsp_hardware_timer_comparator)(const struct ble_msg_hardware_timer_comparator_rsp_t *msg);
	void(*ble_rsp_hardware_io_port_irq_enable)(const struct ble_msg_hardware_io_port_irq_enable_rsp_t *msg);
	void(*ble_rsp_hardware_io_port_irq_direction)(const struct ble_msg_hardware_io_port_irq_direction_rsp_t *msg);
	void(*ble_rsp_test_phy_tx)(const struct ble_msg_test_phy_tx_rsp_t *msg);
	void(*ble_rsp_test_phy_rx)(const struct ble_msg_test_phy_rx_rsp_t *msg);
	void(*ble_rsp_test_phy_end)(const struct ble_msg_test_phy_end_rsp_t *msg);
	void(*ble_rsp_test_phy_reset)(const struct ble_msg_test_phy_reset_rsp_t *msg);
	void(*ble_rsp_test_get_channel_map)(const struct ble_msg_test_get_channel_map_rsp_t *msg);
	void(*ble_rsp_test_debug)(const struct ble_msg_test_debug_rsp_t *msg);
	void(*ble_rsp_test_channel_mode)(const struct ble_msg_test_channel_mode_rsp_t *msg);
	void(*ble_rsp_dfu_reset)(const struct ble_msg_dfu_reset_rsp_t *msg);
	void(*ble_rsp_dfu_flash_set_address)(const struct ble_msg_dfu_flash_set_address_rsp_t *msg);
	void(*ble_rsp_dfu_flash_upload)(const struct ble_msg_dfu_flash_upload_rsp_t *msg);
	void(*ble_rsp_dfu_flash_upload_finish)(const struct ble_msg_dfu_flash_upload_finish_rsp_t *msg);
	void(*ble_evt_system_boot)(const struct ble_msg_system_boot_evt_t *msg);
	void(*ble_evt_system_debug)(const struct ble_msg_system_debug_evt_t *msg);
	void(*ble_evt_system_endpoint_watermark_rx)(const struct ble_msg_system_endpoint_watermark_rx_evt_t *msg);
	void(*ble_evt_system_endpoint_watermark_tx)(const struct ble_msg_system_endpoint_watermark_tx_evt_t *msg);
	void(*ble_evt_system_script_failure)(const struct ble_msg_system_script_failure_evt_t *msg);
	void(*ble_evt_system_no_license_key)(const struct ble_msg_system_no_license_key_evt_t *msg);
	void(*ble_evt_system_protocol_error)(const struct ble_msg_system_protocol_error_evt_t *msg);
	void(*ble_evt_flash_ps_key)(const struct ble_msg_flash_ps_key_evt_t *msg);
	void(*ble_evt_attributes_value)(const struct ble_msg_attributes_value_evt_t *msg);
	void(*ble_evt_attributes_user_read_request)(const struct ble_msg_attributes_user_read_request_evt_t *msg);
	void(*ble_evt_attributes_status)(const struct ble_msg_attributes_status_evt_t *msg);
	void(*ble_evt_connection_status)(const struct ble_msg_connection_status_evt_t *msg);
	void(*ble_evt_connection_version_ind)(const struct ble_msg_connection_version_ind_evt_t *msg);
	void(*ble_evt_connection_feature_ind)(const struct ble_msg_connection_feature_ind_evt_t *msg);
	void(*ble_evt_connection_raw_rx)(const struct ble_msg_connection_raw_rx_evt_t *msg);
	void(*ble_evt_connection_disconnected)(const struct ble_msg_connection_disconnected_evt_t *msg);
	void(*ble_evt_attclient_indicated)(const struct ble_msg_attclient_indicated_evt_t *msg);
	void(*ble_evt_attclient_procedure_completed)(const struct ble_msg_attclient_procedure_completed_evt_t *msg);
	void(*ble_evt_attclient_group_found)(const struct ble_msg_attclient_group_found_evt_t *msg);
	void(*ble_evt_attclient_attribute_found)(const struct ble_msg_attclient_attribute_found_evt_t *msg);
	void(*ble_evt_attclient_find_information_found)(const struct ble_msg_attclient_find_information_found_evt_t *msg);
	void(*ble_evt_attclient_attribute_value)(const struct ble_msg_attclient_attribute_value_evt_t *msg);
	void(*ble_evt_attclient_read_multiple_response)(const struct ble_msg_attclient_read_multiple_response_evt_t *msg);
	void(*ble_evt_sm_smp_data)(const struct ble_msg_sm_smp_data_evt_t *msg);
	void(*ble_evt_sm_bonding_fail)(const struct ble_msg_sm_bonding_fail_evt_t *msg);
	void(*ble_evt_sm_passkey_display)(const struct ble_msg_sm_passkey_display_evt_t *msg);
	void(*ble_evt_sm_passkey_request)(const struct ble_msg_sm_passkey_request_evt_t *msg);
	void(*ble_evt_sm_bond_status)(const struct ble_msg_sm_bond_status_evt_t *msg);
	void(*ble_evt_gap_scan_response)(const struct ble_msg_gap_scan_response_evt_t *msg);
	void(*ble_evt_gap_mode_changed)(const struct ble_msg_gap_mode_changed_evt_t *msg);
	void(*ble_evt_hardware_io_port_status)(const struct ble_msg_hardware_io_port_status_evt_t *msg);
	void(*ble_evt_hardware_soft_timer)(const struct ble_msg_hardware_soft_timer_evt_t *msg);
	void(*ble_evt_hardware_adc_result)(const struct ble_msg_hardware_adc_result_evt_t *msg);
	void(*ble_evt_dfu_boot)(const struct ble_msg_dfu_boot_evt_t *msg);
	*/
	//Reset device

	/* These are the methods that can pass data back to UI thread */
signals:
	void connectBLED(bool);
	void updateLOG(QString);

	/* These are slots that receive signals from the UI thread */
public slots:
void backgroundTask();
void onDisconnect();				// handles when user presses the disconect button, siganl is emiitted from BluetoothGUI
void onScan();


private:
	QSerialPortInfo bled_port;
	bool bled112_connected;						// TRUE when bled112 is connected, FALSE otherwise
	int readMessage();							// Reads data from BLED112, returns 0 for success

	/* For BGLIB use */
	unsigned char lastCommand[2];
	unsigned char lastResponse[2];
	unsigned char lastEvent[2];
	unsigned char packetMode;

	/* Incoming packet Buffer variables */
	unsigned char * bgapiRXBuffer;
	unsigned char   bgapiRXBufferSize;
	unsigned char	bgapiRXBufferPos;
	unsigned short	bgapiRXDataLen;
	
};
Q_DECLARE_METATYPE(BLED112*)
#endif // BLED112_H
