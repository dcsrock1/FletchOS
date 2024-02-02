ENTRY(start)

SECTIONS
{
	. = 1M;

	.boot :
	{
		KEEP(*(.multiboot_header))
	}
	.idt BLOCK(0x1000) : ALIGN(0x1000)
	{
		IDT = .;
		. = . + 0x1000;
	}
	.text :
	{
		*(.text)
	}
}
