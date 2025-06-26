## 🧱 Bare Metal STM32F4

This repository showcases firmware development for the STM32F4 series using a **pure bare-metal approach** — without relying on STM32 HAL or CMSIS. It features a **handwritten startup file**, a **custom linker script**, and builds using the **GCC ARM Embedded Toolchain**.

### 🚀 Highlights
- No STM32 HAL or CMSIS dependencies
- Direct register-level programming
- Custom `startup.s` and `linker.ld` written from scratch
- Compiled with `arm-none-eabi-gcc`
- Clean, minimal code structure for learning purposes

### 🧪 Implemented Examples
- Clock configuration
- GPIO toggle
- UART transmit/receive
- Delay with SysTick
- Peripheral initialization by register access

### 📦 Target MCU
- STM32F407VET6 (or compatible STM32F4 device)

---

This project is ideal for those learning how MCUs work at the lowest level, or building their own lightweight embedded framework from scratch.
