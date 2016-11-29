# Wi-Fi Cloud Thermometer

It assumes that NodeMCU DEVKIT V1.0 board is used.

## Basic commands

Build code:

    pio run

Upload code:

    pio run -t upload

Upload code over ther air (OTA):

    pio run --t upload --upload-port 192.168.1.22

## Other Notes

### Sleep Mode

Connect `GPIO16/USER/WAKE` and `RST` pins and uncomment `ESP.deepSleep(60 * 1000000);` line to put the board into sleep mode for 60 seconds.

![NodeMCU DEVKIT V1.0](https://pradeepsinghblog.files.wordpress.com/2016/04/nodemcu_pins.png)

Note, that firmware uploading will not work while pins are connected.