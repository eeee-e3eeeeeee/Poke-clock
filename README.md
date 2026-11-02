#  Poke Clock

It's a clock that displays pixel art Pokémon that I draw by myself. It will display the date and time and will look like a retro TV.

## Features

- Displays current time.
- Shows the date and day of the week.
- Displays custom Pokémon pixel art.
- 3d modeled enclosure
- looks like a retro tv and has antenna that look like pikachu's ears.

##  Hardware

| Component | Purpose |
|---|---|
| Seeed Studio XIAO ESP32-C3 | Main microcontroller |
| Elecrow 2-inch IPS TFT Display | Color display |
| Jumper wires | Electrical connections |
| 3D-printed enclosure | Clock housing |

## Tools

- **C++** – Clock firmware and display programming.
- **PlatformIO** – Development environment in VS Code.
- **Adafruit GFX Library** – Graphics and drawing functions.
- **Adafruit ST7789 Library** – TFT display communication.
- **Piskel** – Creating custom Pokémon pixel art.
- **image2cpp** – Converting pixel art into C++ bitmap arrays.
- **KiCad** – Circuit schematic design.
- **Onshape** – 3D enclosure design.

## Pixel Art

Custom Pokémon sprites are created in Piskel using a 32 × 32 pixel canvas.

The images are converted into RGB565 format using image2cpp.

## How It Works

1. The ESP32-C3 connects to Wi-Fi.
2. It gets the current time.
3. The time is displayed on the TFT screen.
4. Custom Pokémon sprites are on screen along side the time

## Stuff I want to add

- Add more Pokémon sprites.
- Make them animated
