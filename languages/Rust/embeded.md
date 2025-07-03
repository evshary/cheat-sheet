# Embedded System

Rust can also be used in ebedded systems.

## Size

Why Rust program is larger:

1. Zero-cost abstractions: When we use generics, Rust will generate the code for each types (monomorphization), which makes the code faster but increases the size.
2. Safety Check
3. Default Link settings
4. Build with standard libraries

How to decrease the size:

1. Use `no_std`
2. Compile optimization:
   1. Build with Release mode
   2. LTO (Link-Time Optimization): Remove unused code
3. Avoid using too many generics

## embedded-hal

A trait to provide the abstraction.
Drivers can call the trait function, and device vendors just needs to implement the HALs.

```raw
+--------------------------------+
|        應用層程式碼              |  <-- (1) 呼叫設備驅動程式
| (使用設備驅動程式和其他函式庫)      |
+--------------------------------+
             ^
             |
             |
+--------------------------------+
|     設備驅動程式 (Crates)        |  <-- (2) 呼叫 `embedded-hal` traits
|  (e.g. `bmp280-rs`, `ssd1306`) |
+--------------------------------+
             ^
             |
             |
+--------------------------------+
|    晶片特定的 HALs (Crates)      |  <-- (3) 實作 `embedded-hal` traits，並呼叫 `PACs`
|(e.g.`stm32f4xx-hal`,`nrf-hal`) |
+--------------------------------+
             ^
             |
             |
+--------------------------------+
| PACs(Peripheral Access Crates) |  <-- (4) 直接操作硬體暫存器
| (直接映射微控制器硬體暫存器)       |
+--------------------------------+
             ^
             |
             |
+--------------------------------+
|            硬體晶片             |
+--------------------------------+
```

## embassy

Provide a framework for aync in embedded systems.

It also provides `embassy-hal` for the abstraction.
