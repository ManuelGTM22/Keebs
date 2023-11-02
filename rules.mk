
MOUSEKEY_ENABLE = yes       # Mouse keys
BACKLIGHT_ENABLE = no     # Enable keyboard backlight functionality
OLED_ENABLE= yes     # OLED display
WPM_ENABLE = yes
LTO_ENABLE = yes
OLED_DRIVER_ENABLE = yes
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
OLED_DRIVER = SSD1306    # OLED display

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
