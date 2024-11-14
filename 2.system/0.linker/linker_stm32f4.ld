ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS 
{
    .text :
    {
        KEEP(*(.isr_vector))   /* Giữ lại vector ngắt */
        *(.text)               /* Mã chương trình */
        *(.rodata)             /* Dữ liệu chỉ đọc */
        . = ALIGN(4);
        _etext = .;            /* Đánh dấu điểm cuối của section text */
    } > FLASH

    _la_data = LOADADDR(.data);

    .data : AT(_la_data)
    {
        _sdata = .;            /* Bắt đầu section data */
        *(.data)               /* Dữ liệu */
        . = ALIGN(4);
        _edata = .;            /* Kết thúc section data */
    } > SRAM

    .bss :
    {
        _sbss = .;             /* Bắt đầu section bss */
        *(.bss)                /* Biến bss */
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;             /* Kết thúc section bss */
    } > SRAM
}
