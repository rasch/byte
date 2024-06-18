# byte

![The byte Keyboard, Version 0.1.0][image]

An 8-key, one-handed, business card sized keyboard.

- Keyboard Maintainer: [rasch](https://github.com/rasch/byte)
- Hardware Supported: Byte 0.1.0 (stm32f072)
- Hardware Availability: [byte]

## Getting Board

Check out [the byte releases page][releases] for the required files to get
PCBs manufactured (`plot.zip`) and/or assembled (`bom.csv` and `cpl.csv`). For
those with soldering abilities, an interactive BOM/CPL HTML file (`ibom.html`)
is provided to aid with self-assembly.

During development, it may be preferable (faster) to run rule checks and test
builds locally. There is a `run` shell script in the root of this repository
that is used by the CI/CD for building releases. This script can be run
directly (`./run pcb`), but it requires the `kicad-cli` 8.0+ release to be
installed. Instead, if `podman` is available, it is recommended to use the
`build` script. This script just runs the `./run` script in the
`kicad/kicad:8.0` container. The build files and reports (ERC/DRC) are placed in
the `dist` directory.

![The byte Keyboard, Version 0.1.0][image-back]

In addition to the parts listed in the BOM, the following will be needed for a
complete keyboard:

- 8 x Kailh Low Profile Choc Switches (PG1350)
- 8 x 1u Choc Keycaps (such as MBK)
- USB-C cable to connect to device
- Some rubber feet or neoprene adhesive rubber pads to prevent the board from
  sliding all over the place

## Firmware Installation

Download the firmware, `byte_left.bin` or `byte_right.bin`, from [the byte
releases page][releases]. To flash the keyboard, press the reset button on the
PCB to enter bootloader mode, then run:

```sh
# left-handed artsey
dfu-util -a 0 -d 0483:DF11 -s 0x8000000:leave -D byte_left.bin

# or right-handed artsey
dfu-util -a 0 -d 0483:DF11 -s 0x8000000:leave -D byte_right.bin
```

For details on compiling the firmware, please see the [Github Actions
workflow][build].

## Keymap

The firmware, `byte_left.bin` and `byte_right.bin`, keymaps are based on the
[ARTSEY v0.9.0][artsey] layout. This layout is of limited use for most people,
but it's fun to learn and very useful for those with certain disabilities. The
firmware keymap configuration, `fw/keymaps/left/keymap.c`, provides a good
starting point for making the byte yours! It can be a macropad for your favorite
game, for drawing with Inkscape, for designing keyboards with KiCad, or even
making PowerPoint presentations (Ew!). Check out the [QMK documentation][qmk] to
get inspiration for your own macropad layout!

## License

[Solderpad Hardware License v2.1](LICENSE)

[byte]: https://github.com/rasch/byte
[releases]: https://github.com/rasch/byte/releases/
[image]: https://i.imgur.com/48yj4tK.jpg
[image-back]: https://i.imgur.com/SwSe1no.jpg
[build]: https://github.com/rasch/byte/blob/main/.github/workflows/fw.yml
[artsey]: https://artsey.io/
[qmk]: https://docs.qmk.fm/#/
